cmake_minimum_required(VERSION 3.24)
project(P2)

set(CMAKE_CXX_STANDARD 11)

add_executable(P2 main.cpp LinkedList.h LinkedListPQ.h ListIterator.h Node.h p2driver.cpp p2pqdriver.cpp PriorityQueue.h)
