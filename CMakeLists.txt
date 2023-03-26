cmake_minimum_required(VERSION 3.24)
project(P2)

set(CMAKE_CXX_STANDARD 11)

add_executable(P2 p2pqdriver.cpp LinkedList.h LinkedListPQ.h ListIterator.h Node.h PriorityQueue.h)
