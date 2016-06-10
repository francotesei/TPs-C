/*En las Ciencias de la Computaci�n, se trata un subtipo de �rboles, los �rboles Binarios.
en su estructura de informaci�n, puede hacer referencia a lo sumo a dos sub�rboles diferenciados, el sub�rbol izquierdo y el sub�rbol derecho.
se puede tener un �rbol vac�o.
Se reconoce que habr� una referencia al nodo ra�z, y que esta no forma parte de la estructura de datos del �rbol Binario.
Esta referencia tendr� la direcci�n del nodo raiz, si este existe.
A partir de la raiz del �rbol, se tendr� un sub�rbol izquierdo y un sub�bol derecho que verifican recursivamente la definici�n.  Es decir que de existir sub�rbol izquierdo (y/o derecho), este puede ser vac�o o tener un nodo (raiz del sub�bol izquierdo/derecho), que puede tener sub�rbol izquierdo y/o derecho.
As� mismo compartimos que la raiz, de existir se encuentra en el nivel 0 (cero), y que los nodos (raices de sus sub�rboles izquierdo/derecho), de existir se encuentran en el nivel 1, y as� sucesivamente.
Los nodos que no tienen ninguno de sus sub�rboles derecho ni izquierdo, se denominan hojas.
profundidad de un �rbol, como el m�ximo nivel de alguna de sus hojas.
altura como uno m�s que el nivel,  la profundidad,  la hacen igual al nivel.
no se puede hablar de profundidad ni nivel de un �rbol vac�o. */

/** precondici�n: �rbol NO VAC�O */
int profundidadArbol(t_arbol *p)
{
   if(*p)
   {
      int profIzq = profundidadArbol(&(*p)->izq),
          profDer = profundidadArbol(&(*p)->der);
      return profIzq > profDer ? profIzq + 1 : profDer + 1;
   }
   return -1; /* con �rbol vac�o devuelve -1 = ERROR: no deb�a utilizar esta primitiva */
}

/** sin precondici�n, devuelve cero cuando el �rbol est� vac�o */
int alturaArbol(t_arbol *p)
{
   if(*p)
   {
      int altIzq = profundidadArbol(&(*p)->izq),
          altDer = profundidadArbol(&(*p)->der);
      return altIzq > altDer ? altIzq + 1 : altDer + 1;
   }
   return 0; /* con �rbol vac�o devuelve 0 = indicador de esta condici�n */
}

En ambos casos vale el > o el >= en el condicional.

�rbol Binario Completo:
- Es un �rbol Binario en que todos sus nodos, salvo las hojas tienen sub�rbol por izquierda y tambi�n sub�rbol por derecha.  Es decir que es estrictamente binario.
- Adem�s todas sus hojas se encuentran al mismo nivel/alura/profundidad.

Con lo cual tiene 2 ^ (h - 1) - 1 nodos, o sea 2 ^ p - 1 nodos.

Teniendo en cuenta que las hojas estar�n a la altura m�xima ... lo que hablamos.
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


�rbol Balanceado:  dado un �rbol de altura/profundidad dada es balanceado si comprende un �rbol completo de altura/profundidad con una altura/profundidad uno menos que la propia.

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
