#include <stdio.h>
#include <stdlib.h>
#include "ProLoadFile.h"

int main()
{
    FILE *fp;//puntero a archivo binario
    FILE *ft1;//puntero a archivo de text de longitud fija
    FILE *ft2;//puntero a archivo de text de longitud variable
    person reg;
    //Crear archivos
    puts("\t\t\t\t\t\t\t\t\t\tUpdate File");
    if(!abrirArchivo(&fp,"w+b",persons,CON_SIN_MSJ))
        return 1;
    if(!abrirArchivo(&ft1,"w+t",personstext,CON_SIN_MSJ))
    {
      fclose(fp);
      return 2;
    }
    if(!abrirArchivo(&ft2,"w+t",personstext2,CON_SIN_MSJ))
    {
        fclose(fp);
        fclose(ft1);
        return 3;
    }
//Cargando Archivos
    while(getIntoPerson(&reg))
    {
        //Escritura de archivo binario
        fwrite(&reg,1,sizeof(person),fp);
        //Escritura de archivo de text de longitud fija
        fprintf(ft1,"%08ld%-*s%-*s%c%02d%02d%04d%09.2f\n",
                reg.dni,
                sizeof(reg.surName),reg.surName,
                sizeof(reg.firstName),reg.firstName,
                reg.sex,
                reg.fec.day,
                reg.fec.month,
                reg.fec.year,
                reg.salary);
        //Escritura de archivo de text de longitud fija
        fprintf(ft2,"%ld%s%s%c%d%d%d%.2f\n",
                reg.dni,
                reg.surName,
                reg.firstName,
                reg.sex,
                reg.fec.day,
                reg.fec.month,
                reg.fec.year,
                reg.salary);
    }


    puts("Mostrando archivo cargado\n\n");
    showFile(&fp);
    puts("\nFin de la carga...");

    fclose(fp);
    fclose(ft1);
    fclose(ft2);
    return 0;
}
