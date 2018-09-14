#include "piece.h"

std::array<std::array<std::array<bool, 4>, 4>, 4>  
    getShapeFromType(const enum PieceShape shapeType) {

    if (shapeType == SquareShape) 
        return std::array<std::array<std::array<bool, 4>, 4>, 4>
               {{{{{0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0}, 
                  {0, 0, 0, 0}}},

                   {{{0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0}, 
                  {0, 0, 0, 0}}},

                 {{{0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0}, 
                  {0, 0, 0, 0}}},

                 {{{0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0}, 
                  {0, 0, 0, 0}}}}};
    else 
        throw "Unknown shape type";
}
