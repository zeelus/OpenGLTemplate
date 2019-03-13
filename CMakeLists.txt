cmake_minimum_required(VERSION 3.12)
project(OpenGLTemplate)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CONFIGURATION_TYPE "Debug")

find_package(glbinding REQUIRED)
include_directories(${glbinding_INCLUDE_DIRS})
set(${PROJECT_NAME}_LIBS ${${PROJECT_NAME}_LIBS} ${glbinding_LIBRARIES})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(KEEP_RPATHS)

if (APPLE)
    set(CMAKE_INSTALL_RPATH "@executable_path/../lib")
else()
    set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
endif()

include_directories(
        "${PROJECT_SOURCE_DIR}/Libs/glm/include"
        "${PROJECT_SOURCE_DIR}/Libs/gli/include")

add_executable(OpenGLTemplate main.cpp source/Rendering.cpp source/Rendering.h)

target_link_libraries(OpenGLTemplate ${${PROJECT_NAME}_LIBS} ${${PROJECT_NAME}_LIBS_DEBUG} ${LINKER_FLAGS} ${CONAN_LIBS})
