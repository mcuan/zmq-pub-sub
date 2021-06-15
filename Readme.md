# Pub-Sub message pattern (ZeroMQ)

This repository contains a docker compose project with two containers:

`publisher` : C++     (cppzmq)  <br>
`subscriber` : Python (pyzmq) <br>

Demonstrating the PUB-SUB pattern sending messages with Protobuf IDL (_see `msg.proto`_)

## Build and Run

Use `docker-compose` for docker networking

```bash
# To build or rebuild:
$ docker-compose build
# To run:
$ docker-compose up
```

