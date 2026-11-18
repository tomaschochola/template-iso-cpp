configure_file(
    cli_config.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/cli_config.hpp
    @ONLY
)

add_library(template_iso_cpp_core STATIC)

target_link_libraries(template_iso_cpp_core PRIVATE project_compile_options)

target_sources(
    template_iso_cpp_core
    PRIVATE
        cli.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_CURRENT_BINARY_DIR}
        FILES
            cli.hpp
            ${CMAKE_CURRENT_BINARY_DIR}/cli_config.hpp
)

add_executable(template_iso_cpp)

target_sources(
    template_iso_cpp
    PRIVATE
        main.cpp
)

set_target_properties(
    template_iso_cpp
    PROPERTIES
        OUTPUT_NAME "${PROJECT_NAME}"
)

target_link_libraries(
    template_iso_cpp
    PRIVATE
        project_compile_options
        template_iso_cpp_core
)

install(
    TARGETS
        template_iso_cpp
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)
