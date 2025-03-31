cmake_minimum_required(VERSION 3.29)
project(cs008LinkedLists)

set(CMAKE_CXX_STANDARD 20)

add_executable(cs008LinkedLists main.cpp
        Node.cpp
        Node.h
        LinkedList.cpp
        LinkedList.h
        NodeIterator.cpp
        NodeIterator.h
        ReverseIterator.cpp
        ReverseIterator.h
        ConstIterator.cpp
        ConstIterator.h
)
