#include <stdio.h>
#include <string.h>
#include "ProUpdate.h"

void createFilePerson()
{
    FILE *file = fopen(FileToUpdate,"wb");
    person vec[] = {{87143658L, "Allende","Miguel",'M',{12,03,1996},7.5},
                    {46868278L,"Franzoi","Maximiliano",'M',{22,01,1990},4.36},
                    {47896425L,"Merlo","Micaela",'F',{24,02,1990},8.55},
                    {16887451L,"Pagnutti","Jose",'M',{26,04,1992},8.98},
                    {87952123L,"Recalde","Camila",'F',{29,07,1993},5.56},
                    {34562501L,"Solla","Tamara",'F',{13,03,1993},7.29},
                    {16549654L,"Sosa","Federico",'M',{5,03,1993},4.89},
                    {22366985L,"Vizzoni","Daniela",'F',{9,07,1997},6.56}};
    if(file)
        fwrite(vec,1,sizeof(vec),file);

    fclose(file);
}

void createFileEmployee()
{
    FILE *file = fopen(FileUpdate,"wb");
    employee vec[] = {{87143658L, "Allende","Miguel",'M',{12,03,1996},7.5,9000},
                 {30589425L,"Brito","Claudio",'M',{4,9,2002},8,9000},
                 {46558892L,"Cena","Marcelo",'M',{23,12,1990},8.9,9000},
                 {79815612L,"Dominguez","Diego",'M',{21,01,1990},6.89,9000},
                 {46868278L,"Franzoi","Maximiliano",'M',{22,01,1990},4.36,5000},
                 {32589614L,"Herrera","Cristobal",'M',{5,11,2003},7.5,5000},
                 {47896425L,"Merlo","Micaela",'F',{24,02,1990},8.55,7000},
                 {98713469L,"Oviedo","Cesar",'M',{9,03,2004},6,5000},
                 {16887451L,"Pagnutti","Jose",'M',{26,04,1992},8.98,3000},
                 {91649487L,"Perez","Leandro",'M',{27,05,1993},7.39,3000},
                 {81659417L,"Recalde","Jose",'M',{28,06,1993},7.28,3000},
                 {87952123L,"Recalde","Camila",'F',{29,07,1993},5.56,3000},
                 {32139745L,"Rodriguez","Fabiana",'F',{30,8,1993},7,9000},
                 {97962146L,"Romero","Johana",'F',{3,8,1993},8.78,6000},
                 {34562501L,"Solla","Tamara",'F',{13,03,1993},7.29,6000},
                 {16549654L,"Sosa","Federico",'M',{5,03,1993},4.89,6000},
                 {66547893L,"Spinelli","Ezequiel",'M',{6,01,1994},6.78,6000},
                 {21656154L,"Tapia","Jorge",'M',{7,05,1995},8.56,6000},
                 {54514964L,"Torres","Mario",'M',{8,06,1996},7.89,9000},
                 {22366985L,"Vizzoni","Daniela",'F',{9,07,1997},6.56,9000}};
    if(file)
        fwrite(vec,1,sizeof(vec),file);
    fclose(file);
}

int openFile(FILE **fp,char *modo,char *archivo,int CON_SIN)
{
    *fp = fopen(archivo,modo);//devuelve una direccion de memoria

    if(!*fp)
    {
        if(CON_SIN_MSJ == CON_SIN)
            fprintf(stderr,"Error-abriendo\"%s\" en modo \"%s\"\n",archivo,modo);

        return 0;
    }
    return 1;
}

int compare(person *a,employee *b)
{
    int cmp = strcmp(a->surName,b->surName);

    if(cmp)
        return cmp;
    cmp = strcmp(a->firstName,b->firstName);
    if(cmp)
        return cmp;
    cmp = compareDate(&a->fec,&b->fec);
    if(cmp)
        return cmp;
    return (a->dni - b->dni);
}

int compareDate(date *fec1,date *fec2)
{
    int cmp = (fec1->year - fec2->year);

    if(!cmp)
    {
        cmp = (fec1->month - fec2->month);
        if(!cmp)
        {
            cmp = (fec1->day - fec2->day);
        }
    }
    return cmp;
}

void showFilePerson(FILE **fp)
{
   person reg;
   long actualPos = ftell(*fp);
   rewind(*fp);
   showPerson(NULL);
   while(!feof(*fp))
   {
       fread(&reg,sizeof(person),1,*fp);
       showPerson(&reg);
   }
   fseek(*fp,actualPos,SEEK_SET);
   fclose(*fp);
}

void showPerson(person *p)
{
    if(p)
    {
        printf("%08ld   %-*s  %-*s  %c    %2d/%2d/%2d     %.2f \n",
                p->dni,
                sizeof(p->surName)-1, p->surName,
                sizeof(p->firstName)-1,p->firstName,
                p->sex,
                p->fec.day,
                p->fec.month,
                p->fec.year,
                p->qualification);
    }
    else
    {
        printf(" %-*s    %-*s %-*s SEXO    FECHA     CALIFICACION\n",sizeof(p->dni),"D.N.I",sizeof(p->surName),"APELLIDO(S)",sizeof(p->firstName),"NOMBRE(S)");
    }
}

void showFileEmployee(FILE **fp)
{
   employee reg;
   long actualPos = ftell(*fp);
   rewind(*fp);
   showEmployee(NULL);
   while(!feof(*fp))
   {
       fread(&reg,sizeof(employee),1,*fp);
       showEmployee(&reg);
   }
   fseek(*fp,actualPos,SEEK_SET);
   fclose(*fp);
}

void showEmployee(employee *p)
{
    if(p)
    {
        printf("%08ld   %-*s  %-*s  %c    %2d/%2d/%2d     %.2f        %.2f\n",
                p->dni,
                sizeof(p->surName)-1, p->surName,
                sizeof(p->firstName)-1,p->firstName,
                p->sex,
                p->fec.day,
                p->fec.month,
                p->fec.year,
                p->qualification,
                p->salary);
    }
    else
    {
        printf(" %-*s    %-*s %-*s SEXO     FECHA    CALIFICACION   SUELDO\n",sizeof(p->dni),"D.N.I",sizeof(p->surName),"APELLIDO(S)",sizeof(p->firstName),"NOMBRE(S)");
    }
}
