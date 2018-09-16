#include "board.h"

#include "misc.h"

#include <iostream>

Board::Board(const ofRectangle &bounds) : bounds(bounds) {
    for (auto &row : landedBlocks) 
        row.fill(TetrominoType::NoType);
}

void Board::draw() const {
    ofPushStyle();

    ofNoFill();

    ofSetColor(ofColor::white);

    ofDrawRectangle(bounds);

    ofPopStyle();

    int rowIndex = 0;
    for (auto const &row : landedBlocks) {
        int columnIndex = 0;

        for (auto const &column : row) {
            if (column != TetrominoType::NoType) {
                drawBlock(ofPoint(bounds.x + columnIndex * BLOCK_SIZE,
                                  bounds.y + rowIndex * BLOCK_SIZE), 
                          getColorFromType(column));
            }

            columnIndex++;
        }

        rowIndex++;
    }

}

bool Board::collides(const Tetromino &tetromino) const {
    const std::array<std::array<bool, 4>, 4> tetrominoShape = tetromino.getCurrentShape();

    int rowIndex = 0;
    for (auto const &row : tetrominoShape) {
        int columnIndex = 0;

        for (auto const &column : row) {
            if (column == true) {
                ofPoint relativePosition = tetromino.getPosition() - bounds.position;

                if (relativePosition.y / BLOCK_SIZE + rowIndex >= BOARD_ROWS)
                    return true;

                if (landedBlocks[relativePosition.y / BLOCK_SIZE + rowIndex]
                                [relativePosition.x / BLOCK_SIZE + columnIndex] 
                                != TetrominoType::NoType)
                    return true;
            }

            columnIndex++;
        }

        rowIndex++;
    }

    return false;
}

bool Board::collidesSideways(const Tetromino &tetromino) const {
    const std::array<std::array<bool, 4>, 4> tetrominoShape = tetromino.getCurrentShape();

    int rowIndex = 0;
    for (auto const &row : tetrominoShape) {
        int columnIndex = 0;

        for (auto const &column : row) {
            if (column == true) {
                ofPoint relativePosition = tetromino.getPosition() - bounds.position;

                if (relativePosition.x / BLOCK_SIZE + columnIndex >= BOARD_COLUMNS ||
                    relativePosition.x / BLOCK_SIZE + columnIndex < 0) {

                        return true;
                }
            }

            columnIndex++;
        }

        rowIndex++;
    }

    return false;
}

bool Board::collidesTop(const Tetromino &tetromino) const {
    const std::array<std::array<bool, 4>, 4> tetrominoShape = tetromino.getCurrentShape();

    int rowIndex = 0;
    for (auto const &row : tetrominoShape) {
        int columnIndex = 0;

        for (auto const &column : row) {
            if (column == true) {
                ofPoint relativePosition = tetromino.getPosition() - bounds.position;
                
                if (relativePosition.y / BLOCK_SIZE <= 0 && collides(tetromino))
                    return true;
            }

            columnIndex++;
        }

        rowIndex++;
    }

    return false;
}

void Board::land(const Tetromino &tetromino) {
    const std::array<std::array<bool, 4>, 4> tetrominoShape = tetromino.getCurrentShape();

    int rowIndex = 0;
    for (auto const &row : tetrominoShape) {
        int columnIndex = 0;

        for (auto const &column : row) {
            if (column == true) {
                ofPoint relativePosition = tetromino.getPosition() - bounds.position;

                if (landedBlocks[relativePosition.y / BLOCK_SIZE + rowIndex]
                                [relativePosition.x / BLOCK_SIZE + columnIndex] 
                                == TetrominoType::NoType) {

                    landedBlocks[relativePosition.y / BLOCK_SIZE + rowIndex]
                                [relativePosition.x / BLOCK_SIZE + columnIndex] 
                                = tetromino.getType();
                }
            }

            columnIndex++;
        }

        rowIndex++;
    }
}
