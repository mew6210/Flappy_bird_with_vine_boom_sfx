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
    std::deque<Pipe> pipes;

    loadSoundsFromDirectory(sounds);
    Pipe pipe1;

    pipes.push_back(pipe1);

    SetTargetFPS(60);





    int pipeSpeed = 200;
    bool shouldPlaySound = true;

    while (!WindowShouldClose())
    {
        if (player.shouldGameStillGo) {
            movePipes(pipes, pipeSpeed);

            BeginDrawing();
            ClearBackground(RAYWHITE);


            drawPlayer(player);

            if (IsKeyPressed(KEY_SPACE)) playRandomSound(sounds);
            drawPipes(pipes);
            std::string scoreString = std::to_string(player.score);
            DrawText(scoreString.c_str(), GetScreenWidth() / 2, 200, 70, DARKGRAY);
            EndDrawing();

            handleScoring(player, pipes);

            handlePipes(pipes);

            handlePlayerMovement(player);

            handleCollisions(player, pipes);
        }
        else {
            BeginDrawing();

            if (shouldPlaySound) {
                playRandomSound(sounds);
                shouldPlaySound = false;
            }
            std::string gameOverText = "Game over\nYour score: " + std::to_string(player.score);
            DrawText(gameOverText.c_str(), GetScreenWidth() / 2, GetScreenHeight()/2, 70, DARKGRAY);



            EndDrawing();

        }



    }

    CloseAudioDevice();
    unloadAllSounds(sounds);
    CloseWindow();
}
