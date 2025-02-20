#include "stuff.h"
#include "raylib.h"

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Totally normal flappybird");


    while (!WindowShouldClose())
    {
       
        
        BeginDrawing();

        ClearBackground(Color(0,0,0));

       
        EndDrawing();
    }


}
