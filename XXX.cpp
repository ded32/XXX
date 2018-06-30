#include "TXLib.h"

//-----------------------------------------------------------------------------

const COLORREF WINDOW_COLOR  = RGB (255, 250, 153);
const COLORREF BEAR_COLOR    = RGB (157, 79, 0);
const COLORREF TREE_COLOR    = RGB (111, 69, 28);
const COLORREF FOLIAGE_COLOR = RGB (43, 247, 88);
const COLORREF APPLE_COLOR   = RGB (240, 49, 97);
const COLORREF BIRD_COLOR    = RGB (102, 148, 162);

//=============================================================================

void DrawHouse (int x, int y,
                double sizeX, double sizeY, double roof = 1,
                COLORREF windowColor = WINDOW_COLOR, COLORREF roofColor = RGB (243, 31, 73), COLORREF treeColor = TREE_COLOR);                                                      //  �������� ������� DrawHouse
void DrawBear  (int x, int y,
                double sizeX, double sizeY,
                double step, double smile, double winkL, double winkR,
                COLORREF bearColor = BEAR_COLOR);
void DrawMan   (int x, int y,
                double sizeX, double sizeY,
                double handL, double handR, double leg, double step,
                double wind, double hair, double winkL, double winkR, double smile,
                COLORREF appleColor = APPLE_COLOR, COLORREF manColor = RGB (121, 48, 194));
void DrawTree  (int x, int y,
                double sizeX, double sizeY, double brunch,
                COLORREF AppleColor = APPLE_COLOR, COLORREF FoliageColor = FOLIAGE_COLOR, COLORREF TreeColor = TREE_COLOR);
void DrawSun   (int x, int y,
                double sizeX, double sizeY,
                double smile, double winkL, double winkR,
                COLORREF sunColor = RGB (255, 255, 0), COLORREF eyeColor = TX_BLACK, COLORREF mouthColor = RGB (237, 28, 36));
void DrawBird  (int x, int y,
                double sizeX, double sizeY,
                double leg, double step, double wing,
                double tail, double wind,
                COLORREF birdColor = BIRD_COLOR);

void FinishTitles (int x, int y);

void DrawBackground ();
void MoveMen ();
void MoveBearsPhysics ();
void MoveSun ();
void MoveBird ();
void MoveFtitles ();

//-----------------------------------------------------------------------------

int main ()
    {
    txCreateWindow (1000, 600);

    txBegin ();

    DrawBackground();

    //MoveBird ();

    MoveMen ();

    MoveBearsPhysics ();

    //MoveFtitles ();

    txEnd ();

    txTextCursor (false);
    return 0;
    }

//-----------------------------------------------------------------------------

void MoveBearsPhysics ()
    {
    int t = 0;
    while (t < 150)
        {
        DrawBackground ();

        DrawSun (t*-1 + 850, t*0.33, 1, 1, -2, 10, 0);

        DrawMan (t*3.67 + 580,          490, 0.25,  0.3, 50, 50, -5, 4, -10, 10, 0, 0, 0, RGB (254, 226, 95), RGB  (0, 255, 255));
        DrawMan (t*3.33 + 540,          490,  0.5,  0.2, 50, 50, -5, 4, -10, 10, 0, 0, 0, RGB (254, 226, 95), RGB (101, 236, 55));
        DrawMan (t*4    + 560, t*0.13 + 490,  0.4, 0.25, 50, 50, -5, 4, -10, 10, 0, 0, 0, RGB (254, 226, 95), RGB (255, 255, 87));

        DrawTree (857, 441, 0.7, 0.7, 55);
        DrawTree (920, 470, 0.4, 0.4, 60, RGB (152, 1, 35), RGB (21, 193, 21), RGB (100, 54, 13));
        DrawTree (885, 525, 0.2, 0.2, -20, RGB (254, 226, 95), RGB (0, 128, 64), RGB (126, 41, 1));
        DrawHouse (510, 470, 0.3, 0.3, 0.9, WINDOW_COLOR, RGB (189, 79, 221));

        DrawBear (t*-3.33 + 1100, t*-0.67 + 572, -0.8, 0.8, 5, -6, 0, 0);

        DrawBear (t*3.13,      t*-0.67 + 620, 0.5, 0.5, 1,  2, 0, 4, RGB (208, 113, 55));

        t++;

        txSleep (20);
        }
    }


