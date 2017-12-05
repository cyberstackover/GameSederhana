#include<windows.h> //  header file for gotoxy
 #include <stdio.h>     //header file for standard input output

  COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left cornor of the screen
 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
  int main()
{

  //calling these function
  gotoxy(10,10);printf("This is demo of gotoxy function\n\n\n");

   return 0;
  }
