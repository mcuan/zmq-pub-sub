cmake_minimum_required(VERSION 3.13)
project(zmq-publisher)
set (CMAKE_CXX_STANDARD 14)

find_package(cppzmq)
find_package(Protobuf)

# include_directories(${Protobuf_INCLUDE_DIR})
include_directories("${PROJECT_SOURCE_DIR}")

PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER msg.proto)
ADD_LIBRARY(idlmsg ${PROTO_HEADER} ${PROTO_SRC})

add_executable(publisher "publisher.cpp")
target_link_libraries(publisher idlmsg
                          ${Protobuf_LIBRARIES}
                          cppzmq)
