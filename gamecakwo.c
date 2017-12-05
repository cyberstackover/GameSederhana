/* DEKLARASI LIBRARY */
#include <stdio.h>
#include <windows.h>

/* DEKLARASI arah aktif asci */
#define ATAS 72
#define BAWAH 80
#define KIRI 75
#define KANAN 77

/* DEKLARASI FUNGSI & VARIABEL */
char key;
int  panjang;
int  bend_no;
int  len;
int  nyawa;
void Delay(long double);
void pindah();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Sirah();
void Boarder();
void Down();
void Left();
void Up();
void record();
void Right();
void ExitGame();
int Scoreonly();

struct kordinat{
    int x;
    int y;
    int arah;
};

typedef struct kordinat kordinat; //struct kordinat
kordinat head, bend[500],food,body[30]; // bend 500 & body 30

int main() //fungsi utama pemanggilan fungsi lain.
{
    MessageBox(NULL,"SELAMAT DATANG DI PERMAINAN D'CAKWO (DICAPLOK MAKIN DOWO)","GAME D'CAKWO ",MB_ICONINFORMATION | MB_OK);
    menu();
    char key; //navigasi
    panjang=0; //menetukan panjang tubuh pertama kali
    head.x=0; //titik x
    head.y=0; //titik y
    head.arah=ATAS; //start mulai arah kepala
    Boarder(); // batas area
    Food(); //inisialisasi makanan
    nyawa=11; // nyawa
    bend[0]=head; //
    pindah();   //insialisasi tekuk kordinat
    return 0; //akhiri game
}

int menu()
{
    char a;
    s:
    system("cls");
    printf("\n\n\n\t\t\t\tGAME D'CAKWO");
    printf("\n\n\n\n\n\t\t1. Start");
    printf("\n\n\n\t\t2. Cara bermain");
    printf("\n\n\n\t\t3. Keluar\n\n");
    printf ("\n\t\t4. Tentang kami\n\n");
    printf ("\n\t\t5. Lihat Skor");
    a=getch();
    switch(a)
    {
        case '1' :
        system("cls");
        break;
        case '2' :
        system("cls");
        printf("\n[+] INSTRUKSI PERMAINAN :\n");
        printf("\n-> GUNAKAN ARAH PADA KEYBOARD UNTUK MENGGERAKKAN KEPALA ULET.\n\n-> KAMU AKAN MENEMUKAN MAKANAN SI ULAT DAN AKAN MENDAPATKAN SCORE +1.\n\n-> DISINI KAMU MEMPUNYAI NYAWA 3x.\n\n-> KAMU DAPAT MENUNDA PERMAINAN DAN MELANJUTKANNYA KEMBALI\n\n-> KAMU DAPAT MENEKAN ESC UNTUK KELUAR DARI PERMAINAN \n");
        printf ("\n");
        system("pause");
        system("cls");
        goto s;
        break;
        case '3' :
        exit(0);
        break;
        case '4' :
        system("cls");
        printf("\n\n\t\t\tTeknik Komputer B");
        printf("\n\n\t\tPoliteknik Elektronika Negeri Surabaya");
        printf("\n\n\t\t=> Muhammad Herwindra B (2210121035)");
        printf("\n\n\t\t=> Agus Supriyanto (2210121043)");
        printf("\n\n\t\t=> Mahfud Ridho Pambudi (2210121047) \n");
        printf ("\n");
        system ("pause");
        system ("cls");
        goto s;
        break;
        case '5' :
        system("cls");
         printf("apakah anda ingin melihat skor, jika iya tekan 'y'\n");
         fopen("record.txt","r");
        system ("pause");
        system ("cls");
        goto s;
        break;
    }
}

