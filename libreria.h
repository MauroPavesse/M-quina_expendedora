#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED

//ARBOL
typedef struct dato{
    int codigo;
    int num;
}TDato;

typedef struct arb{
    TDato dato;
    struct arb *izq;
    struct arb *der;
}TArb;

//FUNCIONES

//Genera el nodo para el arbol.
TArb *generanodoArbol(TDato dato);

//Inserta el nodo en su lugar correspondiente.
void insertarEnArbol(TArb **A, TDato datos);

//Lee el archivo "PRECIOS.txt" y carga el codigo del producto con su precio.
void cargarArbol(TArb **A);

//Devuelve el precio del codigo del producto a buscar.
int traePrecio(TArb *A, int codigo);

//Busca el codigo del producto en el arbol para obtener su precio.
void buscaPrecio(TArb *A, int codigo, int *precio);

//Muestra los botones simulando que estas presionando los de la maquina.
void teclado();

//Verifica si el boton que aprestaste existe en la maquina.
int verificar(char codigo);

//Hace los calculos para ver si el dinero alcanza para la bebida y calcula el vuelto.
int dinero_vuelto(int num, int *dinero_ant);

#endif // LIBRERIA_H_INCLUDED
