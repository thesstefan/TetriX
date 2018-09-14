#include "ofMain.h"

enum PieceShape { SquareShape, LShape };

std::array<std::array<std::array<bool, 4>, 4>, 4>
    getShapeFromType(const enum PieceShape shapeType);

class Piece {
    private:
        constexpr static int TILE_SIZE = 20;

        const ofColor color;

        ofPoint position;

        std::array<std::array<std::array<bool, 4>, 4>, 4> shape;

        void drawTile(const ofPoint &position) const;

        int currentRotation;

    public:
        Piece(const ofColor &color, const enum PieceShape shapeType,
              const ofPoint &position);

        void draw() const;
};
