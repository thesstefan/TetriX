#include "board.h"

#include <iostream>

Board::Board(const ofRectangle &bounds) : bounds(bounds) {}

void Board::draw() const {
    ofPushStyle();

    ofNoFill();

    ofSetColor(ofColor::white);

    ofDrawRectangle(bounds);

    for (int rowIndex = 0; rowIndex < bounds.width / TILE_SIZE; rowIndex++)
        for (int columnIndex = 0; columnIndex < bounds.height / TILE_SIZE; columnIndex++) {
            ofDrawRectangle(ofPoint(bounds.x + rowIndex * TILE_SIZE,
                                    bounds.y + columnIndex * TILE_SIZE),
                            TILE_SIZE, TILE_SIZE);
        }

    ofPopStyle();
}

bool Board::collision(const Piece &piece) const {
    std::cout << piece.getPosition().y << " " << bounds.y << std::endl;

    return piece.getPosition().y >= bounds.y + bounds.height;
}
