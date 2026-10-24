// SPDX-License-Identifier: CC-BY-ND-4.0

/**
 * @file
 * @brief Application entry point.
 *
 * @author Tomáš Chochola <tomaschochola@tomaschochola.cz>
 * @copyright © 2026 Tomáš Chochola <tomaschochola@tomaschochola.cz>
 *
 * @see https://creativecommons.org/licenses/by-nd/4.0/
 * @see https://github.com/tomaschochola
 * @see https://github.com/sponsors/tomaschochola
 */

#include "todo.hpp"

[[nodiscard]] auto main() noexcept -> int
{
    return app::todo();
}
