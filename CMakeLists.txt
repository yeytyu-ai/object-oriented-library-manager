cmake_minimum_required(VERSION 3.10)

project(ObjectOrientedLibraryManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(library_manager
    main.cpp
    library_manager.cpp
    storage.cpp
    member.cpp
    loan.cpp
)

add_executable(test_library
    test_library.cpp
    library_manager.cpp
    storage.cpp
    member.cpp
    loan.cpp
)
