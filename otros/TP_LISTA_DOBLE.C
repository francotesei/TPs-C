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
 t_info info;
 struct s_nodo *ant,
               *sig;
}t_nodo;

typedef t_nodo *t_ld;



char menu(const char *mensaje, const char *opciones);
int comparar(t_info *a, t_info *b);
void crear_lista_doble(t_ld *p);
int lista_doble_vacia(t_ld *p);
int lista_doble_llena(t_ld *p);
int insertar_lista_doble_ordenada(t_ld *p, t_info *d);
int sacar_lista_doble_ordenada(t_ld *p, t_info *d);
void mostrar_lista_doble(t_ld *p);
void vaciar_lista_doble(t_ld *p);

int main()
{
 char linea[100];
 FILE *fptxt;
 char opcion;
 t_info info;
 t_ld ld;
 printf("LISTA  %p\n", &ld);
 opcion = menu("Ingrese:  \n"
               "1 - Crear Lista Doble\n"
               "2 - Insertar en Lista Doble\n"
               "3 - Sacar de Lista Doble\n"
               "4 - Mostrar Lista Doble Ordenada\n"
               "5 - Vaciar Lista Doble\n"
               "9 - Salir\n"
               "      opcion:   ","123459");
 while (opcion !='9')
 {
 switch(opcion)
 {
  case '1':
          crear_lista_doble(&ld);
          break;
  case '2':
          if((fptxt=fopen("Dato_3_18.txt","rb")) == NULL)
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
            if (insertar_lista_doble_ordenada(&ld, &info))
             printf("Inserto Dato : \n", info.dato);
            else
             printf("Sin Memoria . \n");
            fread(&info.dato,1,1,fptxt);
            }
          fclose(fptxt);
          scanf("%*c");
          break;
   case '3':
           printf("Ingresar la CLAVE del NODO a EXTRAER de la LISTA\n");
           fflush(stdin);
           scanf("%c",&info.dato);
           if (sacar_lista_doble_ordenada(&ld, &info))
            printf("El nodo sacado es : %c \n", info.dato);
           else
            printf("No esta en la Lista doble. \n");
            break;
   case '4':
             if(!lista_doble_vacia(&ld))
              mostrar_lista_doble(&ld);
             else
              printf("La LISTA esta VACIA. \n");
             break;
   case '5':
             vaciar_lista_doble(&ld);
             printf("La LISTA fue vaciada\n");
             break;
 } // switch
 opcion = menu("Ingrese:  \n"
 					"1 - Crear Lista Doble\n"
               "2 - Insertar en Lista Doble\n"
               "3 - Sacar de Lista Doble\n"
               "4 - Mostrar Lista Doble Ordenada\n"
               "5 - Vaciar Lista Doble\n"
               "9 - Salir\n"
               "      opcion:   ","123459");

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

//======================= Funcion de COMPARACION ===============================

int comparar(t_info *a, t_info *b)
{
 char cad1[15], cad2[15];

 sprintf(cad1,"%c", a->dato);
 sprintf(cad2,"%c", b->dato);
 if(!strcmp(cad1, cad2))
  return 0;
 else
  if(strcmp(cad1, cad2) > 0)
   return 1;
  else
   return -1;
}


//=============== CREAR LISTA DOBLE = ==========================================

void crear_lista_doble(t_ld *p)
{
 *p = NULL;
}

//============== LISTA DOBLE  VACIA ============================================

int lista_doble_vacia(t_ld *p)
{
 return *p == NULL;
}

//=============== LISTA DOBLE LLENA ============================================

int lista_doble_llena(t_ld *p)
{
 t_nodo *nuevo = (t_nodo *) malloc(sizeof(t_nodo));
 free(nuevo);
 return nuevo == NULL;
}

//=================  INSERTAR en LISTA DOBLE ORDENADA ==========================

int insertar_lista_doble_ordenada(t_ld *p, t_info *d)
{
 t_nodo *ant,
        *sig,
        *nue;
 if(*p == NULL) // LISTA VACIA
  {printf("Lista Vacia \n");
   *p = (t_nodo *) malloc(sizeof (t_nodo));
   if(*p == NULL)
    return 0;  printf("PRIMER NODO  %p \n", *p);
   (*p)->info = *d;
   (*p)->ant = (*p)->sig = NULL;
   return 1;
  }
 // NO ESTA VACIA
 sig = *p;
 ant = sig->ant;
 while(ant && comparar(&ant->info, d) > 0) // Ciclo para RETROCEDER
  {printf("Busca Insercion RETROCEDE \n");
   sig = ant;
   ant = ant->ant;
  }
 while(sig && comparar(&sig->info, d) < 0)  // Ciclo par AVANZAR
  {printf("Busca Insercion AVANZA \n");
   ant = sig;
   sig = sig->sig;
  }
 printf("NODO generado\n");
 nue = (t_nodo *) malloc(sizeof(t_nodo));
 if (nue == NULL)
  return 0;
  printf("Ubicacion NODO %p \n", nue);
 nue->info = *d;
 nue->ant = ant;
 nue->sig = sig;
 if(ant)
  ant->sig = nue;
 if(sig)
  sig->ant = nue;
 *p = nue;
 return 1;
}


//================  SACAR de LISTA DOBLE ORDENADA por CLAVE ====================
   /*
int sacar_lista_doble_ordenada(t_ld *p, t_info *d)
{
 t_nodo *ant,
        *sig,
        *elim;
 char marca_AR;
 if(!(*p))  // LISTA VACIA
  return 0;
 if(!(*p)->ant && !(*p)->sig)  // NODO UNICO
  if(!comparar(&(*p)->info, d))
   {printf("Elimina UNICO NODO \n");
    *d = (*p)->info;
    free(*p);
    *p = NULL;
    return 1;
   }
  else
   {
    printf("NODO no ENCONTRADO \n");
    return 0;
   }
 // MAS de un NODO
 sig = *p;
 ant = sig->ant;
 while(ant && comparar(&ant->info, d) > 0) // Ciclo para RETROCEDER
  {printf("Busca Eliminacion RETROCEDE \n");
   sig = ant;
   ant = ant->ant;
   marca_AR = 'R';
  }
 while(sig && comparar(&sig->info, d) < 0)  // Ciclo par AVANZAR
  {printf("Busca Eliminacion AVANZA \n");
   ant = sig;
   sig = sig->sig;
   marca_AR = 'A';
  }
 if(marca_AR == 'A' && !comparar(&sig->info, d))  // ENCONTRO en AVANCE
  {printf("Encontro en AVANCE %c\n",sig->info);
   elim = sig;
   ant = sig->ant;
   sig = sig->sig;
   *d  = sig->info;
   ant->sig = sig;
   if(sig)
    sig->ant = ant;
   free(elim);
   *p = ant;
  }
 else                                              // Encontro en RETROCESO
  if(!comparar(&ant->info, d))
   {printf("Encontro en RETROCESO  %c\n", ant->info);
    elim = ant;
    sig = ant->sig;
    ant = ant->ant;
    *d  = ant->info;
    sig->ant = ant;
    if(ant)
     ant->sig = sig;
    free(elim);
    *p = sig;
   }
  else
   {
    printf("NODO no ENCONTRADO \n");
    return 0;
   }
  return 1;
}    */
int sacar_lista_doble_ordenada(t_ld *p, t_info *d)
{
 t_nodo *aux;
 if(*p)
  {
   aux = *p;
   while(aux->sig && comparar(d, &aux->info) > 0)
    aux = aux->sig;
   while(aux->ant && comparar(d, &aux->info) < 0)
    aux = aux->ant;
   if (comparar(d, &aux->info) == 0)
    {
     if(aux->sig)
      aux->sig->ant = aux->ant;
     if(aux->ant)
      aux->ant->sig = aux->sig;
     *d = aux->info;
     if(*p == aux)
      if(aux->sig)
       *p = aux->sig;
      else
       *p = aux->ant;
     free(aux);
     return 1;
    }
  }
 return 0;
}

//==================MOSTRAR LISTA DOBLE ========================================

void mostrar_lista_doble(t_ld *p)
{
 while(*p && (*p)->ant)  // Para ubicarse al COMIENZO.
  p = &(*p)->ant;
 while(*p)
  {
   printf("El valor del NODO  es: %c\n", (*p)->info);
   p = &(*p)->sig;
  }

}

//================ VACIAR LISTA DOBLE   ========================================
void vaciar_lista_doble(t_ld *p)
{
 t_nodo *elim,
        *aux;
//       *sig;
 /*t_ld   *p_ori = p;
   printf("ORIGEN %p \n", p_ori);
 while(*p && (*p)->ant)  // Para ubicarse al COMIENZO.
  p = &(*p)->ant;
 printf("Vaciar NODO %p \n", *p);
 elim = *p;
 while(elim)
  {printf("El valor del NODO  es: %c\n", elim->info);
    printf("Vaciar NODO %p \n", elim);
    sig = elim->sig;
    free(elim);
    elim = sig;
  }
  *p_ori = NULL;    */
 aux = (*p)->sig;
 while(aux)
  {printf("Elimina en AVANCE %c\n ", aux->info);
   elim = aux;
   aux = aux->sig;
   free(elim);
  }
 aux = *p;
 while(aux)
  {printf("Elimina en RETROCESO %c\n", aux->info);
   elim = aux;
   aux = aux->ant;
   free(elim);
  }
 *p = NULL;
}


