import zmq

from msg_pb2 import *

context = zmq.Context()
socket = context.socket(zmq.SUB)
socket.connect("tcp://publisher:12345")
socket.setsockopt_string(zmq.SUBSCRIBE, "")

msg = Gps_Imu()

while True:

    encoded_msg = socket.recv()
    msg.ParseFromString(encoded_msg)
    print(str(msg))
