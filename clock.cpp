#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include<time.h>
void sline(int,int,int,int,int,int,float,int,int);
void hline(int,int,int,int,int,int,float,int,int);
void mline(int,int,int,int,int,int,float,int,int);
void grid(int,int,int,int);
void main()
{
 int gd=DETECT,gm,maxx,maxy,midx,midy;
 int sincolor=4,soutcolor=0,hincolor=1,houtcolor=0,mincolor=13,moutcolor=0;
 int bakcolor=14;
 int gcolor=0,grad=3;

 float thita,X,Y,h,s,m;
 initgraph(&gd,&gm,"c:\\tc\\bgi");

 maxx=getmaxx();
 maxy=getmaxy();
 midx=maxx/2;
 midy=maxy/2;
 float phi=3.1423,degree,dh,dm;
 int rad=125;
 int HX,HY,MX,MY,SX,SY,ML=rad-25,SL=rad-20,HL=rad-55;
 char str[10];
 cleardevice();
  setfillstyle(1,bakcolor);
 circle(midx,midy,rad-10);
 floodfill(midx,midy,15);
  setfillstyle(1,1);
 circle(midx,midy,rad+10);
 floodfill(midx+rad+5,midy,15);
 for(thita=270+45;thita<=360+135;thita=thita+(180/60))
 {
   degree=((2*phi)/180)*thita;
   X=midx+rad*(cos(degree));
   Y=midy+rad*(sin(degree));
   itoa(degree,str,10);
   setfillstyle(1,4);
   circle(X,Y,1);
   floodfill(X,Y,15);
 }
  for(thita=270+45;thita<=360+135;thita=thita+(180/12))
  {
   degree=((2*phi)/180)*thita;
   X=midx+rad*(cos(degree));
   Y=midy+rad*(sin(degree));
   setfillstyle(1,4);
   circle(X,Y,3);
   floodfill(X,Y,15);
  }
  struct time t;
  gettime(&t);
   s=270+45+t.ti_sec*(180/60);
   h=270+45+t.ti_hour*(180/12)+((t.ti_min*(180/60)))/12;
   m=270+45+t.ti_min*(180/60)+((t.ti_sec*(180/60))/60);
   degree=((2*phi)/180)*s;
   dh=((2*phi)/180)*h;
   dm=((2*phi)/180)*m;
   SX=midx+SL*(cos(degree));
   SY=midy+SL*(sin(degree));
   HX=midx+HL*(cos(dh));
   HY=midy+HL*(sin(dh));
   MX=midx+ML*(cos(dm));
   MY=midy+ML*(sin(dm));
  while(!kbhit())
  {
   grid(midx,midy,grad,gcolor);
   sline(midx,midy,SX,SY,bakcolor,bakcolor,degree,rad,SL);
   circle(SX,SY,2);
   hline(midx,midy,HX,HY,bakcolor,bakcolor,dh,rad,HL);
   mline(midx,midy,MX,MY,bakcolor,bakcolor,dm,rad,ML);
   gettime(&t);
   if(t.ti_sec==0)
   {
    gotoxy(44,4);
    printf("0 ");
   }
   gotoxy(35,4);
   printf("%d : %d : %d",t.ti_hour,t.ti_min,t.ti_sec);
   s=270+45+t.ti_sec*(180/60);
   h=270+45+t.ti_hour*(180/12)+((t.ti_min*(180/60)))/12;
   m=270+45+t.ti_min*(180/60)+((t.ti_sec*(180/60))/60);
   degree=((2*phi)/180)*s;
   dh=((2*phi)/180)*h;
   dm=((2*phi)/180)*m;
   SX=midx+SL*(cos(degree));
   SY=midy+SL*(sin(degree));
   HX=midx+HL*(cos(dh));
   HY=midy+HL*(sin(dh));
   MX=midx+ML*(cos(dm));
   MY=midy+ML*(sin(dm));

   sline(midx,midy,SX,SY,sincolor,soutcolor,degree,rad,SL);
   circle(SX,SY,2);
   hline(midx,midy,HX,HY,hincolor,houtcolor,dh,rad,HL);
   mline(midx,midy,MX,MY,mincolor,moutcolor,dm,rad,ML);
   delay(1000);
  }
 getch();
}

void sline(int midx,int midy,int SX,int SY,int incolor,int outcolor,float degree,int rad,int SL)
{
 int lx,ly,rx,ry,mx,my;
 float phi=3.1423;
 float width=0.04;
 lx=midx+(SL-10)*(cos(degree+width));
 ly=midy+(SL-10)*(sin(degree+width));
 rx=midx+(SL-10)*(cos(degree-width));
 ry=midy+(SL-10)*(sin(degree-width));
 mx=midx+(rad/2)*(cos(degree));
 my=midy+(rad/2)*(sin(degree));
 setcolor(outcolor);
 line(midx,midy,lx,ly);
 line(midx,midy,rx,ry);
 line(lx,ly,SX,SY);
 line(rx,ry,SX,SY);
 setfillstyle(1,incolor);
 floodfill(mx,my,outcolor);
}
void mline(int midx,int midy,int SX,int SY,int incolor,int outcolor,float degree,int rad,int ML)
{
 int lx,ly,rx,ry,mx,my;
 float phi=3.1423;
 float width=0.07;
 lx=midx+(ML-20)*(cos(degree+width));
 ly=midy+(ML-20)*(sin(degree+width));
 rx=midx+(ML-20)*(cos(degree-width));
 ry=midy+(ML-20)*(sin(degree-width));
 mx=midx+(rad/2)*(cos(degree));
 my=midy+(rad/2)*(sin(degree));
 setcolor(outcolor);
 line(midx,midy,lx,ly);
 line(midx,midy,rx,ry);
 line(lx,ly,SX,SY);
 line(rx,ry,SX,SY);
 setfillstyle(1,incolor);
 floodfill(mx,my,outcolor);
 line(midx,midy,SX,SY);
}
void hline(int midx,int midy,int SX,int SY,int incolor,int outcolor,float degree,int rad,int HL)
{
 int lx,ly,rx,ry,mx,my;
 float phi=3.1423;
 float width=0.155;
 lx=midx+(HL-30)*(cos(degree+width));
 ly=midy+(HL-30)*(sin(degree+width));
 rx=midx+(HL-30)*(cos(degree-width));
 ry=midy+(HL-30)*(sin(degree-width));
 mx=midx+(rad/2)*(cos(degree));
 my=midy+(rad/2)*(sin(degree));
 setcolor(outcolor);
 line(midx,midy,lx,ly);
 line(midx,midy,rx,ry);
 line(lx,ly,SX,SY);
 line(rx,ry,SX,SY);
 setfillstyle(1,incolor);
 floodfill(mx,my,outcolor);
 line(midx,midy,SX,SY);
}
void grid(int midx,int midy,int grad,int gcolor)
{
 for(int i=1;i<=grad;i++)
 {
 setcolor(gcolor);
 circle(midx-1,midy+1,i);
 }
 //setfillstyle(1,gcolor);
 //floodfill(midx,midy,15);
}
