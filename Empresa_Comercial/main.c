#include <stdio.h>
#include <stdlib.h>
#include "protComercial.h"

int main()
{
    FILE *fp;
    Lista lista;
    tInfo reg;
    datos dato;
    char prov[26];
    printf("\t\t\t\t\tEJEMPLO DE PARCIAL\n\n");
    printf("\t\t\t\t\tIngrese fecha y cantidad minima a evaluar\n");

    if(!abrirArchivo(&fp,ARCHPROD,"r+b",!CON_SIN_MSJ))
    {
        crearArchivo(&fp);
        if(!abrirArchivo(&fp,ARCHPROD,"r+b",CON_SIN_MSJ))
            return 0;
    }
    crearLista(&lista);
    do
    {
        printf("Fecha: ");
        fflush(stdin);
        scanf("%d/%d/%d",&dato.fcom.dia,&dato.fcom.mes,&dato.fcom.anio);
    }while(!fechaValida(&dato.fcom));

    printf("\nCantidad minima: ");
    scanf("%d",&dato.stockMin);

    fread(&reg,1,sizeof(reg),fp);
    while(!feof(fp))
    {
        if(compararXfcomYstock(&reg,&dato))
            actualizacionPrecio(&fp,&reg);
        if(!listaLlena(&lista))
            insertarPorFechaVentaYdescripcion(&lista,&reg,compararXfcomYDescrp);

        fread(&reg,1,sizeof(reg),fp);
    }
    system("cls");
    mostrarArchivo(&fp);
    fclose(fp);
    printf("\t\t\t\t\nIngrese el proveedor a eliminar de la lista: ");
    fflush(stdin);
    gets(prov);
    eliminarDeLista(&lista,prov);
    vaciarLista(&lista);

    return 0;
}
