cmake_minimum_required(VERSION 3.16)
project(pack)

set(CMAKE_CXX_STANDARD 11)

add_executable(pack main.cpp Packet.cpp Packet.h Attack.cpp Attack.h SniffingAttack.cpp SniffingAttack.h ModificationAttack.cpp ModificationAttack.h AccessPoint.cpp AccessPoint.h)
