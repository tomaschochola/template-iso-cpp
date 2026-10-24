// SPDX-License-Identifier: CC-BY-ND-4.0

/**
 * @file
 * @brief Dummy template placeholder; replace or remove in generated projects.
 *
 * @author Tomáš Chochola <tomaschochola@tomaschochola.cz>
 * @copyright © 2026 Tomáš Chochola <tomaschochola@tomaschochola.cz>
 *
 * @see https://creativecommons.org/licenses/by-nd/4.0/
 * @see https://github.com/tomaschochola
 * @see https://github.com/sponsors/tomaschochola
 */

#include <cassert>

#include "todo.hpp"

static auto test_app_todo_returns_zero() noexcept -> void
{
    assert(app::todo() == 0);
}

[[nodiscard]] auto main() noexcept -> int
{
    test_app_todo_returns_zero();

    return 0;
}
