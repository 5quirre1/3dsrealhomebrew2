#include <3ds.h>
#include <citro2d.h>
#include "game.hpp"

int main(int argc, char *argv[])
{
    // init
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();

    // make the top screne thr target
    C3D_RenderTarget *top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

    // make game
    Game game;
    game.init();

    // main loop
    while (aptMainLoop())
    {
        // read all input
        hidScanInput();
        u32 kDown = hidKeysDown();
        if (kDown & KEY_START)
            break;

        // read the circle pad
        circlePosition circle;
        hidCircleRead(&circle);

        // update and draw everything
        game.update(circle);
        game.render(top);
    }

    // cleanup
    C2D_Fini();
    C3D_Fini();
    gfxExit();
    return 0;
}
