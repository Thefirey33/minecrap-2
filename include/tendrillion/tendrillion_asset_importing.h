
#ifndef MINECRAP_2_GAME_MASTER_TENDRILLION_ASSET_IMPORTING_H
#define MINECRAP_2_GAME_MASTER_TENDRILLION_ASSET_IMPORTING_H
#include <map>
#include <string>
#include <vector>

#include "raylib.h"


constexpr auto ASSET_PATH_REFERENCE = "assets";

namespace tendrillion {
    class tendrillion_asset_importing {
        public:
            std::map<std::string, Texture2D, std::less<>> textures;
            std::map<std::string, Sound, std::less<>> sounds;
            tendrillion_asset_importing();
            Texture2D& GetTextureByKey(const std::string &key);
            Sound& GetSoundByKey(const std::string &key);
    };
}

#endif //MINECRAP_2_GAME_MASTER_TENDRILLION_ASSET_IMPORTING_H