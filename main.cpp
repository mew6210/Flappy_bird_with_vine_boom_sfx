#include "stuff.h"


int main()
{
    
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "Totally normal flappybird");
    ToggleBorderlessWindowed();

    Player player;
    InitAudioDevice();
    std::vector<Sound> sounds;
    //std::vector<Pipe> pipes;

    loadSoundsFromDirectory(sounds);


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        drawPlayer(player);

        if (IsKeyPressed(KEY_SPACE)) playRandomSound(sounds);


       
        EndDrawing();
    }

    CloseAudioDevice();
    unloadAllSounds(sounds);
    CloseWindow();
}
