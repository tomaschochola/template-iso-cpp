#include "cli.hpp"
#include "cli_config.hpp"

#include <cstdio>
#include <cstdlib>

#include <error.h>

namespace {

    auto close_output() noexcept -> void {
        bool failed = std::ferror(stdout) != 0;

        if (std::fclose(stdout) == EOF) {
            failed = true;
        }

        if (failed) {
            (void)std::fputs(APP_NAME ": could not write output\n", stderr);
            (void)std::fflush(stderr);
            std::_Exit(EXIT_FAILURE);
        }
    }

} // namespace

[[nodiscard]] auto main(int argc, char *argv[]) noexcept -> int {
    if (std::atexit(close_output) != 0) {
        ::error(EXIT_FAILURE, 0, "could not register output cleanup");
    }

    if (app::run(argc, argv, 0) != 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
