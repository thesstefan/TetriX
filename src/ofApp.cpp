#include "ofApp.h"

#include <iostream>

ofApp::ofApp() : board(ofRectangle(ofPoint(ofGetWidth() / 3, 100), TILE_SIZE * 20, TILE_SIZE * 30)) {}
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);

    piece = std::unique_ptr<Piece>
        (new Piece(ofPoint(ofGetWidth() / 3, 100), PieceShape::IShape));
}

//--------------------------------------------------------------
void ofApp::update(){
    float newTime = ofGetElapsedTimef() - deltaTime;

    if (newTime >= 0.5) {
        piece->translate(ofPoint(0, TILE_SIZE));

        deltaTime += newTime;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    piece->draw();

    board.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == OF_KEY_RIGHT)
        piece->translate(ofPoint(TILE_SIZE, 0));
    else if (key == OF_KEY_LEFT)
        piece->translate(ofPoint(-TILE_SIZE, 0));
    else if (key == OF_KEY_UP)
        piece->rotate(1);
}
