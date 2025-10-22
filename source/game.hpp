#pragma once
#include <3ds.h>
#include <citro2d.h>

// game
class Game
{
public:
    void init();
    void update(circlePosition circle);
    void render(C3D_RenderTarget *top);
private:
    float r, g, b;
    float targetR, targetG, targetB;
};
