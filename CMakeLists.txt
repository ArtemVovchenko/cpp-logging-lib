cmake_minimum_required(VERSION 3.19)
project(Logging)

set(CMAKE_CXX_STANDARD 14)

add_library(
        Logging SHARED
        include/Log.h
        include/Logger.h
        include/MessageHandler.h
        include/Types.h
        include/Abstract.h
        src/Log.cpp
        src/Logger.cpp
        src/MessageHandler.cpp
)