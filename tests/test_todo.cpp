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
