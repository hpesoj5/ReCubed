#include "SaveManager.hpp"
#include <fstream>

namespace Save
{
    void SaveManager::save(int level)
    {
        int highestLevel { load() };
        if (level <= highestLevel)
            return;

        std::ofstream file { SAVE_PATH };
        if (file.is_open())
            file << level;
    }

    int SaveManager::load()  // highestLevel is the highest level completed
    {
        std::ifstream file { SAVE_PATH };
        int highestLevel {};
        if (file.is_open())
            file >> highestLevel;
        return highestLevel;
    }
}
