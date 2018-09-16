#include "piece.h"

Piece::Piece(const ofPoint &position, const enum PieceShape shapeType) :
    position(position), color(getColorFromType(shapeType)), shape(getShapeFromType(shapeType)) {
    
    currentRotation = 0;
}

void Piece::drawTile(const ofPoint &position) const {
    ofPushStyle();

    ofSetColor(color);

    ofDrawRectangle(position, TILE_SIZE - 0.5, TILE_SIZE - 0.5);

    ofPopStyle();
}

void Piece::draw() const {
    int row_index = 0;

    for (auto const &row : shape[currentRotation]) {
        int column_index = 0;

        for (auto const &column : row) {
            if (column == true)
                drawTile(ofPoint(position.x + TILE_SIZE * column_index,
                                 position.y + TILE_SIZE * row_index));

            column_index++;
        }

        row_index++;
    }
}

void Piece::rotate(int direction) {
    if (direction < 0) {
        if (currentRotation == 3)
            currentRotation = 0;
        else 
            currentRotation++;
    } else if (direction > 0) {
        if (currentRotation == 0)
            currentRotation = 3;
        else 
            currentRotation--;
    }
}

void Piece::translate(const ofPoint &amount) {
    position += amount;
}

ofPoint Piece::getPosition() const {
    return position;
}
