add_executable(test_create_release test_create_release.c)
target_link_libraries(test_create_release
                      memory::mngr
                      ${PROJECT_NAME}_project_warnings
                      ${PROJECT_NAME}_sanitizers
)
add_test(
    NAME test_create_release
    COMMAND test_create_release
)