void MoveMen ()                        //400, 500; 410, 505; 420, 505
    {
    int t = 0;
    while (t < 150)
        {
        DrawBackground ();

        DrawSun (t*-1 + 1000, t*0.33 - 50, 1, 1, -2, 10, 0);

        DrawMan (t*-2    + 400,           500,  0.5,  0.2, 50,  50, -5, 4, -10, 10, 0, 0, 0, RGB (254, 226, 95), RGB (101, 236, 55));
        DrawMan (t*-2.33 + 410, t*0.07  + 505, 0.25,  0.3,  0, -10, -5, 4, -10, 10, 0, 0, 0, RGB (254, 226, 95), RGB  (0, 255, 255));
        DrawMan (t*-2.33 + 420, t*-0.13 + 505,  0.4, 0.25,  0,   0, -5, 4, -10, 10, 0, 0, 0, RGB (254, 226, 95), RGB (255, 255, 87));

        DrawHouse (160, 450, 0.8, 0.8);

        DrawMan (t*2.67 + 100, t*1.2 + 500, -0.9, 0.8, -50, -3, -5, 4, -10, 10, 0, 0, 3, APPLE_COLOR, RGB  (255, 43, 48));
        DrawMan (t*2.67 +  50, t*1.2 + 500,  0.6, 0.8, -50, -3, -5, 4, -10, 10, 0, 0, 3, APPLE_COLOR, RGB (196, 86, 211));

        t++;

        txSleep (20);
        }
    }

void MoveBird ()
    {
    int x = 1000;
    int y = 235;
    while (x > 800)
        {
        DrawBackground ();
        DrawSun (535, 115, 1, 1, -2, 10, 0);
        DrawBear (530, 502, 0.8, 0.8, 5, -6, 0, 0);
        DrawBear (450, 550, 0.5, 0.5, 1, 2, 0, 4, RGB (208, 113, 55));
        DrawMan (700, 508, 0.6, 0.8, -10, 10, 2, 2.5, 15, 10, 0, 0, 4, APPLE_COLOR);
        DrawMan (660, 540, 1, 0.5, 50, 0, 5, 1.5, 0, 5, 2, 2, -2, RGB (151, 17, 6), RGB (255, 128, 0));
        DrawMan (550, 580, 0.5, 0.3, 50, 50, -5, 4, -10, 10, 0, 0, 0, RGB (254, 226, 95), RGB (0, 255, 255));

        DrawBird (x, y, 1, 1, 10, 2, 0, 10, 15);


        //DrawMan (t*1    + 300, t*0.2  + 480,  0.5,  0.2, 50,  50, -5, 4, -10, 10, 0, 0, 0, RGB (254, 226, 95), RGB (101, 236, 55));
        //DrawMan (         410, t*0.2  + 485, 0.25,  0.3,  0, -10, -5, 4, -10, 10, 0, 0, 0, RGB (254, 226, 95), RGB  (0, 255, 255));
        //DrawMan (t*-0.8 + 500, t*0.15 + 490,  0.4, 0.25,  0,   0, -5, 4, -10, 10, 0, 0, 0, RGB (254, 226, 95), RGB (255, 255, 87));




        x = x - 10;
        y = y + 10;
        txSleep (20);
        }
    }

void MoveFtitles ()
    {
    int x = 1000;
    while (x > 480)
        {
        DrawBackground ();

        FinishTitles (x, 150);

        x = x - 10;
        txSleep (25);
        }
    }
//-----------------------------------------------------------------------------

