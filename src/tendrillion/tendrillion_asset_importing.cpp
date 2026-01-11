#include "tendrillion_asset_importing.h"

#include <cstring>
#include <iostream>

#include "tendrillion_game_engine.h"

tendrillion::tendrillion_asset_importing::tendrillion_asset_importing() {
    const auto file_path_list = LoadDirectoryFiles(ASSET_PATH_REFERENCE);

    for (int i = 0; i < file_path_list.count; i++) {
        const auto filename = file_path_list.paths[i];
        const auto filename_without_ext = std::string(GetFileNameWithoutExt(filename));

        // Asset types and insert them i guess.
        if (const auto file_extension = GetFileExtension(filename); strcmp(file_extension, ".png") == 0) {
            this->textures.try_emplace(filename_without_ext, LoadTexture(filename));
        } else if (strcmp(file_extension, ".wav") == 0) {
            this->sounds.try_emplace(filename_without_ext, LoadSound(filename));
        }
    }
}

Sound& tendrillion::tendrillion_asset_importing::GetSoundByKey(const std::string& key) {
    if (this->sounds.contains(key))
        return this->sounds.find(key)->second;
    throw std::invalid_argument("Key not found");
}

Texture2D& tendrillion::tendrillion_asset_importing::GetTextureByKey(const std::string& key) {
    if (this->textures.contains(key))
        return this->textures.find(key)->second;
    throw std::invalid_argument("Key not found");
}
