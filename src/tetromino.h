#pragma once

#include "ofMain.h"

#include "constants.h"

enum TetrominoShape { OShape, TShape, IShape, JShape, LShape, SShape, ZShape };

ofColor getColorFromType(const enum TetrominoShape shapeType);

std::array<std::array<std::array<bool, 4>, 4>, 4>
    getShapeFromType(const enum TetrominoShape shapeType);

class Tetromino {
    private:
        ofPoint position;

        ofRectangle bounds;

        const ofColor color;

        std::array<std::array<std::array<bool, 4>, 4>, 4> shape;

        void drawTile(const ofPoint &position) const;

        int currentRotation;

    public:
        Tetromino(const ofPoint &position, const enum TetrominoShape shapeType);

        void draw() const;

        void rotate(int direction);

        void translate(const ofPoint &amount);

        ofPoint getPosition() const;
};