void DrawHouse (int x, int y,
                double sizeX, double sizeY, double roof,
                COLORREF windowColor, COLORREF roofColor, COLORREF treeColor)                                              // ����������� ������� DrawHouse
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
              double step, double smile, double winkL, double winkR,
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
    txEllipse (x+67*sizeX, y-(66-winkL)*sizeY, x+ 80*sizeX, y-(52+winkL)*sizeY);
    txEllipse (x+94*sizeX, y-(66-winkR)*sizeY, x+107*sizeX, y-(52+winkR)*sizeY);
    txEllipse (x+82*sizeX, y-48*sizeY, x+ 90*sizeX, y-40*sizeY);
    txLine (x+86*sizeX, y-(28-smile)*sizeY, x+78*sizeX, y-(33+smile)*sizeY);
    txLine (x+86*sizeX, y-(28-smile)*sizeY, x+94*sizeX, y-(33+smile)*sizeY);
    }

void DrawMan (int x, int y,
              double sizeX, double sizeY,
              double handL, double handR, double leg, double step,
              double wind, double hair, double winkL, double winkR, double smile,
              COLORREF appleColor, COLORREF manColor)
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (manColor);
    txEllipse (x-17*sizeX, y-33*sizeY, x+16*sizeX, y+33*sizeY);                           // 754; 508
    txLine (x-50*sizeX, y-(28+handL)*sizeY ,x-15*sizeX, y-15*sizeY);
    txLine (x+15*sizeX, y-15*sizeY, x+36*sizeX, y+(17-handR)*sizeY);
    txLine (x- 7*sizeX, y+30*sizeY, x-(10+leg)*sizeX, y+(63-step)*sizeY);
    txLine (x+ 8*sizeX, y+30*sizeY, x+(14+leg)*sizeX, y+(63+step)*sizeY);
    txLine (x, y-63*sizeY, x+   wind *sizeX, y-(74+hair)*sizeY);
    txLine (x, y-63*sizeY, x-(8-wind)*sizeX, y-(74+hair)*sizeY);
    txLine (x, y-63*sizeY, x+(8+wind)*sizeX, y-(74+hair)*sizeY);
    txSetFillColor (RGB (236, 223, 179));
    txEllipse (x-17*sizeX, y-63*sizeY, x+18*sizeX, y-33*sizeY);
    txSetFillColor (TX_BLACK);
    txEllipse (x-10*sizeX, y-(55-winkL)*sizeY, x- 1*sizeX, y-(47+winkL)*sizeY);
    txEllipse (x+ 1*sizeX, y-(55-winkR)*sizeY, x+10*sizeX, y-(47+winkR)*sizeY);
    txLine (x-5*sizeX, y-(42+smile)*sizeY, x, y-(42-smile)*sizeY);
    txLine (x+5*sizeX, y-(42+smile)*sizeY, x, y-(42-smile)*sizeY);
    txSetColor (appleColor);
    txSetFillColor (appleColor);
    txCircle (x-53*sizeX, y-(33+handL)*sizeY, 10);
    }

void DrawTree (int x, int y,
              double sizeX, double sizeY, double brunch,
              COLORREF AppleColor, COLORREF FoliageColor, COLORREF TreeColor)
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (TreeColor);
    txRectangle (x-14*sizeX, y-133*sizeY, x+14*sizeX, y+133*sizeY);                              // 857; 441
    POINT Brunch[8] = {{x-14*sizeX, y-(46-brunch)*sizeY}, {x-42*sizeX, y-(62-brunch)*sizeY}, {x-84*sizeX, y-(62-brunch)*sizeY}, {x-86*sizeX, y-(66-brunch)*sizeY}, {x-46*sizeX, y-(66-brunch)*sizeY}, {x-57*sizeX, y-(74-brunch)*sizeY}, {x-55*sizeX, y-(77-brunch)*sizeY}, {x-14*sizeX, y-(51-brunch)*sizeY}};
    txPolygon (Brunch, 8);
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
              double smile, double winkL, double winkR,
              COLORREF sunColor, COLORREF eyeColor, COLORREF mouthColor)
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
    txSetColor (eyeColor);
    txSetFillColor (eyeColor);
    txEllipse (x-35*sizeX, y-(25-winkL)*sizeY, x- 5*sizeX, y-winkL*sizeY);
    txEllipse (x+ 5*sizeX, y-(25-winkR)*sizeY, x+35*sizeX, y-winkR*sizeY);
    txSetColor (mouthColor, 3);
    txLine (x-15*sizeX, y+(25+smile)*sizeY, x*sizeX, y+(30-smile)*sizeY);
    txLine (x+15*sizeX, y+(25+smile)*sizeY, x*sizeX, y+(30-smile)*sizeY);
    }

