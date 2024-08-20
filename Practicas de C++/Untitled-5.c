#include <stdio.h>
#include <stdlib.h>                             
 struct estructura_IVSS {
	char Apellido[10];
    int opc;
    int opc2;
    int codigo;
    int clave;
    int valida = 12345;
    char buscar[9];
    int encontrado;

int e; //variable para validar tres intentos de clave
bool flag; //bandera que indica si ingreso la clave correctamente.

//Variables del Struct
struct datos {
    
    char Serial[15];
    char N/Bien[15];
    char Marca[15];
    char Modelo[15];
    char Ram[15];
    char Procesador[15];
    char Monitor[15];
    char Sistema/operativo[15];
    char N/Equipo[20];

}PC;

    time_t tiempo=time(0);
   struct tm *tlocal = localtime(&tiempo);


void validador(int);
void menu();
void registrar();
void consultar();
void marco();
void modificar();
void eliminar();
void creditos();
void salir();
void inventarioGen();
void logo();
FILE* datosPC;

//FILE* ptauxiliar;

//Bienvenida al usuario
main()
{
system("COLOR B0");
Sleep(200);

    printf("********************************************************************************");Sleep(300);
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("                                                                                ");
      gotoxy(19,3);
       printf("Rep\243blica Bolivariana de Venezuela\n");Sleep(300);
      gotoxy(10,4);
       printf("Ministerio del Poder Popular para la Educaci\242n Universitaria");Sleep(300);
      gotoxy(20,5);
       printf("Colegio Universitario de Caracas");Sleep(300);
      gotoxy(15,6);
       printf("Programa Nacional de Formaci\242n en Inform\240tica\n");Sleep(300);
      gotoxy(30,8);
        printf("BIENVENIDOS");Sleep(300);
      gotoxy(15,10);
        printf("SISTEMA CREADO PARA EL INVENTARIADO DE EQUIPOS DEL IVSS ");Sleep(300);
      gotoxy(15,11);
        printf("POR FAVOR INGRESE CLAVE PARA ACCEDER AL SISTEMA");Sleep(300);

   logo();
   gotoxy(30,14);
      printf("CLAVE:");Sleep(300);
    scanf("%d",&clave);
   //validador(clave);
   
      do{
       if (clave == valida)//CLAVE DE ACCESO 12345
        {
      system("cls");
        printf("                                                                                ");
        printf("                           ********************                                 ");
        printf("                           *  CLAVE CORRECTA  *                                 ");
        printf("                           ********************                                 ");
        printf("                                                                                ");
        printf("                     COLEGIO UNIVERSITARIO DE CARACAS                           ");
        printf("                                                                                ");

        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
        printf("********************************************************************************");
        printf("********************************************************************************");
      system("pause");
      flag = true;
      //menu();
      }else{

         if(e != 3){
          system("cls");
         gotoxy(30, 9);
           printf("********************");
         gotoxy(30,10);
           printf("* CLAVE INCORRECTA *");
         gotoxy(30,11);
           printf("********************");
         gotoxy(23,16);
           printf("POR FAVOR INGRESE NUEVAMENTE LA CLAVE:");
           scanf("%d",&clave);
         flag = false;
         e++;
         //validador(clave);
         }else{
            system("cls");

         gotoxy(30, 9);
           printf("********************");
         gotoxy(30,10);
           printf("* CLAVE INCORRECTA *");
         gotoxy(30,11);
           printf("********************");
         gotoxy(17,16);
           printf("error en clave comuniquese con el administrador\n");
         gotoxy(17,30);
            system("pause");
          exit(0);
         }
      }
      }while(flag == false);

      system("cls");
      gotoxy(4, 7);
      printf("Ingresar Nombre de Usuario: ");
      scanf("%s",&Nombre);
      gotoxy(4, 9);
      printf("Ingresar Apellido de Usuario: ");
      scanf("%s",&Apellido);


    do
        {
       system("cls");
        system("COLOR B0");
        printf("********************************************************************************");//Sleep(300);
        printf("                                                USUARIO: %s %s")//9,Nombre,Apellido);
        printf("\n");
        printf("\t\t\tCONTROL DE INVENTARIO DE EQUIPOS\n\n\n");
        printf("ELIJA UNA OPCI\340N:\n\n");
        printf("\t1.INGRESAR DATOS DE UN EQUIPO.\n");
        printf("\t2.CONSULTAR DATOS DE UN EQUIPO.\n");
        printf("\t3.ELIMINAR UN REGISTRO DEL INVENTARIO\n");
        printf("\t4.MODIFICAR DATOS DE REGISTRO DE UN EQUIPO.\n");
        printf("\t5.VER REPORTES DE INVENTARIO.\n");
        printf("\t6.CR\220DITOS DEL PROGRAMA.\n");
        printf("\t7.AYUDA AL USUARIO.\n\n");
        printf("\t8.SALIR.\n\n");
        printf("OPCI\340N:");
        scanf("%d",&opc);

        system("cls");
        switch (opc)
        {

            case 1:        /*Ingresar un equipo al registro de inventario*/
               registrar();
            break;

            case 2:        /*Buscar y mostrar un determinado equipo por numero de bien*/
               consultar();
            break;

            case 3:        /*Editar para modificar un Registro de inventario*/
            eliminar ();
            break;

            case 4:        /*Funcion para eliminar un Registro del inventario*/
            modificar();
            break;

            case 5:        /*Mostrando los equipos que han sido registrados hasta el momento*/
                 inventarioGen();
            break;

            case 6:        /*Creditos mas los agradecimientos*/
            creditos();
            system ("pause");
            break;

            case 7:        /*Asistencia al usuario*/
            printf("\tAsistencia al usuario\n");
            system ("pause");
            break;

            case 8:        /*Mensaje de Despedida*/
            salir();

            system ("pause");
            break;

            default:    /*En caso de que el usuario haya pulsado una opcion fuera del menu*/
            printf ("Opcion invalida!\n");
            system ("pause");
            break;
        }
    }while(opc != 8);

}
}	Equipo;
      
  
int main()
{
 
   char opc;   
   char Serial;
   int Bandera;
   Bandera=0;
       FILE *archivo;         
                  
       
       archivo = fopen("Inventario IVSS.txt","r");
       if (archivo == NULL){ 
           printf("\n  Error de apertura del archivo. \n\n");
           	exit( 1 );
          
           }
       else {                   
            while (feof(archivo) == 0){	
            fflush(stdin);
	        printf("\n\250Desea ingresar datos continuar? (s/n): ");
	        scanf("%c",&opc); 
		  		if (opc == 's' || opc == 'S'){
			     	printf( "\n   Serial \t" );
				scanf( "%s",Serial );		
				  	
		  		 system("cls");
			   
			   
				 fscanf(archivo,"%30s %30s %11s %3s\n",Equipo.Marca,Equipo.Modelo,Equipo.Serial,Equipo.Caracteristicas);
				// printf( "\n %d\t  %d",personal.Serial,Serial);
				 
				 if (Equipo== Equipo.Serial) 
				 {
				  
				  printf( "\n\n El valor ya exite \t" );
				 			  
				   Bandera=0;
				 } 
				 else
				  {
				  
				  Bandera=1;
		          
				 }	
				 if (Bandera==1){
				 
				 printf( "\n Equipo : \t" );
			     scanf( "%s",Equipo.Serial );
			   	 printf( "\n Marca : \t" );
		   		 scanf( "%s",Equipo.Marca );
    	    	 printf( "\n Modelo :\t " );
        	     scanf( "%s",Equipo.Modelo );
            	 printf( "\n Serial : \t " );
       		     scanf( "%s",Equipo.Nombre); 
       		     printf( "\n Caracteristicas : \t " );
       		     scanf( "%s",Equipo.Caracteristicas);                   
				 fflush(stdin);
		     	   
				 fprintf(archivo," %15s %30s %30s %11s %200s\n",Equipo.Nombre,Equipo.Modelo,Equipo.Marca,Equipo.Serial,Equipo.Caracteristicas); 	   
			       
			 printf( "\n Nombre =\t %s",Equipo.Nombre );
            printf( "\n Modelo = \t %s",Equipo.Modelo );
             printf( "\n Marca = \t %s",Equipo.Marca );
             printf( "\n Serial = \t %s",Equipo.Serial );
              printf( "\n Caracteristicas =\t %s",Equipo.Caracteristicas );         
       			}
				else if(opc == 'n' || opc == 'N'){
	  						fclose(archivo);
	 						 return(0);
				}
        
		  } 
          
    
  } 
		
			
 } 