void pindah() //navigasi berpindah
{
    int a,i;
    do{
        Food();
        fflush(stdin);
        len=0;
        for(i=0;i<30;i++)
        {
            body[i].x=0;
            body[i].y=0;
            if(i==panjang)
            break;
        }
        Delay(panjang);
        Boarder();
        if(head.arah==KANAN)
            Right();
        else if(head.arah==KIRI)
            Left();
        else if(head.arah==BAWAH)
            Down();
        else if(head.arah==ATAS)
            Up();
        ExitGame();
    }

    while(!kbhit());
    a=getch();
    if(a==27)
    {
        system("cls");
        exit(0);
    }
    key=getch();
    if((key==KANAN&&head.arah!=KIRI&&head.arah!=KANAN)||(key==KIRI&&head.arah!=KANAN&&head.arah!=KIRI)||
		(key==ATAS&&head.arah!=BAWAH&&head.arah!=ATAS)||(key==BAWAH&&head.arah!=ATAS&&head.arah!=BAWAH))
    {
        bend_no++;
        bend[bend_no]=head;
        head.arah=key;
        if(key==ATAS)
            head.y--;
        if(key==BAWAH)
            head.y++;
        if(key==KANAN)
            head.x++;
        if(key==KIRI)
            head.x--;
        pindah();
    }
    else if(key==27)
    {
        system("cls");
        exit(0);
    }
    else
    {
        printf("\a");
        pindah();
    }
}
void gotoxy(int x, int y) //koordinat function xy
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void GotoXY(int x, int y) //koordinat function XY
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}
void Up() //fungsi arah atas
{
    int i;
    for(i=0;i<=(bend[bend_no].y-head.y)&&len<panjang;i++)
    {
        GotoXY(head.x,head.y+i);
        {
            if(len==0)
                printf("^");
            else
                printf("@");
        }
        body[len].x=head.x;
        body[len].y=head.y+i;
        len++;
    }
    Sirah();
    if(!kbhit())
        head.y--;

}
void Down() //fungsi arah bawah
{
    int i;
    for(i=0;i<=(head.y-bend[bend_no].y)&&len<panjang;i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("V");

            else
                printf("@");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Sirah();
    if(!kbhit())
        head.y++;

}
void Left() //fungsi arah kiri
{
    int i;
    for(i=0;i<=(bend[bend_no].x-head.x)&&len<panjang;i++)
    {
        GotoXY((head.x+i),head.y);
       {
                if(len==0)
                    printf("<");
                else
                    printf("(");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Sirah();
    if(!kbhit())
        head.x--;
}
void Right() //fungsi arah kanan
{
    int i;
    for(i=0;i<=(head.x-bend[bend_no].x)&&len<panjang;i++)
    {
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf(")");
        }
        len++;
    }
    Sirah();
    if(!kbhit())
        head.x++;

}
void Delay(long double k) //fungsi delay
{
    Score();
    long double i;
    for(i=0;i<=(10000000);i++);
}
void ExitGame() //gameover
{
    int i,check=0;
    for(i=4;i<panjang;i++)   //dimulai dengan 4 karena membutuhkan minimal 4 elemen untuk menyentuh tubuhnya sendiri
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //nilai cek yang meningkat sebagai koordinat kepala sama dengan setiap koordinat tubuh lainnya
        }
        if(i==panjang||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0 ||(head.x==15&&(head.y>=20&&head.y<30))
    ||(head.x==20&&(head.y>=10&&head.y<20))||(head.x==25&&(head.y>=20&&head.y<30))
    ||(head.x==30&&(head.y>=10&&head.y<20))||(head.x==35&&(head.y>=20&&head.y<30))||(head.x==40&&(head.y>=10&&head.y<20))
    ||(head.x==45&&(head.y>=20&&head.y<30))||(head.x==50&&(head.y>=10&&head.y<20))||(head.x==55&&(head.y>=20&&head.y<30))
    ||(head.x==60&&(head.y>=10&&head.y<20))||(head.x==65&&(head.y>=20&&head.y<30))
    ||(head.y==15&&(head.x>=10&&head.x<12))||(head.y==15&&(head.x>=13&&head.x<15))
    ||(head.y==15&&(head.x>=35&&head.x<46))||(head.y==15&&(head.x>=65&&head.x<70)))

    {
        nyawa--;
        if(nyawa>=1) //KONDISI AWAL
        {
            head.x=13;
            head.y=25;
            bend_no=0;
            head.arah=KIRI;
            pindah();
        }
        else
        {

            MessageBox(NULL,"COBA LAGI YA, CEMUNGUT","GAME OVER ",MB_ICONINFORMATION | MB_OK);
            record();

            exit(0);
        }
    }
}
int Food() //inisialisasi makanan
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
void Sirah() //transisi arah
{
    int i,j,diff;
    for(i=bend_no;i>=0&&len<panjang;i--)
    {
            if(bend[i].x==bend[i-1].x)
            {
                diff=bend[i].y-bend[i-1].y;
                if(diff<0)
                    for(j=1;j<=(-diff);j++)
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y+j;
                        GotoXY(body[len].x,body[len].y);
                        printf("8");
                        len++;
                        if(len==panjang)
                            break;
                    }
                else if(diff>0)
                    for(j=1;j<=diff;j++)
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y-j;
                        GotoXY(body[len].x,body[len].y);
                        printf("8");
                        len++;
                        if(len==panjang)
                            break;
                    }
            }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1;j<=(-diff)&&len<panjang;j++)
                {
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                        printf("8");
                    len++;
                    if(len==panjang)
                            break;
                }
            else if(diff>0)
                for(j=1;j<=diff&&len<panjang;j++)
                {
                    body[len].x=bend[i].x-j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                        printf("8");
                    len++;
                    if(len==panjang)
                        break;
                }
        }
    }
}
void Boarder() //garis pembatas permainan
{
    system("cls"); //clear untuk gambar
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

void record(){
    char plname[20],nplname[20],cha,c;
    int i,j,px;
    FILE *info;
    info=fopen("skor.txt","a+");
    getch();
    system("cls");
    printf("Masukkan nama mu !!\n");
    scanf("%[^\n]",plname);

    for(j=0;plname[j]!='\0';j++){ //to convert the first letter after space to capital
    nplname[0]=toupper(plname[0]);
    if(plname[j-1]==' '){
    nplname[j]=toupper(plname[j]);
    nplname[j-1]=plname[j-1];}
    else nplname[j]=plname[j];
    }
    nplname[j]='\0';


    fprintf(info,"Nama Pemain :%s\n",nplname);
     //for date and time
  time_t mytime;
  mytime = time(NULL);
  fprintf(info,"Waktu Main:%s",ctime(&mytime));

      fprintf(info,"Skor:%d\n",px=Scoreonly());//call score to display score

    for(i=0;i<=50;i++)
    fprintf(info,"%c",'_');
    fprintf(info,"\n");
    fclose(info);
    printf("apakah anda ingin melihat skor, jika iya tekan 'y'\n");
    cha=getch();
    system("cls");
    if(cha=='y'){
    info=fopen("skor.txt","r");
    do{
        putchar(c=getc(info));
        }while(c!=EOF);}
      fclose(info);
}

int Score() //score permainan
{
    int score;
    GotoXY(10,32);
    printf ("^^^^^");
    GotoXY(10,33);
    printf ("start");
    GotoXY(25,5);
    printf ("GAME d'cakwo (gamenya anak POLOS)");
    GotoXY(20,8);
    score=panjang-1;
    printf("SCORE : %d",(panjang-1));
    score=panjang-1;
    GotoXY(50,8);
    printf("NYAWA : %d",nyawa);
    return score;
}

int Scoreonly()
{
int score=Score();
system("cls");
return score;
}
