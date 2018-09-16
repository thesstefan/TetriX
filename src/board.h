#pragma once

#include "ofMain.h"

#include "tetromino.h"

class Board {
    private:
        const ofRectangle bounds;

        std::array<std::array<enum TetrominoType, BOARD_COLUMNS>, BOARD_ROWS> landedBlocks;

    public:
        Board(const ofRectangle &bounds);

        void update();

        void draw() const;

        bool collides(const Tetromino &tetromino) const;
        bool collidesSideways(const Tetromino &tetromino) const;
        bool collidesTop(const Tetromino &tetromino) const;

        void land(const Tetromino &tetromino);
};
