#include "TXLib.h"

//-----------------------------------------------------------------------------

const COLORREF WINDOW_COLOR  = RGB (255, 250, 153);
const COLORREF BEAR_COLOR    = RGB (157, 79, 0);
const COLORREF TREE_COLOR    = RGB (111, 69, 28);
const COLORREF FOLIAGE_COLOR = RGB (43, 247, 88);
const COLORREF APPLE_COLOR   = RGB (240, 49, 97);
const COLORREF BIRD_COLOR    = RGB (102, 148, 162);

//=============================================================================

void DrawHouse (int x, int y, double sizeX, double sizeY, double roof = 1, COLORREF windowColor = WINDOW_COLOR, COLORREF roofColor = RGB (243, 31, 73), COLORREF treeColor = TREE_COLOR);                                                      //  прототип функции DrawHouse
void DrawBear (int x, int y, double sizeX, double sizeY, double step, COLORREF bearColor = BEAR_COLOR);
void DrawMan (int x, int y, double sizeX, double sizeY, double hand = 0, double leg = 0, double step = 0, COLORREF appleColor = APPLE_COLOR, COLORREF manColor = RGB (121, 48, 194));
void DrawTree (int x, int y, double sizeX, double sizeY, COLORREF AppleColor = APPLE_COLOR, COLORREF FoliageColor = FOLIAGE_COLOR, COLORREF TreeColor = TREE_COLOR);
void DrawSun (int x, int y, double sizeX, double sizeY, COLORREF sunColo = RGB (255, 255, 0));
void DrawBird ();
void DrawBackground ();

//-----------------------------------------------------------------------------

int main ()
    {

    txCreateWindow (1000, 600);

    DrawBackground();

    DrawHouse (340, 470, 0.5, 0.2, 1, TX_LIGHTGRAY, TX_BLACK);

    DrawHouse (510, 470, 0.3, 0.3, 0.9, WINDOW_COLOR, RGB (189, 79, 221));

    DrawHouse (430, 470, 0.2, 0.3, 1.1, RGB (131, 224, 252), RGB (255, 128, 192));
                                                                    // вызов функции  DrawHouse
    DrawHouse (160, 490, 0.8, 0.8);

    DrawBear (533, 502, 0.8, 0.8, 5);

    DrawBear (450, 550, 0.5, 0.5, 1, RGB (208, 113, 55));

    DrawMan (700, 508, 0.8, 0.8, 3, 2, 2.5, APPLE_COLOR);

    DrawTree (857, 441, 0.7, 0.7);

    DrawTree (920, 490, 0.4, 0.4, RGB (152, 1, 35), RGB (21, 193, 21), RGB (100, 54, 13));

    DrawTree (885, 525, 0.2, 0.2, RGB (254, 226, 95), RGB (0, 128, 64), RGB (126, 41, 1));

    DrawSun(535, 115, 1, 1);

    DrawBird();

    txTextCursor (false);
    return 0;
    }

//-----------------------------------------------------------------------------

void DrawHouse (int x, int y,
                double sizeX, double sizeY, double roof,
                COLORREF windowColor, COLORREF roofColor, COLORREF treeColor)                                              // определение функции DrawHouse
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (RGB (204, 129, 53));
    txRectangle (x-157*sizeX, y-130*sizeY, x+158*sizeX, y+120*sizeY);                               // 242; 455
    txSetFillColor (roofColor);
    POINT triangle[3] = {{x+2*sizeX, y-324*roof*sizeY}, {x-221*sizeX, y-120*sizeY}, {x+234*sizeX, y-120*sizeY}};
    txPolygon (triangle, 3);
    txSetFillColor (windowColor);
    txRectangle (x-135*sizeX, y-103*sizeY, x- 27*sizeX, y-33*sizeY);
    txRectangle (x+ 25*sizeX, y-103*sizeY, x+133*sizeX, y-33*sizeY);
    txSetFillColor (treeColor);
    txRectangle (x-120*sizeX, y-1*sizeY, x-41*sizeX, y+120*sizeY);
    txLine (x- 81*sizeX, y-103*sizeY, x- 81*sizeX, y-34*sizeY);
    txLine (x-135*sizeX, y- 68*sizeY, x- 27*sizeX, y-68*sizeY);
    txLine (x+ 25*sizeX, y- 68*sizeY, x+133*sizeX, y-68*sizeY);
    txLine (x+ 79*sizeX, y-103*sizeY, x+ 79*sizeX, y-34*sizeY);
    }

