cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(DatabaseInventory VERSION 1.0)

add_executable(main main.cpp)

find_package(SQLite3)

add_subdirectory(Database)

target_link_libraries(
    main PUBLIC Database "${SQLite3_LIBRARIES}"
)

target_include_directories(
    main PUBLIC "${SQLite3_INCLUDE_DIRS}" "${PROJECT_SOURCE_DIR}/Database"
)
