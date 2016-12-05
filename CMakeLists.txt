cmake_minimum_required (VERSION 3.5)
project (JYNX)

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
# FIND_PACKAGE(Caffe REQUIRED)
# INCLUDE_PACKAGE_CVMLAUX()
add_definitions(-DBOOST_ALL_NO_LIB -DUSE_OPENCV -DUSE_LMDB -DUSE_LEVELDB)

file(GLOB NativeTrainer_Source
    "${CMAKE_SOURCE_DIR}/samples/Test/*.hpp"
    "${CMAKE_SOURCE_DIR}/samples/Test/*.cpp"
    )

set(CAFFE_DIR ${CMAKE_SOURCE_DIR}/../windows-caffe)

file(GLOB CAFFE_DEP
    "${CAFFE_DIR}/build/libraries/lib/*.lib"
    "${CAFFE_DIR}/build/libraries/lib/libopenblas.dll.a"
    "${CAFFE_DIR}/build/install/lib/*.lib"
    "${CAFFE_DIR}/build/libraries/x64/vc12/lib/*.lib"
    "$ENV{CUDA_PATH}/lib/x64/*.lib"
    )

#message("Source ->" ${NativeTrainer_Source})
#message("All the static lib ->" ${CAFFE_DEP})

#message("CUDA PATH ->" $ENV{CUDA_PATH})
#message("CAFFE DEFINITION -> " ${Caffe_DEFINITIONS})
#message("CMake CXX FLAGS ->" ${CMAKE_CXX_FLAGS})

# FIXME: Why cmake can not locate caffe installation
INCLUDE_DIRECTORIES(${CAFFE_DIR}/build/install/include ${CAFFE_DIR}/build/libraries/include  ${CAFFE_DIR}/build/libraries/include/boost-1_61 )
add_executable(NativeTrainer ${NativeTrainer_Source})
#add_library(NativeTrainer SHARED ${NativeTrainer_Source})
# FIXME: /EHSC still not work
SET_TARGET_PROPERTIES(NativeTrainer PROPERTIES COMPILER_FLAGS "/EHsc")
set_target_properties(NativeTrainer PROPERTIES LINKER_LANGUAGE Cxx)
#set_target_properties(NativeTrainer PROPERTIES SUFFIX ".asi")
SET( TARGET_LINK_LIBS ${TARGET_LINK_LIBS} ${CAFFE_DEP})
# SET( TARGET_LINK_LIBS ${TARGET_LINK_LIBS} ${SCRIPT_HOOKV_LIBS})
target_link_libraries(NativeTrainer ${TARGET_LINK_LIBS} kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib)
