#include "game.hpp"
#include <cmath>

void Game::init() { // init game
    r = g = b = 0.5f;
    targetR = targetG = targetB = 0.5f;
}

// upate
void Game::update(circlePosition circle) {
    float nx = circle.dx / 156.0f;
    float ny = circle.dy / 156.0f;

    targetR = (nx + 1.0f) * 0.5f;
    targetG = (ny + 1.0f) * 0.5f;
    targetB = (1.0f - fabs(nx - ny)) * 0.5f + 0.25f;

    float amazing = 0.05f;
    r += (targetR - r) * amazing;
    g += (targetG - g) * amazing;
    b += (targetB - b) * amazing;
}

// render
void Game::render(C3D_RenderTarget* top) {
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_TargetClear(top, C2D_Color32f(r, g, b, 1.0f));
    C2D_SceneBegin(top);
    C3D_FrameEnd(0);
}
