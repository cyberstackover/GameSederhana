#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define MAX 10
int int_x=35, move, n, x, poin=0, bebek=0,j=0,play=1;
char navigasi;
COORD coord={0,0}; //tipe data coord yang diambil dari library windows.h
void about();
void petunjuk();
void awal();
void game();
void closing();

/*=================== Deklarasi Score Linked List =============*/

struct dtnilai
{
	int skor;
	char nama[20];
	int no;
	struct dtnilai *next;
};
struct dtnilai *tampung;
struct dtnilai *ujung;
struct dtnilai *first;

/*=================== Deklarasi Stack =============*/
struct tumpukkan
{   char isi[MAX];
    char nama[MAX];
    int atas;
};

struct tumpukkan t;
int top;
void inisialisasi()
{
    t.atas=0;
    top=0;
}
void push(char x)
{
    if (t.atas==MAX)
        printf("Tumpukkan sudah penuh");
    else
    {
        t.atas=top+1;
        t.isi[t.atas]=x;
        top=t.atas;
    }
}
void pop()
{
    if (top==0)
        printf("Tumpukkan sudah/masih kosong\n");
    else
    {
        printf("%c",t.isi[top]);
        t.atas=top-1;
        top=t.atas;
    }
}

/*=============================fungsi gotoxy pada library windows.h=====================================*/

