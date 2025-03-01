﻿#pragma once

#include <iostream>
#include "raylib.h"
#include <vector>
#include <filesystem>
#include <random>
#include <deque>




class Player {

public:
	int positionX = GetScreenWidth()/2;
	int positionY = GetScreenHeight()/2;
	int size=  GetScreenWidth() *0.03;
	Color playerColor = Color(RED);
	int score = 0;
	bool shouldGameStillGo = true;


};

class Pipe {
public:
	
	int width = GetScreenWidth() / 20;
	int whereHole = GetScreenHeight()/2;
	int posX = GetScreenWidth() + width;
	int howBigHole = 400;
	bool addedToScore = false;

	Pipe() {
		
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(howBigHole/2, GetScreenHeight()-howBigHole/2);


		whereHole = dist(gen);
	}


};




void drawPlayer(Player& player);


void loadSoundsFromDirectory(std::vector<Sound>& sounds);

void unloadAllSounds(std::vector<Sound>& sounds);


void playRandomSound(std::vector<Sound>& sounds);

void drawPipes(std::deque<Pipe>& pipes);

void handlePipes(std::deque<Pipe>& pipes);

void movePipes(std::deque<Pipe>& pipes, int pipeSpeed);
void handlePlayerMovement(Player& player);

void handleScoring(Player& player,std::deque<Pipe>& pipes);

void handleCollisions(Player& player, std::deque<Pipe>& pipes);