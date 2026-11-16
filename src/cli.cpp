#include "cli.hpp"
#include "cli_config.hpp"

const char *argp_program_version = APP_NAME " " APP_VERSION;

namespace app {

    auto run(int argument_count, char *arguments[], unsigned flags) noexcept -> error_t {
        return argp_parse(nullptr, argument_count, arguments, flags, nullptr, nullptr);
    }

} // namespace app
