#include "TXLib.h"

//-----------------------------------------------------------------------------

const COLORREF WINDOW_COLOR  = RGB (255, 250, 153);
const COLORREF BEAR_COLOR    = RGB (157, 79, 0);
const COLORREF TREE_COLOR    = RGB (111, 69, 28);
const COLORREF FOLIAGE_COLOR = RGB (43, 247, 88);
const COLORREF APPLE_COLOR   = RGB (240, 49, 97);
const COLORREF BIRD_COLOR    = RGB (102, 148, 162);

//=============================================================================

void DrawHouse();                                                      //  �������� ������� DrawHouse
void DrawBear();
void DrawMan();
void DrawTree();
void DrawSun();
void DrawBird();
void DrawBackground();

//-----------------------------------------------------------------------------

int main ()
    {

    txCreateWindow (1000, 600);

    DrawBackground();

    DrawHouse();                                                         // ����� �������  DrawHouse

    DrawBear();

    DrawMan();

    DrawTree();

    DrawSun();

    DrawBird();

    txTextCursor (false);
    return 0;
    }

//-----------------------------------------------------------------------------

void DrawHouse()                                              // ����������� ������� DrawHouse
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (RGB (204, 129, 53));
    txRectangle (242-157, 445-120, 242+158, 455+120);                               // 242; 455
    txSetFillColor (RGB (243, 31, 73));
    POINT triangle[3] = {{242+2, 455-324}, {242-221, 455-120}, {242+234, 455-120}};
    txPolygon (triangle, 3);
    txSetFillColor (WINDOW_COLOR);
    txRectangle (242-135, 455-103, 242-27, 455-33);
    txRectangle (242+25, 455-103, 242+133, 455-33);
    txSetFillColor (TREE_COLOR);
    txRectangle (242-120, 455-1, 242-41, 455+120);
    txLine (242-81, 455-103, 242-81, 455-34);
    txLine (242-135, 455-68, 242-27, 455-68);
    txLine (242+25, 455-68, 242+133, 455-68);
    txLine (242+79, 455-103, 242+79, 455-34);
    }

void DrawBear()
    {
    txSetColor (TX_BLACK, 3);
    txSetFillColor (BEAR_COLOR);
    txEllipse (533-75, 508-55, 533+75, 502+48);                                       // 533; 502
    txEllipse (533+43, 502-81, 533+129, 502-20);
    txEllipse (533+42, 502-90, 533+64, 502-72);
    txEllipse (533+114, 502-93, 533+135, 502-68);
    txEllipse (533-91, 502-29, 533-72, 502-11);
    txEllipse (533+50, 502+30, 533+67, 502+64);
    txEllipse (533+30, 502+38, 533+48, 502+72);
    txEllipse (533-59, 502+36, 533-41, 502+73);
    txEllipse (533-40, 502+43, 533-20, 502+78);
    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_BLACK);
    txEllipse (533+67, 502-66, 533+80, 502-52);
    txEllipse (533+94, 502-66, 533+107, 502-52);
    txEllipse (533+82, 502-48, 533+90, 502-40);
    }

void DrawMan()
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (RGB (121, 48, 194));
    txEllipse (754-17, 508-33, 754+16, 508+33);                           // 754; 508
    txLine (754-50, 508-28 ,754-16, 508-15);
    txLine (754+15, 508-15, 754+36, 508+17);
    txLine (754-7, 508+30, 754-10, 508+63);
    txLine (754+8, 508+30, 754+14, 508+63);
    txSetFillColor (RGB (236, 223, 179));
    txEllipse (754-17, 508-63, 754+18, 508-33);
    txSetFillColor (TX_BLACK);
    txEllipse (754-10, 508-55, 754-1, 508-47);
    txEllipse (754+1, 508-55, 754+10, 508-47);
    txSetColor (APPLE_COLOR);
    txSetFillColor (APPLE_COLOR);
    txEllipse (754-64, 508-40, 754-48, 508-26);
    }

void DrawTree()
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (TREE_COLOR);
    txRectangle (843, 308, 871, 574);
    POINT brunch[8] = {{843, 395}, {815, 379}, {773, 379}, {771, 375}, {811, 375}, {800, 367}, {802, 364}, {843, 390}};
    txPolygon (brunch, 8);
    txSetColor (FOLIAGE_COLOR);
    txSetFillColor (FOLIAGE_COLOR);
    txEllipse (766, 170, 916, 329);
    txEllipse (850, 125, 983, 280);
    txEllipse (740, 99, 880, 243);
    txEllipse (822, 58, 933, 180);
    txSetColor (APPLE_COLOR);
    txSetFillColor (APPLE_COLOR);
    txEllipse (792, 153, 812, 174);
    txEllipse (876, 193, 898, 215);
    txEllipse (814, 236, 836, 259);
    }

void DrawSun()
    {
    txSetColor (TX_BLACK);
    txSetFillColor (RGB (255, 255, 0));
    txEllipse (535-60, 115-60, 535+60, 115+60);                                           // 535 115
    txSetColor (RGB (255, 255, 0), 5);
    txLine (535+6, 115+74, 535+6, 115+130);
    txLine (535+72, 115-1, 535+146, 115-1);
    txLine (535-138, 115-3, 535-71, 115-3);
    txLine (535-2, 115-65, 535+2, 115-115);
    txLine (535+52, 115-48, 535+93, 115-98);
    txLine (535+51, 115+52, 535+101, 115+99);
    txLine (535-51, 115+49, 535-100, 115+88);
    txLine (535-106, 115-98, 535-50, 115-50);
    }

void DrawBird()
    {
       txSetColor (TX_BLACK);
    txSetFillColor (BIRD_COLOR);
    txEllipse (782-9, 366-5, 782+9, 366+5);                                  // 782; 366
    txEllipse (766, 354, 777, 364);
    txSetFillColor (RGB (255, 255, 255));
    txEllipse (768, 357, 771, 360);
    txLine (781, 370, 781, 375);
    txLine (784, 370, 784, 375);
    txLine (782, 364, 782, 369);
    txLine (776, 366, 782, 369);
    txLine (791, 366, 798, 359);
    txLine (791, 366, 798, 373);
    txLine (791, 366, 801, 363);
    txLine (791, 366, 801, 371);
    txSetColor (RGB (255, 255, 0));
    txLine (765, 358, 764, 361);
    txLine (763, 361, 767, 361);
    }

void DrawBackground()
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
