#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *mem_chr(const void*, int, size_t);
int mem_cmp(const void*,const void*,int);
void *mem_cpy(const void*, const void*, int);
void *mem_set(void *,int, size_t);
char *str_cat(char*, const char*);
char *str_chr(char*, int);
int str_cmp(const char*, const char*);
char *str_cpy(char *,const char*);
size_t str_cspn(const char*, const char*);
char *str_error(int);
char *str_ncat(char*, const char*, size_t);
int str_ncmp(const char*, const char*, size_t);
char *str_ncpy(char*, const char*, size_t);
char *str_pbrk(const char*, const char*);

void main()
{
    char cad[31], cad2[31];
    //int carc;
    puts("\t\tIngrese cadena:\n\n\t\t");
    gets(cad2);
//    puts("\n\n\t\tIngrese caracter a buscar en cadena:\n\t\t\t");
//    scanf("%d",&carc);
    printf("%s\n\n\t", str_cpy(cad,cad2));
}
//
//void *mem_chr(const void *s, int c, size_t n)
//{
//    while((unsigned char)*s != (unsigned char)c && n != 0)
//    {
//        s++;
//        n--;
//    }
//    return n ? s : NULL;
//
//}
//
//int mem_cmp(const void *s1,const void *s2,int n)
//{
//    while((unsigned char)*s1 == (unsigned char)*s2 && n != 0)
//    {
//        n --;
//        s1 ++;
//        s2 ++;
//    }
//    return ((unsigned char)*s1 - (unsigned char)*s2); //si sale xq n=0, al hacer la resta y como las dos cadenas son iguales va a retornar 0
//}
//
//void *mem_cpy(void *s1, const void *s2, int n)
//{
//    void *aux = s1;
//
//    while(n --)
//
//        *s1 ++ = *s2 ++;//ver si lo podes hacer en la misma linea cuando funcione
//
//    return aux;
//}
//void *mem_set(void *s,int c, size_t n)
//{
//    void *aux = s;
//
//    while(n --)
//    {
//      *((unsigned char*)aux) ++ = (unsigned char) c; //no se si el casteo esta bien
//    }
//    return s;
//}
//char *str_cat(char *s1, const char *s2) //fijate si esta bien puestos los operadores '++' y '--'
//{
//    char * aux = s1;
//
//    while(*aux)// hay que clavarle el ; ?
//        aux ++;
//
//    while(s2 ++)                       // fijate si hay que clavarle el caracter nulo
//      *aux = *s2;
//
//    return s1;
//}
//char *str_chr(char *s, int c)
//{
//    while(*s && *s != (unsigned char)c)
//      s++;
//
//    return (*s == (unsigned char)c ? s : NULL; //al puntero tambien lo tengo que convertir a unsigned??
//}
//
////Hace una comparacon sin signo (unsigned char) de las cadenas s1 y s2
//int str_cmp(const char *s1, const char *s2)
//{
//    while(*s1 && *s1 == *s2)//preguntar por como compara los caracteres
//    {
//        s1 ++;
//        s2 ++;
//    }
//    return (*(unsigned char *)s1 - *(unsigned char *)s1);
//}
char *str_cpy(char *s1,const char *s2)
{
    char *aux = s1;

    while(*s2)
        *s1 ++ = *s2 ++;
    *s1 = '\0';

    return aux;
}
//
//size_t str_cspn(const char *s1, const char *s2)
//{
//    size_t cant = 0;
//
//    while(*s1 && !strchr(s2,*s1)) //strchr devuelve el puntero al carcter encontrado o null si no esta.
//    {
//        cant ++;
//        s1 ++;
//    }
//    return cant;
//}
//char *str_error(int numerror)
//{
//    char vec[41];
//
//    sprintf(vec,"%.*s\n",sizeof(vec) - 2, numerror >= 0 && numerror < system_error ? sys_errlist[numerror] : "Unknow Error");
//
//    return vec;
//}
//size_t str_len(const char *s)
//{
//    size_t cant;
//
//    while(*s ++) //preguntar por procedencia de operadores, esta mal esto
//      cant ++;
//
//    return cant;
//}
//char *str_ncat(char*s1, const char *s2, size_t n)
//{
//    char *aux = s1;
//
//    while(*aux)
//        aux ++;//preguntar por procedencia de operadores
//    while(*s2 && n --)
//        *s1 ++ = *((char *)s2) ++;
//    *s1 = '\0';
//    return aux;
//}
//int str_ncmp(const char *s1, const char *s2, size_t n) // preguntar por como lo hizo el profe
//{
//    while(*s1 && *s1 ++ == *s2 ++ && n --)
//        ;
//    return (n == 0 || *s1 == '\0' ? 0 : (*(unsigned char*)s1) - (*(unsigned char*)s2));
//}
//
//char *str_ncpy(char *s1, const char *s2, size_t n)
//{
//    char *aux = s1;
//
//    while(*s2 ++ && n --)
//
//        *s1 ++ = *(char*)s2;
//    while(n --)
//
//     s1* ++ = '\0';
//
//    return aux;
//}
//
//char *str_pbrk(const char *s1, const char *s2)
//{
//    char *aux = (char*)s1, aux2 = (char*)s2;
//
//    while(*aux && !strchr(aux2,*aux))// aux++ aca
//        aux ++;
//
//    return *aux ? aux : NULL;
//}
