#include "graphicbuttons.h"

graphicButtons::graphicButtons() {

}

void graphicButtons::start(){
    dot.load("images/dot.png");
    dash.load("images/dash.png");
    reset.load("images/reset.png");
}

void graphicButtons::draw(int x, int y, int style){
    rightx = x+175;
    bottomy = y+175;
    if (style == 1){
        dot.draw(x,y);
    }
    else if (style == 2){
        dash.draw(x,y);
    }
    else if (style == 3){
        reset.draw(x,y);
    }
}
