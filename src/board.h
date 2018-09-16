#pragma once

#include "ofMain.h"

#include "tetromino.h"

class Board {
    private:
        const ofRectangle bounds;

        std::array<std::array<int, BOARD_COLUMNS>, BOARD_ROWS> landedBlocks;

    public:
        Board(const ofRectangle &bounds);

        void update();

        void draw() const;

        bool collision(const Tetromino &tetromino) const;
};
