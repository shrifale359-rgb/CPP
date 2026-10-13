#include<graphics.h>
#include<conio.h>
#include<iostream>

using namespace std;

int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;

int xmin=150,ymin=100,xmax=400,ymax=300;

int getcode(int x,int y){
    int code=0;

    if(x<xmin)code|=LEFT;
    if(x>xmax)code|=RIGHT;
    if(y<ymin)code|=BOTTOM;
    if(y>ymax)code|=TOP;

    return code;

}
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int x1=100,y1=150;
    int x2=450,y2=250;

    rectangle(xmin,ymin,xmax,ymax);

    setcolor(RED);
    line(x1,y1,x2,y2);

    int c1=getcode(x1,y1);
    int c2=getcode(x2,y2);


    while(true){
        if(c1|c2==0){
            break;
        }
        if(c1&c2!=0){
            x1=x2;

            break;
        }
        int code=c1?c2:c2;
        float x,y;

        if(code&TOP){
            x=x1+(x2-x1)*(ymax-y1)/(float)(y2-y1);
            y=ymax;
        }

        else if(code&BOTTOM){
            x=x1+(x2-x1)*(ymin-y1)/(float)(y2-y1);
            y=ymin;
        }
        else if(code&RIGHT){
            y=y1+(y2-y1)*(xmax-x1)/(float)(x2-x1);
            x=xmax;
        }
        else{
            y=y1+(y2-y1)*(xmin-x1)/(float)(x2-x1);
            x=xmin;
        }
        if(code==c1){
            x1=x;
            y1=y;
            c1=getcode(x1,y1);
        }
        else{
            x2=x;
            y2=y;
            c2=getcode(x2,y2);
        }
    }

    if(c1==0 && c2==0){
        setcolor(GREEN);
        line(x1,y1,x2,y2);
    }
    getch();
    closegraph();
    return 0;
}
