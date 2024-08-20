/*PROGRAMA PARA REALIZAR INVENTARIO DE PRODUCTOS
PROGRAMADORES DEL HOY:  ALEXANDER TOVAR
FECHA:04-04-2018*/

//#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <direct.h> // para mkdir


//Declaracion de Variables
//Variables Fueras del Struct
char Nombre[10];
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
	char NBien[9];
	char UDpt[10];
	char UNombre[10];
	char UApellido[10];
	char UElaborado[10];
	char UModelo[10];
	char UDisco[10];
	char URam[10];
	char UProcesador[10];
	char UMonitor[10];
	char USistema[10];
	char UService[10];
	char UMicrosoft[10];
	char ULicencia[10];
	char UAntivirus[10];
	char UAdmi[10];
	char dateing[9];
	char datemod[9];

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
		printf("SISTEMA CREADO PARA EL INVENTARIADO DE EQUIPOS U.E.P.CORAZONDEMARI ");Sleep(300);
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
		printf("\t                         SSSSSSSSSSS\n");
		printf("\t                     SSSSSSSSSSSSSSSSSSS\n");
		printf("\t                   SSSSSSSSSSSSSSSSSSSSSSS\n");
		printf("\t                 SSSSSSSSSSSSSSSSSSSSSSSSSSS\n");
		printf("\t                SSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n");
		printf("\t               SSSSSSSSSS            SSSSSSSSS\n");
		printf("\t              SSSSSSSSS                SSSSSSSS\n");
		printf("\t             SSSSSSSSS  SSSSSSSSSSSSSS  SSSSSSSS\n");
		printf("\t             SSSSSSSS   SS          SS   SSSSSSS\n");
		printf("\t             SSSSSSSS   SS  ?   ?SSS   SSSSSSS\n");
		printf("\t             SSSSSSSS   SS  ?   ?      SSSSSSS \n");
		printf("\t             SSSSSSSS   SS  ????SS   SSSSSSS\n");
		printf("\t             SSSSSSSS   SS          SS   SSSSSSS \n");
		printf("\t             SSSSSSSSS  SSSSSSSSSSSSSS  SSSSSSSS\n");
		printf("\t              SSSSSSSSS                SSSSSSSS\n");
		printf("\t               SSSSSSSSS              SSSSSSSS\n");
		printf("\t                SSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n");
		printf("\t                 SSSSSSSSSSSSSSSSSSSSSSSSSSS\n");
		printf("\t                  SSSSSSSSSSSSSSSSSSSSSSSSS\n");
		printf("\t                     SSSSSSSSSSSSSSSSSSS\n");
		printf("\t                         SSSSSSSSSSS\n");
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
		printf("********************************************************************************");Sleep(300);
		printf("                                                USUARIO: %s %s",Nombre,Apellido);
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

			case 1:		/*Ingresar un equipo al registro de inventario*/
			   registrar();
			break;

			case 2:		/*Buscar y mostrar un determinado equipo por numero de bien*/
			   consultar();
			break;

			case 3:		/*Editar para modificar un Registro de inventario*/
            eliminar ();
			break;

			case 4:		/*Funcion para eliminar un Registro del inventario*/
            modificar();
			break;

			case 5:		/*Mostrando los equipos que han sido registrados hasta el momento*/
				 inventarioGen();
			break;

			case 6:		/*Creditos mas los agradecimientos*/
			creditos();
			system ("pause");
			break;

			case 7:		/*Asistencia al usuario*/
			printf("\tAsistencia al usuario\n");
			system ("pause");
			break;

			case 8:		/*Mensaje de Despedida*/
			salir();

			system ("pause");
			break;

			default:	/*En caso de que el usuario haya pulsado una opcion fuera del menu*/
			printf ("Opcion invalida!\n");
			system ("pause");
			break;
		}
	}while(opc != 8);

}

