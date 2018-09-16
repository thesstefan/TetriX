#pragma once

#include "ofMain.h"

#include "tetromino.h"

#include "board.h"

class ofApp : public ofBaseApp{
    private:
        bool GAME_OVER = false;

        std::unique_ptr<Tetromino> tetromino;

        Board board;

        float deltaTime = 0;

    public:
        ofApp();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
};
