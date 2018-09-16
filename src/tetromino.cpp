#include "tetromino.h"

#include "misc.h"

Tetromino::Tetromino(const ofPoint &position, const enum TetrominoType type) :
    position(position), type(type),
    color(getColorFromType(type)), shape(getShapeFromType(type)) {
    
    currentRotation = 0;
}

void Tetromino::draw() const {
    int row_index = 0;

    for (auto const &row : shape[currentRotation]) {
        int column_index = 0;

        for (auto const &column : row) {
            if (column == true)
                drawBlock(ofPoint(position.x + BLOCK_SIZE * column_index,
                                  position.y + BLOCK_SIZE * row_index), color);

            column_index++;
        }

        row_index++;
    }
}

void Tetromino::rotate() {
    if (currentRotation == 3)
        currentRotation = 0;
    else 
        currentRotation++;
}

void Tetromino::translate(const ofPoint &amount) {
    position += amount;
}

ofPoint Tetromino::getPosition() const {
    return position;
}

enum TetrominoType Tetromino::getType() const {
    return type;
}

std::array<std::array<bool, 4>, 4> Tetromino::getCurrentShape() const {
    return shape[currentRotation];
}
