#pragma once

#include "ofMain.h"

#include "piece.h"

class Board {
    private:
        const ofRectangle bounds;

    public:
        constexpr static int SIZE = 20;

        Board(const ofRectangle &bounds);

        void update();

        void draw() const;

        bool collision(const Piece &piece) const;
};
