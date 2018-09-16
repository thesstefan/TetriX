#include "ofApp.h"

#include <iostream>

ofApp::ofApp() {}

void ofApp::setup(){
    ofBackground(0, 0, 0);

    tetromino = std::unique_ptr<Tetromino>
        (new Tetromino(ofPoint(ofGetWidth() / 3, 100), TetrominoType::ZType));
}

//--------------------------------------------------------------
void ofApp::update(){
    float newTime = ofGetElapsedTimef() - deltaTime;

    if (newTime >= 0.5) {
        tetromino->translate(ofPoint(0, BLOCK_SIZE));

        deltaTime += newTime;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    tetromino->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == OF_KEY_RIGHT)
        tetromino->translate(ofPoint(BLOCK_SIZE, 0));
    else if (key == OF_KEY_LEFT)
        tetromino->translate(ofPoint(-BLOCK_SIZE, 0));
    else if (key == OF_KEY_UP)
        tetromino->rotate();
}
