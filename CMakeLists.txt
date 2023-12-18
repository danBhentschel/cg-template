cmake_minimum_required(VERSION 3.12)

project(CgFall2023)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.13.10
)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)

# Add the main executable
add_executable(fall_2023 project.cpp)

# Link the required libraries: -lm, -lpthread, -ldl, -lcrypt
target_link_libraries(fall_2023 PRIVATE m pthread dl crypt)

project(tests)

# Add tests target with Catch2-provided main
add_executable(tests
    test_main.cpp

    true_test.cpp
    )
target_link_libraries(tests PRIVATE m pthread dl crypt Catch2::Catch2)

target_compile_definitions(tests PRIVATE UNIT_TEST)

include(CTest)
include(Catch)
catch_discover_tests(tests)

