/* DEKLARASI LIBRARY */
#include <stdio.h>
#include <windows.h>

/* DEKLARASI arah aktif asci */
#define ATAS 72
#define BAWAH 80
#define KIRI 75
#define KANAN 77



void Boarder();

struct kordinat{
    int x;
    int y;
    int arah;
};

typedef struct kordinat kordinat;
kordinat head, bend[500],food,body[30]; // bend 500 & body 30

int main()
{
    MessageBox(NULL,"SELAMAT DATANG DI PERMAINAN D'CAKWO (DICAPLOK MAKIN DOWO) lihat instruksi berikut","GAME D'CAKWO ",MB_ICONINFORMATION | MB_OK);
    Boarder(); // batas area
    return 0;
}

void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }


int Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        panjang++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
    else if(food.x==0)/* untuk membuat makanan untuk pertama kalinya coz variabel global diinisialisasi dengan 0 */
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }

}

void Boarder() //garis pembatas permainan
{
    system("cls"); //clear
    int i;
    GotoXY(food.x,food.y);   /*menampilkan makanan*/
        printf("\3");
    for(i=10;i<71;i++)
    {
        GotoXY(i,10);
        printf("#"); //atas
        GotoXY(i,30);
            printf("#"); //bawah
    }
    for(i=10;i<31;i++)
    {
        GotoXY(10,i);
            printf("#"); //kiri
        GotoXY(70,i);
            printf("#"); //kanan
    }
    for (i=20;i<30;i++){ //15&28
        GotoXY (15,i);
        printf("#");
    }
    for (i=10;i<15;i++){ // GARIS VERTICAL
        GotoXY (i,15);
        if (i==12)
        printf(" ");  //BOLONG
        else
        printf("#");
    }
        for (i=65;i<70;i++){ // GARIS VERTICAL
        GotoXY (i,15);
        printf("#");
    }

    for (i=35;i<46;i++){ // GARIS VERTICAL
        GotoXY (i,15);
        printf("#");
    }
  for (i=10;i<20;i++){ //15&28
        GotoXY (20,i);
        printf("#");
    }

    for (i=20;i<30;i++){ //15&28
        GotoXY (25,i);
        printf("#");
    }
    for (i=10;i<20;i++){ //15&28
        GotoXY (30,i);
        printf("#");
    }
    for (i=20;i<30;i++){ //15&28
        GotoXY (35,i);
        printf("#");
    }
    for (i=10;i<20;i++){ //15&28
        GotoXY (40,i);
        printf("#");
    }
    for (i=20;i<30;i++){ //15&28
        GotoXY (45,i);
        printf("#");
    }
    for (i=10;i<20;i++){ //15&28
        GotoXY (50,i);
        printf("#");
    }
    for (i=20;i<30;i++){ //15&28
        GotoXY (55,i);
        printf("#");
    }
    for (i=10;i<20;i++){ //15&28
        GotoXY (60,i);
        printf("#");
    }
    for (i=20;i<30;i++){ //15&28
        GotoXY (65,i);
        printf("#");
    }

}
