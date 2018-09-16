#include "misc.h"

void drawBlock(const ofPoint &position, const ofColor &color) {
    ofPushStyle();

    ofSetColor(color);

    ofDrawRectangle(position, BLOCK_SIZE - 0.5, BLOCK_SIZE - 0.5);

    ofPopStyle();
}

ofColor getColorFromType(const enum TetrominoType type) {
    if (type == OType)
        return ofColor::yellow;
    else if (type == TType)
        return ofColor::magenta;
    else if (type == IType)
        return ofColor::cyan;
    else if (type == JType)
        return ofColor::blue;
    else if (type == LType)
        return ofColor::orange;
    else if (type == SType)
        return ofColor::green;
    else if (type == ZType)
        return ofColor::red;
    else
        throw "Unknown shape type.";
}

std::array<std::array<std::array<bool, 4>, 4>, 4>  
    getTypeFromType(const enum TetrominoType type) {

    if (type == OType) {
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
    } else if (type == TType) {  
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
    } else if (type == IType) {  
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
    } else if (type == JType) {
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
    } else if (type == LType) {
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
    } else if (type == SType) {
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
    } else if (type == ZType) {
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
