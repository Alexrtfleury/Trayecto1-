// Pantalla colores
#include <stdio.h> // para el printf, scanf

#include <conio.h> // para el getch
#include <windows.h> // para el system y Sleep
int main()
{
int c=1;
printf("\n\nesto de aprender C++ esta facil");
printf("\nsi quiero... puedo, sino quiero... no puedo ;)\n\n\n");
system ("pause");
printf("\n\n\n ***** FELICITACIONES... ya comenzaste *****\n\n");
do{
system("color 2c");Sleep(400);
system("color 6c");Sleep(400);
system("color 5c");Sleep(400);
system("color 70");Sleep(400);
printf("\n\t\t 000000____000000");
printf("\n\t\t 00000000_000000000");
printf("\n\t\t 0000000000000000");
printf("\n\t\t  00000000000000");
printf("\n\t\t   0000000000");
printf("\n\t\t    000000");
printf("\n\t\t      00");
system("color c3");Sleep(400);
printf("\n\t\t  yyyyyy___yyyyy *");
printf("\n\t\t yyyyyyyy_yyyyyyy *");
printf("\n\t\t yyyyyyyyyyyyyyyy *");
printf("\n\t\t  yyyyyyyyyyyyyy *");
printf("\n\t\t   00000000000 *");
printf("\n\t\t     00000 *");
printf("\n\t\t       0 *");
system("color 7c");Sleep(400);
printf("\n\t\t *   000000___00000");
printf("\n\t\t *  00000000_0000000");
printf("\n\t\t *  0000000000000000");
printf("\n\t\t *   00000000000000");
printf("\n\t\t *    0000000000");
printf("\n\t\t *      00000");
printf("\n\t\t *        0");
printf("\n\t\t * *");
printf("\n\t\t * *\n\n");

c=c+1;
}while(c<=8);
}