#include <iostream>

/**
 *****************************************
 Aufgabe 2.1b
 *****************************************
 int intVal = 0;                  4 Bytes
 int *pintVal = &intVal;          4 Bytes - int *
 int **pPintVal = &pIntVal;       4 Bytes - int**
 char charVal = 'C';              1 Byte  - char
 char *pCharVal = &charVal;       4 Bytes - char *
 char **pPcharVal = &pCharVal; // 4 Bytes - char **
 
 *****************************************
 Aufgabe 2.1c
 *****************************************
 
 4 Adressen. Jede Adresse braucht 4 Bytes (32 Bit)
 
 *****************************************
 Aufgabe 2.1d
 *****************************************
 int i = 5; 
 char c = '%' 
 int *pI = &i;
 char *pC = &c;
 
  *****************************************
 Aufgabe 2.1f
 *****************************************
 *p3 = 'S'
 *p3 = 'T', p3 = 6940
 *p1 = 'S', p1 = 6940

  *****************************************
 Aufgabe 2.1i
 *****************************************
 *&intVal	Wert von intVal
 *&pIntVal	Wert von pIntVal (Adresse von intVal)
 &*pIntVal	Wert von pIntVal (Adresse von intVal)
 **&pIntVal	Wert von intVal
 *&*&intVal	Wert von intVal
 &*&pIntVal	Adresse von pIntVal
 *&*pIntVal	Wert von intVal
 *****************************************
 Aufgabe 2.1j
 *****************************************
 *intVal      intVal ist kein Zeiger, kann also auch nicht dereferenziert werden.
 **pIntVal    *pIntVal ist ein int, also kein Zeiger und kann somit auch nicht weiter dereferenziert werden.
 **&*pIntVal  *pIntVal ist ein int, &*pIntVal ist ein Zeiger auf einen int, *&*pIntVal ist wieder ein int,
              also kann er nicht weiter derefernziert werden.
 &*intVal     intVal ist ein int, kann also nicht dereferenziert werden.
 &42          42 ist ein Literal vom Typ int und keine Variable. Nur Variablen haben Adressen im Speicher.
 
 *****************************************
 Aufgabe 2.1o
 *****************************************
 int * const a            Der Integer Wert: *a=1;
 const int * a            Der Pointer, also die Addresse, die in b gespeichert wird: a = &b; wo b const int ist
 int const a              Nichts 
 int const * a            Der Pointer: a=&b; wo b const int ist
 int const * const a      Nichts
 int const * const *a     Der Pointer a, also die Addresse in a. a = &b; //wo b ist int const * const
 int const ** const a     Der Pointer in a, also die Addresse, in der Addresse *a: *a = &b // wo b ist int const.
 int ** const a           Der Wert von **a und der Pointer *a:  *a = &b //wo b ist int, **a = 1;

 *****************************************
 Aufgabe 2.1p
 *****************************************
 
 int *j = &i;
 int i = *j;
 int **k = __i;      nicht möglich
 int **k = &j;
 int i = **k;
 int *j = *k;
 int const l = *j;
 int *j = __l;    nicht möglich. Cannot convert const int* to int*
 int const * const m = j;  //kein Operator. * to const *
 int *j = __m;  nicht möglich. Cannot convert const * to *
 int const * const m = &l; 
 int const *n = j; // kein Operator. int * to const int *
 int const *n = &l;
 int const *n = *k;
 int **k = __n; nicht möglich. Cannot convert const int * to int *
 int **k = __m; nicht möglich. Cannot convert const int * to int *
 int const * const m = *k;
 int const * const *o = &m;
 int const * const *o = &n;
 const int ** const p = __m; nicht möglich. Cannot convert const int * const * to const int **
 const int ** const p = &n;
 
 Alle const Variablen müssen bei der Deklaration auch initialisiert werden, weil sie nicht neu zugewiesen werden dürfen: 
 int const l;
 int const * const m;
 const int ** const p;
 
 */

