cmake_minimum_required(VERSION 3.3)
project(ipd13a CXX)
include(.ipd/cmake/CMakeLists.txt)

# A simple I/O example.
add_cxx_program(io_example
        src/io_example.cxx)

add_cxx_test_program(reference_examples
        test/reference_examples.cxx)

add_cxx_test_program(alloc_examples
        test/allocation_examples.cxx)

add_cxx_test_program(vector_examples
        test/vector_examples.cxx)


# Exercises
add_cxx_test_program(test_ipd13a-3
        exercise/test_ipd13a-3.cxx
        exercise/ipd13a-3.cxx)

add_cxx_test_program(test_ipd13a-4
        exercise/test_ipd13a-4.cxx
        exercise/ipd13a-4.cxx)
