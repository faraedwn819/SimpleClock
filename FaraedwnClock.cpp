/**
* FaraedwnClock.cpp
* @author  Faraedwn Shaquli
* @version 1.0
* @since   2020-01-25
*/
#include<graphics.h>
#include<math.h>
#include<iostream>
#include<stdio.h>
#include<windows.h>
using namespace std;
int centerX,centerY;
double COS(double angle){
return cos( angle * ( (22/7.0)/180.0 ) );
}
double SIN(double angle){
return sin( angle * ( (22/7.0)/180.0 ) );
}
void setSmallLines(){
setcolor(WHITE);
setlinestyle(SOLID_LINE,0,7);
circle(centerX,centerY,3);
setlinestyle(SOLID_LINE,0,1);
int x1 = centerX;
int y1 = centerY-310;
int x2 = centerX;
int y2 = centerY-290;
int counter = 0;
int x3 = centerX;
int y3 = centerY-270;
    int angle2 = 0;
    while(true){
        int x11 = centerX+ (x1-centerX)*COS(angle2) - (y1-centerY)*SIN(angle2);
        int y11 = centerY+ (x1-centerX)*SIN(angle2) + (y1-centerY)*COS(angle2);
        int x22 = centerX+ (x2-centerX)*COS(angle2) - (y2-centerY)*SIN(angle2);
        int y22 = centerY+ (x2-centerX)*SIN(angle2) + (y2-centerY)*COS(angle2);
        setcolor(14);
        line(x11,y11,x22,y22);
        int x33 = centerX+ (x3-centerX)*COS(angle2) - (y3-centerY)*SIN(angle2);
        int y33 = centerY+ (x3-centerX)*SIN(angle2) + (y3-centerY)*COS(angle2);
        if(angle2%5 == 0){
                if(counter != 0){
                    char arr[100];
                    sprintf(arr,"%d" , (counter));
                    double strWidth =  textwidth(arr);
                    double strHeight = textheight(arr);
                    outtextxy(x33-strWidth/2,y33-strHeight/2,arr);
                    setcolor(WHITE);
                }
            counter++;
        }
        if(angle2>=360)
            break;
        angle2+=6;
    }
}
void moveClock(){
    int x1 = centerX, y1 = centerY-270;
    int x2 = centerX, y2 = centerY+20;
    int x3 = centerX, y3 = centerY-250;
    int x4 = centerX, y4 = centerY+15;
    int x5 = centerX-220, y5 = centerY;
    int x6 = centerX+10, y6 = centerY;
    int angle=0, angle2=0, angle3=3,x33,y33,x44,y44,x55 = x5,y55=y5,x66=x6,y66=y6,page =0;
    while(true){
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        setSmallLines();
        int x11 = centerX+ (x1-centerX)*COS(angle) - (y1-centerY)*SIN(angle);
        int y11 = centerY+ (x1-centerX)*SIN(angle) + (y1-centerY)*COS(angle);
        int x22 = centerX+ (x2-centerX)*COS(angle) - (y2-centerY)*SIN(angle);
        int y22 = centerY+ (x2-centerX)*SIN(angle) + (y2-centerY)*COS(angle);
        setcolor(LIGHTGREEN);
        line(x11,y11,x22,y22);
        if(angle%180 == 0){
            x33 = centerX+ (x3-centerX)*COS(angle2) - (y3-centerY)*SIN(angle2);
            y33 = centerY+ (x3-centerX)*SIN(angle2) + (y3-centerY)*COS(angle2);
            x44 = centerX+ (x4-centerX)*COS(angle2) - (y4-centerY)*SIN(angle2);
            y44 = centerY+ (x4-centerX)*SIN(angle2) + (y4-centerY)*COS(angle2);
            if(angle2>=360)
                angle2 = 0;
            angle2+=3;
        }
        if((angle+6)%360 == 0 && angle2%36==0){
            x55 = centerX+ (x5-centerX)*COS(angle3) - (y5-centerY)*SIN(angle3);
            y55 = centerY+ (x5-centerX)*SIN(angle3) + (y5-centerY)*COS(angle3);
            x66 = centerX+ (x6-centerX)*COS(angle3) - (y6-centerY)*SIN(angle3);
            y66 = centerY+ (x6-centerX)*SIN(angle3) + (y6-centerY)*COS(angle3);
            if(angle3>=360)
                angle3 = 0;
            angle3+=3;
        }
        setcolor(13);
        line(x33,y33,x44,y44);
        setcolor(14);
        line(x55,y55,x66,y66);
        if(GetAsyncKeyState(VK_RETURN))
            exit(0);
        page =1-page;
        delay(900);
        Beep(50,100);
        if(angle>=360)
            angle=0;
        angle+=6;
    }
}
int main(){
    DWORD x = GetSystemMetrics(SM_CXSCREEN);
    DWORD y = GetSystemMetrics(SM_CYSCREEN);
    initwindow(x,y,"",-3,-3);
    centerX = x/2;
    centerY = y/2;
    settextstyle(0,0,3);
    moveClock();
    getch();
    return 0;
}
