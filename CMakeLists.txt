cmake_minimum_required(VERSION 4.0)
project(PCSimulatorScript)
add_executable(PCSimulatorScript main.c
                PcToJson.c)
include_directories(PCSimulatorScript Include)
target_link_libraries(PCSimulatorScript readline)
