cmake_minimum_required (VERSION 3.0)
project (createdefaultcmakelistsfile)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(GLOB SOURCES "*.cpp")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.67 COMPONENTS filesystem regex)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(createdefaultcmakelistsfile ${SOURCES})
    target_link_libraries(createdefaultcmakelistsfile ${Boost_LIBRARIES})
endif()
