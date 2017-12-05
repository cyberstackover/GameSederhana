#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <time.h>

int color, maxcolor, x, y;
void *body;
void *headright;
void *headup;
void *telur;
int  posx[200],posy[200],panjang,markah,markaht,markahinc;
int a,size,d,telurx,telury,rawak;
char dir1,dir2;
int pix;

void goright(void);
void goleft(void);
void goup(void);
void godown(void);
void kesan(int,int);

void main()
{
markah=0;
printf("Push any key\n");
getch();
exit(1);
}

cleardevice();
setcolor(10);
outtextxy(50,150,"SELECT DIFFICULTY LEVEL");
outtextxy(470,450,"Programmer");
outtextxy(470,460,"Badrol Nizam Ibrahim");
setcolor(13);
outtextxy(50,170, "    1  E X P E R T");
outtextxy(50,190, "    2  N O R M A L "   );
outtextxy(50,210, "    3  E A S Y");
outtextxy(50,240, "    X  EXIT");
char lev;
level:
;
lev=getch();
if(lev==49){
d=50;markahinc=300;}
else
if (lev==50){
d=100;markahinc=150;}
else
if(lev==51){
d=300;markahinc=50;}
else
if(lev==120)
exit(1);
else
goto level;

cleardevice();

// draw body
setcolor(2);
setfillstyle(INTERLEAVE_FILL,2);
circle(10,10,10);
floodfill(10,10,2);
size=imagesize(0,0,20,20);
body=malloc(size);
getimage (0,0,20,20,body);
cleardevice();

//draw head
setcolor(3);
setfillstyle(INTERLEAVE_FILL,3);
fillellipse(10,10,10,10);       //head right/left
size=imagesize(0,0,20,20);
headright=malloc(size);
getimage(0,0,20,20,headright);
cleardevice();

fillellipse(10,10,10,10);       //head up/down
size=imagesize(0,0,20,20);
headup=malloc(size);
getimage(0,0,20,20,headup);
cleardevice();

//lukis telur ayam
setcolor (14);
setfillstyle(SOLID_FILL,14);
fillellipse(10,10,10,8);
size=imagesize(0,0,30,30);
telur=malloc(size);
getimage(0,0,30,30,telur);
cleardevice();

setfillstyle(SOLID_FILL,5);   //lukis sempadan
bar (0,0,getmaxx()-200,20);
bar (0,0,20,getmaxy());
bar (0,getmaxy()-20,getmaxx()-200,getmaxy());
bar (getmaxx()-220,0,getmaxx()-200,getmaxy());

randomize();
rawak=rand() % ((getmaxx()-260)/20);
telurx=rawak*20+20;
rawak=rand() % ((getmaxy()-60)/20);
telury=rawak*20+20;
putimage(telurx,telury,telur,XOR_PUT);


posx[1]=100;    //tempat permulaan
posy[1]=100;
putimage(posx[1],posy[1],headright,XOR_PUT);
for (a=2;a<=100;a++){
posx[a]=posx[a-1]-20;
posy[a]=posy[a-1];
}

panjang=6;
for(a=2;a<=panjang;a++){
putimage(posx[a],posy[a],body,XOR_PUT);
}


gotoxy(60,4);
//gunakan font lain
//settextstyle(SANS_SERIF_FONT,HORIZ_DIR,10);
//setusercharsize(6,1,6,1);
setcolor(12);
outtextxy(470,5,"Hi S C O R E");
outtextxy(470,50,"S C O R E");
outtextxy(470,100,"L E N G T H");
setcolor(6);
outtextxy(470,300,"PUSH  x  TO EXIT");
setcolor(8);
outtextxy(470,450,"Programmer");
outtextxy(470,460,"Badrol Nizam Ibrahim");
gotoxy(60,8);
printf("%i",panjang);
gotoxy(60,5);
puts("0");
gotoxy(60,2);
printf("%i",markaht);

goright();
}//end of main
//=====================lets the game begin===============================


