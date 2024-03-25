add_library(string_split string_split.cpp)
target_link_libraries(string_split PUBLIC no_strings_attached)

if(BUILD_TESTING)
    add_executable(string_split_test string_split_test.cpp)
    target_link_libraries(string_split_test PRIVATE string_split GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(string_split_test)
endif()