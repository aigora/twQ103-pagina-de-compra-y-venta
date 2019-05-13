#include <stdio.h>
#include <string.h>
#include <conio.h>
#define N 50
#define USUARIOS 100
#define PRODUCTOS 200

struct usuario {
	char nombreu[N];
	char nombre[N];
	char apellido1[N];
	char apellido2[N];
	char pass1[N];
	char pass2[N];
};

struct venta {
	char categoria[N];
	float precio[N];
	char marca[N];
};

char menu();

int main(){
	
	struct usuario registro[USUARIOS];
	struct venta vender[PRODUCTOS];
	int opcion, i, op, op2;
	FILE * users;
	FILE * ventas;
	int nusuarios=0;
	int nproductos=0;
	int longitud;
	char nombreus[50];
	char pass[50];
	int comp1, comp2;
	
	system("color 4f");
	
	users = fopen("C:/ficheros infor/registro.txt","r");
	if(users==NULL)
	{
		printf("No se pudo abrir correctamente el fichero\n");
		return -1;
	}
		while(fscanf(users,"%s\t%s\t%s\t%s\t%s\n",registro[nusuarios].nombreu, registro[nusuarios].nombre, registro[nusuarios].apellido1, registro[nusuarios].apellido2, registro[nusuarios].pass1)!=EOF) {
				nusuarios++;
		    }
	
	ventas = fopen("C:/ficheros infor/venta.txt","r");
	if(users==NULL)
	{
		printf("No se pudo abrir correctamente el fichero\n");
		return -1;
	}
		while(fscanf(ventas,"%s\t%f\t%s\n",vender[nproductos].categoria, vender[nproductos].precio, vender[nproductos].marca)!=EOF) {
				nproductos++;
		    }
	
	fclose (ventas);
	fclose(users);
		
	printf("----------------------------------------------------------------\n\n");
	printf("                         PUZZLES\n\n");
	printf("----------------------------------------------------------------\n\n");
	
printf("       Bnienvenido a puzzles\n\n �Somos una pagina de compra-ventas en la que puede confiar!\n\n");

printf("Porfavor escoja una opcion para continuar\n\n");


do{	

opcion=menu();
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
		
			{
					if(nusuarios==0)
					{
						printf("Todavia no hay ningun usuario registrado en el cajero. Cree un usuario antes.");
						break;
					}
					else
					{
						users=fopen("registro.txt","r");
						if(registro==NULL)
						{
							printf("El fichero no se pudo abrir\n");
							return -1;
						}
						else
						{
							i=0;
							do
							{
								do
								{
									printf("Introduzca su usuario:\n\n");
									scanf("%s",nombreus);
									printf("\n");
									for(i=0;i<nusuarios;i++)
									{
										comp1=strcmp(nombreus,registro[i].nombreu);
										if(comp1==0)
										{
											printf("El nombre es correcto. Puede continuar\n\n");
											
											break;
										}
										else if(i==nusuarios-1)
										{
											printf("Su nombre no esta registrado o es incorrecto.\nPruebe otra vez\n\n");
										}
									}
									
									
								}while(comp1==1||comp1==-1);
								i=0;
								do
								{
									fflush(stdin);
									printf("Introduzca su password:\n");
									scanf("%s",pass);
									
									
									comp2=strcmp(pass,registro[i].pass1);
									if(comp2==0)
									{						
										printf("\nHa introducido correctamente la contrase�a. Bienvenido.\n");	
									}
									else
									{
									printf("\nLa contrase�a esta mal introducida.\nPruebe otra vez\n\n");
									}
								i++;
								}while (comp2!=0);
								
								fclose(users);
							
							}while(fscanf(users,"%s\t%s\t%s\t%s\t%s\n", registro[i].nombreu, registro[i].nombre, registro[i].apellido1, registro[i].apellido2, registro[i].pass1)!=EOF);
						}
				
					printf("Presione cualquier tecla para continuar\n\n");
					getch();
					break;
					}	
				}
		
        system("cls");
        printf("Ha iniciado sesion correctamente\n");
        printf("Elija que desea hacer a continuacion:\n\n");
        printf("1-VENDER\n 2-COMPRAR\n\n");
        scanf("%d",&op2);
        
        switch (op2) {
        	case 1:{
				break;
			}
			
			case 2:{
				break;
			}
        		
		}
        
        
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

char menu(){
	char opcion;
	printf("1-Crear nuevo usuario\n");
	printf("2-Iniciar sesion\n");
	printf("3-Cerrar sesion\n\n");
	fflush(stdin);
	return opcion;
} 




















