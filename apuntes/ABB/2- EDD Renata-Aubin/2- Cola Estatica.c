#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define TAM 5

typedef struct
{
	char nombre[10];
	int dni;
}t_info;

typedef struct
{
	t_info dato[TAM];
	int pri;
	int ult;
}t_cola;

void CrearCola(t_cola*);
void VaciarCola(t_cola*);
int ColaVacia(const t_cola*);
int ColaLlena(const t_cola*);
int Acolar(t_cola*,const t_info*);
int Desacolar(t_cola*,t_info*);
int VerPri(const t_cola*,t_info*);

void main()
{
	t_cola cola;
	t_info dato;
	int op;
	FILE *pf;
	CrearCola(&cola);
	do
	{
		printf("\n\n---------------------------------------------------------------------");
		printf("\n1- Acolar dato");
		printf("\n2- Desacolar dato");
		printf("\n3- Vaciar cola");
		printf("\n4- Chequear si esta vacia");
		printf("\n5- Chequear si esta llena");
		printf("\n6- Ver primero");
		printf("\n7- Guardar cola en archivo");
		printf("\n8- Vaciar cola actual y cargar la del archivo");
		printf("\n9- Salir");
		printf("\nIngrese opcion: ");
		scanf("%d",&op);

		switch (op){
		case 1:
			if(!ColaLlena(&cola))
			{
				printf("\nIngrese nombre: ");
				scanf("%s",&dato.nombre);
				printf("\nIngrese dni: ");
				scanf("%d",&dato.dni);
				Acolar(&cola,&dato);
				printf("\nDato acolado correctamente.");
			}
			else
				printf("\nLa cola esta llena y no se puede agregar nada");
		break;
		case 2:
			if(Desacolar(&cola,&dato))
				printf("\nDato desacolado correctamente: Nombre %s  DNI: %d",dato.nombre,dato.dni);
			else
				printf("\nLa cola esta vacia");
		break;
		case 3:
			if(!ColaVacia(&cola))
			{
				VaciarCola(&cola);
				printf("\nSe vacio la cola correctamente");
			}
			else
				printf("\nLa cola ya esta vacia");
		break;
		case 4:
			if(ColaVacia(&cola))
				printf("\nLa cola esta vacia");
			else
				printf("\nLa cola no esta vacia");
		break;
		case 5:
			if(ColaLlena(&cola))
				printf("\nLa cola esta llena");
			else
				printf("\nLa cola no esta llena");
		break;
		case 6:
			if(VerPri(&cola,&dato))
				printf("\nEl primero es: Nombre: %s  DNI: %d",dato.nombre,dato.dni);
			else
				printf("\nLa cola esta vacia");
		break;
		case 7:
			if(ColaVacia(&cola))
				printf("\nNo se puede guardar porque la cola esta vacia");
			else
			{
				if(!(pf=fopen("cola.dat","wb")))
					printf("\nNo se puede crear el archivo");
				else
				{
					while(Desacolar(&cola,&dato))
						fwrite(&dato,sizeof(t_info),1,pf);
					printf("\nCola guardada correctamente en el archivo");
					fclose(pf);
				}
			}
		break;
		case 8:
			if(!(pf=fopen("cola.dat","rb")))
				printf("\nNo se puede abrir el archivo");
			else
			{
				VaciarCola(&cola);
				fread(&dato,sizeof(t_info),1,pf);
				while(!feof(pf))
				{
					Acolar(&cola,&dato);
					fread(&dato,sizeof(t_info),1,pf);
				}
				fclose(pf);
				printf("\nCola cargada de archivo correctamente");
			}
		break;
		}
	}while(op!=9);

	printf("\n\nChau :-D");
	getch();

}

void CrearCola(t_cola *pc)
{
	pc->pri=0;
	pc->ult=-1;
}

void VaciarCola(t_cola *pc)
{
	pc->pri=0;
	pc->ult=-1;
}

int ColaVacia(const t_cola *pc)
{
	return pc->ult==-1;
}

int ColaLlena(const t_cola *pc)
{
	if((pc->ult+1==TAM&&pc->pri==0)||(pc->ult!=-1&&pc->ult+1==pc->pri))
		return 1;
	return 0;
}

int Acolar(t_cola *pc,const t_info *d)
{
	if((pc->ult+1==TAM&&pc->pri==0)||(pc->ult!=-1&&pc->ult+1==pc->pri))
		return 0;
	pc->ult=(pc->ult+1)%TAM;
	pc->dato[pc->ult]=*d;
	return 1;
}

int Desacolar(t_cola *pc,t_info *d)
{
	if(pc->ult==-1)
		return 0;
	*d=pc->dato[pc->pri];
	if(pc->ult==pc->pri)
	{
		pc->pri=0;
		pc->ult=-1;
	}
	else
		pc->pri=(pc->pri+1)%TAM;
	return 1;
}

int VerPri(const t_cola *pc,t_info *d)
{
	if(pc->ult==-1)
		return 0;
	*d=pc->dato[pc->pri];
	return 1;
}
