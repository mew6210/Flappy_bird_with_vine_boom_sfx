#pragma once

#include <iostream>
#include "raylib.h"
#include <vector>
#include <filesystem>
#include <random>




class Player {

public:
	int positionX = GetScreenWidth()/2;
	int positionY = GetScreenHeight()/2;
	Color playerColor = Color(RED);




};






void drawPlayer(Player& player);


void loadSoundsFromDirectory(std::vector<Sound>& sounds);

void unloadAllSounds(std::vector<Sound>& sounds);


void playRandomSound(std::vector<Sound>& sounds);