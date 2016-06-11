#include <stdio.h>
#include <stdlib.h>
#include "protClientes.h"

int main()
{
    FILE *cliente,
         *indice,
         *novedad;
    Lista lista;
    tInfo indi;
    printf("\t\t\t\t\t\tPrueba Listas\n\n");

    if(!abrirArchivo(&cliente,ARCH_CLI,"r+b",!CON_SIN_MSJ))
    {
        crearArchivoCli(&cliente);
        if(!abrirArchivo(&cliente,ARCH_CLI,"r+b",CON_SIN_MSJ))
            return 0;
    }
    if(!abrirArchivo(&indice,ARCH_IND,"r+b",!CON_SIN_MSJ))
    {
        crearArchivoInd(&indice);
        if(!abrirArchivo(&indice,ARCH_IND,"r+b",CON_SIN_MSJ))
        {
            fclose(cliente);
            return 0;
        }
    }
    if(!abrirArchivo(&novedad,ARCH_NOV,"r+b",!CON_SIN_MSJ))
    {
        crearArchivoNov(&novedad);
        if(!abrirArchivo(&novedad,ARCH_NOV,"r+b",CON_SIN_MSJ))
        {
            fclose(cliente);
            fclose(indice);
            return 0;
        }
    }
    crearLista(&lista);
    fread(&indi,1,sizeof(tInfo),indice);
    while(!feof(indice) && !listaLlena(&lista))
    {
        insertarEnOrden(&lista,&indi,compararXindice);
        fread(&indi,1,sizeof(tInfo),indice);
    }
    fclose(indice);
    if(!listaVacia(&lista))
        actualizarArch(&cliente,&novedad,&lista);
    mostrarArchivo(&cliente);
    fclose(novedad);
    vaciarLista(&lista);
    return 0;
}
