#include <stdio.h>
#include <stdlib.h>
#include "ArchProt.h"
#include "prototipos.h"

int main()
{
    FILE *fp;
    createFile();

    if(abrirArchivo(&fp,"rb",persons,CON_SIN_MSJ))
     {
         printf("\t\t\t\t\t\tPRUEBA MANEJO DE ARCHIVOS\n\n\n");
         showFile(&fp);
     }
    return 0;
}
