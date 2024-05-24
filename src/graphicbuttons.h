#pragma once
#include "ofMain.h"

class graphicButtons {
public:
    graphicButtons();

    ofImage dot;
    ofImage dash;
    ofImage reset;

    int style = 0;
    int x;
    int y;
    int rightx;
    int bottomy;

    void start ();
    void draw(int x, int y, int style);
};
