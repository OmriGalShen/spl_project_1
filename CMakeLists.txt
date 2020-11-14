cmake_minimum_required(VERSION 3.17)
project(spl_project_1)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(spl_project_1
        include/Agent.h
        include/Graph.h
        include/json.hpp
        include/Session.h
        include/Tree.h
        src/classes/agents/Agent.cpp
        src/classes/agents/ContactTracer.cpp
        src/classes/agents/Virus.cpp
        src/classes/trees/CycleTree.cpp
        src/classes/trees/MaxRankTree.cpp
        src/classes/trees/RootTree.cpp
        src/classes/trees/Tree.cpp
        src/classes/Graph.cpp
        src/classes/Session.cpp
        src/main.cpp)
