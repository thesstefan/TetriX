#include <cstdlib>

#include "ofApp.h"

ofApp::ofApp() : board(ofRectangle(ofPoint(ofGetWidth() / 3, 100),
                                   BOARD_COLUMNS * BLOCK_SIZE,
                                   BOARD_ROWS * BLOCK_SIZE)) {}

void ofApp::setup(){
    ofBackground(0, 0, 0);

    srand(time(NULL)); 

    const enum TetrominoType randomType = 
        static_cast<TetrominoType>(rand() % TYPES_NUMBER + 1);

    const ofPoint startingPosition = ofPoint(ofGetWidth() / 3 + 4 * BLOCK_SIZE, 100);

    tetromino = std::unique_ptr<Tetromino>(new Tetromino(startingPosition, randomType));
}

void ofApp::update(){
    if (GAME_OVER == false) {
        float newTime = ofGetElapsedTimef() - deltaTime;

        if (newTime >= 0.5) {
            tetromino->translate(ofPoint(0, BLOCK_SIZE));

            if (board.collides(*tetromino)) {
                tetromino->translate(ofPoint(0, -BLOCK_SIZE));

                board.land(*tetromino);

                const enum TetrominoType randomType = 
                    static_cast<TetrominoType>(rand() % TYPES_NUMBER + 1);

                const ofPoint startingPosition = ofPoint(ofGetWidth() / 3 + 4 * BLOCK_SIZE, 100);

                tetromino.reset(new Tetromino(startingPosition, randomType));
            }

            deltaTime += newTime;
        }

        if (board.collidesTop(*tetromino))
            GAME_OVER = true;
    }
}

void ofApp::draw(){
    if (GAME_OVER == false) {
        tetromino->draw();

        board.draw();
    }
}

void ofApp::keyPressed(int key) {
    if (GAME_OVER == false) {
        if (key == OF_KEY_RIGHT) {
            tetromino->translate(ofPoint(BLOCK_SIZE, 0));
        
            if (board.collidesSideways(*tetromino) || board.collides(*tetromino))
                tetromino->translate(ofPoint(-BLOCK_SIZE, 0));
        } else if (key == OF_KEY_LEFT) {
            tetromino->translate(ofPoint(-BLOCK_SIZE, 0));

            if (board.collidesSideways(*tetromino) || board.collides(*tetromino))
                tetromino->translate(ofPoint(BLOCK_SIZE, 0));
        } else if (key == OF_KEY_UP) {
            tetromino->rotate();

            if (board.collides(*tetromino) || board.collidesSideways(*tetromino))
                for (int rotationIndex = 0; rotationIndex < POSSIBLE_ROTATIONS - 1; rotationIndex++)
                    tetromino->rotate();
        } else if (key == OF_KEY_DOWN) {
            tetromino->translate(ofPoint(0, BLOCK_SIZE));

            if (board.collides(*tetromino))
                tetromino->translate(ofPoint(0, -BLOCK_SIZE));
        }
    }
}
