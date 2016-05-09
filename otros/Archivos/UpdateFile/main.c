#include <stdio.h>
#include <stdlib.h>
#include "ProUpdate.h"

int main()
{
    FILE *fp;
    FILE *fpe;
    person regP;
    employee regE;
    int cmp;

    printf("\t\t\t\t\t\t\t\tFile Update\n\n");
    createFilePerson();
    createFileEmployee();
    if(!openFile(&fp,"r+b",FileToUpdate,CON_SIN_MSJ))
       return 1;
    if(!openFile(&fpe,"r+b",FileUpdate,CON_SIN_MSJ))
    {
        fclose(fp);
        return 1;
    }

    fread(&regP,1,sizeof(person),fp);
    fread(&regE,1,sizeof(employee),fpe);

    while(!feof(fp) && !feof(fpe))
    {
        cmp = compare(&regP,&regE);

        if(cmp < 0)
            fread(&regP,1,sizeof(person),fp);
        else
        {
            if(cmp > 0)
                fread(&regE,1,sizeof(employee),fpe);
            else
            {
                if(regP.qualification > 7)
                {
                    regE.salary *= 1.15;
                    fseek(fpe,-1 * sizeof(employee),SEEK_CUR);
                    fwrite(&regE,1,sizeof(employee),fpe);
                    fseek(fpe,0L,SEEK_SET);// para volver a leer
                }
                fread(&regP,1,sizeof(person),fp);
                fread(&regE,1,sizeof(employee),fpe);
            }

        }
    }
    showFilePerson(&fp);
    puts(" ");
    showFileEmployee(&fpe);
    fclose(fp);
    fclose(fpe);
    return 0;
}