void DrawBear (int x, int y,
              double sizeX, double sizeY,
              double step,
              COLORREF bearColor)
    {
    txSetColor (TX_BLACK, 3);
    txSetFillColor (bearColor);
    txEllipse (x- 75*sizeX, y-49*sizeY, x+ 75*sizeX, y+48*sizeY);                                       // 533; 502
    txEllipse (x+ 43*sizeX, y-81*sizeY, x+129*sizeX, y-20*sizeY);
    txEllipse (x+ 42*sizeX, y-90*sizeY, x+ 64*sizeX, y-72*sizeY);
    txEllipse (x+114*sizeX, y-93*sizeY, x+135*sizeX, y-68*sizeY);
    txEllipse (x- 91*sizeX, y-29*sizeY, x- 72*sizeX, y-(11-step)*sizeY);
    txEllipse (x+ 50*sizeX, y+30*sizeY, x+ 67*sizeX, y+(64-step)*sizeY);
    txEllipse (x+ 30*sizeX, y+38*sizeY, x+ 48*sizeX, y+(72+step)*sizeY);
    txEllipse (x- 59*sizeX, y+36*sizeY, x- 41*sizeX, y+(73-step)*sizeY);
    txEllipse (x- 40*sizeX, y+43*sizeY, x- 20*sizeX, y+78*sizeY);
    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_BLACK);
    txEllipse (x+67*sizeX, y-66*sizeY, x+ 80*sizeX, y-52*sizeY);
    txEllipse (x+94*sizeX, y-66*sizeY, x+107*sizeX, y-52*sizeY);
    txEllipse (x+82*sizeX, y-48*sizeY, x+ 90*sizeX, y-40*sizeY);
    txLine (x+86*sizeX, y-28*sizeY, x+78*sizeX, y-33*sizeY);
    txLine (x+86*sizeX, y-28*sizeY, x+94*sizeX, y-33*sizeY);
    }

void DrawMan (int x, int y,
              double sizeX, double sizeY,
              double hand, double leg, double step,
              COLORREF appleColor, COLORREF manColor)
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (manColor);
    txEllipse (x-17*sizeX, y-33*sizeY, x+16*sizeX, y+33*sizeY);                           // 754; 508
    txLine (x-50*sizeX, y-(28+hand)*sizeY ,x-16*sizeX, y-15*sizeY);
    txLine (x+15*sizeX, y-15*sizeY, x+36*sizeX, y+17*sizeY);
    txLine (x- 7*sizeX, y+30*sizeY, x-(10+leg)*sizeX, y+(63-step)*sizeY);
    txLine (x+ 8*sizeX, y+30*sizeY, x+(14+leg)*sizeX, y+(63+step)*sizeY);
    txSetFillColor (RGB (236, 223, 179));
    txEllipse (x-17*sizeX, y-63*sizeY, x+18*sizeX, y-33*sizeY);
    txSetFillColor (TX_BLACK);
    txEllipse (x-10*sizeX, y-55*sizeY, x- 1*sizeX, y-47*sizeY);
    txEllipse (x+ 1*sizeX, y-55*sizeY, x+10*sizeX, y-47*sizeY);
    txSetColor (appleColor);
    txSetFillColor (appleColor);
    txCircle (x-53*sizeX, y-(33+hand)*sizeY, 10);
    }

