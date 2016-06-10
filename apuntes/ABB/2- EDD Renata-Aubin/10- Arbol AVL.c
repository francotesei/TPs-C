/*En las Ciencias de la Computación, se trata un subtipo de árboles, los Árboles Binarios.
en su estructura de información, puede hacer referencia a lo sumo a dos subárboles diferenciados, el subárbol izquierdo y el subárbol derecho.
se puede tener un árbol vacío.
Se reconoce que habrá una referencia al nodo raíz, y que esta no forma parte de la estructura de datos del Árbol Binario.
Esta referencia tendrá la dirección del nodo raiz, si este existe.
A partir de la raiz del árbol, se tendrá un subárbol izquierdo y un subábol derecho que verifican recursivamente la definición.  Es decir que de existir subárbol izquierdo (y/o derecho), este puede ser vacío o tener un nodo (raiz del subábol izquierdo/derecho), que puede tener subárbol izquierdo y/o derecho.
Así mismo compartimos que la raiz, de existir se encuentra en el nivel 0 (cero), y que los nodos (raices de sus subárboles izquierdo/derecho), de existir se encuentran en el nivel 1, y así sucesivamente.
Los nodos que no tienen ninguno de sus subárboles derecho ni izquierdo, se denominan hojas.
profundidad de un árbol, como el máximo nivel de alguna de sus hojas.
altura como uno más que el nivel,  la profundidad,  la hacen igual al nivel.
no se puede hablar de profundidad ni nivel de un árbol vacío. */

/** precondición: Árbol NO VACÍO */
int profundidadArbol(t_arbol *p)
{
   if(*p)
   {
      int profIzq = profundidadArbol(&(*p)->izq),
          profDer = profundidadArbol(&(*p)->der);
      return profIzq > profDer ? profIzq + 1 : profDer + 1;
   }
   return -1; /* con árbol vacío devuelve -1 = ERROR: no debía utilizar esta primitiva */
}

/** sin precondición, devuelve cero cuando el árbol está vacío */
int alturaArbol(t_arbol *p)
{
   if(*p)
   {
      int altIzq = profundidadArbol(&(*p)->izq),
          altDer = profundidadArbol(&(*p)->der);
      return altIzq > altDer ? altIzq + 1 : altDer + 1;
   }
   return 0; /* con árbol vacío devuelve 0 = indicador de esta condición */
}

En ambos casos vale el > o el >= en el condicional.

Árbol Binario Completo:
- Es un Árbol Binario en que todos sus nodos, salvo las hojas tienen subárbol por izquierda y también subárbol por derecha.  Es decir que es estrictamente binario.
- Además todas sus hojas se encuentran al mismo nivel/alura/profundidad.

Con lo cual tiene 2 ^ (h - 1) - 1 nodos, o sea 2 ^ p - 1 nodos.

Teniendo en cuenta que las hojas estarán a la altura máxima ... lo que hablamos.
int arbolCompleto(t_nodo *p)
{
   int h = alturaArbol(p);
   return esCompleto(p, h);  /* invocando la funci'on que lo determina */
}

int esCompleto(t_nodo *p, int h)
{
   if(*p)
   {
      return esCompleto(&(*p)->izq, h - 1) && esCompleto(&(*p)->der, h - 1);
   }
   return h == 0;
}


Árbol Balanceado:  dado un árbol de altura/profundidad dada es balanceado si comprende un árbol completo de altura/profundidad con una altura/profundidad uno menos que la propia.

int arbolBalanceado(t_nodo *p)
{
   int h = alturaArbol(p);
   return esBalanceado(p, h);  /* invocando la funci'on que lo determina */
}

int esBalanceado(t_nodo *p, int h)
{
   if(*p)
   {
      return esBalanceado(&(*p)->izq, h - 1) && esBalanceado(&(*p)->der, h - 1);
   }
   return h <= 1;
}
