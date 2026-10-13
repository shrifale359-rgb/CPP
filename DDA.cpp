#include <graphics.h>
#include <conio.h>
#include <math.h>

void lineDDA(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1,dy=y2-y1;
    int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    float x=x1,y=y1;
    float xi=(float)dx/steps,yi=(float)dy/steps;

    for(int i=0;i<=steps;i++)
    {
        putpixel(round(x),round(y),WHITE);
        x+=xi; y+=yi;
    }
}

void circleBres(int xc,int yc,int r)
{
    int x=0,y=r,p=3-2*r;
    while(x<=y)
    {
        putpixel(xc+x,yc+y,WHITE); putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE); putpixel(xc-x,yc-y,WHITE);
        putpixel(xc+y,yc+x,WHITE); putpixel(xc-y,yc+x,WHITE);
        putpixel(xc+y,yc-x,WHITE); putpixel(xc-y,yc-x,WHITE);
        if(p<0) p+=4*x+6;
        else {p+=4*(x-y)+10; y--;}
        x++;
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int l=150,t=80,r=450,b=280;
    lineDDA(l,t,r,t); lineDDA(r,t,r,b);
    lineDDA(r,b,l,b); lineDDA(l,b,l,t);

    int mx=(l+r)/2,my=(t+b)/2;
    lineDDA(l,my,mx,t); lineDDA(mx,t,r,my);
    lineDDA(r,my,mx,b); lineDDA(mx,b,l,my);

    circleBres(mx,my,78);

    getch();
    closegraph();
    return 0;
}
