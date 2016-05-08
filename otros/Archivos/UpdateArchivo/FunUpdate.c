#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ProUpdate.h"
int abrirArchivo(FILE **fp,char *modo,char *archivo,int CON_SIN)
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

int getIntoPerson(person *reg)
{
       if(menuOption("Desea ingresar datos?","YN"))
        {
            fflush(stdin);
            scanf("%ld",&reg->dni);
             fflush(stdin);
            scanf("%s %s",&reg->surName,&reg->firstName);
             fflush(stdin);
            scanf("%c",&reg->sex);
             fflush(stdin);
            scanf("%02d/%02d/%04d",&reg->fec.day,&reg->fec.month,&reg->fec.year);
             fflush(stdin);
            scanf("%f",&reg->salary); // ponfo 0.2f y no me guarda el campo ingresado

            return 1;
        }

       return 0;
}

char menuOption(const char *msj,const char *option)
{
    char op;
    puts(msj);
    do{
    fflush(stdin);
    scanf("%c",&op);
    }while(!strchr(option,toupper(op)));

    return (*strchr(option,toupper(op)) == 'Y'? 1 : 0);
}

void createFile()
{
    FILE *file = fopen(persons,"wb");
    person vec[] = {{87143658L, "Allende","Miguel",'M',{12,3,1996},9000},
                  {47896425L,"Merlo","Micaela",'F',{24,2,1990},7000},
                  {16887451L,"Pagnutti","Jose",'M',{26,4,1992},3000},
                  {87952123L,"Recalde","Camila",'F',{29,7,1993},3000},
                  {34562501L,"Solla","Tamara",'F',{13,3,1993},6000},
                  {22366985L,"Vizzoni","Daniela",'F',{9,7,1997},9000},
                  {46868278L,"Franzoi","Maximiliano",'M',{22,1,1990},5000},
                  {16549654L,"Sosa","Federico",'M',{5,3,1993},6000}};
    if(file)
        fwrite(vec,1,sizeof(vec),file);

    fclose(file);
}

void showFile(FILE **fp)
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
        printf("%08ld   %-*s   %-*s   %c %2d/%2d/%2d   %.2f \n",
                p->dni,
                sizeof(p->surName)-1, p->surName,
                sizeof(p->firstName)-1,p->firstName,
                p->sex,
                p->fec.day,
                p->fec.month,
                p->fec.year,
                p->salary);
    }
    else
    {
        printf(" %-*s    %-*s %-*s SEXO FECHA SUELDO\n",sizeof(p->dni),"D.N.I",sizeof(p->surName),"APELLIDO(S)",sizeof(p->firstName),"NOMBRE(S)");
    }
}

