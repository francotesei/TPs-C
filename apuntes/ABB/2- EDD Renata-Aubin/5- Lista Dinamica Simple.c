typedef struct{
        int cantRep;
        char clave[100];
} t_info;

typedef struct snodo
{
        t_info info;
        struct snodo*sig;
}t_nodo;

typedef t_nodo * t_lista;  //(VIEJO) (NUEVO)     cada vez q pongo t_lista  es un *t_nodo (apunta a t_nodo)



int ponerAlFinal(t_lista *p,const t_info *d)
{
        while(*p)
                p=&(*p)->sig;
        *p=(t_nodo*)malloc(sizeof(t_nodo));
        if(!*p)
                return SIN_MEMORIA;
        (*p)->dato=*d;
        (*p)->sig=NULL;
        return TODO_OK;
}


int ponerAlFinalNoRepet(t_lista *p,const t_info *d)
{
        while(*p)
        {
                if(comparar(&(*p)->dato,d)=0)
                {
                        actualizarCantDeRep(*p);
                        return CLAVE_DUPLICADA;        //return 2;
                }
                p=&(*p)->sig;

        }
        *p=(t_nodo*)malloc(sizeof(t_nodo));
        if(!*p)
                return SIN_MEMORIA;  //return 0;
        (*p)->dato=*d;
        (*p)->sig=NULL;
        return TODO_OK;   //return 1
}

int comparar(t_info *t1,t_info *t2)
{
        return strcmp(t1->clave,t2->clave);
}

void actualizarCantDeRep(t_nodo * p)
{
        p->dato.cantRep+=1;
}


insertar despues de una clave. lista desordenada . si la clave no esta, se inserta al final.
insertar despues de n cantidad de nodos. (por posicion)
eliminar una clave ordenada y desordenada.
eliminar n nodos consecutivos desde una posicion.


int insertaDespClaveOrde(t_lista*p,const t_info*d,char * clave)
{
        t_nodo*nue;
        int cmp;
        while(*p&&(cmp=compararClave(clave,(*p)->info.clave)>0)
                p=&(*p)->sig;
        if(*p && cmp<0)               // segun el enunciado de la profe, cuando no se encuentra la clave, hay que agregar al final
        {
                while(*p)                                //vamos hasta el final de la lista
                        p=&(*p)->sig;
        }
        nue=(t_nodo*)malloc(sizeof(t_nodo));
        if(!nue)
                return SIN_MEMORIA;
        nue->info=*d;
        nue->sig=(*p)->sig;
        (*p)->sig=nue;
        return TODO_BIEN;
}

int insertaDespClaveDesord(t_lista*p,const t_info*d,char * clave)
{
        t_nodo*nue;
        int cmp;
        while(*p&&(cmp=compararClave(clave,(*p)->info.clave)!=0)  // aca si no hay coincidencia, este while te lleva hasta el final de la lista
                p=&(*p)->sig;
        // insertar nuevo
        nue=(t_nodo*)malloc(sizeof(t_nodo));
        if(!nue)
                return SIN_MEMORIA;
        nue->info=*d;
        nue->sig=(*p)->sig;
        (*p)->sig=nue;
        return TODO_BIEN;
}

int compararClave(char *s1,char *s2)
{
        return strcmp(s1,s2);
}

int insertaDespDePosicion(t_lista*p,const t_info*d,int pos)
{
        t_nodo*nue;
        int i=0;
        while(*p && i<pos )
        {
                p=&(*p)->sig;
                i++;
        }
        if(!*p)
                return ERROR_POSICION_MAYOR_QUE_EL_TAMAÑO_DE_LA_LISTA;  // EJ: SI LA LISTA TIENE 2 REGISTROS, Y LE MANDO DE PARAMETRO POS=5.
        // insertar nuevo
        nue=(t_nodo*)malloc(sizeof(t_nodo));
        if(!nue)
                return SIN_MEMORIA;
        nue->info=*d;
        nue->sig=(*p)->sig;
        (*p)->sig=nue;
        return TODO_BIEN;
}


int eliminarPorClaveListaOrd(t_lista*p,t_info*d)
{
        t_nodo*aux;
        int cmp;
        while(*p&&(cmp=comparar(d,&(*p)->info))>0)
                p=&(*p)->sig;
        if(*p&&cmp==0){
                //lo encontre
                *d=(*p)->info;
                aux=*p;
                *p=aux->sig;
                free(aux);
                return TODO_BIEN;
                }
        return NO_ENCONTRADO;
}

int eliminarPorClaveListaDesord(t_lista*p,t_info*d)
{
        t_nodo*aux;
        int cmp;
        while(*p&&(cmp=comparar(d,&(*p)->info))!=0)    //esta linea sola es diferente a la funcion eliminarPorClaveListaOrd
                p=&(*p)->sig;
        if(*p&&cmp==0){
                //lo encontre
                *d=(*p)->info;
                aux=*p;
                *p=aux->sig;
                free(aux);
                return TODO_BIEN;
                }
        return NO_ENCONTRADO;
}

int eliminarNNodosDesdePosicion(t_lista*p,int pos,int cantABorrar)
{
        t_nodo *aux1;
        t_lista *aux2;
        int i=0,j=0;

        //ahora voy a posicionarme
        while(*p && i<pos )
        {
                p=&(*p)->sig;
                i++;
        }
        if(!*p)
                return ERROR_DE_POSICION;   //return 0;


        //ahora verifico si se puede borrar todos los nodos
        aux2=p;
        while(*aux2 && j<cantABorrar)
        {
                aux2=&(*aux2)->sig;
                j++;
        }
        if(!*aux2 && j<cantABorrar)
                return ERROR_DE_RANGO_A_BORRAR;  //return 0;


        //una vez verificado que se puede borrar los N nodos, ahora puedo eliminarlos
        j=0;
        while(*p && j<cantABorrar)
        {
            aux1=*p;
                *p=aux1->sig;
                free(aux1);
                j++;
        }
        return TODO_OK;
}
