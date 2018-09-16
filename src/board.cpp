#include "board.h"

Board::Board(const ofRectangle &bounds) : bounds(bounds) {}

void Board::draw() const {
    ofPushStyle();

    ofNoFill();

    ofSetColor(ofColor::white);

    ofDrawRectangle(bounds);

    for (int rowIndex = 0; rowIndex < bounds.width / BLOCK_SIZE; rowIndex++)
        for (int columnIndex = 0; columnIndex < bounds.height / BLOCK_SIZE; columnIndex++) {
            ofDrawRectangle(ofPoint(bounds.x + rowIndex * BLOCK_SIZE,
                                    bounds.y + columnIndex * BLOCK_SIZE),
                            BLOCK_SIZE, BLOCK_SIZE);
        }

    ofPopStyle();
}

bool Board::collision(const Tetromino &tetromino) const {
    return tetromino.getPosition().y >= bounds.y + bounds.height;
}
