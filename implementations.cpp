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






void drawPipe(Pipe& pipe) {


    DrawRectangle(pipe.posX, 0, pipe.width, pipe.whereHole, GREEN);

    DrawRectangle(pipe.posX, pipe.whereHole+pipe.howBigHole, pipe.width, GetScreenHeight(), GREEN);

}


void drawPipes(std::deque<Pipe>& pipes) {

    for (Pipe& pipe : pipes) {
        drawPipe(pipe);
    }


}



bool shouldAddPipe(std::deque<Pipe>& pipes) {

    int screenWidth = GetScreenWidth();

    if (pipes[0].posX < screenWidth-screenWidth*0.3) {
        return true;
    }
    else return false;

    



}
void addPipe(std::deque<Pipe>& pipes) {

    pipes.push_front(Pipe());

}



bool shouldDeletePipe(std::deque<Pipe>& pipes) {
    int length = pipes.size() - 1;
    if (pipes[length].posX < 0 - pipes[length].width) return true;
    else return false;


}



void deletePipe(std::deque<Pipe>& pipes) {

    pipes.pop_back();


}


void handlePipes(std::deque<Pipe>& pipes) {

    
    if (shouldAddPipe(pipes)) {
        addPipe(pipes);
    }




    if (shouldDeletePipe(pipes)) {
        deletePipe(pipes);
    }
    
    
}



void movePipes(std::deque<Pipe>& pipes,int pipeSpeed) {
    float deltaTime = GetFrameTime();
    for (Pipe& pipe : pipes) {
        pipe.posX -= pipeSpeed * deltaTime;

    }


}

void handlePlayerMovement(Player& player) {

    float deltaTime = GetFrameTime(); 
    static float velocityY = 0.0f;
    static float gravity = 800.0f;     // Gravity force
    static float jumpForce = -350.0f;  // Upward force when jumping




    velocityY += gravity * deltaTime;



    player.positionY += velocityY * deltaTime;

    if (IsKeyPressed(KEY_W)) {
        velocityY = jumpForce;
    }

}