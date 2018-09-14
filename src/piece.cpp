#include "piece.h"

Piece::Piece(const ofColor &color, const enum PieceShape shapeType,
             const ofPoint &position) :
    color(color), position(position), shape(getShapeFromType(shapeType)) {
    
    currentRotation = 0;
}

void Piece::drawTile(const ofPoint &position) const {
    ofPushStyle();

    ofSetColor(ofColor::black);

    const float CONTOUR_SIZE = TILE_SIZE / 10;

    ofDrawRectangle(position - CONTOUR_SIZE, TILE_SIZE + CONTOUR_SIZE, TILE_SIZE + CONTOUR_SIZE);

    ofSetColor(color);

    ofDrawRectangle(position, TILE_SIZE, TILE_SIZE);

    ofPopStyle();
}

void Piece::draw() const {
    int row_index = 0;

    for (auto const &row : shape[currentRotation]) {
        int column_index = 0;

        for (auto const &column : row) {
            if (column == true)
                drawTile(ofPoint(position.x + TILE_SIZE * row_index,
                                 position.y + TILE_SIZE * column_index));

            column_index++;
        }

        row_index++;
    }
}
