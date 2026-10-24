add_library(template_iso_cpp_core STATIC)

target_sources(
    template_iso_cpp_core
    PRIVATE
        todo.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES todo.hpp
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
        OUTPUT_NAME "template-iso-cpp"
)

target_link_libraries(
    template_iso_cpp
    PRIVATE
        template_iso_cpp_core
)

install(
    TARGETS template_iso_cpp
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)
