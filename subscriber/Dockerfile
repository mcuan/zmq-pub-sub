FROM gcc:9

RUN	set -ex; 																					\
		apt-get update; 																		\
		apt-get install -y cmake libzmq3-dev libprotobuf-dev protobuf-compiler python3-pip; 													\
		mkdir -p /usr/src; 																		\
		cd /usr/src;																			\
		curl -L https://github.com/zeromq/cppzmq/archive/refs/tags/v4.7.1.tar.gz | tar -zxf -;	\
		cd /usr/src/cppzmq-4.7.1;																\
		cmake -D CPPZMQ_BUILD_TESTS:BOOL=OFF .; make; make install

COPY . /usr/src/pub-sub

RUN set -ex;												\
		cd /usr/src/pub-sub;								\
		mkdir build;										\
		protoc --proto_path=. --python_out=. msg.proto;

RUN pip3 install pyzmq
RUN pip3 install protobuf

EXPOSE 12345