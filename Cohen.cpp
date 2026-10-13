#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

int c(int x,int y,int xmin,int ymin,int xmax,int ymax)
{
    return (x<xmin?1:0)|(x>xmax?2:0)|
           (y<ymin?4:0)|(y>ymax?8:0);
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int xmin=150,ymin=100,xmax=450,ymax=300;
    int x1=80,y1=150,x2=500,y2=350;

    rectangle(xmin,ymin,xmax,ymax);
    setcolor(RED);
    line(x1,y1,x2,y2);
    setcolor(GREEN);

    while(true)
    {
        int a=c(x1,y1,xmin,ymin,xmax,ymax);
        int b=c(x2,y2,xmin,ymin,xmax,ymax);

        if(!(a|b))
        {
            line(x1,y1,x2,y2);
            break;
        }
        if(a&b) break;

        int o=a?a:b,x,y;
        if(o&8) { x=x1+(x2-x1)*(ymax-y1)/(y2-y1); y=ymax; }
        else if(o&4) { x=x1+(x2-x1)*(ymin-y1)/(y2-y1); y=ymin; }
        else if(o&2) { y=y1+(y2-y1)*(xmax-x1)/(x2-x1); x=xmax; }
        else { y=y1+(y2-y1)*(xmin-x1)/(x2-x1); x=xmin; }

        if(o==a) x1=x,y1=y;
        else x2=x,y2=y;
    }

    getch();
    closegraph();
    return 0;
}
