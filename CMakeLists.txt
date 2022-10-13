cmake_minimum_required(VERSION 3.0.0)

project(seam_track_v2)

SET(ARCH_TYPE "64")
SET(DISTRO_TYPE "buster")
SET(DISTRO_NAME "${DISTRO_TYPE}${ARCH_TYPE}")

# --- target ---
SET(TARGET_NAME "seam_track_v2")
SET(TARGET_NAME_ROOT ${TARGET_NAME_2})
SET(CMAKE_VERBOSE_MAKEFILE 1)
# configure_file ( "${PROJECT_SOURCE_DIR}/ximea-acquire.h.in" "${PROJECT_BINARY_DIR}/ximea-acquire.h" )

# --- build ---
if ( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
    MESSAGE( STATUS "building Debug package -> rename bin" )
    set(TARGET_NAME "${TARGET_NAME}-dbg")
endif( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )

# --- include directories ---
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_BINARY_DIR} )
set(INC_DIR "${CMAKE_SOURCE_DIR}/archives/dependencies/include")
MESSAGE( STATUS "INC_DIR= ${INC_DIR}")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/archives/dependencies/lib")
MESSAGE(STATUS "LIB_DIR = ${LIB_DIR}")

# --- includes AKA headers ---
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${INC_DIR})
include_directories(${INC_DIR}/common)
include_directories(/usr/include /usr/local/include /usr/local/include/google/protobuf /usr/local/include/opencv4)
include_directories(/usr/include/boost)

# --- libs AKA sources (compiled) ---
link_directories(${LIB_DIR})
link_directories(${CMAKE_SOURCE_DIR})
link_directories(${LIB_DIR}/common)
link_directories(/usr/local/include)
link_directories(/usr/lib /usr/lib/x86_64-linux-gnu /usr/local/lib)

# --- Linking ---
set(SOURCES ${LIB_DIR}/egm.pb.cc ${LIB_DIR}/xiApiPlusOcv.cpp common/pthread_creator.cpp common/common.cpp grey_alg.cpp ximea_camera.cpp pid_controller.cpp wobble_controller.cpp egm_sensor.cpp main.cpp udp_server.cpp)
set(HEADERS ${INC_DIR}/egm.pb.h  ${INC_DIR}/xiApiPlusOcv.hpp /usr/local/include/opencv4/opencv2/imgcodecs.hpp /usr/include/boost/filesystem.hpp common/pthread_creator.h common/common.h grey_alg.h ximea_camera.h wobble_controller.h pid_controller.h egm_sensor.h udp_server.h)

# --- Adds Executable ---
# Needs complete path relative to CMAKE_CURRENT_SOURCE_DIR or CMAKE_CURRENT_BINARY_DIR
ADD_EXECUTABLE(${TARGET_NAME} ${SOURCES} ${HEADERS})


    target_link_libraries(${TARGET_NAME} -lprotobuf -lm3api -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lboost_system -lboost_filesystem)
    target_link_libraries(${TARGET_NAME} Qt5::Core)




# --- Compiler Options ---
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-unknown-pragmas -Wno-unused-variable -Wno-uninitialized -D_GNU_SOURCE -D_REENTRANT -fopenmp -gstabs")
SET(CMAKE_EXE_LINKER_FLAGS "-L/usr/lib -lrt -lpthread -lstdc++" )

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
