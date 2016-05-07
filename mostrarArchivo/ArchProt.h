#ifndef MOSTRARARCHPROT_H_INCLUDED
#define MOSTRARARCHPROT_H_INCLUDED
#define persons "persons"

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

#endif // MOSTRARARCHPROT_H_INCLUDED
