#include "stuff.h"




void drawPlayer(Player& player) {

	DrawRectangle(player.positionX, player.positionY, 50, 50, player.playerColor);

}




void loadSoundsFromDirectory(std::vector<Sound>& sounds) {

    namespace fs = std::filesystem;
    std::vector<std::string> filenames;
    std::string directoryName = "\\audio\\"; // Your target directory
    std::string pathToAudio = fs::current_path().string() + directoryName;
   



        for (const auto& entry : fs::directory_iterator(pathToAudio)) {
            if (entry.is_regular_file()) { 
                std::cout<<entry.path().filename().string();
                std::string wholePath = pathToAudio + entry.path().filename().string();
                sounds.push_back(LoadSound(wholePath.c_str()));
            }
        }

      
}


void unloadAllSounds(std::vector<Sound>& sounds) {

    for (const Sound& sound : sounds) {
        UnloadSound(sound);
    }
}



void playRandomSound(std::vector<Sound>& sounds) {

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, sounds.size() - 1);


    PlaySound(sounds[dist(gen)]);
}