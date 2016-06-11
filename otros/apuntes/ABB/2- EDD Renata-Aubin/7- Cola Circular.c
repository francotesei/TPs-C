typedef struct{
	int x;
} t_dato;

typedef struct snodo{
t_dato dato;
struct snodo*sig;
}t_nodo;

typedef t_nodo * t_cola;

void main()
{


}
void crear_cola( t_cola *p)
{
    *p=NULL;
}

int colaVacia( const t_cola *p )
{
    return (  (*p==NULL)?0:1);
}

int colaLLena(const t_cola *p )
{
    t_nodo *aux = (t_nodo*)malloc ( sizeof(t_nodo ));
    if (aux)
    {
        free(aux);
        return (0);
    }
    else
    {
        return COLA_LLENA;
    }
}


int ponerEnColaC(t_cola *p,const t_dato *d)
{
	t_nodo * nue=(t_nodo*)malloc(sizeof(t_nodo));
	if(!nue)
		return SIN_MEMORIA;
	nue->dato=*d;
	if(*p==NULL)
		nue->sig=nue;
	else
	{
		nue->sig=(*p)->sig;
		(*p)->sig=nue;
	}
	*p=nue;
	return TODO_BIEN;
}


int sacarDeColaC(t_cola *p,t_dato *d)
{
	t_nodo *aux;
	if(!(*p))
		return COLA_VACIA; //return 0;
	*d=(*p)->sig->dato;
	aux=(*p)->sig;
	if(*p==aux)
		*p=NULL;
	else
		*p->sig=aux->sig;
	free(aux);
	return TODO_OK;
}

void vaciarColaC(t_cola *p)
{
	t_nodo *aux;
	while(*p)
	{
		aux=(*p)->sig;
		if(*p==aux)
			*p=NULL;
		else
			(*p)->sig=aux->sig;
		free(aux);
	}
}
