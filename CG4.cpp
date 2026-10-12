
#include <graphics.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};
Point p[6] = {
    {150, 150}, {350, 150}, {350, 250},
    {250, 200}, {150, 300}, {150, 150}
};

int n = 5;
// Scan Line Polygon Filling Algorithm
void scanLineFill(int color)
{
    int ymin = p[0].y, ymax = p[0].y;

    for (int i = 1; i < n; i++)
    {
        ymin = min(ymin, p[i].y);
        ymax = max(ymax, p[i].y);
    }
    setcolor(WHITE);
    for (int y = ymin; y <= ymax; y++)
    {
        int x[10], count = 0;

        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;

            if ((p[i].y <= y && p[j].y > y) ||
                (p[j].y <= y && p[i].y > y))
            {
                x[count++] = p[i].x +
                    (y - p[i].y) * (p[j].x - p[i].x) /
                    (p[j].y - p[i].y);
            }
        }
        sort(x, x + count);

        for (int i = 0; i < count - 1; i += 2)
            line(x[i], y, x[i + 1], y), setcolor(color);
    }
    // Draw polygon boundary
    setcolor(WHITE);
    for (int i = 0; i < n; i++)
        line(p[i].x, p[i].y,
             p[(i + 1) % n].x, p[(i + 1) % n].y);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int choice, color;

    do
    {
        cout << "\n--- MENU ---";
        cout << "\n1. Draw Concave Polygon";
        cout << "\n2. Fill Polygon";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cleardevice();
                setcolor(WHITE);

                for (int i = 0; i < n; i++)
                    line(p[i].x, p[i].y,
                         p[(i + 1) % n].x,
                         p[(i + 1) % n].y);
                break;
          
            case 2:
                cout << "\nChoose color (1-15): ";
                cin >> color;

                if (color >= 1 && color <= 15)
                    scanLineFill(color);
                else
                    cout << "Invalid color!";
                break;
          
            case 3:
                break;
            default:
                cout << "Invalid choice!";
        }

    } while (choice != 3);
    closegraph();
    return 0;
}
