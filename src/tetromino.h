#pragma once

#include "ofMain.h"

#include "constants.h"

enum TetrominoType { NoType, OType, TType, IType, JType, LType, SType, ZType };

class Tetromino {
    private:
        ofPoint position;
        const ofColor color;

        std::array<std::array<std::array<bool, 4>, 4>, 4> shape;

        int currentRotation;

    public:
        Tetromino(const ofPoint &position, const enum TetrominoType type);

        void draw() const;

        void rotate();

        void translate(const ofPoint &amount);

        ofPoint getPosition() const;
};
