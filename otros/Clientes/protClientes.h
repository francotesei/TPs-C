#ifndef PROTCLIENTES_H_INCLUDED
#define PROTCLIENTES_H_INCLUDED
#define ARCH_CLI "clientes"
#define ARCH_IND "indices"
#define ARCH_NOV "novedades"
#define comparar compararXindice
#define O_K 0
#define CLAV_DUP 1
#define SIN_MEM 2
#define CON_SIN_MSJ 1
typedef struct
{
    unsigned nro_cli;
    float saldo;
}clientes;

typedef struct
{
    unsigned nro_cli;
    unsigned reg;
}indices,tInfo;

typedef struct
{
    unsigned nro_cli;
    char nov;
    float importe;
}novedades;

typedef struct tNodo
{
    tInfo info;
    struct tNodo *sig;
}tNodo,*Lista;

void crearArchivoCli(FILE **fp);
void crearArchivoInd(FILE **fp);
void crearArchivoNov(FILE **fp);
int abrirArchivo(FILE **fp,const char *nombre,const char *modo,int CON_SIN);
void actualizarArch(FILE **cl,FILE **nov,Lista *p);
void crearLista(Lista *p);
int listaVacia(Lista *p);
int listaLlena(Lista *p);
void vaciarLista(Lista *p);
int insertarEnOrden(Lista *p,const tInfo *d,int (*comparar)(const unsigned*,const unsigned*));
int compararXindice(const unsigned *d1,const unsigned *d2);
void mostrarArchivo(FILE **fp);
void mostrarCliente(clientes *p);

#endif // PROTCLIENTES_H_INCLUDED
