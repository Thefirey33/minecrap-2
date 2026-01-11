#include <iostream>
#include <memory>

#include "tendrillion_game_engine.h"


int main() {
    const auto tendrillion_game_engine = std::make_unique<tendrillion::tendrillion_game_engine>(800, 600, "Minecrap 2");
    tendrillion_game_engine->start_render_loop();
    return 0;
}
