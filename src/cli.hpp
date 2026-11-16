#pragma once

#include <argp.h>

namespace app {

    [[nodiscard]] auto run(int argument_count, char *arguments[], unsigned flags) noexcept -> error_t;

}
