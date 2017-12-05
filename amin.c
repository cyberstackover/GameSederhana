#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
////////////////////////////////////////////////// Variabel Global ///////////////////////////////////////////////////////
struct name
{
    int nilai,a[6];
    char nama[20];
    struct name *next;
};
//////////////////////////////////////////////// 4.Tentang Kami ////////////////////////////////////////////////////////
void buat()
{
    system("cls");
    printf("\n\n\n\t\t*****============================*****");
    printf("\n\n\t\t\tGame Ini Asli Buatan");
    printf("\n\n\t\t\tTeknik Komputer B");
    printf("\n\n\t\tPoliteknik Elektronika Negeri Surabaya");
    printf("\n\n\t\t=> Abd Muhaimin(2210121049)");
    printf("\n\n\t\t=> Anang Habibi(2210121037)");
    printf("\n\n\t\t=> Moh.Ismi Musyafani(2210121054) \n");
    printf("\n\t\t*****============================*****");
    printf("\n\n\t\tTekan M untuk kembali ke menu dan X untuk keluar.= ");
    back();
}
/////////////////////////////////
int yes()
{
int k=0;
char answer[3];
scanf("%s",&answer);
if ((strcmp(answer,"M")==0 || strcmp(answer,"m")==0))
{
k=1;
}
else{
printf("\n\n\t\tPilih (M/T/K) = ");
k=yes();}
return(k);
}
//////////////////////////////////////////////// 2.Cara Main ////////////////////////////////////////////////////////
void ayo(){
system("cls");
printf("\n  *****===================================================================*****");
printf("\n  Bagaimana Cara Bermainnya :");
printf("\n\n\t1.Utamakan membaca doa terlebih dahulu.\n\n\tFokuskan pikiran anda dan pandangan anda\n\n\t2.Perhatikan Angka Yang akan muncul.\n\n\tAngka akan muncul secara berkedip atau bergiliran kemudian menghilang.\n\n\t3.Setelah itu akan muncul pertanyaan.\n\n\t4.Anda diharuskan untuk menebak pertanyaan tersebut.\n\n\tJika benar skor akan bertambah 20 dan jika salah skor akan berkurang 20.\n\n\t5.Selamat Mencoba ^^.");
printf("\n  *****===================================================================*****");
printf("\n\t\tTekan M untuk kembali ke menu dan X untuk keluar.= ");
back();
}
////////////////////////////////////////////////// Kembali ke Menu //////////////////////////////////////////////
void back(){
char y[2];
    scanf("%s",&y);
    if((strcmp(y,"M")==0) || (strcmp(y,"m")==0)) {system("cls"); menu();}
    else if((strcmp(y,"X")==0) || (strcmp(y,"x")==0)){
    exit(0);}
    else
    exit(0);
}
//////////////////////////////////////////////////// Menu ///////////////////////////////////////////////////////////////
void menu ()
{
    int x;
    printf("\n\n\n\n\n\n\t\t*****============================*****");
    printf("\n\n\t\t  1. Mulai ");
    printf("\n\n\t\t\t  2. Cara Main ");
    printf("\n\n\t\t\t\t  3. Tentang Kami ");
    printf("\n\n\t\t\t\t\t   4. keluar \n");
    printf("\n\t\t*****============================*****");
    printf("\n\n\t\tPilih = ");
    scanf("%d",&x);
    if(x==1) {printf(" ");}
    else if(x==2)  {ayo();}
    else if(x==3)  {buat();}
    else if(x==4)  {exit(0);}
    else
    exit;

}
//////////////////////////////////////////////// Tampilkan Data ////////////////////////////////////////////////////////
void tamda(struct name *ujung,struct name *awal)
{
    struct name *p1 , *p2;
    int i,temp,j=0;
    char tn[10];
    p1 = awal;
    p2 = p1->next;
    while(p1!=NULL){
    while(p2!=NULL){
    if((p1->nilai)<(p2->nilai)){
    temp = p1->nilai;
    strcpy(tn,p1->nama);
    p1->nilai = p2->nilai;
    strcpy(p1->nama,p2->nama);
    p2->nilai = temp;
    strcpy(p2->nama,tn);
    }
    p2=p2->next;
    }
    if(p1->next==NULL)
    break;
    p1=p1->next;
    p2=p1->next;
    }
    ujung=awal;
    system("cls");
    printf("\n\n***=Nama Pemain=======Jumlah Skor=***\n");
    ujung=awal;
    while(ujung!=NULL)
    {
    printf("%10s%18d\t\n",ujung->nama,ujung->nilai);
    ujung=ujung->next;
    }
    printf("***===============================***\n");

}
//////////////////////////////////////////////// Loading ////////////////////////////////////////////////////////
void loading()
{
int i,k;
double j;
char dot[4] = {'.','.','.'};
char ling[5] = {' ','|','_','|'};
printf("\n\n\t\t\tTunggu Bos");
for(i=0;i<3;i++)
{
    printf("%c",dot[i]);
    for(j=0;j<21911119;j++);
}
system("cls");
for(k=0;k<3;k++){
printf("\n\n\t\t\tTunggu Bos...");
printf("\n");
printf("\t\t\t     _");
printf("\n\t\t\t");
for(i=0;i<4;i++)
{
    printf(" %c",ling[i]);
    for(j=0;j<21911119;j++);
}
system("cls");
}
}
//////////////////////////////////////////////// SKOr ////////////////////////////////////////////////////////
int tambah(int skor)
{
    skor=skor+20;
    return (skor);
}

