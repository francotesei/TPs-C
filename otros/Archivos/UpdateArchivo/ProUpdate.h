#ifndef PROUPDATE_H_INCLUDED
#define PROUPDATE_H_INCLUDED
#define CON_SIN_MSJ  1
#define persons "persons"
#define personstext "personstext"
#define personstext2 "personstext2"

typedef struct
{
    int day,
        month,
        year;
}date;

typedef struct
{
    long dni;
    char surName[50],
         firstName[50],
         sex;
    date fec;
    float salary;
}person;

void createFile();
void showFile(FILE **fp);
void showPerson(person *p);
int abrirArchivo(FILE **fp,char *modo,char *archivo,int CON_SIN);
int getIntoPerson(person *reg);
char menuOption(const char *msj,const char *option);


#endif // PROUPDATE_H_INCLUDED
