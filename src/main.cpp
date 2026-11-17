#include "cli.hpp"
#include "cli_config.hpp"

#include <cstdlib>

[[nodiscard]] auto main(int argc, char *argv[]) noexcept -> int {
    if (app::run(argc, argv, 0) != 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
