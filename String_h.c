#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *mem_chr(const void*, int, size_t);
int mem_cmp(const void*,const void*,int);
void *mem_cpy(void*, const void*, int);
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

//void main()//strcpy
//{
//    char cad[31], cad2[31];
//    puts("\t\tIngrese cadena:\n\n\t\t");
//    gets(cad2);
//    printf("%s\n\n\t", str_cpy(cad,cad2));
//}

//void main()//memchr
//{
//    char cad[31];
//
//    puts("\t\tIngrese cadena:\n\n\t\t");
//    gets(cad);
//    printf("%s\n\n\t", mem_chr(cad,'d',8));
//}
//
//void main()//mem_cmp
//{
//    char cad[31],cad2[31];
//    int mem;
//    puts("\t\tIngrese cadena 1:\n\n\t\t");
//    gets(cad);
//    puts("\t\tIngrese cadena 2:\n\n\t\t");
//    gets(cad2);
//    mem = mem_cmp(cad,cad2,5);
//    if(mem > 0 || mem < 0)
//    {
//        if(mem > 0)
//          printf("\n\n\t cadena 1 mayor a cadena 2");
//        else
//          printf("\n\n\t cadena 1 menor a cadena 2");
//    }
//    else
//        printf("\n\n\t cadena 1 igual a cadena 2");
//}

//void main()//mem_cpy
//{

//    char cad[31], cad2[31];
//    puts("\t\tIngrese cadena:\n\n\t\t");
//    gets(cad2);
//    puts(mem_cpy(cad,cad2,6));
//}

//void main()//mem_set
//{
//
//    char cad[31];
//    puts("\t\tIngrese cadena:\n\n\t\t");
//    gets(cad);
//    puts(mem_set(cad,2,6));
//}

//void main()//str_cat
//{
//
//    char cad[31], cad2[31];
//    puts("\t\tIngrese cadena 1:\n\n\t\t");
//    gets(cad);
//    puts("\t\tIngrese cadena 2:\n\n\t\t");
//    gets(cad2);
//    puts(str_cat(cad,cad2));
//}

//void main()//str_chr
//{
//
//    char cad[31];
//    puts("\t\tIngrese cadena 1:\n\n\t\t");
//    gets(cad);
//    puts(str_chr(cad,'h'));
//}

//void main()//str_cmp
//{
//
//    char cad[31],cad2[31];
//    int mem;
//    puts("\t\tIngrese cadena 1:\n\n\t\t");
//    gets(cad);
//    puts("\t\tIngrese cadena 2:\n\n\t\t");
//    gets(cad2);
//    mem = str_cmp(cad,cad2);
//    printf("\n %d",mem);
//    if(mem > 0 || mem < 0)
//    {
//        if(mem > 0)
//          printf("\n\n\t cadena 1 mayor a cadena 2");
//        else
//          printf("\n\n\t cadena 1 menor a cadena 2");
//    }
//    else
//       printf("\n\n\t cadena 1 igual a cadena 2");
//}


//void *mem_chr(const void *s, int c, size_t n)
//{
//    void *s2 = s;
//    while(*(unsigned char*)s2 != (unsigned char)c && n != 0)
//    {
//        s2++;
//        n--;
//    }
//   return n ? s2 : NULL;
//   //Localiza la primera aparición del carácter c (convertido a unsigned char) en los
////primeros n caracteres (cada uno interpretado como un unsigned char) del objeto
////apuntado por s.
////La función retorna un puntero al carácter localizado, o un puntero nulo si el carácter no
////apareció en el objeto.
//}
//
//int mem_cmp(const void *s1,const void *s2,int n)
//{
//    while(*(unsigned char*)s1 == *(unsigned char*)s2 && n != 0)
//    {
//        n --;
//        s1 ++;
//        s2 ++;
//    }
//    return (*(unsigned char*)s1 - *(unsigned char*)s2); //si sale xq n=0, al hacer la resta y como las dos cadenas son iguales va a retornar 0
//
////    Compara los primeros n caracteres del objeto apuntado por s1 (interpretado como
////unsigned char) con los primeros n caracteres del objeto apuntado por s2 (interpretado
////como unsigned char).
////La función retorna un número entero mayor, igual, o menor que cero, apropiadamente
////según el objeto apuntado por s1 es mayor, igual, o menor que el objeto apuntado por
////s2.
//}
//
//void *mem_cpy(void *s1, const void *s2, int n)
//{
//    void *aux = s1;
//    void *aux2 = s2;
//
//    while(n --)
//    {
//        *((char*)aux) = *((char*)aux2);//ver si lo podes hacer en la misma linea cuando funcione
//        aux ++;
//        aux2 ++;
//    }
//
//    return s1;
//
////    Copia los primeros n caracteres del objeto apuntado por s2 al objeto apuntado por s1.
////    La función retorna el valor de s1. Si al copiar un objeto al otro se superponen, entonces
////el comportamiento no está definido.
//}
//void *mem_set(void *s,int c, size_t n)
//{
//    void *aux = s;
//
//    while(n --)
//    {
//      *((unsigned char*)aux) = (unsigned char) c; //no se si el casteo esta bien
//      aux ++;
//    }
//    return s;
//
////    Copia el valor de c (convertido a unsigned char) en cada uno de los primeros n
////caracteres en el objeto apuntado por s.
////La función retorna el valor de s.
//}
//char *str_cat(char *s1, const char *s2) //fijate si esta bien puestos los operadores '++' y '--'
//{
//    char * aux = s1, *aux2 = s2;
//
//    while(*aux)// hay que clavarle el ; ?
//        aux ++;
//
//    while(*aux2)                       // fijate si hay que clavarle el caracter nulo
//      *aux ++ = *aux2 ++;
//    *aux = '\0';
//
//    return s1;
//
////    Añade una copia de la cadena apuntada por s2 (incluyendo el carácter nulo) al final de
////la cadena apuntada por s1. El carácter inicial de s2 sobrescribe el carácter nulo al final
////de s1.
////La función retorna el valor de s1. Si la copia hace que los objetos se superpongan,
////entonces el comportamiento no está definido.
//}

//char *str_chr(char *s, int c)
//{
//    while(*s && *s != (unsigned char)c)
//      s++;
//
////    return (*s == (unsigned char)c ? s : NULL);
////    Localiza la primera aparición de c (convertido a unsigned char) en la cadena apuntada
////por s (incluyendo el carácter nulo).
////La función retorna un puntero a partir del carácter encontrado. Si no se ha encontrado
////el carácter, c, entonces retorna un puntero null.
//}


//int str_cmp(const char *s1, const char *s2)
//{
//    char *aux = s1, *aux2 = s2;
//
//    while(*aux && *aux == *aux2)//preguntar por como compara los caracteres
//    {
//        aux ++;
//        aux2 ++;
//    }
//    return (*(unsigned char *)aux - *(unsigned char *)aux2);
////    Compara la cadena apuntada por s1 con la cadena apuntada por s2.
////    La función retorna un número entero mayor, igual, o menor que cero, apropiadamente
////según la cadena apuntada por s1 es mayor, igual, o menor que la cadena apuntada por
////s2.
//}
//Copia la cadena apuntada por s2 (incluyendo el carácter nulo) a la cadena apuntada por
//s1.
//char *str_cpy(char *s1,const char *s2)
//{
//    char *aux = s1;
//
//    while(*s2)
//        *s1 ++ = *s2 ++;
//    *s1 = '\0';
//
//    return aux;
//}
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
