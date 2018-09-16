#include "tetromino.h"

Tetromino::Tetromino(const ofPoint &position, const enum TetrominoShape shapeType) :
    position(position), color(getColorFromType(shapeType)), shape(getShapeFromType(shapeType)) {
    
    currentRotation = 0;
}

void Tetromino::drawTile(const ofPoint &position) const {
    ofPushStyle();

    ofSetColor(color);

    ofDrawRectangle(position, BLOCK_SIZE - 0.5, BLOCK_SIZE - 0.5);

    ofPopStyle();
}

void Tetromino::draw() const {
    int row_index = 0;

    for (auto const &row : shape[currentRotation]) {
        int column_index = 0;

        for (auto const &column : row) {
            if (column == true)
                drawTile(ofPoint(position.x + BLOCK_SIZE * column_index,
                                 position.y + BLOCK_SIZE * row_index));

            column_index++;
        }

        row_index++;
    }
}

void Tetromino::rotate(int direction) {
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

void Tetromino::translate(const ofPoint &amount) {
    position += amount;
}

ofPoint Tetromino::getPosition() const {
    return position;
}
