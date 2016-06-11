#ifndef PROTCOMERCIAL_H_INCLUDED
#define PROTCOMERCIAL_H_INCLUDED
#define ARCHPROD "Productos"
#define COMPFECHA(A,B,C,D,E,F) ((A)-(B) == 0 ? ((C)-(D) == 0 ? (E)-(F): (C)-(D)):(A)-(B))
#define ES_BISSIESTO(X) ((X) % 4 == 0 && (X) % 100 != 0) || (X) % 400 == 0
#define MAYOR100(X) (X) > 100
#define comparar compararXfcomYDescrp
#define O_K 0
#define CLA_DUP 1
#define SIN_MEM 2
#define CON_SIN_MSJ 1
typedef struct
{
    int dia,
        mes,
        anio;
}fecha;

typedef struct
{
    char codi[10],
         desc[50],
         prov[26];
    fecha fcom,
          fvta;
    float prec,
          cost;
    int cant;
}producto,tInfo;

typedef struct
{
    fecha fcom;
    int stockMin;
}datos;

typedef struct tNodo
{
    tInfo info;
    struct tNodo *sig;
}tNodo, *Lista;
//Manejo archivos
void crearArchivo(FILE **fp);
int abrirArchivo(FILE **fp,const char *nombre,const char *modo,int CON_SIN);
int compararXfcomYstock(const tInfo *d1,const datos *d2);
void actualizacionPrecio(FILE ** fp,tInfo *d);
int fechaValida(fecha *d);
//Manejo lista
void crearLista(Lista *p);
int listaVacia(Lista *p);
int listaLlena(Lista *p);
int insertarPorFechaVentaYdescripcion(Lista *p,const tInfo *d,int (*comparar)(const tInfo*,const tInfo*));
int compararXfcomYDescrp(const tInfo *d1,const tInfo *d2);
void eliminarDeLista(Lista *p,char *prov);
void vaciarLista(Lista *p);
void mostrarArchivo(FILE **fp);
void mostrarProd(const tInfo *d);
#endif // PROTCOMERCIAL_H_INCLUDED
