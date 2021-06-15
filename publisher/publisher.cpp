#include <iostream>
#include <chrono>
#include <thread>

#include <build/msg.pb.h>

#include <zmq.hpp>

std::string create_gpb_msg(int count) {
    telemetry::Gps_Imu msg;
    msg.set_lat(1.0f);
    msg.set_lon(2.0f);
    msg.set_alt(3.0f);
    msg.set_heading(4.0f);

    msg.set_time(count);

    msg.set_imu_x_accel(6.0f);
    msg.set_imu_y_accel(7.0f);
    msg.set_imu_z_accel(8.0f);

    msg.set_imu_gyro_x(9.0f);
    msg.set_imu_gyro_y(10.0f);
    msg.set_imu_gyro_z(11.0f);
    msg.set_imu_gyro_temp(12.0f);

    return msg.SerializeAsString();
}

int main(int argc, char *argv[])
{
    zmq::context_t context (1);
    zmq::socket_t publisher (context, ZMQ_PUB);
    publisher.bind("tcp://*:12345");

    int count = 0;

    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::string encoded_msg = create_gpb_msg(count);
        zmq::message_t zmq_msg(encoded_msg.begin(), encoded_msg.end());
        publisher.send(zmq_msg, zmq::send_flags::none);

        count+=1;
    }

    return 0;
}