void registrar(){
	system("COLOR B0");
	printf("\t\t\tINGRESAR DATOS DE UN EQUIPO\n\n\n\n");
	printf("INGRESE EL N\351MERO DE BIEN:");
   fflush(stdin);
	//scanf("%d",&PC.NBien);
   gets(PC.NBien);

	printf("\nDEPARTAMENTO:");
   fflush(stdin);
	gets(PC.UDpt);

	printf("NOMBRE DEL USUARIO DEL EQUIPO:");
	fflush(stdin);
	gets(PC.UNombre);

	printf("APELLIDO DEL USUARIO DEL EQUIPO:");
	fflush(stdin);
	gets(PC.UApellido);

	printf("ELABORADO POR:");
	fflush(stdin);
	gets(PC.UElaborado);

	printf("MARCA Y MODELO DEL EQUIPO:");
	fflush(stdin);
	gets(PC.UModelo);

	printf("FABRICANTE Y CAPACIDAD DEL DISCO DURO:");
	fflush(stdin);
	gets(PC.UDisco);

	printf("MARCA Y MODELO DE LA MEMORIA RAM:");
	fflush(stdin);
	gets(PC.URam);

	printf("PROCESADOR:");
	fflush(stdin);
	gets(PC.UProcesador);

	printf("MARCA Y MODELO DEL MONITOR:");
	fflush(stdin);
	gets(PC.UMonitor);

	printf("SISTEMA OPERATIVO:");
	fflush(stdin);
	gets(PC.USistema);

	printf("SERVIPACK:");
	fflush(stdin);
	gets(PC.UService);

	printf("MICROSOFT OFFICE:");
	fflush(stdin);
	gets(PC.UMicrosoft);

	printf("LICENCIA:");
	fflush(stdin);
	gets(PC.ULicencia);

	printf("ANTIVIRUS:");
	fflush(stdin);
	gets(PC.UAntivirus);

	printf("SISTEMA ADMINISTRAIVO:");
	fflush(stdin);
	gets(PC.UAdmi);

//	time_t tiempo=time(0);
//   struct tm *tlocal = localtime(&tiempo);
	strftime(PC.dateing,  9, "%d/%m/%y", tlocal);  //guardar fecha del registro del inventario para seguridad
	strcpy(PC.datemod, "00/00/00");

    mkdir("inventario");
	datosPC=fopen("inventario/bd.txt","a+");
   //fseek(datosPC, 0L, SEEK_END );
	fprintf(datosPC, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",PC.NBien,PC.UDpt,PC.UNombre,PC.UApellido,PC.UElaborado,PC.UModelo,PC.UDisco,PC.URam,PC.UProcesador,PC.UMonitor,PC.USistema,PC.UService,PC.UMicrosoft,PC.ULicencia,PC.UAntivirus,PC.UAdmi,PC.dateing,PC.datemod);
   //fwrite(&PC, sizeof(struct datos), 1, datosPC);

	fclose(datosPC);

	printf("\nDATOS GUARDADOS EXITOSAMENTE\n");
	system ("pause");
return;
}


void consultar()
{

   //int caracter;
	int encontrado=0;
	printf("\t\tCONSULTAR DATOS DE UN EQUIPO\n\n");
   //fflush(stdin);
	printf("INGRESE EL N\351MERO DE BIEN:");
	scanf("%s",&buscar);


   FILE * datosPC = NULL;
	datosPC = fopen("inventario/bd.txt","r");
   if(datosPC == NULL)
        {
                printf("\nFichero no existe! \nPor favor creelo");
                getch();
                return;
        }
     if(feof(datosPC)) printf("Archivo vacio");


     do{
        fscanf(datosPC, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",PC.NBien,PC.UDpt,PC.UNombre,PC.UApellido,PC.UElaborado,PC.UModelo,PC.UDisco,PC.URam,PC.UProcesador,PC.UMonitor,PC.USistema,PC.UService,PC.UMicrosoft,PC.ULicencia,PC.UAntivirus,PC.UAdmi,PC.dateing,PC.datemod);

        if(!strcmp(PC.NBien, buscar)){
        encontrado=1;

         printf("N\351MERO DE BIEN: %s\n",&PC.NBien);
	      printf("DEPARTAMENTO: %s\n",PC.UDpt);
	      printf("NOMBRE DEL USUARIO DEL EQUIPO: %s\n",PC.UNombre);
      	printf("APELLIDO DEL USUARIO DEL EQUIPO: %s\n",PC.UApellido);
	      printf("ELABORADO POR: %s\n",PC.UElaborado);
	      printf("MARCA Y MODELO DEL EQUIPO: %s\n",PC.UModelo);
	      printf("FABRICANTE Y CAPACIDAD DEL DISCO DURO: %s\n",PC.UDisco);
	      printf("MARCA Y MODELO DE LA MEMORIA RAM: %s\n",PC.URam);
	      printf("PROCESADOR: %s\n",PC.UProcesador);
	      printf("MARCA Y MODELO DEL MONITOR: %s\n",PC.UMonitor);
	      printf("SISTEMA OPERATIVO: %s\n",PC.USistema);
	      printf("SERVIPACK: %s\n",PC.UService);
	      printf("MICROSOFT OFFICE: %s\n",PC.UMicrosoft);
	      printf("LICENCIA: %s\n",PC.ULicencia);
	      printf("ANTIVIRUS: %s\n",PC.UAntivirus);
	      printf("SISTEMA ADMINISTRAIVO: %s\n",PC.UAdmi);
	      printf("\nFECHA EN LA QUE SE REALIZ\340 EL INVENTARIO: %s\n",PC.dateing);
       	printf("\nFECHA EN LA QUE SE MODIFIC\340 EL INVENTARIO: %s\n",PC.datemod);
         system("pause");
         }

         if(encontrado==0 && feof(datosPC)){
         printf("\n\n\t\t\tREGISTRO DE EQUIPO NO ENCONTRADO\n\n");
         system ("pause");
         }
      }while(encontrado==0 && !feof(datosPC));
	fclose(datosPC);
	return;
}


void modificar()	/*Funcion para modificar un Registro de inventario*/
{
  FILE* datosPC;
  FILE* aux;
   printf("\t\tMODIFICAR DATOS DE UN EQUIPO\n\n");
   fflush(stdin);
   printf("INGRESE EL NUMERO DE BIEN:");
   scanf("%s",&buscar);
   encontrado=0;
   datosPC=fopen("inventario/bd.txt","rt");
   aux=fopen("inventario/bdaux.txt","a+");

if(datosPC == NULL)
        {
                printf("\nFichero no existe! \nPor favor creelo");
                getch();
                return;
        }
     if(feof(datosPC)) printf("Archivo vacio");


     do{
        fscanf(datosPC, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",PC.NBien,PC.UDpt,PC.UNombre,PC.UApellido,PC.UElaborado,PC.UModelo,PC.UDisco,PC.URam,PC.UProcesador,PC.UMonitor,PC.USistema,PC.UService,PC.UMicrosoft,PC.ULicencia,PC.UAntivirus,PC.UAdmi,PC.dateing,PC.datemod);

      if(!strcmp(PC.NBien, buscar)){
       do{
		encontrado=1;
		printf("1.-N\351MERO DE BIEN: %s",PC.NBien);
		printf("\n2.-DEPARTAMENTO: %s",PC.UDpt);
		printf("\n3.-NOMBRE DEL USUARIO DEL EQUIPO: %s",PC.UNombre);
		printf("\n4.-APELLIDO DEL USUARIO DEL EQUIPO: %s",PC.UApellido);
		printf("\n5.-ELABORADO POR: %s",PC.UElaborado);
		printf("\n6.-MARCA Y MODELO DEL EQUIPO: %s",PC.UModelo);
		printf("\n7.-FABRICANTE Y CAPACIDAD DEL DISCO DURO: %s",PC.UDisco);
		printf("\n8.-MARCA Y MODELO DE LA MEMORIA RAM: %s",PC.URam);
		printf("\n9.-PROCESADOR: %s",PC.UProcesador);
		printf("\n10.-MARCA Y MODELO DEL MONITOR: %s",PC.UMonitor);
		printf("\n11.-SISTEMA OPERATIVO: %s",PC.USistema);
		printf("\n12.-SERVIPACK: %s",PC.UService);
		printf("\n13.-MICROSOFT OFFICE: %s",PC.UMicrosoft);
		printf("\n14.-LICENCIA: %s",PC.ULicencia);
		printf("\n15.-ANTIVIRUS: %s",PC.UAntivirus);
		printf("\n16.-SISTEMA ADMINISTRAIVO: %s",PC.UAdmi);
		printf("\n17.-Salir del modulo de modificacion de datos\n");
		printf("Opcion: ");
		scanf("%d",&opc2);

		switch (opc2){

		case 1:
			printf("\nINGRESE EL NUEVO N\351MERO DEL EQUIPO:");
			fflush(stdin);
         gets(PC.NBien);
		break;

		case 2:
			printf("\nDEPARTAMENTO");
			fflush(stdin);
			gets(PC.UDpt);
      break;
		case 3:
			printf("\nNOMBRE DEL USUARIO DEL EQUIPO:");
			fflush(stdin);
			gets(PC.UNombre);
		break;

		case 4:
			printf("\nAPELLIDO DEL USUARIO DEL EQUIPO:");
			fflush(stdin);
			gets(PC.UApellido);
		break;

		case 5:
			printf("\nELABORADO POR:");
			fflush(stdin);
			gets(PC.UElaborado);
		break;

		case 6:
			printf("\nMARCA Y MODELO DEL EQUIPO:");
			fflush(stdin);
			gets(PC.UModelo);
		break;

		case 7:
			printf("\nFABRICANTE Y CAPACIDAD DEL DISCO DURO:");
			fflush(stdin);
			gets(PC.UDisco);
		break;

		case 8:
			printf("\nMARCA Y MODELO DE LA MEMORIA RAM:");
			fflush(stdin);
			gets(PC.URam);
		break;

		case 9:
			printf("\nPROCESADOR:");
			fflush(stdin);
			gets(PC.UProcesador);
		break;

		case 10:
			printf("\nMARCA Y MODELO DEL MONITOR:");
			fflush(stdin);
			gets(PC.UMonitor);
		break;

		case 11:
			printf("\nSISTEMA OPERATIVO:");
			fflush(stdin);
			gets(PC.USistema);
		break;

		case 12:
			printf("\nSERVIPACK:");
			fflush(stdin);
			gets(PC.UService);
		break;

		case 13:
			printf("\nMICROSOFT OFFICE:");
			fflush(stdin);
			gets(PC.UMicrosoft);
		break;

		case 14:
			printf("\nLICENCIA:");
			fflush(stdin);
			gets(PC.ULicencia);
		break;

		case 15:
			printf("\nANTIVIRUS:");
			fflush(stdin);
			gets(PC.UAntivirus);
		break;

		case 16:
			printf("\nSISTEMA ADMINISTRAIVO:");
			fflush(stdin);
			gets(PC.UAdmi);
		break;

		case 17:/*Mensaje de Despedida*/
         //time_t tiempom=time(0);
   		//struct tml *tlocalm = localtime(&tiempom);
			strftime(PC.datemod,  9, "%d/%m/%y", tlocal);

			//_strdate(PC.datemod);  //guardar fecha de modificaci\F3n del inventario para seguridad
			printf ("Datos modificados correctamente!\n");
         system ("pause");
	     	break;

		    default:/*En caso de que el usuario haya pulsado una opcion fuera del menu*/
			printf ("Opcion invalida!\n");
         system ("pause");
		    break;
		}

	     }while(opc2 != 17);

	 	}//cierre de if
    fprintf(aux, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",PC.NBien,PC.UDpt,PC.UNombre,PC.UApellido,PC.UElaborado,PC.UModelo,PC.UDisco,PC.URam,PC.UProcesador,PC.UMonitor,PC.USistema,PC.UService,PC.UMicrosoft,PC.ULicencia,PC.UAntivirus,PC.UAdmi,PC.dateing,PC.datemod);

     if(encontrado==0 && feof(datosPC)){
         printf("\n\n\t\t\tREGISTRO DE EQUIPO NO ENCONTRADO\n\n");
         system ("pause");
         }
     }while(!feof(datosPC));

  fclose(datosPC);
  fclose(aux);

 remove("inventario/bd.txt");
 rename("inventario/bdaux.txt","inventario/bd.txt");
  return;
}


void eliminar()	/*Funcion para eliminar un Registro del inventario*/
{

	FILE* datosPC;
  	FILE* aux;
   printf("\t\tELIMINAR REGISTRO DE UN EQUIPO\n\n");
   fflush(stdin);
   printf("INGRESE EL NUMERO DE BIEN:");
   scanf("%s",&buscar);
   encontrado=0;
   datosPC=fopen("inventario/bd.txt","rt");
   aux=fopen("inventario/bdaux.txt","a+");

   do{
	fscanf(datosPC, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",PC.NBien,PC.UDpt,PC.UNombre,PC.UApellido,PC.UElaborado,PC.UModelo,PC.UDisco,PC.URam,PC.UProcesador,PC.UMonitor,PC.USistema,PC.UService,PC.UMicrosoft,PC.ULicencia,PC.UAntivirus,PC.UAdmi,PC.dateing,PC.datemod);
	if(!strcmp(PC.NBien, buscar)){

		encontrado=1;
		printf("DATOS DEL REGISTRO:\n\n");
		printf("N\351MERO DE BIEN: %s",&PC.NBien);
		printf("\nDEPARTAMENTO: %s",PC.UDpt);
		printf("\nNOMBRE DEL USUARIO DEL EQUIPO: %s",PC.UNombre);
		printf("\nAPELLIDO DEL USUARIO DEL EQUIPO: %s",PC.UApellido);
		printf("\nELABORADO POR: %s",PC.UElaborado);
		printf("\nMARCA Y MODELO DEL EQUIPO: %s",PC.UModelo);
		printf("\nFABRICANTE Y CAPACIDAD DEL DISCO DURO: %s",PC.UDisco);
		printf("\nMARCA Y MODELO DE LA MEMORIA RAM: %s",PC.URam);
		printf("\nPROCESADOR: %s",PC.UProcesador);
		printf("\nMARCA Y MODELO DEL MONITOR: %s",PC.UMonitor);
		printf("\nSISTEMA OPERATIVO: %s",PC.USistema);
		printf("\nSERVIPACK: %s",PC.UService);
		printf("\nMICROSOFT OFFICE: %s",PC.UMicrosoft);
		printf("\nLICENCIA: %s",PC.ULicencia);
		printf("\nANTIVIRUS: %s",PC.UAntivirus);
		printf("\nSISTEMA ADMINISTRAIVO: %s",PC.UAdmi);
		printf("\n\n1.-CONFIRMAR ELIMINACI\340N\n");
		printf("\n2.-SALIR SIN ELIMINAR\n");
		printf("Opcion: ");
		scanf("%d",&opc2);

		switch (opc2){

		    case 1:/*Mensaje de Despedida*/
			_strdate(PC.datemod);  //guardar fecha de modificaci\F3n del inventario para seguridad
			printf ("REGISTRO ELIMINADO!\n");  system ("pause");
	     	    break;

		    case 2:/*Mensaje de Despedida*/
			fprintf(aux, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",PC.NBien,PC.UDpt,PC.UNombre,PC.UApellido,PC.UElaborado,PC.UModelo,PC.UDisco,PC.URam,PC.UProcesador,PC.UMonitor,PC.USistema,PC.UService,PC.UMicrosoft,PC.ULicencia,PC.UAntivirus,PC.UAdmi,PC.dateing,PC.datemod);
			printf ("REGISTRO NO ELIMINADO!\n");  system ("pause");
	     	    break;

		    default:/*En caso de que el usuario haya pulsado una opcion fuera del menu*/
			printf ("Opcion invalida!\n"); system ("pause");
		    break;
		}
	}
	if(strcmp(PC.NBien, buscar))
	   fprintf(aux, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",PC.NBien,PC.UDpt,PC.UNombre,PC.UApellido,PC.UElaborado,PC.UModelo,PC.UDisco,PC.URam,PC.UProcesador,PC.UMonitor,PC.USistema,PC.UService,PC.UMicrosoft,PC.ULicencia,PC.UAntivirus,PC.UAdmi,PC.dateing,PC.datemod);
	if(encontrado==0 && feof(datosPC))
	   {printf("\n\n\t\t\tREGISTRO DE EQUIPO NO ENCONTRADO\n\n");
      system ("pause");
      }
  }
  while(!feof(datosPC));

  fclose(datosPC);
  fclose(aux);

 remove("inventario/bd.txt");
 rename("inventario/bdaux.txt","inventario/bd.txt");

  return;
}


void creditos()
         {
			system("COLOR B0");
			printf("********************************************************************************");
			printf("********************************************************************************");
			printf("                                                                                ");
			printf("                                    CREDITOS                                    ");
			printf("                                                                                ");
			printf("          MINISTERIO DEL PODER POPULAR PARA LA EDUCACION UNIVERSITARIA          ");
			printf("         Por ser la primera institucion encargada de nuestros estudios y        ");
			printf("                   por brindarnos oportunidades de estudio.                     ");
			printf("                                                                                ");
			printf("                       COLEGIO UNIVERSITARIO DE CARACAS                         ");
			printf("      Por ofrececernos una excelente calidad de estudios y de preparacion       ");
			printf("                                                                                ");
			printf("                 PROGRAMA NACIONAL DE FORMACION EN INFORMATICA                  ");
			printf("       Por dedicar plenamente su mision a los estudiantes, para obtener una     ");
			printf("       preparacion a nivel tecnico y profesional en Instituciones del Estado.   ");
			printf("                                                                                ");
			printf("                         DOCENTE: MgSc. LORENZO MOREJON                      ");
			printf("   Por su esfuerzo y de/dicacion como tambien su excelente labor como Docente.   ");
			printf("    por convertirse ademas de profesora en una amiga. Por creer en nosotros     ");
			printf("         por inculcarnos ese sentido de seriedad y responsabilidad              ");
			printf("              por eso le agredecemos con toda la honestidad.                    ");
			printf("                                                                                ");
			printf("                              MARCO, JESUS, MAURICIO                                 ");
			printf("         Porque unidos el exito esta de nuestro lado, porque entendimos         ");
			printf("                que con entrega y dedicacion todo se puede.                     ");
			printf("                                                                                ");
			printf("                                                           oo                   ");
			printf("                                    +++++                 oooo                  ");
			printf("                                   +++++++               oooooo                 ");
			printf("                                    (O O)               oooooooo                ");
			printf("                       +--------oOO--(_)-------------+   oooooo                 ");
			printf("                       |          AGRADECIDOS        |    oooo                  ");
			printf("                       +----------------oOO----------+     xx                   ");
			printf("                                   |__|__|                xxxx                  ");
			printf("                                    | | |                xxxxxx                 ");
			printf("                                   ooO Ooo                                      ");
			printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
			system ("pause");
			system("cls");
			return;
         }


void salir()
         {
			system("COLOR 1E");
			{
			printf("********************************************************************************");
			printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
			printf("                                                                                ");
			printf("                                    \ \|/ /\n");
			printf("                                     (O O)\n");
			printf("                        +--------oOO--(_)-------------+\n");
			printf("                        |          HASTA LUEGO        |\n");
			printf("                        +----------------oOO----------+\n");
			printf("                                   |__|__|\n");
			printf("                                    | | |\n");
			printf("                                   ooO Ooo\n");
			printf("\n\n");
			printf("                CCCCCCC        UUUU         UUUU        CCCCCCC                 ");
			printf("              CCCCCCCCCCC      UUUU         UUUU      CCCCCCCCCCC               ");
			printf("            CCCCC     CCCCC    UUUU         UUUU    CCCCC     CCCCC             ");
			printf("            CCCCC     CCCCC    UUUU         UUUU    CCCCC     CCCCC             ");
			printf("            CCCCC     CCCCC    UUUU         UUUU    CCCCC     CCCCC             ");
			printf("            CCCCC              UUUU         UUUU    CCCCC                       ");
			printf("            CCCCC              UUUU         UUUU    CCCCC                       ");
			printf("            CCCCC              UUUU         UUUU    CCCCC                       ");
			printf("            CCCCC              UUUU         UUUU    CCCCC                       ");
			printf("            CCCCC              UUUU         UUUU    CCCCC                       ");
			printf("            CCCCC     CCCCC    UUUU         UUUU    CCCCC     CCCCC             ");
			printf("            CCCCC     CCCCC    UUUUU       UUUUU    CCCCC     CCCCC             ");
			printf("            CCCCC     CCCCC     UUUUU     UUUUU     CCCCC     CCCCC             ");
			printf("              CCCCCCCCCCC        UUUUU   UUUUU        CCCCCCCCCCC               ");
			printf("                CCCCCCC           UUUUUUUUUUU           CCCCCCC                 ");
			printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
			printf("********************************************************************************");
			system ("pause");
			exit(0);
			}
	return;//SALIDAAA
}


void inventarioGen(){

   FILE * datosPC = NULL;
	datosPC = fopen("inventario/bd.txt","r");
   int cf = 78;
   int ci = 1;
   int c;
   int ff  = 15;
   int fi = 3;
   int f;
   int i = 4;
   if(datosPC == NULL)
        {
                printf("\nFichero no existe! \nPor favor creelo");
                getch();
                return;
        }
     if(feof(datosPC)) printf("Archivo vacio");



       gotoxy(25,2);
      printf("Reporte de bienes");
     do{

        fscanf(datosPC, "%s %s  %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",PC.NBien,PC.UDpt,PC.UNombre,PC.UApellido,PC.UElaborado,PC.UModelo,PC.UDisco,PC.URam,PC.UProcesador,PC.UMonitor,PC.USistema,PC.UService,PC.UMicrosoft,PC.ULicencia,PC.UAntivirus,PC.UAdmi,PC.dateing,PC.datemod);

      gotoxy(2,i);
     	printf("**Datos del Usuario");
      i++;
      gotoxy(2,i);
     	printf("*Nro");
      gotoxy(10,i);
     	printf("*departamento");
		gotoxy(25,i);
     	printf("*Nombre");
      gotoxy(40,i);
     	printf("*Apellido");
		gotoxy(55,i);
     	printf("*fecha Mod");
      gotoxy(67, i);
      printf("*Elaborado");
      i=i+1;
     	gotoxy(3,i);
     	printf("%s",PC.NBien);
      gotoxy(11,i);
     	printf("%s", PC.UDpt);
		gotoxy(26,i);
     	printf("%s", PC.UNombre);
      gotoxy(41,i);
     	printf("%s",PC.UApellido);
		gotoxy(56,i);
     	printf("%s", PC.datemod);
      gotoxy(68, i);
      printf("%s",PC.UElaborado);
      i=i+1;
      gotoxy(2,i);
     	printf("**Datos del Hardware");
      i=i+1;
      gotoxy(2,i);
     	printf("*Modelo");
      gotoxy(17,i);
     	printf("*Disco");
		gotoxy(35,i);
     	printf("*Ram");
      gotoxy(50,i);
     	printf("*Procesador");
		gotoxy(65,i);
     	printf("*Monitor");
      i=i+1;
     	gotoxy(3,i);
     	printf("%s",PC.UModelo);
      gotoxy(18,i);
     	printf("%s", PC.UDisco);
		gotoxy(36,i);
     	printf("%s", PC.URam);
      gotoxy(51,i);
     	printf("%s",PC.UProcesador);
		gotoxy(66,i);
     	printf("%s", PC.UMonitor);

      i=i+1;
      gotoxy(2,i);
     	printf("**Datos del sofware");
      i=i+1;
      gotoxy(2,i);
     	printf("*Sistema Op");
      gotoxy(20,i);
     	printf("*Servipack");
      gotoxy(35,i);
     	printf("*Microsof Office");

      i=i+1;
      gotoxy(3,i);
     	printf("%s", PC.USistema);
      gotoxy(21,i);
     	printf("%s", PC.UService);
      gotoxy(35,i);
     	printf("%s", PC.UMicrosoft);



      i=i+1;
		gotoxy(2,i);
     	printf("*Licencia");
		gotoxy(15,i);
     	printf("*Antivirus");
		gotoxy(30,i);
     	printf("*Sistema Administrativo");


      i=i+1;
		gotoxy(3,i);
     	printf("%s", PC.ULicencia);
		gotoxy(16,i);
     	printf("%s", PC.UAntivirus);
		gotoxy(31,i);
     	printf("%s", PC.UAdmi);



      for(c=ci;c<=cf;c++){
      	gotoxy(c,fi);
      	printf("%c",176);
         gotoxy(c,ff);
      	printf("%c",176);
      }

      for(f=fi; f<=ff; f++){
         gotoxy(ci,f);
      	printf("%c",176);
         gotoxy(cf,f);
      	printf("%c",176);
      }

       fi = ff + 2; // estas operaciones mueven las filas para crear el cuadro.
       ff = fi + 12;
       i= i+4;

        if(i >= 46 ){ //con esta validacion se realiza la paginacion de la informacion ya que el gotoxy no abarga mas de 46 filas de la pantalla.
         printf("\n\nPresionar enter para ver la proxima pagina...\n");
          system ("pause");
          system("cls");
          cf = 78;
          ci = 1;
          ff  = 15;
          fi = 3;
          i = 4;

       }

		} while(!feof(datosPC));
    	printf("\n\n");
   fclose(datosPC);
	system ("pause");
   return;
}

void logo(){
     int f=0,c=0;
     for(c=4;c<=11;c++){
         gotoxy(c,10);
         printf("%c%",177);
         gotoxy(c,17);
         printf("%c%",177);
         if(c>5&&c<13){
            gotoxy(c,15);
            printf("%c%",177);
         }
     }
     for(f=11;f<=16;f++){
         gotoxy(4,f);
         printf("%c%",177);
         if(f>11&&f<16){
            gotoxy(6,f);
            printf("%c%",177);
            gotoxy(9,f);
            printf("%c%",177);
         }
     }
     gotoxy(11,11);
     printf("%c%",177);
     gotoxy(11,12);
     printf("%c%",177);
     gotoxy(11,15);
     printf("%c%",177);
     gotoxy(11,16);
     printf("%c%",177);
     gotoxy(10,12);
     printf("%c%",177);
     gotoxy(10,15);
     printf("%c%",177);

}