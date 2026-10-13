#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 200, y1 = 200;
    int x2 = 300, y2 = 200;
    int x3 = 250, y3 = 100;

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    int choice;
    cout << "\n2D Transformations Menu:\n";
    cout << "1. Translation\n2. Scaling\n3. Rotation\n4. Reflection\n5. Shearing\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: { // Translation
            int tx, ty;
            cout << "Enter tx and ty: ";
            cin >> tx >> ty;
            x1 += tx; y1 += ty;
            x2 += tx; y2 += ty;
            x3 += tx; y3 += ty;
            setcolor(GREEN);
            break;
        }

        case 2: { // Scaling
            float sx, sy;
            cout << "Enter sx and sy: ";
            cin >> sx >> sy;
            x1 = x1 * sx; y1 = y1 * sy;
            x2 = x2 * sx; y2 = y2 * sy;
            x3 = x3 * sx; y3 = y3 * sy;
            setcolor(YELLOW);
            break;
        }

        case 3: { // Rotation
            float angle;
            cout << "Enter rotation angle (in degrees): ";
            cin >> angle;
            angle = angle * M_PI / 180;
            int xr = 200, yr = 200; // pivot point
            int x1r = xr + (x1 - xr) * cos(angle) - (y1 - yr) * sin(angle);
            int y1r = yr + (x1 - xr) * sin(angle) + (y1 - yr) * cos(angle);
            int x2r = xr + (x2 - xr) * cos(angle) - (y2 - yr) * sin(angle);
            int y2r = yr + (x2 - xr) * sin(angle) + (y2 - yr) * cos(angle);
            int x3r = xr + (x3 - xr) * cos(angle) - (y3 - yr) * sin(angle);
            int y3r = yr + (x3 - xr) * sin(angle) + (y3 - yr) * cos(angle);
            x1 = x1r; y1 = y1r;
            x2 = x2r; y2 = y2r;
            x3 = x3r; y3 = y3r;
            setcolor(CYAN);
            break;
        }

        case 4: { // Reflection
            int axis;
            cout << "Reflect about (1) X-axis or (2) Y-axis? ";
            cin >> axis;
            if (axis == 1) {
                y1 = -y1 + 400;
                y2 = -y2 + 400;
                y3 = -y3 + 400;
            } else {
                x1 = -x1 + 400;
                x2 = -x2 + 400;
                x3 = -x3 + 400;
            }
            setcolor(MAGENTA);
            break;
        }

        case 5: { // Shearing
            float shx, shy;
            cout << "Enter shx and shy: ";
            cin >> shx >> shy;
            x1 = x1 + shx * y1;
            x2 = x2 + shx * y2;
            x3 = x3 + shx * y3;
            y1 = y1 + shy * x1;
            y2 = y2 + shy * x2;
            y3 = y3 + shy * x3;
            setcolor(RED);
            break;
        }

        default:
            cout << "Invalid choice!";
            closegraph();
            return 0;
    }

    // Draw transformed triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();
    closegraph();
    return 0;}
