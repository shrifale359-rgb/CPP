#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

// DDA Line Drawing Algorithm
void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += Xinc;
        y += Yinc;
    }
}

// Bresenham’s Circle Drawing Algorithm
void BresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        if (d < 0)
            d = d + 4 * x + 6;
        else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int left = 200, top = 150, right = 400, bottom = 350;
    int xc = (left + right) / 2;
    int yc = (top + bottom) / 2;
    int radius = 100;

    // Rectangle
    DDA(left, top, right, top);
    DDA(right, top, right, bottom);
    DDA(right, bottom, left, bottom);
    DDA(left, bottom, left, top);

    // Diagonals
    DDA(left, top, right, bottom);
    DDA(right, top, left, bottom);

    // Circle
    BresenhamCircle(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}
