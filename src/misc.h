#pragma once

#include "ofMain.h"

#include "tetromino.h"

void drawBlock(const ofPoint &position, const ofColor &color);

ofColor getColorFromType(const enum TetrominoType type);

std::array<std::array<std::array<bool, 4>, 4>, 4>
    getShapeFromType(const enum TetrominoType type);
