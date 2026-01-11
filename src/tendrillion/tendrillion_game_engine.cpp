#include "tendrillion_game_engine.h"

#include <memory>
#include <ranges>

#include "raylib.h"

tendrillion::tendrillion_game_engine::tendrillion_game_engine(const int window_width, const int window_height, const char* title) {
    // Initialization
    this->window_width = window_width;
    this->window_height = window_height;
    this->title = title;
    InitWindow(this->window_width, this->window_height, title);
    this->asset_importing = std::make_unique<tendrillion_asset_importing>();
}


void tendrillion::tendrillion_game_engine::unload_game_engine() const {
    // Unload all assets...
    for (const auto &sound: this->asset_importing->sounds | std::views::values)
        UnloadSound(sound);
    for (const auto &texture: this->asset_importing->textures | std::views::values)
        UnloadTexture(texture);
}

void tendrillion::tendrillion_game_engine::start_render_loop() const {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        EndDrawing();
    }
    this->unload_game_engine();
    CloseWindow();
}