int kurang(int skor)
{
    skor=skor-20;
    return (skor);
}
//////////////////////////////////////////////// Delay ////////////////////////////////////////////////////////
void delay(char n)
{
    int i;double j;
    if(n=='L')
    {
    j=99999999;
    for(i=0;i<j; i++){}
    system("cls");
    }
    else if(n=='M')
    {
    j=21911119;
    for(i=0;i<j; i++){}
    system("cls");
    }
    else if(n=='H')
    {
    j=111111;
    for(i=0;i<j; i++){}
    system("cls");
    }

}
//////////////////////////////////////////////// Program Utama ////////////////////////////////////////////////////////
void main ()
{
    struct name *tampung;
    struct name *awal;
    struct name *ujung;
    int j=0;char s='H',temp[20],answer[3];
    int jawab,i,skor = 0,angka,n=0,score=0;
    static int soal[6]={1311133,27127117,62972782,79691797,79697797};
    loading();
    menu();
while (1)
{
    system("cls");
    if(j==0)
    {
        if(n>4)
        n=0;
        if(n==0){
        printf("\n\t\tMasukkan Nama Anda :  ");
        scanf("%s",&temp);
        system("cls");
        printf("\n\t*******======================================================*******");
        printf("\n\tSelamat Datang |%s| ^_^-<Selamat Mencoba Dan Semoga Berhasil *_^9",temp);
        printf("\n\t*******======================================================*******\n\t\t\t");
        system("pause");
        awal = (struct name*)malloc(sizeof(struct name));
        awal->next = NULL;
        tampung = awal;
        }
        strcpy(awal->nama,temp);
        awal->a[n] = soal[n];angka=awal->a[n];
        n++;
    }
    else
    {
        if(n>4){
        n=0;
        }
        if(n==0){
        score=0;
        ujung = (struct name*)malloc(sizeof(struct name));
        printf("\n\t\tMasukkan Nama Anda :  ");
        scanf("%s",&temp);
        system("cls");
        printf("\n\t*******======================================================*******");
        printf("\n\tSelamat Datang |%s| ^_^-<Selamat Mencoba Dan Semoga Berhasil *_^9",temp);
        printf("\n\t*******======================================================*******\n\t\t\t");
        system("pause");
        tampung->next=ujung;
        ujung->next = NULL;
        tampung = ujung;
        }
        ujung->a[n] = soal[n];
        angka=ujung->a[n];
        strcpy(ujung->nama,temp);
        n++;

    }

for(i=0;i<9;i++){
printf("\t\t\t\t Lihat Angka \t%d\n",angka);
system("cls");
delay(s);
}

if (n==0)
printf("\n\n\t\tBerapakah angka 3 nya ?");
else if(n==1){
s='H';
printf("\n\n\t\tBerapakah angka 1 nya ?");
}
else if(n==2){
s='M';
printf("\n\n\t\tBerapakah angka 2 nya ?");
}
else if(n==3){
s='M';
printf("\n\n\t\tBerapakah angka 7 nya ?");
}
else if(n==4){
s='L';
printf("\n\n\t\tBerapakah angka 9 nya ?");}
else if(n==5){
s='H';
printf("\n\n\t\tBerapakah angka 9 nya ?");}

scanf("%d",&jawab);
if(jawab == 3){
system("cls");
printf("\n\t\tJawaban Benar !! Skor Anda Bertambah %d",tambah(skor));
score+=tambah(skor);
printf("\n\t\tTotal Skor Anda %d\n\t\t",score);
system("pause");
if(j==0)
awal->nilai=score;
else
ujung->nilai=score;
}
else{
system("cls");
printf("\n\t\tJawaban Salah !! Skor Anda Berkurang %d\n\t\t",tambah(skor));
score+=kurang(skor);
printf("\n\t\tTotal Skor Anda %d\n\t\t",score);
system("pause");
if(j==0)
awal->nilai=score;
else
ujung->nilai=score;
}
if(n>4){
system("cls");
printf("\n\n\n\n\n\n\t\t*****============================*****");
printf("\n\n\t\t  (M). Mulai Lagi ");
printf("\n\n\t\t\t  (T). Daftar Pemain ");
printf("\n\n\t\t\t\t   (K). Keluar ");
printf("\n\t\t*****============================*****");
printf("\n\n\t\tPilih (M/T/K) = ");
scanf("%s",&answer);
if ((strcmp(answer,"M")==0 || strcmp(answer,"m")==0))
{
j++;
continue;
}
else if ((strcmp(answer,"T")==0 || strcmp(answer,"t")==0))
break;
else {
j=yes();
}
}
else
continue;
}//end of while
tamda(ujung,awal);
}
