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
                COLORREF windowColor = WINDOW_COLOR, COLORREF roofColor = RGB (243, 31, 73), COLORREF treeColor = TREE_COLOR);                                                      //  прототип функции DrawHouse
void DrawBear  (int x, int y,
                double sizeX, double sizeY,
                double step, double smile, double winkL, double winkR,
                COLORREF bearColor = BEAR_COLOR);
void DrawMan   (int x, int y,
                double sizeX, double sizeY, double apple,
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
void BeginTitles (int x, int y);

void DrawBackground ();
void MoveMen ();
void MoveBearsPhysics ();
void MoveSun ();
void MoveBird ();
void MoveFtitles ();
void MoveThreemen ();
void MoveBtitles ();

//-----------------------------------------------------------------------------

int main ()
    {
    txCreateWindow (1000, 600);

    txBegin ();

    DrawBackground ();

    MoveBtitles ();

    MoveBird ();

    MoveThreemen ();

    MoveMen ();

    MoveBearsPhysics ();

    MoveFtitles ();

    txEnd ();

    txTextCursor (false);
    return 0;
    }

//-----------------------------------------------------------------------------

void MoveBtitles ()
    {
    int t = 0;
    while (t < 100)
        {
        DrawBackground ();

        txSetColor (TX_BLACK);
        txSelectFont ("Impact", 60);
        txTextOut (400, t*0.7, "The cartoon");
        txSelectFont ("Comic Sans MS", 40);
        txTextOut (t*4.9, t*-4.8 + 600, "made by");
        txSelectFont ("Gabriola", 90);
        txTextOut (t*-6.1 + 1000, t*-3.6 + 500, "Blinova Sofa");

        t++;
        txSleep (20);
        }
    }

void MoveBearsPhysics ()
    {
    int t = 0;
    while (t < 150)
        {
        DrawBackground ();

        DrawSun (t*-1.5 + 575, t*0.49 + 89.5, 1, 1, -2, 10, 0);           //575; 89.5

        DrawMan (t*3.67 + 580,          490, 0.25,  0.3, -10, 0, 0, t/4%2*8 - 4, t/4%2*7, t%17 -  8, t%5 + 5, 0, 0, 0, RGB (254, 226, 95), RGB  (0, 255, 255));
        DrawMan (t*3.33 + 540,          490,  0.5,  0.2,  -5, 0, 0, t/3%2*8 - 3, t/3%2*5, t%15 -  7, t%8 + 7, 0, 0, 0, RGB (254, 226, 95), RGB (101, 236, 55));
        DrawMan (t*4    + 560, t*0.13 + 490,  0.4, 0.25, -10, 0, 0, t/4%2*6 - 2, t/4%2*6, t%21 - 10, t%7    , 0, 0, 0, RGB (254, 226, 95), RGB (255, 255, 87));

        //HAND                                               FOOT                                     HAIR
        // t =        1 2 3  4  5  6 7 8 9  10               t =       0 1 2 3 4 5 6 7 8 9 10         t =   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
        // t/3 =      0 0 1  1  1  2 2 2 3  3                t/4 =     0 0 0 0 1 1 1 1 2 2 2          t%7 = 0 0 0 0 0 0 0 0 1 2 3  4  5  6  0
        // t/3%2 =    0 0 1  1  1  0 0 0 1  1                t/4%2 =   0 0 0 0 1 1 1 1 0 0 0

        DrawTree (t/10%2 + 857, 441, 0.7, 0.7, t/10%2*8 + 55);
        DrawTree (t/5%2  + 920, 470, 0.4, 0.4,  t/5%2*8 + 60, RGB (152, 1, 35), RGB (21, 193, 21), RGB (100, 54, 13));
        DrawTree (t/3%2  + 885, 525, 0.2, 0.2,  t/3%2*8 - 20, RGB (254, 226, 95), RGB (0, 128, 64), RGB (126, 41, 1));
        DrawBird (810, t/10%2*8 + 425, 1, 1, 10, 2,  0, t/3%3 + 10, t/3%5 + 15);
        DrawBird (162, 179, -1.2, 1.2, -2, 0, 10, t/3%5 +  5, t/3%8 -  5, RGB (255, 128, 192));
        DrawHouse (510, 470, 0.3, 0.3, 0.9, WINDOW_COLOR, RGB (189, 79, 221));

        //TREE; HOUSE
        // t =     0 1 2 3 4 5 6 7 8 9 10
        // t/2 =   0 0 1 1 2 2 3 3 4 4 5
        // t/2%2 = 0 0 1 1 0 0 1 1 0 0 1

        DrawBear (t*-3.33 + 1100, t*-0.67 + 572, -0.8, 0.8, t/5%2*6 - 4, -6, t/10%2*5, t/10%2*5);

        DrawBear (t*3.13,         t*-0.67 + 620,  0.5, 0.5, t/4%2*5 - 2,  2,  t/7%2*5, t/7%2*5, RGB (208, 113, 55));

        //BEAR
        // t =       0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        // t/4 =     0 0 0 0 1 1 1 1 2 2 2  2  3  3  3  3
        // t/4%2 =   0 0 0 0 1 1 1 1 0 0 0  0  1  1  1  1
        // t/4%2*6 = 0 0 0 0 6 6 6 6 0 0 0  0  6  6  6  6

        t++;

        txSleep (20);
        }
    }


void MoveMen ()
    {
    int t = 0;
    while (t < 150)
        {
        DrawBackground ();

        DrawSun (t*-1.5 + 800, t*0.49 + 16, 1, 1, -2, 10, 0);

        DrawMan (t*-2    + 400,           500,  0.2,  0.2,  -5, 50,  50, -5, 4, t%17 -  8, t%5 + 5, 0, 0, 0, RGB (254, 226, 95), RGB (101, 236, 55));
        DrawMan (t*-2.33 + 415, t*0.07  + 505, 0.25,  0.3, -10,  0, -10, -5, 4, t%15 -  7, t%8 + 7, 0, 0, 0, RGB (254, 226, 95), RGB  (0, 255, 255));
        DrawMan (t*-2.33 + 430, t*-0.13 + 505,  0.4, 0.25, -10,  0,   0, -5, 4, t%21 - 10, t%7    , 0, 0, 0, RGB (254, 226, 95), RGB (255, 255, 87));

        DrawHouse (160, 450, 0.8, 0.8);

        DrawMan (t*2.67 + 100, t*2 + 500, t*-0.01 - 0.9, t*0.01 + 0.8,   0, 0, -3, -5, 4, t%7  - 10, t%8 + 7, t/10%2*5, t/10%2*5, 3, APPLE_COLOR, RGB  (255, 43, 48));
        DrawMan (t*2.4  +  50, t*2 + 500, t*0.01  + 0.6, t*0.01 + 0.8, -10, 0, -3, -5, 4, t%10 - 10,      10,  t/7%2*5,  t/7%2*5, 3, APPLE_COLOR, RGB (196, 86, 211));

        //WINK
        //t =     0 1 2 3 4 5 6 7 8 9 10             t =       0 1 2 3 4 5 6 7 8 9 10           t =        0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20            t =       0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
        //t%2 =   0 1 0 1 0 1 0 1 0 1 0              t/2 =     0 0 1 1 2 2 3 3 4 4 5            t/10 =     0 0 0 0 0 0 0 0 0 0 1  1  1  1  1  1  1  1  1  1  2             t/7 =     0 0 0 0 0 0 0 1 1 1 1  1  1  1  2
        //t%2*5 = 0 5 0 5 0 5 0 5 0 5 0              t/2%2 =   0 0 1 1 0 0 1 1 0 0 1            t/10%2 =   0 0 0 0 0 0 0 0 0 0 1  1  1  1  1  1  1  1  1  1  0             t/7%2 =   0 0 0 0 0 0 0 1 1 1 1  1  1  1  0
        //                                           t/2%2*5 = 0 0 5 5 0 0 5 5 0 0 5            t/10%2*5 = 0 0 0 0 0 0 0 0 0 0 5  5  5  5  5  5  5  5  5  5  0             t/7%2*5 = 0 0 0 0 0 0 0 5 5 5 5  5  5  5  0

        DrawTree (t/10%2 + 857, 441, 0.7, 0.7, t/10%2*8 + 55);
        DrawTree (t/5%2  + 920, 470, 0.4, 0.4,  t/5%2*8 + 60, RGB (152, 1, 35), RGB (21, 193, 21), RGB (100, 54, 13));
        DrawTree (t/3%2  + 885, 525, 0.2, 0.2,  t/3%2*8 - 20, RGB (254, 226, 95), RGB (0, 128, 64), RGB (126, 41, 1));
        DrawBird (810, t/10%2*8 + 425,    1,   1, 10, 2,  0, t/3%3 + 10, t/3%5 + 15);
        DrawBird (162, 179, -1.2, 1.2, -2, 0, 10, t/3%5 +  5, t/3%8 -  5, RGB (255, 128, 192));

        t++;

        txSleep (20);
        }
    }

void MoveBird ()
    {
    int t = 0;
    while (t < 100)
        {
        DrawBackground ();

        DrawSun (t*-1 + 1000, t*0.33 - 50, 1, 1, -2, 10, 0);

        DrawTree (t/10%2 + 857, 441, 0.7, 0.7, t/10%2*8 + 55);
        DrawTree (t/5%2  + 920, 470, 0.4, 0.4,  t/5%2*8 + 60, RGB (152, 1, 35), RGB (21, 193, 21), RGB (100, 54, 13));
        DrawTree (t/3%2  + 885, 525, 0.2, 0.2,  t/3%2*8 - 20, RGB (254, 226, 95), RGB (0, 128, 64), RGB (126, 41, 1));

        DrawBird (t*-2 + 1005, t*3.5 + 80,    1,   1, 10, 2,  t/6%2*8, t/3%3 + 10, t/3%5 + 15);

        DrawBird (t*2  -   33, t*-2 + 377, -1.2, 1.2, -2, 0, t/4%2*10, t/3%5 +  5, t/3%8 -  5, RGB (255, 128, 192));

        //BIRD
        //t =        0 1 2  3  4 5 6  7  8 9 10
        //t/2%2 =    0 0 1  1  0 0 1  1  0 0 1
        //t/2%2*10 = 0 0 10 10 0 0 10 10 0 0 10

        t++;
        txSleep (10);
        }
    }

void MoveFtitles ()
    {
    int t = 0;
    while (t < 110)
        {
        DrawBackground ();

        FinishTitles (t*-7 + 1200, 150);

        t++;
        txSleep (10);
        }
    }

void MoveThreemen ()
    {
    int t = 0;
    while (t < 50)
        {
        DrawBackground ();
        DrawTree (t/10%2 + 857, 441, 0.7, 0.7, t/10%2*8 + 55);
        DrawTree (t/5%2  + 920, 470, 0.4, 0.4,  t/5%2*8 + 60, RGB (152, 1, 35), RGB (21, 193, 21), RGB (100, 54, 13));
        DrawTree (t/3%2  + 885, 525, 0.2, 0.2,  t/3%2*8 - 20, RGB (254, 226, 95), RGB (0, 128, 64), RGB (126, 41, 1));

        DrawSun (t*-2 + 900, t*0.66 - 17, 1, 1, -2, 10, 0);

        DrawBird (810, t/10%2*8 + 425,    1,   1, 10, 2,  0, t/3%3 + 10, t/3%5 + 15);
        DrawBird (162, 179, -1.2, 1.2, -2, 0, 10, t/3%5 +  5, t/3%8 -  5, RGB (255, 128, 192));

        DrawMan (t*2    + 300, t*0.4  + 480,  0.2,  0.2,  -5, 50, 50, -5, 4, t%17 -  8, t%5 + 5, 0, 0, 0, RGB (254, 226, 95), RGB (101, 236, 55));
        DrawMan (         410, t*0.4  + 485, 0.25,  0.3, -10, 0, -10, -5, 4, t%15 -  7, t%8 + 7, 0, 0, 0, RGB (254, 226, 95), RGB  (0, 255, 255));
        DrawMan (t*-1.6 + 500, t*0.3  + 490,  0.4, 0.25, -10, 0,   0, -5, 4, t%21 - 10, t%7    , 0, 0, 0, RGB (254, 226, 95), RGB (255, 255, 87));

        t++;
        txSleep (10);
        }
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
              double step, double smile, double winkL, double winkR,
              COLORREF bearColor)
    {
    txSetColor (TX_BLACK, 3);
    txSetFillColor (bearColor);
    txEllipse (x- 75*sizeX, y-49*sizeY, x+ 75*sizeX, y+48*sizeY);                                       // 533; 502
    txEllipse (x+ 43*sizeX, y-81*sizeY, x+129*sizeX, y-20*sizeY);
    txEllipse (x+ 42*sizeX, y-90*sizeY, x+ 64*sizeX, y-72*sizeY);
    txEllipse (x+114*sizeX, y-93*sizeY, x+135*sizeX, y-68*sizeY);
    txEllipse (x- 91*sizeX, y-29*sizeY, x- 72*sizeX, y-11*sizeY);
    txEllipse (x+ 50*sizeX, y+30*sizeY, x+ 67*sizeX, y+(64-step)*sizeY);
    txEllipse (x+ 30*sizeX, y+38*sizeY, x+ 48*sizeX, y+(72+step)*sizeY);
    txEllipse (x- 59*sizeX, y+36*sizeY, x- 41*sizeX, y+(73-step)*sizeY);
    txEllipse (x- 40*sizeX, y+43*sizeY, x- 20*sizeX, y+(78+step)*sizeY);
    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_BLACK);
    txEllipse (x+67*sizeX, y-(66-winkL)*sizeY, x+ 80*sizeX, y-(52+winkL)*sizeY);
    txEllipse (x+94*sizeX, y-(66-winkR)*sizeY, x+107*sizeX, y-(52+winkR)*sizeY);
    txEllipse (x+82*sizeX, y-48*sizeY, x+ 90*sizeX, y-40*sizeY);
    txLine (x+86*sizeX, y-(28-smile)*sizeY, x+78*sizeX, y-(33+smile)*sizeY);
    txLine (x+86*sizeX, y-(28-smile)*sizeY, x+94*sizeX, y-(33+smile)*sizeY);
    }

void DrawMan (int x, int y,
              double sizeX, double sizeY, double apple,
              double handL, double handR, double leg, double step,
              double wind, double hair, double winkL, double winkR, double smile,
              COLORREF appleColor, COLORREF manColor)
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (manColor);
    txEllipse (x-17*sizeX, y-33*sizeY, x+16*sizeX, y+33*sizeY);                           // 754; 508
    txLine (x-36*sizeX, y+(17-handL)*sizeY ,x-15*sizeX, y-15*sizeY);
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
    txCircle (x-43*sizeX, y+(5-handL)*sizeY, 10+apple);
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

void BeginTitles (int x, int y)
    {
    txSetColor (TX_BLACK);
    txSelectFont ("Impact", 60);
    txTextOut (x-100, y-80, "The cartoon");
    txSelectFont ("Comic Sans MS", 40);
    txTextOut (x-10, y-30, "made by");
    txSelectFont ("Gabriola", 90);
    txTextOut (x-110, y-10, "Blinova Sofa");
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
    }
