#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

//ARBOL
TArb *generanodoArbol(TDato dato){
    TArb *aux;
    aux=malloc(sizeof(TArb));
    aux->dato=dato;
    aux->izq=NULL;
    aux->der=NULL;
    return aux;
}

void insertarEnArbol(TArb **A, TDato datos){
    if(*A==NULL){
        *A=generanodoArbol(datos);
    }
    else{
        if((*A)->dato.codigo > datos.codigo)
            insertarEnArbol(&(*A)->izq, datos);
        else
            insertarEnArbol(&(*A)->der, datos);
    }
}

void cargarArbol(TArb **A){
    TDato datos;
    FILE *archivo;
    archivo=fopen("PRECIOS.txt","rt");
    while(!feof(archivo)){
        fscanf(archivo, "%d %d\n",&datos.codigo, &datos.num);
        insertarEnArbol(&(*A), datos);
    }
    fclose(archivo);
}

int traePrecio(TArb *A, int codigo){
    int precio;
    buscaPrecio(A, codigo, &precio);
    return precio;
}

void buscaPrecio(TArb *A, int codigo, int *precio){
    if(A!=NULL){
        if(A->dato.codigo==codigo){
            *precio=A->dato.num;
        }
        else{
            if(A->dato.codigo < codigo){
                buscaPrecio(A->der, codigo, &(*precio));
            }
            else{
                buscaPrecio(A->izq, codigo, &(*precio));
            }
        }
    }
    else{
        printf("NO SE ENCONTRO!\n");
    }
}

void teclado(){
    printf("\t[ 1 ][ 2 ][ 3 ]\n\t[ 4 ][ 5 ][ 6 ]\n\t[ 7 ][ 8 ][ 9 ]\n\t  [ C ][ S ]\n\t  [ A ][ R ]\n\n\t\t");
}

int verificar(char codigo){
    return(codigo!='1' && codigo!='2' && codigo!='3' && codigo!='4' && codigo!='5' && codigo!='6' && codigo!='7' && codigo!='8' && codigo!='9' && codigo!='S' && codigo!='s' && codigo!='|');
}

int dinero_vuelto(int num, int *dinero_ant){
    char eleccion; //Para ver si quiere cancelar o no
    int dinero, dinero2, aux=*dinero_ant; //Dinero ingresado a la maquina y luego sumado al vuelto (si es que hay)
    printf("Precio: %d\n\n",num);
    teclado();
    printf("\nC para cancelar || A para aceptar\n");
    do{
        eleccion=getch();
    }while(eleccion!='c' && eleccion!='C' && eleccion!='a' && eleccion!='A');
    if(eleccion=='a' || eleccion=='A'){
        if(aux<num){ //Si el vuelto le alcanza para comprar otra lata sin ingresar dinero nuevamente
            printf("Ingrese dinero: ");
            scanf("%d",&dinero);
            dinero=dinero+(*dinero_ant);
            do{
                if(dinero<num){
                    printf("\nDinero insuficiente\n");
                    printf("Ingrese mas dinero: ");
                    scanf("%d",&dinero2);
                    dinero=dinero+dinero2;
                }
            }while(dinero<num);
            *dinero_ant=dinero-num;
            return 0;
        }
        else{
            *dinero_ant=(*dinero_ant)-num;
            return 0;
        }
    }
    else{
        printf("\nCancelando...");
        Sleep(2000);
        system("cls");
        return 1;
    }
}