// Aufgabe 2.1g
void swapPointers(int** p1, int** p2) {
    int* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


// Aufgabe 2.1h
void square(int a) { // Call by Value
    a = a * a;
}

// Aufgabe 2.1h
void square2(int* a) { // Call by Pointer
    *a = *a * *a;
}

// Aufgabe 2.1h
void square3(int& a) { // Call by Reference
    a = a * a;
}

// Aufgabe 2.1k
void swapPointer(int* i1, int* i2) {
    int tmp = *i1;
    *i1 = *i2;
    *i2 = tmp;
}

// Aufgabe 2.1k
void swapReference(int& i1, int& i2) {
    int tmp = i1;
    i1 = i2;
    i2 = tmp;
}

// Aufgabe 2.1l
void foo(int& i) {
    int i2 = i;
    int& i3 = i;
    std::cout << "i = " << i << std::endl;
    std::cout << "i2 = " << i2 << std::endl;
    std::cout << "i3 = " << i3 << std::endl;
    std::cout << "&i = " << &i << std::endl;
    std::cout << "&i2 = " << &i2 << std::endl;
    std::cout << "&i3 = " << &i3 << std::endl;
}

// Aufgabe 2.1m
void constCorrectnessWithVariables() {
    int i = 1;
    int j = 2;

    int* iP = &i;

    const int* ciP = &i;
    ciP = &j;
    //	*ciP = -1; // Error

    int const* ciP2 = &i; // Equivalent to ciP ("to-the-right" style)
    ciP2 = &j;
    //	*ciP2 = -1; // Error

    int* const icP = &i;
    *icP = -2;
    //	icP = ciP; // Error

    const int* const cicP = &i;
    //	*cicP = -3; // Error
    //	cicP = ciP; // Error

    // Advanced const correctness

    int** iPP = &iP;
    //	const int **ciPP = &iP; // Error

    const int* const* cicPP = &iP;
    //	**cicPP = 3; // Error
    //	*cicPP = &iP; // Error
    cicPP = iPP;

    int** const iPcP = &iP;
    **iPcP = 3;
    *iPcP = iP;
    //	iPcP = iPP; //Error
}

////////////////////////////////////////////////////////////////////////////////
// Aufgabe 2.1n - Übergabewerte
////////////////////////////////////////////////////////////////////////////////

int op1(int* param) {
    std::cout << "works1" << std::endl;
}

int op2(int param) {
    std::cout << "works2" << std::endl;
}

void op3(int& param) {
    std::cout << "works3" << std::endl;
}

void op4(const int** param) {
    std::cout << "works4" << std::endl;
}

void ex_uebergabewerte() {
    int i = 0;
    int* j = &i;
    const int* const k = &i;
    int** l = &j;
    const int* m = &i;

    op1(&i);
    op1(j);
    // op1(k); // does not work because of const -> invalid conversion from 'const int*' to 'int*'
    op1(*l);
    // op1(m); // does not work because of const

    op2(i);
    op2(*j);
    op2(*k);
    op2(**l);
    op2(*m);

    op3(i);
    op3(*j);
    // op3(k); // cannot convert const int* to int* -> const correctness
    op3(**l);
    // op3(*m); // does not work because of const

    // op4(&&i);
    /** 
     * Note: 
     * (1) Of cource using '&&i' is syntactically not possible in C or C++. 
     * (2) However, when trying a similar operation with a workaround (see Clarification below) you will get the following error:
     * invalid conversion from 'int**' to 'const int**', reason is it could be a workaround to change value of 'const int**'
     */
	
    // op4(&j);  //same as above   -> see https://stackoverflow.com/a/16390371
    // op4(&k); // invalid conversion from ‘const int* const*’ to ‘const int**’ -> const correctness
    // op4(l);
    op4(&m);

    /*
     * Clarification on op4(l):
     * Source: http://stackoverflow.com/a/3438177/4999000
     *
     * Have a look at the example below to see why it is not possible to pass int **l to op4(const int **param).
     *
		const int constant = 10;
		int *modifier = 0;
		const int ** const_breaker = &modifier; // [*] this operation is illegal

		*const_breaker = & constant;   // no problem, const_breaker points to
									// pointer to a constant integer, but...
									// we are actually doing: modifer = &constant!!!
		*modifier = 5;                 // ouch!! we are modifying a constant!!!
	*/
}


int main() {
    // Aufgabe 2.1h
    int intVal = 5;
    int* pIntVal = &intVal;

    square(intVal); // Bei square ändert sich die intVal nicht, weil es eine Kopie gemacht wird und die lokal in der Funktion benutzt wird.
    std::cout << intVal << std::endl;
    square2(pIntVal);
    std::cout << *pIntVal << std::endl;
    square3(intVal);
    std::cout << intVal << std::endl;

    // Aufgabe 2.1l
    int i1 = 3, i2 = 5;
    std::cout << i1 << " " << i2 << std::endl;
    swapPointer(&i1, &i2);
    std::cout << i1 << " " << i2 << std::endl;
    swapReference(i1, i2);
    std::cout << i1 << " " << i2 << std::endl;
    // Aufgabe 2.1m
    int var = 42;
    std::cout << "&var = " << &var << std::endl;
    foo(var);

    ex_uebergabewerte();
}
