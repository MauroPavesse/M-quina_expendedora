#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include "windows.h" //Para poner un tiempo antes de continuar
//CODIGOS Y PRECIOS EN LA LISTA "PRECIOS.txt"
//Codigos:
//Linea Coca Cola: [1] Coca cola || [2] Fanta || [3] Sprite
//Linea Pepsi: [4] Pepsi || [5] Mirinda || [6] SevenUp
//Linea Manaos: [7] Pomelo || [8] Uva || [9] Naranja
//Teclas funcionales:
//"C" CANCELAR || "S" SALIR || "R" RETIRAR || "A" ACEPTAR

void main()
{
    //CARGA ARBOLES CON CODIGO Y PRECIO
    TArb *A=NULL;
    cargarArbol(&A);

    char codigo; //El boton pulsado
    int vuelto=0; //El dinero que tiene cargado en la maquina
    int compro; //0 SI COMPRO, 1 SI CANCELO LA COMPRA
    printf("==================================================================\n");
    printf("              MAQUINA EXPENDEDORA DE LATAS DE GASEOSAS\n");
    printf("==================================================================\n\n");
    Sleep(2000); //Tiempo de espera
    system("cls"); //Limpia pantalla
    do{
        //ESTADO "INICIO"
        do{
            printf("Dinero disponible: %d\n\n",vuelto);
            teclado(); //Muesta los botones
            codigo=getch(); //Lee el boton apretado
            if(verificar(codigo)){ //Verifica si se encuentra ese boton
                printf("Codigo incorrecto!\n");
                Sleep(1000);
                system("cls");
            }
        }while(verificar(codigo)); //Mientras no sea un boton va a quedar en un bucle
        system("cls");
        if(codigo!='s' && codigo!='S'){ //Si no se pulsó la S significa que entró un numero
            //ESTADO "PRODUCTO (PRECIO)"
            printf("Dinero disponible: %d\n",vuelto);
            switch(codigo){ //Depende del código de la lata
                case '1': compro=dinero_vuelto(traePrecio(A, 1), &vuelto); break; //Devuelve por parámetro
                case '2': compro=dinero_vuelto(traePrecio(A, 2), &vuelto); break; //el dinero disponible
                case '3': compro=dinero_vuelto(traePrecio(A, 3), &vuelto); break; //dentro de la maquina.
                case '4': compro=dinero_vuelto(traePrecio(A, 4), &vuelto); break; //"Compro" va a contener
                case '5': compro=dinero_vuelto(traePrecio(A, 5), &vuelto); break; //1 o 0 dependiendo si
                case '6': compro=dinero_vuelto(traePrecio(A, 6), &vuelto); break; //hizo la compra o no
                case '7': compro=dinero_vuelto(traePrecio(A, 7), &vuelto); break;
                case '8': compro=dinero_vuelto(traePrecio(A, 8), &vuelto); break;
                case '9': compro=dinero_vuelto(traePrecio(A, 9), &vuelto); break;
            }
            system("cls");
            if(compro!=1){ //Si hizo la compra
                //ESTADO "COMPRADO"
                printf("Dinero disponible: %d\n\n",vuelto);
                teclado(); //Muestra los botónes
                char aux; //Simplemente es para que precione la tecla R
                do{
                    printf("\nPulsa R para retirar!\n");
                    //VUELVE AL ESTADO "INICIO"
                    aux=getch();
                }while(aux!='r' && aux!='R');
                printf("Retire su lata =D\n");
                Sleep(1200);
                system("cls");
            }
        }
        else{
            //ESTADO "TERMINA Y DA VUELTO"
            if(vuelto!=0){ //Si tiene vuelto
                printf("\nSu vuelto es: %d\nEmitiendo su vuelto...\n",vuelto);
                Sleep(3000);
            }
            else{ //Si no tiene vuelto
                printf("No tiene vuelto\n\nHASTA LUEGO!\n");
                Sleep(2000);
            }
            vuelto=0;
            system("cls");
        }
    }while(codigo!='|'); //Simplemente para cerrar el programa con alguna tecla
}
