#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct kotak
{
    int indeks;
    char sampah;
    struct kotak *prev;
    struct kotak *next;
};
int score;
void menu()
{
    char a;
    s:
    system("cls");
    printf("\n\n\n\t\t\t\tGAME GO GREEN");
    printf("\n\n\n\n\n\t\t1. Start");
    printf("\n\n\n\t\t2. Cara bermain");
    printf("\n\n\n\t\t3. Keluar\n\n");
    a=getch();
    switch(a)
    {
        case '1' :
        break;
        case '2' :
        system("cls");
        printf("\n\t1.Jalankan pointer G untuk membersihkan sampah");
        printf("\n\t2.Setiap sampah yang dibersihkan akan mendapatkan poin 10");
        printf("\n\t3.Hati - hati terhadap pagar (|) karena jika menabrak game berakhir");
        printf("\n\t4.Game akan selesai jika berhenti pada simbol finish (F)\n\n");
        system("pause");
        system("cls");
        goto s;
        break;
        case '3' :
        exit(0);
        break;
    }
}
void level(int z[22],int y[30])
{
    struct kotak *tampung, *ujung, *awal;
    int j,i,k,indeks=0,m;
    char r,l;
  for(i=0;i<100;i++)
    {
        if (i==0)
            {awal=(struct kotak*)malloc(sizeof(struct kotak));
           	awal->indeks = i;
           	awal->sampah = 'G';
            awal->prev=NULL;
            awal->next=NULL;
            tampung=awal;
            }
            else if(i==z[0]||i==z[1]||i==z[2]||i==z[3]||i==z[4]||i==z[5]||i==z[6]||
                    i==z[7]||i==z[8]||i==z[9]||i==z[10]||i==z[11]||i==z[12]||i==z[13]||
                    i==z[14]||i==z[15]||i==z[16]||i==z[17]||i==z[18]||i==z[19]||i==z[20]||
                    i==z[21]||i==z[22])
            {   ujung=(struct kotak*)malloc(sizeof(struct kotak));
            	ujung->indeks = i;
            	ujung->sampah ='*';
                ujung->prev=tampung;
                ujung->next=NULL;
                tampung->next=ujung;
                tampung=ujung;
            }
           else if(i==y[0]||i==y[1]||i==y[2]||i==y[3]||i==y[4]||i==y[5]||i==y[6]||i==y[7]||
                    i==y[8]||i==y[9]||i==y[10]||i==y[11]||i==y[12]||i==y[13]||i==y[14]||i==y[15]||
                    i==y[16]||i==y[17]||i==y[18]||i==y[19]||i==y[20]||i==y[21]||i==y[22]||i==y[23]||
                    i==y[24]||i==y[25]||i==y[26]||i==y[27])
            {   ujung=(struct kotak*)malloc(sizeof(struct kotak));
            	ujung->indeks = i;
            	ujung->sampah ='|';
                ujung->prev=tampung;
                ujung->next=NULL;
                tampung->next=ujung;
                tampung=ujung;
            }
             else if(i==99)
            {   ujung=(struct kotak*)malloc(sizeof(struct kotak));
            	ujung->indeks = i;
            	ujung->sampah ='F';
                ujung->prev=tampung;
                ujung->next=NULL;
                tampung->next=ujung;
                tampung=ujung;
            }
             else
            {   ujung=(struct kotak*)malloc(sizeof(struct kotak));
            	ujung->indeks = i;
            	ujung->sampah =' ';
                ujung->prev=tampung;
                ujung->next=NULL;
                tampung->next=ujung;
                tampung=ujung;
            }

}
system("cls");
printf("---------------------GAME GO GREEN-------------------\n");
printf("-----------------------------------------------------\n");
ujung=awal;
m=0;
for(k=0;k<10;k++){
for(j=0;j<10;j++){
printf("%5c",ujung->sampah);
ujung=ujung->next;
}
printf("\n\n");
}
printf("-----------------------------------------------------\n");
printf(" Gunakan arah atas, bawah, kanan dan kiri untuk menggerakkan: ");
ujung = awal;
printf("\n");
while(ujung->next!=NULL){
l=getch();
if(l==77){
if(ujung->next->sampah=='*')
score+=10;
else if(ujung->next->sampah=='|'){
system("cls");
printf("\t\t\t\n\n\nGAME OVER\n\n");
ujung = awal;
printf("SCORE = %d",score);
break;
}
ujung->sampah=' ';
ujung=ujung->next;
ujung->sampah='G';
system("cls");
ujung = awal;
for(k=0;k<10;k++){
for(j=0;j<10;j++){
printf("%5c",ujung->sampah);
ujung=ujung->next;
}
printf("\n\n");
}
ujung = awal;
m++;
while(ujung->indeks!=m)
ujung=ujung->next;
}
else if(l==75){
if(ujung->prev->sampah=='*')
score+=10;
else if(ujung->prev->sampah=='|'){
system("cls");
printf("\t\t\t\n\n\nGAME OVER\n\n");
printf("SCORE = %d",score);
break;
}
if(ujung->prev==NULL)
break;
ujung->sampah=' ';
ujung=ujung->prev;
ujung->sampah='G';
system("cls");
ujung = awal;
for(k=0;k<10;k++){
for(j=0;j<10;j++){
printf("%5c",ujung->sampah);
ujung=ujung->next;
}
printf("\n\n");
}
ujung = awal;
m--;
while(ujung->indeks!=m)
ujung=ujung->next;
}
else if(l==72){
if(ujung->prev==NULL)
break;
ujung->sampah=' ';
m=m-10;
while(ujung->indeks!=m)
ujung=ujung->prev;
if(ujung->sampah=='*')
score+=10;
else if(ujung->sampah=='|'){
system("cls");
printf("\t\t\t\n\n\nGAME OVER\n\n");
printf("SCORE = %d",score);
break;
}
ujung->sampah='G';
system("cls");
ujung = awal;
for(k=0;k<10;k++){
for(j=0;j<10;j++){
printf("%5c",ujung->sampah);
ujung=ujung->next;
}
printf("\n\n");
}
ujung = awal;
while(ujung->indeks!=m)
ujung=ujung->next;
}
else if(l==80){
ujung->sampah=' ';
m=m+10;
while(ujung->indeks!=m)
ujung=ujung->next;
if(ujung->sampah=='*')
score+=10;
else if(ujung->sampah=='|'){
system("cls");
printf("\t\t\t\n\n\nGAME OVER\n\n");
printf("SCORE = %d",score);
break;
}
ujung->sampah='G';
system("cls");
ujung = awal;
for(k=0;k<10;k++){
for(j=0;j<10;j++){
printf("%5c",ujung->sampah);
ujung=ujung->next;
}
printf("\n\n");
}
ujung = awal;
while(ujung->indeks!=m)
ujung=ujung->next;
}
printf("score = %d",score);
}
}
void main()
{
    static int p[30]={2,7,24,29,31,36,44,46,49,52,58,63,64,70,77,79,81,84,90,92,94,96,98};
    static int t[22]={5,8,13,18,23,27,33,34,40,45,47,51,59,65,78,83,85,93,97};
    static int p2[30]={3,6,9,12,15,20,22,28,30,32,34,36,44,48,51,53,58,65,67,72,75,79,85,87,92,98};
    static int t2[22]={2,8,11,14,17,29,31,35,44,48,52,55,59,63,66,73,74,78,82,86,91};
    char answer;
    main:
    menu();
    level(t,p);
printf("\nApakah anda ingin main lanjut level 2 ?(Y/T) ");
scanf("%s",&answer);
if(answer == 'Y'||answer == 'y'){
level(t2,p2);
}
else if (answer=='T'||answer=='t'){
score = 0;
goto main;
}
system("pause");
score = 0;
goto main;
}
