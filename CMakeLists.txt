project(pyfoo)

cmake_minimum_required(VERSION 3.1)
cmake_policy(VERSION 3.1)

find_package(Shiboken2 2.0.0 REQUIRED)
find_package(PySide2 2.0.0 REQUIRED)
find_package(Qt5 5.6 REQUIRED COMPONENTS Widgets)

add_definitions(${Qt5Widgets_DEFINITIONS})
add_definitions(-DQT_NO_KEYWORDS)

message(STATUS "qt include dir: ${Qt5Widgets_INCLUDE_DIRS}")
message(STATUS "libshiboken include dir: ${SHIBOKEN_INCLUDE_DIR}")
message(STATUS "pyside2 include dir: ${PYSIDE_INCLUDE_DIR}")
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${SHIBOKEN_INCLUDE_DIR})
include_directories(${SHIBOKEN_PYTHON_INCLUDE_DIR})
include_directories(${PYSIDE_INCLUDE_DIR})
include_directories(${PYSIDE_INCLUDE_DIR}/QtWidgets)
include_directories(${PYSIDE_INCLUDE_DIR}/QtGui)
include_directories(${PYSIDE_INCLUDE_DIR}/QtCore)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 
set(LIBRARY_OUTPUT_PATH  "${CMAKE_BINARY_DIR}/out")
set(EXECUTABLE_OUTPUT_PATH  "${CMAKE_BINARY_DIR}/out")

# create the C++ library
set(foo_SRC mainwindow.h mainwindow.cpp)
add_library(foo SHARED ${foo_SRC})
target_link_libraries(foo ${Qt5Widgets_LIBRARIES})

# call shiboken2 to create the wrapping code
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/pyfoo.txt.in" "${CMAKE_CURRENT_BINARY_DIR}/pyfoo.txt" @ONLY)
set(pyfoo_SRC
    ${CMAKE_CURRENT_BINARY_DIR}/wrap/pyfoo/pyfoo_python.h
    ${CMAKE_CURRENT_BINARY_DIR}/wrap/pyfoo/pyfoo_module_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/wrap/pyfoo/mainwindow_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/wrap/pyfoo/mainwindow_wrapper.cpp
    )
add_custom_command( COMMAND ${SHIBOKEN_BINARY} --project-file=${CMAKE_CURRENT_BINARY_DIR}/pyfoo.txt
                    DEPENDS foo ${CMAKE_CURRENT_BINARY_DIR}/pyfoo.txt
                    OUTPUT ${pyfoo_SRC}
                    )

# build the python module
include_directories(${CMAKE_CURRENT_BINARY_DIR}/wrap/pyfoo)
add_library(pyfoo SHARED ${pyfoo_SRC})
target_link_libraries(pyfoo foo ${SHIBOKEN_PYTHON_LIBRARIES} ${SHIBOKEN_LIBRARY} ${PYSIDE_LIBRARY})
if(WIN32)
    set_property(TARGET pyfoo PROPERTY SUFFIX ".pyd")
endif()

# create a minimal example just to test the C++ library (OPTIONAL)
add_executable(main WIN32 main.cpp)
target_link_libraries(main foo)