#ifndef MINECRAP_2_GAME_MASTER_TENDRILLION_GAME_ENGINE_H
#define MINECRAP_2_GAME_MASTER_TENDRILLION_GAME_ENGINE_H

#include <memory>

#include "tendrillion_asset_importing.h"


namespace tendrillion {
    class tendrillion_game_engine {
        public:
            int window_width;
            int window_height;
            const char* title;
            std::unique_ptr<tendrillion_asset_importing> asset_importing;
            tendrillion_game_engine(int window_width, int window_height, const char* title);
            void unload_game_engine() const;
            void start_render_loop() const;
    };
}
#endif //MINECRAP_2_GAME_MASTER_TENDRILLION_GAME_ENGINE_H