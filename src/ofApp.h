#pragma once

#include "ofMain.h"

#include "piece.h"

#include "board.h"

class ofApp : public ofBaseApp{
    std::unique_ptr<Piece> piece;

    Board board;

    float deltaTime;

	public:
    ofApp();
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
};