void DrawBird (int x, int y,
               double sizeX, double sizeY,
               double leg, double step, double wing,
               double tail, double wind,
               COLORREF birdColor)
    {
    txSetColor (TX_BLACK);
    txSetFillColor (birdColor);
    txEllipse (x- 9*sizeX, y- 5*sizeY, x+9*sizeX, y+5*sizeY);                                  // 782; 366
    txEllipse (x-16*sizeX, y-12*sizeY, x-5*sizeX, y-2*sizeY);
    txSetFillColor (RGB (255, 255, 255));
    txEllipse (x-14*sizeX, y-9*sizeY, x-11*sizeX, y-6*sizeY);
    txLine (x-1*sizeX, y+4*sizeY, x-(1+leg)*sizeX, y+(9-step)*sizeY);
    txLine (x+2*sizeX, y+4*sizeY, x+(2+leg)*sizeX, y+(9+step)*sizeY);
    txLine (x, y-2*sizeY, x, y+(3-wing)*sizeY);
    txLine (x-6*sizeX, y, x, y+(3-wing)*sizeY);
    txLine (x+9*sizeX, y, x+(16+tail)*sizeX, y-(7+wind)*sizeY);
    txLine (x+9*sizeX, y, x+(16+tail)*sizeX, y+(7-wind)*sizeY);
    txLine (x+9*sizeX, y, x+(19+tail)*sizeX, y-(3+wind)*sizeY);
    txLine (x+9*sizeX, y, x+(19+tail)*sizeX, y+(5-wind)*sizeY);
    txSetColor (RGB (255, 255, 0));
    txLine (x-17*sizeX, y-8*sizeY, x-18*sizeX, y-5*sizeY);
    txLine (x-19*sizeX, y-5*sizeY, x-15*sizeX, y-5*sizeY);
    }

void FinishTitles (int x, int y)
    {
    txSetColor (TX_BLACK);
    txSelectFont ("Comic Sans MS", 100);
    txTextOut (x-215, y-40, "COUNTRYLIFE...");           //235, 60
    }

void DrawBackground ()
    {


    txSetColor (RGB (80, 186, 88));
    txSetFillColor (RGB (80, 186, 88));
    txRectangle (1, 492, 1000, 600);

    txSetColor (RGB (97, 221, 243));
    txSetFillColor (RGB (97, 221, 243));
    txRectangle (0, 0, 1000, 492);

    DrawHouse (340, 470, 0.5, 0.2, 1, TX_LIGHTGRAY, TX_BLACK);

    DrawHouse (510, 470, 0.3, 0.3, 0.9, WINDOW_COLOR, RGB (189, 79, 221));

    DrawHouse (430, 470, 0.2, 0.3, 1.1, RGB (131, 224, 252), RGB (255, 128, 192));

    DrawHouse (160, 450, 0.8, 0.8);

    DrawTree (857, 441, 0.7, 0.7, 55);

    DrawTree (920, 470, 0.4, 0.4, 60, RGB (152, 1, 35), RGB (21, 193, 21), RGB (100, 54, 13));

    DrawTree (885, 525, 0.2, 0.2, -20, RGB (254, 226, 95), RGB (0, 128, 64), RGB (126, 41, 1));

    DrawBird (160, 182, 1.2, 1.2, -2, 0, 10, 5, -5, RGB (255, 128, 192));
    }
