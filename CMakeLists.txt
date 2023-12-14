cmake_minimum_required(VERSION 3.26)
project(ProyectoTeoria_RG)

set(CMAKE_CXX_STANDARD 14)

if(MINGW)
        link_libraries(ws2_32 wsock32)
endif()

include_directories(./src/lib/binarySearch)
include_directories(./src/lib/linearSearch)
include_directories(./src/lib/quicksort)

add_executable(ProyectoTeoria_RG ./src/main.cpp)

add_subdirectory(./src/lib/binarySearch)
add_subdirectory(./src/lib/linearSearch)
add_subdirectory(./src/lib/quicksort)

target_link_directories(ProyectoTeoria_RG
        PRIVATE binarySearch
        PRIVATE linearSearch
        PRIVATE quicksort)

target_link_libraries(ProyectoTeoria_RG
        PRIVATE binarySearch
        PRIVATE linearSearch
        PRIVATE quicksort)