cmake_minimum_required (VERSION 3.5)

SET( PROJECT_NAME NativeTrainer )
PROJECT( ${PROJECT_NAME} )

# the net configuration file and weight
set (DEEP_DRIVE_NET \"${CMAKE_SOURCE_DIR}/deep_drive_model.prototxt\")
set (DEEP_DRIVE_WEIGHT \"${CMAKE_SOURCE_DIR}/caffe_deep_drive_train_iter_35352.caffemodel\")
set (DEEP_DRIVE_TEST_IMAGE \"${CMAKE_SOURCE_DIR}/0.jpg\")


configure_file (
"${PROJECT_SOURCE_DIR}/NetConfig.h.in"
"${PROJECT_BINARY_DIR}/NetConfig.h"
)

include_directories("${PROJECT_BINARY_DIR}")

SET( DL_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules )

# SET( CMAKE_DEBUG_POSTFIX _d )
INCLUDE( ${DL_MODULE_PATH}/CMake_lib_macros.cmake )

INCLUDE_PACKAGE_CUDA()
INCLUDE_PACKAGE_CVMLAUX()

file(GLOB NativeTrainer_Source
    "${CMAKE_SOURCE_DIR}/samples/Test/*.hpp"
    "${CMAKE_SOURCE_DIR}/samples/Test/*.cpp"
    )

add_executable(${PROJECT_NAME} ${NativeTrainer_Source})
target_link_libraries(${PROJECT_NAME} ${TARGET_LINK_LIBS})
