cmake_minimum_required(VERSION 3.28)
project(BEClient)

set(CMAKE_CXX_STANDARD 20)

add_executable(BEClient main.cpp
        src/Client.cpp
        src/MessageStr.cpp
        src/Fabric.cpp
        include/Client.h
        include/IMessage.h
        include/MessageStr.h
        include/Fabric.h
        src/SocketConnection.cpp
        include/SocketConnection.h
)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_BINARY_DIR}
)
