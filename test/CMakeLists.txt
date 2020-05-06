cmake_minimum_required(VERSION 3.8)

set(This BitStreamTests)

set(Sources
    BitStreamTests.cpp
    FrequencyCounterTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Huffman
)

add_test(
    NAME ${This}
    COMMAND ${This}
)