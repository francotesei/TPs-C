#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"
#include "ProUpdate.h"

int main()
{
    FILE *fp;//puntero a archivo binario
    FILE *ft1;//puntero a archivo de text de longitud fija
    FILE *ft2;//puntero a archivo de text de longitud variable
    person reg;
    //Crear archivos
    puts("/t/t/t/t/t/t/t/t/t/tUpdate File/n/n");
    if(!abrirArchivo(&fp,"wb",personas,CON_SIN_MSJ))
        return 1;
    if(!abrirArchivo(&ft1,"wb",personas1,CON_SIN_MSJ))
    {
      fclose(fp);
      return 2;
    }
    if(!abrirArchivo(&ft2,"wb",personas2,CON_SIN_MSJ))
    {
        fclose(fp);
        fclose(ft1);
        return 3;
    }

    while(getIntoPerson(reg))
    {
        //Escritura de archivo binario
        fwrite(&reg,sizeof(person),1,fp);
        //Escritura de archivo de text de longitud fija
        fprintf(ft1,"%8ld %-*s %-*s %c %02d %02d %04d %09.2f\n",
                reg.dni,
                sizeof(reg.nom),reg.nom,
                sizeof(reg.ape),reg.ape,
                reg.sex,
                reg.day,
                reg.month,
                reg.year,
                reg.salary);
        //Escritura de archivo de text de longitud fija
        fprintf(ft2,"%ld %s %s %c %d %d %d %.2f\n",
                reg.dni,
                sizeof(reg.nom),reg.nom,
                sizeof(reg.ape),reg.ape,
                reg.sex,
                reg.day,
                reg.month,
                reg.year,
                reg.salary);
    }

    fclose(fp);
    fclose(ft1);
    fclose(ft2);
    return 0;
}
