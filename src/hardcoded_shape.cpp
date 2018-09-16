#include "piece.h"

ofColor getColorFromType(const enum PieceShape shapeType) {
    if (shapeType == OShape)
        return ofColor::yellow;
    else if (shapeType == TShape)
        return ofColor::magenta;
    else if (shapeType == IShape)
        return ofColor::cyan;
    else if (shapeType == JShape)
        return ofColor::blue;
    else if (shapeType == LShape)
        return ofColor::orange;
    else if (shapeType == SShape)
        return ofColor::green;
    else if (shapeType == ZShape)
        return ofColor::red;
    else
        throw "Unknown shape type.";
}

std::array<std::array<std::array<bool, 4>, 4>, 4>  
    getShapeFromType(const enum PieceShape shapeType) {

    if (shapeType == OShape) {
        return std::array<std::array<std::array<bool, 4>, 4>, 4>
               {{{{{0, 1, 1, 0},
                   {0, 1, 1, 0},
                   {0, 0, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 1, 1, 0},
                   {0, 1, 1, 0},
                   {0, 0, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 1, 1, 0},
                   {0, 1, 1, 0},
                   {0, 0, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 1, 1, 0},
                   {0, 1, 1, 0},
                   {0, 0, 0, 0}, 
                   {0, 0, 0, 0}}}}};
    } else if (shapeType == TShape) {  
        return std::array<std::array<std::array<bool, 4>, 4>, 4>
               {{{{{0, 1, 0, 0},
                   {1, 1, 1, 0},
                   {0, 0, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 1, 0, 0},
                   {0, 1, 1, 0},
                   {0, 1, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 0, 0, 0},
                   {1, 1, 1, 0},
                   {0, 1, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 1, 0, 0},
                   {1, 1, 0, 0},
                   {0, 1, 0, 0}, 
                   {0, 0, 0, 0}}}}};
    } else if (shapeType == IShape) {  
        return std::array<std::array<std::array<bool, 4>, 4>, 4>
               {{{{{0, 0, 0, 0},
                   {1, 1, 1, 1},
                   {0, 0, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 0, 1, 0},
                   {0, 0, 1, 0},
                   {0, 0, 1, 0}, 
                   {0, 0, 1, 0}}},

                 {{{0, 0, 0, 0},
                   {0, 0, 0, 0},
                   {1, 1, 1, 1}, 
                   {0, 0, 0, 0}}},

                 {{{0, 1, 0, 0},
                   {0, 1, 0, 0},
                   {0, 1, 0, 0}, 
                   {0, 1, 0, 0}}}}};
    } else if (shapeType == JShape) {
        return std::array<std::array<std::array<bool, 4>, 4>, 4>
               {{{{{1, 0, 0, 0},
                   {1, 1, 1, 0},
                   {0, 0, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 1, 1, 0},
                   {0, 1, 0, 0},
                   {0, 1, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 0, 0, 0},
                   {1, 1, 1, 0},
                   {0, 0, 1, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 1, 0, 0},
                   {0, 1, 0, 0},
                   {1, 1, 0, 0}, 
                   {0, 0, 0, 0}}}}};
    } else if (shapeType == LShape) {
        return std::array<std::array<std::array<bool, 4>, 4>, 4>
               {{{{{0, 0, 1, 0},
                   {1, 1, 1, 0},
                   {0, 0, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 1, 0, 0},
                   {0, 1, 0, 0},
                   {0, 1, 1, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 0, 0, 0},
                   {1, 1, 1, 0},
                   {1, 0, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{1, 1, 0, 0},
                   {0, 1, 0, 0},
                   {0, 1, 0, 0}, 
                   {0, 0, 0, 0}}}}};
    } else if (shapeType == SShape) {
        return std::array<std::array<std::array<bool, 4>, 4>, 4>
               {{{{{0, 1, 1, 0},
                   {1, 1, 0, 0},
                   {0, 0, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 1, 0, 0},
                   {0, 1, 1, 0},
                   {0, 0, 1, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 0, 0, 0},
                   {0, 1, 1, 0},
                   {1, 1, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{1, 0, 0, 0},
                   {1, 1, 0, 0},
                   {0, 1, 0, 0}, 
                   {0, 0, 0, 0}}}}};
    } else if (shapeType == ZShape) {
        return std::array<std::array<std::array<bool, 4>, 4>, 4>
               {{{{{1, 1, 0, 0},
                   {0, 1, 1, 0},
                   {0, 0, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 0, 1, 0},
                   {0, 1, 1, 0},
                   {0, 1, 0, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 0, 0, 0},
                   {1, 1, 0, 0},
                   {0, 1, 1, 0}, 
                   {0, 0, 0, 0}}},

                 {{{0, 1, 0, 0},
                   {1, 1, 0, 0},
                   {1, 0, 0, 0}, 
                   {0, 0, 0, 0}}}}};
    } else
        throw "Unknown shape type.";
}
