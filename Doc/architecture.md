photon_rtc/
├── README.md
├── CMakeLists.txt
├── LICENSE
├── .gitignore
├── build.sh
│
├── photon/
│   ├── runtime/
│   │   ├── task/
│   │   │   ├── task.h
│   │   │   ├── task.cpp
│   │   │   └── README.md
│   │   │
│   │   ├── io_loop/
│   │   │   ├── io_loop.h
│   │   │   ├── io_loop.cpp
│   │   │   └── README.md
│   │   │
│   │   ├── accept_awaiter/
│   │   │   ├── accept_awaiter.h
│   │   │   ├── accept_awaiter.cpp
│   │   │   └── README.md
│   │   │
│   │   ├── connect_awaiter/
│   │   │   ├── connect_awaiter.h
│   │   │   ├── connect_awaiter.cpp
│   │   │   └── README.md
│   │   │
│   │   ├── read_awaiter/
│   │   │   ├── read_awaiter.h
│   │   │   ├── read_awaiter.cpp
│   │   │   └── README.md
│   │   │
│   │   ├── write_awaiter/
│   │   │   ├── write_awaiter.h
│   │   │   ├── write_awaiter.cpp
│   │   │   └── README.md
│   │   │
│   │   ├── writev_awaiter/
│   │   │   ├── writev_awaiter.h
│   │   │   ├── writev_awaiter.cpp
│   │   │   └── README.md
│   │   │
│   │   ├── timeout_awaiter/
│   │   │   ├── timeout_awaiter.h
│   │   │   ├── timeout_awaiter.cpp
│   │   │   └── README.md
│   │   │
│   │   └── mutex/
│   │       ├── mutex.h
│   │       ├── mutex.cpp
│   │       └── README.md
│   │
│   ├── network/
│   │   ├── socket/
│   │   │   ├── socket.h
│   │   │   ├── socket.cpp
│   │   │   └── README.md
│   │   │
│   │   ├── acceptor/
│   │   │   ├── acceptor.h
│   │   │   ├── acceptor.cpp
│   │   │   └── README.md
│   │   │
│   │   ├── connector/
│   │   │   ├── connector.h
│   │   │   ├── connector.cpp
│   │   │   └── README.md
│   │   │
│   │   └── handler/
│   │       ├── handler.h
│   │       ├── handler.cpp
│   │       └── README.md
│   │
│   ├── protocol/
│   │   ├── protocol/
│   │   │   ├── protocol.h
│   │   │   ├── protocol.cpp
│   │   │   └── README.md
│   │   │
│   │   ├── config/
│   │   │   ├── config.h
│   │   │   ├── config.cpp
│   │   │   └── README.md
│   │   │
│   │   └── error/
│   │       ├── error.h
│   │       ├── error.cpp
│   │       └── README.md
│   │
│   ├── rpc/
│   │   ├── channel/
│   │   │   ├── channel.h
│   │   │   ├── channel.cpp
│   │   │   └── README.md
│   │   │
│   │   ├── channel_map/
│   │   │   ├── channel_map.h
│   │   │   ├── channel_map.cpp
│   │   │   └── README.md
│   │   │
│   │   └── dispatcher/
│   │       ├── dispatcher.h
│   │       ├── dispatcher.cpp
│   │       └── README.md
│   │
│   ├── memory/
│   │   ├── buffer_pool/
│   │   │   ├── buffer_pool.h
│   │   │   ├── buffer_pool.cpp
│   │   │   └── README.md
│   │   │
│   │   └── slab/
│   │       ├── slab.h
│   │       ├── slab.cpp
│   │       └── README.md
│   │
│   ├── services/
│   │   ├── echo_service/
│   │   │   ├── echo_service.h
│   │   │   ├── echo_service.cpp
│   │   │   └── README.md
│   │   │
│   │   └── ping_service/
│   │       ├── ping_service.h
│   │       ├── ping_service.cpp
│   │       └── README.md
│   │
│   └── app/
│       ├── server_app/
│       │   ├── server_app.h
│       │   ├── server_app.cpp
│       │   └── README.md
│       │
│       └── client_app/
│           ├── client_app.h
│           ├── client_app.cpp
│           └── README.md
│
├── benchmarks/
│   ├── client_bench.py
│   ├── client_bench.sh
│   ├── client_bench.bat
│   ├── client_bench_win.py
│   ├── server_bench.sh
│   ├── benchmark_report.md
│   └── README.md
│
└── docs/
    └── architecture.mds