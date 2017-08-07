# Both FindGTest and ExternalProject were added in CMake 2.8.0.
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(unit-tests CXX)
add_executable(${PROJECT_NAME} test_factorial.cpp)

# Try the FindGTest module first.
find_package(GTest)
if (NOT GTEST_FOUND)
    message(STATUS "Resorting to external GTest project")
    # Include the external Google Test project, and mark as a dependency.
    include(GoogleTestExternal.cmake)
    add_dependencies(${PROJECT_NAME} googletest)
    # Mimic the FindGTest module's library variables.
    ExternalProject_Get_Property(googletest binary_dir)
    set(GTEST_LIBRARY        ${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_STATIC_LIBRARY_SUFFIX})
    set(GTEST_MAIN_LIBRARY   ${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX})
    set(GTEST_BOTH_LIBRARIES ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
endif()

target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} -pthread)
add_test(NAME test_factorial COMMAND ${PROJECT_NAME})
