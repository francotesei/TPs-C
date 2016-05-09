#ifndef PROUPDATE_H_INCLUDED
#define PROUPDATE_H_INCLUDED
#define FileToUpdate "PersonFile"
#define FileUpdate "EmployeeFile"
#define CON_SIN_MSJ 1
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
    float qualification;
}person;

typedef struct
{
    long dni;
    char surName[50],
         firstName[50],
         sex;
    date fec;
    float qualification;
    float salary;
}employee;

void createFilePerson();
void createFileEmployee();
int openFile(FILE **fp,char *modo,char *archivo,int CON_SIN);
int compare(person *a,employee *b);
int compareDate(date *fec1,date *fec2);
void showFilePerson(FILE **fp);
void showPerson(person *p);
void showFileEmployee(FILE **fp);
void showEmployee(employee *p);
#endif // PROUPDATE_H_INCLUDED
