#pragma once

#include "ofMain.h"

#include "tetromino.h"

#include "board.h"

class ofApp : public ofBaseApp{
    private:
        std::unique_ptr<Tetromino> tetromino;

        float deltaTime;

    public:
        ofApp();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
};
