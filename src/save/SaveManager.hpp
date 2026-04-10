#pragma once

#include <string>

namespace Save
{
    class SaveManager
    {
    public:
        static void save(int highestLevel);
        static int load();

    private:
        SaveManager() = delete;
        static inline const std::string SAVE_PATH { "src/save/save.dat" };
    };
}
