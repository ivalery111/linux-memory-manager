add_library(mngr)
add_library(memory::mngr ALIAS mngr)

set(SOURCES mngr/_create_pages.c
            mngr/_release_pages.c
            mngr/release_pages.c
            mngr/create_mngr.c
            mngr/release_mngr.c

            vm_page_family/_instantiate.c
            vm_page_family/instantiate.c
            vm_page_family/print.c
)

target_sources(mngr
    PRIVATE ${SOURCES}
)
target_include_directories(mngr
    PUBLIC ${CMAKE_SOURCE_DIR}/include
    PRIVATE ${CMAKE_SOURCE_DIR}/include/memory_mngr
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/internal
)

target_link_libraries(mngr
    PRIVATE ${PROJECT_NAME}_project_warnings ${PROJECT_NAME}_sanitizers
)

