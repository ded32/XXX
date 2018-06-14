#include "TXLib.h"

int main ()
    {
    const COLORREF WINDOW_COLOR  = RGB (255, 250, 153);
    const COLORREF BEAR_COLOR    = RGB (157, 79, 0);
    const COLORREF TREE_COLOR    = RGB (111, 69, 28);
    const COLORREF FOLIAGE_COLOR = RGB (43, 247, 88);
    const COLORREF APPLE_COLOR   = RGB (240, 49, 97);
    const COLORREF BIRD_COLOR    = RGB (102, 148, 162);

    txCreateWindow (1000, 600);

    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txRectangle (0, 0, 1000, 600);

    txSetColor (RGB (80, 186, 88));
    txSetFillColor (RGB (80, 186, 88));
    txRectangle (1, 492, 1000, 600);

    txSetColor (RGB (97, 221, 243));
    txSetFillColor (RGB (97, 221, 243));
    txRectangle (0, 0, 1000, 492);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (RGB (204, 129, 53));
    txRectangle (85, 335, 400, 575);
    txSetFillColor (RGB (243, 31, 73));
    POINT triangle[3] = {{244, 131}, {21, 335}, {476, 335}};
    txPolygon (triangle, 3);
    txSetFillColor (WINDOW_COLOR);
    txRectangle (107, 352, 215, 422);
    txRectangle (267, 352, 375, 422);
    txSetFillColor (TREE_COLOR);
    txRectangle (122, 454, 201, 575);
    txLine (161, 352, 161, 421);
    txLine (107, 387, 215, 387);
    txLine (267, 387, 375, 387);
    txLine (321, 352, 321, 421);

    txSetColor (TX_BLACK, 3);
    txSetFillColor (BEAR_COLOR);
    txEllipse (458, 453, 608, 550);
    txEllipse (576, 421, 662, 482);
    txEllipse (575, 412, 597, 430);
    txEllipse (647, 415, 668, 434);
    txEllipse (442, 473, 461, 491);
    txEllipse (583, 532, 600, 566);
    txEllipse (563, 540, 581, 574);
    txEllipse (474, 538, 492, 575);
    txEllipse (493, 545, 513, 580);
    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_BLACK);
    txEllipse (600, 436, 613, 450);
    txEllipse (627, 436, 640, 450);
    txEllipse (615, 454, 623, 462);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (RGB (121, 48, 194));
    txEllipse (737, 475, 770, 541);
    txLine (704, 480 ,738, 493);
    txLine (769, 493, 790, 525);
    txLine (747, 538, 744, 571);
    txLine (762, 538, 768, 571);
    txSetFillColor (RGB (236, 223, 179));
    txEllipse (737, 445, 772, 475);
    txSetFillColor (TX_BLACK);
    txEllipse (744, 453, 753, 461);
    txEllipse (755, 453, 764, 461);
    txSetColor (APPLE_COLOR);
    txSetFillColor (APPLE_COLOR);
    txEllipse (690, 468, 706, 482);

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

    txSetColor (TX_BLACK);
    txSetFillColor (RGB (255, 255, 0));
    txEllipse (475, 56, 596, 177);
    txSetColor (RGB (255, 255, 0), 5);
    txLine (541, 189, 541, 245);
    txLine (607, 114, 681, 114);
    txLine (397, 112, 464, 112);
    txLine (533, 50, 537, 0);
    txLine (587, 67, 628, 17);
    txLine (586, 167, 636, 214);
    txLine (484, 164, 435, 203);
    txLine (429, 17, 485, 65);

    txSetColor (TX_BLACK);
    txSetFillColor (BIRD_COLOR);
    txEllipse (773, 361, 791, 371);
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

    txTextCursor (false);
    return 0;
    }
