#include <cassert>
#include <cstdlib>
#include <cstring>

#include "cli.hpp"
#include "cli_config.hpp"

#ifdef NDEBUG
#error "Unit tests require assertions"
#endif

static auto test_version_metadata() noexcept -> void {
    assert(argp_program_version != nullptr);
    assert(std::strcmp(argp_program_version, APP_NAME " " APP_VERSION) == 0);
}

static auto test_no_arguments() noexcept -> void {
    char program_name[] = APP_NAME;
    char *arguments[] = {program_name, nullptr};
    const auto result = app::run(1, arguments, ARGP_SILENT);
    assert(result == 0);
}

static auto test_option_terminator() noexcept -> void {
    char program_name[] = APP_NAME;
    char operand[] = "--";
    char *arguments[] = {program_name, operand, nullptr};
    const auto result = app::run(2, arguments, ARGP_SILENT);
    assert(result == 0);
}

static auto test_unknown_option() noexcept -> void {
    char program_name[] = APP_NAME;
    char operand[] = "--unknown";
    char *arguments[] = {program_name, operand, nullptr};
    const auto result = app::run(2, arguments, ARGP_SILENT);
    assert(result != 0);
}

static auto test_unexpected_operand() noexcept -> void {
    char program_name[] = APP_NAME;
    char operand[] = "operand";
    char *arguments[] = {program_name, operand, nullptr};
    const auto result = app::run(2, arguments, ARGP_SILENT);
    assert(result != 0);
}

static auto test_empty_operand() noexcept -> void {
    char program_name[] = APP_NAME;
    char operand[] = "";
    char *arguments[] = {program_name, operand, nullptr};
    const auto result = app::run(2, arguments, ARGP_SILENT);
    assert(result != 0);
}

static auto test_operand_after_terminator() noexcept -> void {
    char program_name[] = APP_NAME;
    char terminator[] = "--";
    char operand[] = "operand";
    char *arguments[] = {program_name, terminator, operand, nullptr};
    const auto result = app::run(3, arguments, ARGP_SILENT);
    assert(result != 0);
}

[[nodiscard]] auto main() noexcept -> int {
    test_version_metadata();
    test_no_arguments();
    test_option_terminator();
    test_operand_after_terminator();
    test_unknown_option();
    test_unexpected_operand();
    test_empty_operand();

    return EXIT_SUCCESS;
}
