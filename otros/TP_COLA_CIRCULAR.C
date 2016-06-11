#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
typedef struct
{
 char dato;
} t_info;
typedef struct s_nodo
{
 t_info dato;
 struct s_nodo *sig;
}t_nodo;

typedef t_nodo *t_cola;



char menu(const char *mensaje, const char *opciones);
void crear_cola_Circular(t_cola *p);
int colavacia_Circular(t_cola *p);
int cola_llena_Circular(t_cola *p);
int insertar_cola_Circular(t_cola *p, t_info *d);
int sacar_cola_Circular(t_cola *p, t_info *d);
int ver_primero_cola_circular(t_cola *p, t_info *d);
void vaciar_cola_Circular(t_cola *p);

int main()
{
 char linea[100];
 FILE *fptxt;
 char opcion;
 t_info info;
 t_cola cola;
 opcion = menu("Ingrese:  \n"
               "1 - Crear Cola Circular\n"
               "2 - Insertar en Cola Circular\n"
               "3 - Sacar de Cola Circular\n"
               "4 - Vaciar Cola Circular\n"
               "5 - Ver Primero de la Cola\n"
               "9 - Salir\n"
               "      opcion:   ","123459");
 while (opcion !='9')
 {
 switch(opcion)
 {
  case '1':
          crear_cola_Circular(&cola);
          break;
  case '2':
         /* if((fptxt=fopen("Dato_3_18.txt","rb")) == NULL)
           {
            printf("Error apertura");
            scanf("%*c");
            exit(1);
           }
          fflush(stdin);
          fread(&info.dato,1,1,fptxt);
          while(!feof(fptxt))
           {
            printf("Letra ingresada %c\n", info.dato);
            if (insertar_cola_Circular(&cola, &info))
             printf("Inserto Dato : \n", info.dato);
            else
             printf("Sin Memoria . \n");
            fread(&info.dato,1,1,fptxt);
            }
          fclose(fptxt);
          scanf("%*c");*/

          puts("Ingrese dato (char)");
          fflush(stdin);
          gets(&info.dato);
          insertar_cola_Circular(&cola, &info);

          break;
   case '3':
           if (sacar_cola_Circular(&cola, &info))
            printf("El nodo sacado es : %c \n", info.dato);
           else
            printf("La pila esta vacia. \n");
            break;
   case '4':
             vaciar_cola_Circular(&cola);
             break;
   case '5':
             if(ver_primero_cola_circular(&cola, &info))
              printf("El Primero de la cola es: %c\n",info.dato);
             else
              printf("Cola Vacia \n");
             scanf("%*c");
             break;
 } // switch
 opcion = menu("Ingrese:  \n"
               "1 - Crear Cola Circular\n"
               "2 - Insertar en Cola Circular\n"
               "3 - Sacar de Cola Circular\n"
               "4 - Vaciar Cola Circular\n"
               "5 - Ver Primero de la Cola\n"
               "9 - Salir\n"
               "      opcion:   ","123459");


    return 0;
 }   // while (opcion ..........
} // main

char menu(const char *mensaje, const char *opciones)
{
 char op;
 do
 {
  printf(mensaje);
  fflush(stdin);
  scanf("%c",&op);
 }while(!strchr(opciones,op));
 return op;
}

//=============== CREAR COLA CIRCULAR ==========================================

void crear_cola_Circular(t_cola *p)
{
 *p = NULL;
}

//============== COLa VACIA ====================================================

int cola_vacia_Circular(t_cola *p)
{
 return *p == NULL;
}

//=============== COLA LLENA ===================================================

int cola_llena_Circular(t_cola *p)
{
 t_nodo *nuevo = (t_nodo *) malloc(sizeof(t_nodo));
 free(nuevo);
 return nuevo == NULL;
}

//=================  INSERTAR en COLA CIRCULAR =================================

int insertar_cola_Circular(t_cola *p, t_info *d)
{
 t_nodo *nuevo = (t_nodo *) malloc(sizeof(t_nodo));
 if(nuevo==NULL)
  {printf("Sin Memoria \n");
   return 0;
  }
 nuevo->dato = *d;
 if (*p == NULL)
  {
   nuevo->sig = nuevo;
  }
 else
  {
   nuevo->sig = (*p)->sig;
   (*p)->sig = nuevo;
  }
  *p = nuevo;
 return 1;
}


//================  SACAR de COLA CIRCULAR =====================================

int sacar_cola_Circular(t_cola *p, t_info *d)
{
 t_nodo *elim;
 if(*p)
  {
   elim = (*p)->sig;
   *d =  elim->dato;
   (*p)->sig  = elim->sig;
   free(elim);
   if (elim == *p)
    *p = NULL;
   return 1;
  }
 else
  return 0;
}

//==================VER PRIMERO COLA CIRCULAR ==================================

int ver_primero_cola_circular(t_cola *p, t_info *d)
{
 if(*p)
  {
   *d = (*p)->sig->dato;
   return 1;
  }
 return 0;
}

//================ VACIAR COLA CIRCULAR ========================================
void vaciar_cola_Circular(t_cola *p)
{
 t_nodo *elim;
 while(*p)
  {
   elim = (*p)->sig;
   (*p)->sig  = elim->sig;
   free(elim);
   if (elim == elim->sig)
    *p = NULL;
  }
}


