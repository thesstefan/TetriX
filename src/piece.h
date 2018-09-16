#pragma once

#include "ofMain.h"

const int TILE_SIZE = 20;

enum PieceShape { OShape, TShape, IShape, JShape, LShape, SShape, ZShape };

ofColor getColorFromType(const enum PieceShape shapeType);

std::array<std::array<std::array<bool, 4>, 4>, 4>
    getShapeFromType(const enum PieceShape shapeType);

class Piece {
    private:
        ofPoint position;

        ofRectangle bounds;

        const ofColor color;

        std::array<std::array<std::array<bool, 4>, 4>, 4> shape;

        void drawTile(const ofPoint &position) const;

        int currentRotation;

    public:
        Piece(const ofPoint &position, const enum PieceShape shapeType);

        void draw() const;

        void rotate(int direction);

        void translate(const ofPoint &amount);

        ofPoint getPosition() const;
};