void DrawTree (int x, int y,
              double sizeX, double sizeY,
              COLORREF AppleColor, COLORREF FoliageColor, COLORREF TreeColor)
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (TreeColor);
    txRectangle (x-14*sizeX, y-133*sizeY, x+14*sizeX, y+133*sizeY);                              // 857; 441
    POINT brunch[8] = {{x-14*sizeX, y-46*sizeY}, {x-42*sizeX, y-62*sizeY}, {x-84*sizeX, y-62*sizeY}, {x-86*sizeX, y-66*sizeY}, {x-46*sizeX, y-66*sizeY}, {x-57*sizeX, y-74*sizeY}, {x-55*sizeX, y-77*sizeY}, {x-14*sizeX, y-51*sizeY}};
    txPolygon (brunch, 8);
    txSetColor (FoliageColor);
    txSetFillColor (FoliageColor);
    txEllipse (x- 91*sizeX, y-271*sizeY, x+ 59*sizeX, y-112*sizeY);
    txEllipse (x-  7*sizeX, y-316*sizeY, x+126*sizeX, y-161*sizeY);
    txEllipse (x-117*sizeX, y-342*sizeY, x+ 23*sizeX, y-198*sizeY);
    txEllipse (x- 35*sizeX, y-383*sizeY, x+ 76*sizeX, y-261*sizeY);
    txSetColor (AppleColor);
    txSetFillColor (AppleColor);
    txEllipse (x-65*sizeX, y-288*sizeY, x-45*sizeX, y-267*sizeY);
    txEllipse (x+19*sizeX, y-248*sizeY, x+41*sizeX, y-226*sizeY);
    txEllipse (x-43*sizeX, y-205*sizeY, x-21*sizeX, y-182*sizeY);
    }

void DrawSun (int x, int y,
              double sizeX, double sizeY,
              COLORREF sunColor)
    {
    txSetColor (TX_BLACK);
    txSetFillColor (RGB (255, 255, 0));
    txEllipse (x-60*sizeX, y-60*sizeY, x+60*sizeX, y+60*sizeY);                                           // 535; 115
    txSetColor (sunColor, 5);
    txLine (x+  6*sizeX, y+74*sizeY, x+  6*sizeX, y+130*sizeY);
    txLine (x+ 72*sizeX, y- 1*sizeY, x+146*sizeX, y-  1*sizeY);
    txLine (x-138*sizeX, y- 3*sizeY, x- 71*sizeX, y-  3*sizeY);
    txLine (x-  2*sizeX, y-65*sizeY, x+  2*sizeX, y-115*sizeY);
    txLine (x+ 52*sizeX, y-48*sizeY, x+ 93*sizeX, y- 98*sizeY);
    txLine (x+ 51*sizeX, y+52*sizeY, x+101*sizeX, y+ 99*sizeY);
    txLine (x- 51*sizeX, y+49*sizeY, x-100*sizeX, y+ 88*sizeY);
    txLine (x-106*sizeX, y-98*sizeY, x- 50*sizeX, y- 50*sizeY);
    }

void DrawBird ()
    {
       txSetColor (TX_BLACK);
    txSetFillColor (BIRD_COLOR);
    txEllipse (782-9, 366-5, 782+9, 366+5);                                  // 782; 366
    txEllipse (782-16, 366-12, 782-5, 366-2);
    txSetFillColor (RGB (255, 255, 255));
    txEllipse (782-14, 366-9, 782-11, 366-6);
    txLine (782-1, 366+4, 782-1, 375);
    txLine (784, 370, 784, 366+9);
    txLine (782, 366-2, 782, 366+3);
    txLine (782-6, 366, 782, 366+3);
    txLine (782+9, 366, 782+16, 366-7);
    txLine (782+9, 366, 782+16, 366+7);
    txLine (782+9, 366, 782+19, 366-3);
    txLine (782+9, 366, 782+19, 366+5);
    txSetColor (RGB (255, 255, 0));
    txLine (782-17, 366-8, 782-18, 366-5);
    txLine (782-19, 366-5, 782-15, 366-5);
    }

void DrawBackground ()
    {
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txRectangle (0, 0, 1000, 600);

    txSetColor (RGB (80, 186, 88));
    txSetFillColor (RGB (80, 186, 88));
    txRectangle (1, 492, 1000, 600);

    txSetColor (RGB (97, 221, 243));
    txSetFillColor (RGB (97, 221, 243));
    txRectangle (0, 0, 1000, 492);
    }
