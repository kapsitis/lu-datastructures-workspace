# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories("../src")

add_executable(runUnitTests
        differentnumbers_test.cpp)
        
target_link_libraries(runUnitTests gtest gtest_main)
target_link_libraries(runUnitTests ${CMAKE_PROJECT_NAME}_lib)

# find_package(GTest REQUIRED)

include(GoogleTest)
gtest_discover_tests(runUnitTests)