find_package(GTest CONFIG REQUIRED)

file(GLOB TARGET_SOURCE_FILES CONFIGURE_DEPENDS *.cc)
target_sources(
        ${TESTS_PROJECT_NAME} PRIVATE
        FILE_SET CXX_MODULES FILES
        ${TARGET_SOURCE_FILES}
)

file(GLOB_RECURSE TARGET_TEST_FILES CONFIGURE_DEPENDS **/*.cpp)
target_sources(
        ${TESTS_PROJECT_NAME} PRIVATE
        ${TARGET_TEST_FILES}
)

target_link_libraries(
        ${TESTS_PROJECT_NAME} PRIVATE
        ${PROJECT_NAME}
        GTest::gtest
        GTest::gtest_main
)
target_compile_options(
        ${TESTS_PROJECT_NAME} PRIVATE
        -fsanitize=address
        -fno-omit-frame-pointer
)
target_link_options(
        ${TESTS_PROJECT_NAME} PRIVATE
        -fsanitize=address
        -rdynamic
)