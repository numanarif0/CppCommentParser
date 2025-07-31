cmake_minimum_required(VERSION 3.25)
project(cmtParser CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

configure_file(window.ui ${CMAKE_BINARY_DIR}/window.ui COPYONLY)

add_executable(cmtParser
    main.cpp
    MainWindow.hpp
    MainWindow.cpp
    Parser.cpp
    Parser.hpp
)


target_include_directories(${PROJECT_NAME} PRIVATE ${GTKMM_INCLUDE_DIRS})


target_link_libraries(${PROJECT_NAME} PRIVATE ${GTKMM_LIBRARIES})