#include <cassert>
#include <cstdlib>

#include "cli.hpp"
#include "cli_config.hpp"

#ifdef NDEBUG
#error NDEBUG
#endif

static auto test_no_arguments() noexcept -> void {
    char program_name[] = APP_NAME;
    char *arguments[] = {program_name, nullptr};
    const auto result = app::run(1, arguments, ARGP_SILENT);
    assert(result == 0);
}

[[nodiscard]] auto main() noexcept -> int {
    test_no_arguments();

    return EXIT_SUCCESS;
}