void gotoxy(int x,int y)
{
   coord.X=x;
   coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/*=============================fungsi delay pada library time.h=====================================*/
 void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

/*=============================opening=====================================*/
void Opening()
{

     int a,ap,at;
     printf("\n\n\n\n\n\n\n\n\t\t\t\tloading = ");
     for(a=0; a<=100; a=a+10)
     {
       printf("%d", a);
       Sleep(100);
       if (a>=10)
          {
                 printf("\b");
                 printf("\b");
          }
       else
                printf("\b");
     }
     system("cls");
}

int main()
{
    	/*=========SALAM==============================================*/
	  system("cls");
	  printf("\n\n\n\n\n\n\n\n\t\t\t ");
       printf("\n\t\t\t %c=========================%c", 197,197);
       printf("\n\t\t\t %c Assalamu'alaikum Wr. Wb %c",179,179);
       printf("\n\t\t\t %c=========================%c", 197,197);
       getch();
       /*===========================================================*/
    system("cls");
    printf("\n\t   ==============================================");
    printf("\n\t   === Selamat Datang di Zona Game - Duck Gun ===");
    printf("\n\t   ==============================================");
    Opening();
    /*=================================================================*/
	awal();

}

void game() //pointer temporary
{
    int p;
	system("cls");
	gotoxy(35,20);printf("=*=");
	int_x=35;
	gotoxy(60,1);printf("Press ESC to exit");
	poin=0;
	bebek=0;
	/*=================== Deklarasi Score Linked List =============*/

		do{
		for(x=1; x<=75; x++)
		{
			delay(100); gotoxy(x-1,2);printf(" "); gotoxy(x,2);printf("S"); //spasi mengikuti S
			if(kbhit())
            {
            navigasi=getch();
            navigasi=getch();
			switch(navigasi) {
			case 77:if(int_x<=73) //kanan
					 {
						 int_x=int_x+1;move=1;
					 }
						break;
			case 75:if(int_x>=3) //kiri
					 {
						 int_x=int_x-1;move=1;
					 }
						break;
			case 27:x=76;navigasi='k';
						break;
			case 72: //atas

				for(n=19;n>0;n=n-1)
				{
					x++;
					gotoxy(x-1,2);printf(" ");
					gotoxy(x,2);printf("S");
					gotoxy(int_x+1,n);printf("%c",219);
					gotoxy(int_x+1,n+1);printf(" ");
					gotoxy(int_x+1,20);printf("*");
					delay(70);
					if(x==75)
					{
						x=1;
						bebek++;
						gotoxy(75,2);
						printf(" ");
					}
					if((x==int_x+1)&&(n==2))
					{
					    push('S');
						poin++;
						gotoxy(1,21);printf("poin : %d",poin);
						gotoxy(60,15);printf("Habiskan :P");
						delay(100);
						x=1;
					}
				}

				gotoxy(int_x+1,1);printf(" ");
				gotoxy(60,1);printf("Press ESC to exit");
				break;
			default:move=0;
				break;
			}
			}
			gotoxy(1,1);printf("Poin : %d",poin);
			gotoxy(1,3);printf(" ");
			gotoxy(15,20);printf(" ");
			gotoxy(1,20);printf("Sisa bebek : %d",bebek);
			if(bebek<0)
				bebek=0;
			if(x==75)
			{
				gotoxy(75,2);printf(" ");
			}
			if(move==1)
			{
				gotoxy(int_x-1,20);printf(" ");
				gotoxy(int_x+3,20);printf(" ");
				gotoxy(int_x,20);printf("=*=");
			}
		}
		bebek++;
		if(bebek>10)
		{
			gotoxy(25,25);
			printf("\n");
			for(p=0;p<poin;p++){
			pop();
			}
            if (j==0)
		    {
            system("cls");
            first=(struct dtnilai*)malloc(sizeof(struct dtnilai));
			first->skor = poin;
			first->no=play;
            printf("Nama	: ");gets(first->nama);
			tampung=first;
			tampung->next=NULL;
			}
			else {
            system("cls");
            ujung=(struct dtnilai*)malloc(sizeof(struct dtnilai));
            tampung->next=ujung;
            ujung->no = play;
			ujung->skor = poin;
			printf("Nama	: ");gets(ujung->nama);
			tampung=ujung;
            tampung->next=NULL;
			}
			j++;
			ujung=first;
			system("cls");
			printf("\t\t\tSCORE\n\n");
			while(ujung!=NULL)
            {
			printf("\t|%d.||%s\t|%d|\n",ujung->no,ujung->nama,ujung->skor);
			ujung=ujung->next;
            }
            play++;
            getch();
			closing();
            getch();
			awal();

		}
	}
	while (navigasi!='k');
	awal();
}

void awal()
{
	int a;
    system("cls");
	printf("\t\t\t===================================\n");
	printf("\t\t\t|     Pilih Menu                  |\n");
	printf("\t\t\t|          1. New Game            |\n");
	printf("\t\t\t|          2. Petunjuk Permainan  |\n");
	printf("\t\t\t|          3. About               |\n");
	printf("\t\t\t|          4. Exit                |\n");
	printf("\t\t\t===================================\n");

	a=getch();
	switch(a)
	{
	case '1': game();
		break;
	case '2': petunjuk();
		break;
	case '3': about();
		break;
	case '4': exit(1);
		break;
	default : printf("\nPilih angka 1-4!");
		getch();
		break;
	}
}

void petunjuk()
{
	system("cls");
	printf("========================\n");
	printf("===Petunjuk Permainan===\n");
	printf("========================\n");
	printf("\t1)Tembaklah bebek yang dilambangkan dengan huruf 'S'\n");
	printf("\n\t2)sedemikian hingga peluru mengenai bebek tersebut.\n");
	printf("\n\t3)Terdapat 10 bebek yang melewati medan tembak.\n");
	printf("\n\t4)Yang mampu menembak bebek dengan tepat dan poin terbanyak\n");
    printf("\n\tDialah yang menjadi pemenang.\n");
	printf("\n\t5)Tiap poin tersebut akan di push pada tumpukan.\n");
	printf("\n\tJika penembak mampu menembak sampai mengenai 10 bebek\n");
	printf("\n\tMaka tumpukan akan penuh\n");
	printf("\n");
	printf("\n\t===Keyboard controler====\n");
	printf("\t|   Kanan : ->            |\n");
	printf("\t|   Kiri : <-             |\n");
	printf("\t|   Tembak : panah atas   |\n");
	printf("\t==========================\n");
	printf("\n\nPress enter to back menu ...");
	getch();
	awal();
}

void about()
{
	system("cls");
	printf("\t\t=========Programmed by=========\n");
	printf("\t\t| 1. Farah Devi Isnanda (33)   |\n");
	printf("\t\t| 2. Havidz Asmanda P   (44)   |\n");
	printf("\t\t| 3. Choirul Umam       (46)   |\n");
	printf("\t\t====Teknik Komputer B 2012=====\n");
	printf("\n\nPress enter to back menu .....");
	getch();
	awal();
}


void closing(){
    delay(1000);
    system("cls");
    gotoxy(10,20);
    printf("\n\n\t\tPoin yang anda dapatkan : %d",poin);
    printf("\n\t-----Terima Kasih Telah Mencoba Program Game Ini------");
    getch();
    awal();

}
