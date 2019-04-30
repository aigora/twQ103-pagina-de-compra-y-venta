#include <stdio.h>
#include <string.h>
#define N 50
#define USUARIOS 100

struct usuario {
	char nombreu[N];
	char nombre[N];
	char apellido1[N];
	char apellido2[N];
	char pass1[N];
	char pass2[N];
};



int main(){
	
	struct usuario registro[USUARIOS];
	int opcion, i, op;
	FILE * users;
	int nusuarios=0;
	int longitud;
	char nombreus[50];
	char pass[50];
	int comp1, comp2;
	
	system("color 9");
	
	users = fopen("C:/ficheros infor/registro.txt","r");
	if(users==NULL)
	{
		printf("No se pudo abrir correctamente el fichero\n");
		return -1;
	}
		while(fscanf(users,"%s\t%s\t%s\t%s\t%s\n",registro[nusuarios].nombreu, registro[nusuarios].nombre, registro[nusuarios].apellido1, registro[nusuarios].apellido2, registro[nusuarios].pass1)!=EOF) {
				nusuarios++;
		    }
		
	fclose(users);
		
	printf("----------------------------------------------------------------\n\n");
	printf("                         PUZZLES\n\n");
	printf("----------------------------------------------------------------\n\n");
	
printf("       Bnienvenido a puzzles\n\n ¡Somos una pagina de compra-ventas en la que puede confiar!\n\n");

printf("Porfavor escoja una opcion para continuar\n\n");


do{	

printf("  1-Crear nuevo usuario\n  2-Iniciar sesion\n  3-Cerrar sesion\n\n");
scanf("%d",&opcion);

switch(opcion)
    {
	case 1: {
		system("cls");
		
	            printf("Introduce tu nombre de usuario:\n");
  				scanf("%s", registro[nusuarios].nombreu);
  				printf("Nombre:\t");
  				scanf("%s", registro[nusuarios].nombre);
  				printf("Primer apellido:\t");
  				scanf("%s", registro[nusuarios].apellido1);
  				printf("Segundo apellido:\t");
  				scanf("%s", registro[nusuarios].apellido2);
  				printf("Introduce tu password (Maximo 10 caracteres):\n");	//poner limite de caracteres con un strlen
     			scanf("%s", registro[nusuarios].pass1);
     			longitud=strlen(registro[nusuarios].pass1);
     			while (longitud>10){
     				printf("Ha superdado el limite de caracteres porfavor repita el password:\n");
     				scanf("%s", registro[nusuarios].pass1);
     				longitud=strlen(registro[nusuarios].pass1);
				 }
         				
         					
         		do{
					printf("Repita su password:\n");
        			scanf("%s", registro[nusuarios].pass2);
         		}
         		while(strcmp(registro[nusuarios].pass1,registro[nusuarios].pass2)!=0);
         		
         		printf("Password correcta\n\n");
         		printf("REGISTRO COMPLETADO\n\n BIENVENIDO A LA PAGINA!!\n\n\n");
         		
         		nusuarios++;
         		
         		users =fopen("C:/ficheros infor/registro.txt","w");
				if(registro==NULL)
				{
					printf("El fichero no se pudo abrir\n");
					return -1;
				}
				
				for (i=0;i<nusuarios;i++)
         		{
         		fprintf(users, "%s\t%s\t%s\t%s\t%s\n", registro[i].nombreu, registro[i].nombre, registro[i].apellido1, registro[i].apellido2, registro[i].pass1);
				}
				fclose(users);		
		
		break;
	}
	
	case 2: {
		system("cls");
		
		users =fopen("C:/ficheros infor/registro.txt","r");
				if(registro==NULL)
				{
					printf("El fichero no se pudo abrir\n");
					return -1;
				}
	do{			
		printf("Nombre de usuario:\n");
		scanf("%s",nombreus);
		comp1=strcmp(nombreus,registro[nusuarios].nombreu);
		while(comp1!=0){
			printf("Usuario no encontrado, vuelva a intentarlo\n");
			scanf("%s",nombreus);
		comp1=strcmp(nombreus,registro[nusuarios].nombreu);
		}
		
		printf("Password:\n");
		scanf("%s", pass);
		comp2=strcmp(pass, registro[nusuarios].pass1);
		while(comp2!=0){
			printf("password incorrecta, vuelva a intentarlo\n");
			scanf("%s",pass);
		comp2=strcmp(nombreus,registro[nusuarios].nombreu);
		}
			
    } while(fscanf(users,"%s %s\n",registro[nusuarios].nombreu, registro[nusuarios].pass1)!=EOF);

	    break;
	}
	case 3: { 
	system("cls");
	printf(" GRACIAS POR SU VISITA\n\n LE ESPERAMOS PRONTO DE VUELTA");
		break;
	}
	
		
            }
    


    }while (opcion<3);

return 0;
}


