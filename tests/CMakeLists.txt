add_executable(test_stub test_stub.c)
target_link_libraries(test_stub
                      ${PROJECT_NAME}_project_warnings
                      ${PROJECT_NAME}_sanitizers
)
add_test(
    NAME test_stub
    COMMAND test_stub
)

add_executable(test_init test_init.c)
target_link_libraries(test_init
                      memory::mngr
                      ${PROJECT_NAME}_project_warnings
                      ${PROJECT_NAME}_sanitizers
)
add_test(
    NAME test_init
    COMMAND test_init
)

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

