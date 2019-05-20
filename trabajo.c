/*
Pagina de compra-venta
Adrian Triner Anton
Guillermo Moreno Domenech
Alberto Hernandez Velayos
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#define N 50
#define USUARIOS 100
#define PRODUCTOS 200

struct usuario {
	char nombreu[N];
	char pass1[N];
	char pass2[N];
	float dinero;
};

struct venta {
	char producto[N];
	char categoria[N];
	char marca[N];
	float precio;
};

struct venta vender[PRODUCTOS]={
	{"Camiseta","Ropa","Nike",19.90},
	{"Zapatillas","Ropa","Adidas",89.90},
	{"Scooter","Motos","Yamaha",599.99},
	{"Motocross","Motos","Kawasaki",2499.90},
	{"Furgoneta","Coches","Peugeot",4999.90},
	{"Descapotable","Coches","Audi",39999.90},
	{"Sofa","Inmobiliario","Ikea",249.90},
	{"Estanteria","Inmobiliario","Ikea",150.00},
	{"FIFA19","Videojuegos","EASports",69.99},
	{"Tetris","Videojuegos","SEGA",14.99},
};

int menu1();
int menu2();
int menu3();

int main(){
	
	struct usuario registro[USUARIOS];
	struct venta vender[PRODUCTOS];
	int opcion, i, op, op2, op3, n;
	FILE * users;
	FILE * ventas;
	int nusuarios=0;
	int nproductos=0;
	int longitud;
	char nombreus[50];
	char pass[50];
	int comp1,comp2,comp3;
	char compra[N],producto1[50];
	float fondos;
	
	system("color 4f");
	
	users = fopen("registro.txt","r");
	if(users==NULL)
	{
		printf("No se pudo abrir correctamente el fichero\n");
		return -1;
	}
		while(fscanf(users,"%s\t%s\t%f\n",registro[nusuarios].nombreu,registro[nusuarios].pass1,&registro[nusuarios].dinero)!=EOF) {
				nusuarios++;
		    }
	
	ventas = fopen("ventas.txt","r");
	if(ventas==NULL)
	{
		printf("No se pudo abrir correctamente el fichero\n");
		return -1;
	}
		while(fscanf(ventas,"%s\t%s\t%s\t%f\n",vender[nproductos].producto,vender[nproductos].categoria,vender[nproductos].marca,&vender[nproductos].precio)!=EOF) {
				nproductos++;
		    }
	
	fclose (ventas);
	fclose(users);
		
	printf("----------------------------------------------------------------\n\n");
	printf("                         PUZZLES\n\n");
	printf("----------------------------------------------------------------\n\n");
	
printf("       Bnienvenido a puzzles\n\n ¡Somos una pagina de compra-ventas en la que puede confiar!\n\n");

printf("Porfavor escoja una opcion para continuar\n\n");


do{	

opcion=menu1();

switch(opcion)
    {
	case 1: {
		system("cls");
		
	            printf("Introduce tu nombre de usuario:\n");
  				scanf("%s", registro[nusuarios].nombreu);
  				printf("Introduce tu password (Maximo 10 caracteres):\n");	//poner limite de caracteres con un strlen
     			scanf("%s", registro[nusuarios].pass1);
     			longitud=strlen(registro[nusuarios].pass1);
     			while (longitud>10)
				 {
     				printf("Ha superdado el limite de caracteres porfavor repita el password:\n");
     				scanf("%s", registro[nusuarios].pass1);
     				longitud=strlen(registro[nusuarios].pass1);
				 }			
         		do{
					printf("Repita su password:\n");
        			scanf("%s", registro[nusuarios].pass2);
         		}
         		while(strcmp(registro[nusuarios].pass1,registro[nusuarios].pass2)!=0);
         		
         		printf("¡Password correcta!\n");
         		
         		printf("Introduzca la cantidad de dinero que desea ingresar a la pagina:\n");
         		scanf("%f",&registro[nusuarios].dinero);
         		printf("REGISTRO COMPLETADO\n\n BIENVENIDO A LA PAGINA!!\n\n\n");
         		
         		nusuarios++;
         		
         		users =fopen("registro.txt","w");
				if(registro==NULL)
				{
					printf("El fichero no se pudo abrir\n");
					return -1;
				}
				
				for (i=0;i<nusuarios;i++)
         		{
         		fprintf(users,"%s\t%s\t%.2f\n",registro[i].nombreu,registro[i].pass1,registro[i].dinero);
				}
				fclose(users);		
		
		break;
	}
	
	case 2: {
		system("cls");
		
			{
					if(nusuarios==0)
					{
						printf("Todavia no hay ningun usuario registrado. Cree un usuario antes.");
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
									printf("Introduzca su password:\n\n");
									scanf("%s",pass);
									printf("\n");
									for(i=0;i<nusuarios;i++)
									{
										comp2=strcmp(pass,registro[i].pass1);
										if(comp2==0)
										{
											printf("El password es correcto. Puede continuar\n\n");
											
											break;
										}
										else if(i==nusuarios-1)
										{
											printf("Su password no esta registrada o es incorrecta.\nPruebe otra vez\n\n");
										}
									}
																		
								}while(comp2==1||comp2==-1);
								i=0;
								
								fclose(users);
							
							}while(fscanf(users,"%s\t%s\n",registro[i].nombreu,registro[i].pass1)!=EOF);
						}
				    printf("Ha iniciado sesion correctamente\n");
					printf("Presione cualquier tecla para continuar\n\n");
					getch();
					}	
				}
		system("cls");
        printf("¿Quiere comprar o vender un articulo?\n\n");
        op2=menu2();
        
        switch (op2) 
		{
        	case 1: {
			system("cls");
			
        		printf("Estos son todos los productos de los que disponemos:\n\n");
        		printf("PRODUCTO            CATEGORIA           MARCA               PRECIO\n\n");
	            ventas = fopen("ventas.txt","r");
	            if(ventas==NULL)
	            {
		        	printf("No se pudo abrir correctamente el fichero\n");
            	}
				while (fscanf(ventas,"%s\t%s\t%s\t%f\n",vender[nproductos].producto,vender[nproductos].categoria,vender[nproductos].marca,&vender[nproductos].precio)!=EOF) 
				{
					printf("%-*s%-*s%-*s%.2f\n",20,vender[nproductos].producto,20,vender[nproductos].categoria,20,vender[nproductos].marca,vender[nproductos].precio);
				}
				do
				{
					fflush(stdin);
					printf("\n¿Que producto desea comprar?\n");
					scanf("%s",producto1);
					printf("\n");
						for(i=0;i<nproductos;i++)
							{
								comp3=strcmp(producto1,vender[i].producto);
								if(comp3==0)
									{
										printf("¡Disponemos de este producto!\n\n"); 
											{
												fondos=registro[i].dinero;
												printf("Usted tiene %.2f euros en su cuenta\n",fondos);
												printf("El producto que desea comprar vale %.2f euros\n\n",vender[i].precio);
												fflush(stdin);
												do
												{	
												for(i=0;i<nproductos;i++)
												{												
												if(fondos<vender[i].precio)
													{
														printf("Dispone de fondos sucientes.¡Gracias por realizar su compra!\n\n");									
														break;
													}	
												else if(fondos>=vender[i].precio)
													{
														printf("Lo sentimos, no dispone de fondos suficientes para comprar dicho producto.\n\n");
														break;
													}
												}
												}while(fondos==1 || fondos==-1);
											}
											break;		
									}	
								else if(i==nproductos-1)
									{
										printf("Lo sentimos, no disponemos de dicho producto.\nPruebe otra vez\n\n");
									}
							}
					
				}while(comp3==1||comp3==-1);
				i=0;
				fclose(ventas);
				getch();
				break;
			}
			
			case 2:{
			system("cls");
		
				printf("Indique el producto que desea vender: (Si el producto tiene mas de una palabra, utilice _ en lugar de un espacio)\n");
  				scanf("%s",vender[nproductos].producto);
  				printf("Categoria en la que se encuentra entre:\n");
  				printf("  -Ropa\n  -Motos\n  -Coches\n  -Inmobiliario\n  -Videojuegos\n");
  				scanf("%s",vender[nproductos].categoria);
  				fflush(stdin);
  				printf("Marca:\n");
                scanf("%s",vender[nproductos].marca);
                fflush(stdin);
  				printf("Precio:\n");
  				scanf("%f",&vender[nproductos].precio);
         		
         		nproductos++;
         		
         		ventas=fopen("ventas.txt","w");
				if(registro==NULL)
				{
					printf("El fichero no se pudo abrir\n");
					return -1;
				}
				
				for (i=0;i<nproductos;i++)
         		{
         		fprintf(ventas,"%s\t%s\t%s\t%.2f\n",vender[i].producto,vender[i].categoria,vender[i].marca,vender[i].precio);
				}
				i=0;
				fclose(ventas);
				break;
			}
        		
		}
        do {
        	op3=menu3();
        	switch (op3){
        			case 1: {
			system("cls");
			
        		printf("Estos son todos los productos de los que disponemos:\n\n");
        		printf("PRODUCTO            CATEGORIA           MARCA               PRECIO\n\n");
	            ventas = fopen("ventas.txt","r");
	            if(ventas==NULL)
	            {
		        	printf("No se pudo abrir correctamente el fichero\n");
            	}
				while (fscanf(ventas,"%s\t%s\t%s\t%f\n",vender[nproductos].producto,vender[nproductos].categoria,vender[nproductos].marca,&vender[nproductos].precio)!=EOF) 
				{
					printf("%-*s%-*s%-*s%.2f\n",20,vender[nproductos].producto,20,vender[nproductos].categoria,20,vender[nproductos].marca,vender[nproductos].precio);
				}
				do
				{
					fflush(stdin);
					printf("\n¿Que producto desea comprar?\n");
					scanf("%s",producto1);
					printf("\n");
						for(i=0;i<nproductos;i++)
							{
								comp3=strcmp(producto1,vender[i].producto);
								if(comp3==0)
									{printf("¡Disponemos de este producto!\n\n"); 
											{
												fondos=registro[i].dinero;
												printf("Usted tiene %.2f euros en su cuenta\n",fondos);
												printf("El producto que desea comprar vale %.2f euros\n\n",vender[i].precio);
												fflush(stdin);
												do
												{	
												for(i=0;i<nproductos;i++)
												{												
												if(fondos<vender[i].precio)
													{
														printf("Dispone de fondos sucientes.¡Gracias por realizar su compra!\n\n");									
														break;
													}	
												else if(fondos>=vender[i].precio)
													{
														printf("Lo sentimos, no dispone de fondos suficientes para comprar dicho producto.\n\n");
														break;
													}
												}
												}while(fondos==1 || fondos==-1);
											}
											break;		
									}	
								else if(i==nproductos-1)
									{
										printf("Lo sentimos, no disponemos de dicho producto.\nPruebe otra vez\n\n");
									}
							}
					
				}while(comp3==1||comp3==-1);
				i=0;
				fclose(ventas);
				getch();
				break;
			}
				case 2: {
				system("cls");
		
	            printf("Indique el producto que desea vender:\n");
  				scanf("%s",vender[nproductos].producto);
  				printf("Categoria en la que se encuentra entre:\n");
  				printf("  -Ropa\n  -Motos\n  -Coches\n  -Inmobiliario\n  -Videojuegos\n");
  				scanf("%s",vender[nproductos].categoria);
  				printf("Marca:\n");
                scanf("%s",vender[nproductos].marca);
  				printf("Precio:\n");
  				scanf("%f",&vender[nproductos].precio);
         		
         		nproductos++;
         		
         		ventas=fopen("ventas.txt","w");
				if(registro==NULL)
				{
					printf("El fichero no se pudo abrir\n");
					return -1;
				}
				for (i=0;i<nproductos;i++)
         		{
         		fprintf(ventas,"%s\t%s\t%s\t%.2f\n",vender[i].producto,vender[i].categoria,vender[i].marca,vender[i].precio);
				}
				i=0;
				fclose(ventas);
				break;
				}
				case 3: {
					system("cls");
	            printf(" HA CERRADO SESION CORRECTAMENTE\n\n¿QUE DESEA HACER AHORA?\n\n");
					break;
				}
			}
        	
		} while (op3>0 && op3<3);
        

	}
	case 3: { 
	system("cls");
	printf(" GRACIAS POR SU VISITA\n\n LE ESPERAMOS PRONTO DE VUELTA\n\n");
		break;
	}
    
    }

}while (opcion>0 && opcion<3);
    
return 0;
}

int menu1(){
	int opcion;
	printf("\n\n");
	printf("1-Crear nuevo usuario\n");
	printf("2-Iniciar sesion\n");
	printf("3-Salir de la aplicacion\n\n");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
} 

int menu2(){
	int op2;
	printf("1-COMPRAR\n");
	printf("2-VENDER\n");
	printf("\n");
	fflush(stdin);
	scanf("%d",&op2);
	return op2;
	
}

int menu3(){
	int op3;
	system ("cls");
	printf("1-Seguir comprando\n");
	printf("2-Seguir vendiendo\n");
	printf("3-Cerrar sesion\n");
	fflush(stdin);
	scanf("%d",&op3);
	return op3;
}