//===============================jalan kanan=============================
void goright()
{
while (!kbhit()){
for (a=panjang;a>1;a--){
putimage(posx[a],posy[a],body,XOR_PUT); //padamkan badan asal
posx[a]=posx[a-1]; //badan ikut kepala
posy[a]=posy[a-1]; //
putimage(posx[a],posy[a],body,XOR_PUT); //letak badan baru
}

kesan(posx[1]+30,posy[1]+11);
putimage(posx[1],posy[1],headright,XOR_PUT);//padamkan kepala asal
posx[1]=posx[1]+20; //gerakkan ke kanan
putimage(posx[1],posy[1],headright,XOR_PUT);//letak kepala baru
delay(d);
}
dir1=getch();
if (dir1==120)
exit(1);
else
if (dir1==0)
dir2=getch();
else
goright();
if(dir2==72)
goup();
else
if(dir2==80)
godown();
else
goright();
}

//================================turun bawah==========================
void godown()
{
while (!kbhit()){
for (a=panjang;a>1;a--){
putimage(posx[a],posy[a],body,XOR_PUT);
posx[a]=posx[a-1];
posy[a]=posy[a-1];
putimage(posx[a],posy[a],body,XOR_PUT);
}

kesan(posx[1]+10,posy[1]+31);
putimage(posx[1],posy[1],headup,XOR_PUT);
posy[1]=posy[1]+20;
putimage(posx[1],posy[1],headup,XOR_PUT);
delay(d);
}
dir1=getch();
if (dir1==120)
exit(1);
else
if (dir1==0)
dir2=getch();
else
godown();
if(dir2==75)
goleft();
else
if(dir2==77)
goright();
else
godown();
}

//================================pergi kiri============================
void goleft()
{
while (!kbhit()){
for(a=panjang;a>1;a--){
putimage(posx[a],posy[a],body,XOR_PUT);
posx[a]=posx[a-1];
posy[a]=posy[a-1];
putimage(posx[a],posy[a],body,XOR_PUT);
}

kesan(posx[1]-10,posy[1]+11);
putimage(posx[1],posy[1],headright,XOR_PUT);
posx[1]=posx[1]-20;
putimage(posx[1],posy[1],headright,XOR_PUT);
delay(d);
}
dir1=getch();
if (dir1==120)
exit(1);
else
if (dir1==0)
dir2=getch();
else
goleft();
if(dir2==72)
goup();
else
if(dir2==80)
godown();
else
goleft();
}

//================================naik atas===============================
void goup()
{
while(!kbhit()){
for(a=panjang;a>1;a--){
putimage(posx[a],posy[a],body,XOR_PUT);
posx[a]=posx[a-1];
posy[a]=posy[a-1];
putimage(posx[a],posy[a],body,XOR_PUT);
}

kesan(posx[1]+10,posy[1]-11);
putimage(posx[1],posy[1],headright,XOR_PUT);
posy[1]=posy[1]-20;
putimage(posx[1],posy[1],headright,XOR_PUT);
delay(d);
}
dir1=getch();
if (dir1==120)
exit(1);
else
if (dir1==0)
dir2=getch();
else
goup();
if(dir2==77)
goright();
else
if(dir2==75)
goleft();
else
goup();
}

//============================kesan perlanggaran==========================
void kesan (int kesanx, int kesany)
{
pix=getpixel (kesanx,kesany);
if ((pix==2) || (pix==5)){
int c;
while(!kbhit()){
setcolor(c);
outtextxy(100,200,"< <   G A M E   O V E R   > >");
c++ ;
delay(100);
}
getch();
delay(1000);
main();
}

else
if (pix==14){
panjang++;
putimage(telurx,telury,telur,XOR_PUT);
rawak=rand()%((getmaxx()-260)/20);
telurx=rawak*20+20;
rawak=rand()%((getmaxy()-60)/20);
telury=rawak*20+20;
putimage(telurx,telury,telur,XOR_PUT);
markah=markah+markahinc;
if(markah>markaht){
markaht=markah;}
gotoxy(60,5);
printf("%i",markah);
gotoxy(60,2);
printf("%i",markaht);
gotoxy(60,8);
printf("%i",panjang);
}

}



