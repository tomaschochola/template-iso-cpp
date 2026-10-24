cmake_minimum_required(VERSION 4.4)

project(
    template_iso_cpp
    VERSION 0.0.0
    SPDX_LICENSE "CC-BY-ND-4.0"
    DESCRIPTION "ISO C++23 application template with testing and sanitizers."
    HOMEPAGE_URL "https://github.com/tomaschochola/template-iso-cpp"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION OFF)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)
set(CMAKE_VERIFY_PRIVATE_HEADER_SETS ON)
set(CMAKE_VERIFY_INTERFACE_HEADER_SETS ON)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -pedantic-errors
)

add_compile_definitions(_GNU_SOURCE=1)

include(GNUInstallDirs)

include(CheckPIESupported)
check_pie_supported(LANGUAGES CXX)

set(
    MEMORYCHECK_COMMAND_OPTIONS
    "-q --tool=memcheck --leak-check=full --num-callers=50 --error-exitcode=255"
)

include(CTest)

add_subdirectory(src)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

install(
    FILES LICENSE
    DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/doc/template-iso-cpp"
)

set(CPACK_PACKAGE_NAME "template-iso-cpp")
set(CPACK_PACKAGE_VENDOR "Tomáš Chochola")
set(CPACK_GENERATOR "TGZ")
set(CPACK_PACKAGE_CHECKSUM "SHA256")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${PROJECT_VERSION}-${X_CPACK_PACKAGE_VARIANT}")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")
set(CPACK_VERBATIM_VARIABLES TRUE)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CPACK_STRIP_FILES TRUE)
endif()

include(CPack)
