#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BLANK 219
#define AGUA 176
#define TOCADO 88
#define HUNDIDO 1

int opcion;
int victoria=0;

 /* Jugadores */
char jugador[2][25];
char aux[25];
int turno=0;
/* ********** */

/* Tableros */
int tablero[2][10][10];
int tableroaux[2][10][10];
/* ********** */


/* Barcos */
typedef struct barco {
    int fila;
    int columna;
}BARCO;

BARCO vSIMPLE[2][5][1]; //Definimos 5 barcos simples de 1 parte cada uno.
BARCO vDOBLE[2][3][2]; // Definimos 3 barcos dobles de 2 partes cada uno.
BARCO vTRIPLE[2][1][3]; // Definimos 1 barco triple de 3 partes cada uno.

/* ********** */


void creaJugadores (void);
void evaluaMenu (int opcion);
void muestraMenu(void);
void instrucciones (void);
void creaTablero (int turno);
void quienvaPrimero (void);
void muestraTablero (int jug);
int evaluaentrada (int num);
int sepuede (int fila, int columna, int tipo, int jug,int j);
void disparar(int jug);
void siguienteTurno (void);
void muestraTableroCreacion (int jug);


int main (void){

    do{
    muestraMenu();
    }while(opcion!=99);

return 0;

}



void jugar(void){

    creaJugadores();
    quienvaPrimero();
    int i;

      creaTablero(turno);
      siguienteTurno();
      creaTablero(turno);

    do{
    for(;;){



        }
    }while(victoria==0);



}

void evaluaMenu (int opcion){

    switch(opcion){
    case 1:
        instrucciones();
        break;
    case 2:
        jugar();
        break;
    case 99:
        system("cls");
        printf("\n\n\t\tMuchas gracias por haber jugado a hundir la flota!\n\n\t\t\tVuelve pronto!\n\n");
        break;
    default:
        system("cls");
        printf("***      Opcion incorrecta  ***\n");
        muestraMenu();
    }



}


void muestraMenu(void){


        printf("\t\t\t*******************************\n");
        printf("\t\t\t***     Hundir La flota     ***\n");
        printf("\t\t\t*******************************\n");
        printf("\t\t\t*******************************\n");
        printf("\t\t\t***                         ***\n");
        printf("\t\t\t***  1) Instrucciones       ***\n");
        printf("\t\t\t***  2) Jugar               ***\n");
        printf("\t\t\t*** 99) Salir               ***\n");
        printf("\t\t\t***                         ***\n");
        printf("\t\t\t*******************************\n\n\n");


        printf("Elije una opcion: ");
        scanf("%d",&opcion);
        evaluaMenu(opcion);

}


 void creaJugadores (void){

    system("cls");
    printf("Nombre del primer jugador: ");
    scanf("%s",jugador[0]);
    printf("\nNombre del segundo jugador: ");
    scanf("%s",jugador[1]);


 }

void instrucciones (void){


        printf("\t\t\t*******************************\n");
        printf("\t\t\t*** Juego para 2 jugadores  ***\n");
        printf("\t\t\t***                         ***\n");
        printf("\t\t\t*** Flota:                  ***\n");
        printf("\t\t\t***                         ***\n");
        printf("\t\t\t*** 5 Barcos de una casilla ***\n");
        printf("\t\t\t*** 3 Barcos de dos casillas***\n");
        printf("\t\t\t*** 1 Barco de 3 casillas   ***\n");
        printf("\t\t\t***                         ***\n");
        printf("\t\t\t*** Como atacar?            ***\n");
        printf("\t\t\t***                         ***\n");
        printf("\t\t\t*** Escribe la fila y la    ***\n");
        printf("\t\t\t*** columna en la que       ***\n");
        printf("\t\t\t*** quieras disparar en tu  ***\n");
        printf("\t\t\t*** turno cuando se te      ***\n");
        printf("\t\t\t*** solicite.               ***\n");
        printf("\t\t\t***                         ***\n");
        printf("\t\t\t***  Como ganar?            ***\n");
        printf("\t\t\t***                         ***\n");
        printf("\t\t\t*** El jugador que destruya ***\n");
        printf("\t\t\t*** la flota del otro antes ***\n");
        printf("\t\t\t*** ganara la partida.      ***\n");
        printf("\t\t\t***                         ***\n");
        printf("\t\t\t*******************************\n");

        system ( "PAUSE" );
        system("cls");
}

void quienvaPrimero (void){

    srand (time(NULL));
    int j1,j2;

        do{
            system("cls");
            if(j1==j2) printf("\nVaya! ha sido empate.\n\n");
            printf("Muy buenas %s y %s. \n\n",jugador[0],jugador[1]);
            printf("Vamos a ver quien va primero\nPara ello, vamos a tirar un dado virtual aleatorio.\n\n%s, te toca! ",jugador[0]);
            system ( "PAUSE" );
            j1=rand()%6+1;
            printf("\n Has sacado un %d",j1);
            printf("\n\n%s, te toca! ",jugador[1]);
            system ( "PAUSE" );
            j2=rand()%6+1;
            printf("\n Has sacado un %d\n\n",j2);


        }while(j1==j2);
        if(j1<j2){
            printf("\nEnhorabuena %s, vas primero. Has ganado a %s %d a %d.\n\n",jugador[1],jugador[0],j2,j1);
            system ( "PAUSE" );
            strcpy(aux,jugador[0]);
            strcpy(jugador[0],jugador[1]);
            strcpy(jugador[1],aux);
        }else{
            printf("\nEnhorabuena %s, vas primero. Has ganado a %s %d a %d.\n\n",jugador[0],jugador[1],j1,j2);
            system ( "PAUSE" );
        }
}

void creaTablero (int jug){

    system("cls");
    printf("Te toca a ti, %s.\nDebes rellenar la fila y la columna de cada barco (Valores del 0 al 9).\n Ejemplo:\n\tFila del barco simple (1):0\n\tColumna del barco simple (1): 2.\n\n",jugador[jug]);
    // Generamos su tablero todo con espacios blancos;
    int i,j;
    for (i=0;i<10;i++){
        for(j=0;j<10;j++){
            tablero[jug][i][j]=BLANK;
        }
    }

    // Generamos su tablero auxiliar para marcar dónde están los barcos;

    for (i=0;i<10;i++){
        for(j=0;j<10;j++){
            tableroaux[jug][i][j]=0;
        }

    }

    // Ahora vamos a empezar a rellenar los barcos simples.

   for (i=0;i<5;i++){

        do{
            muestraTableroCreacion(jug);
            do{
                printf("\nFila del barco simple (%d): ",i+1);
                scanf("%d",&vSIMPLE[jug][i][0].fila);
            }while(evaluaentrada(vSIMPLE[jug][i][0].fila)!=1);

            do{
                printf("\nColumna del barco simple (%d): ",i+1);
                scanf("%d",&vSIMPLE[jug][i][0].columna);
            }while(evaluaentrada(vSIMPLE[jug][i][0].columna)!=1);
        }while(sepuede(vSIMPLE[jug][i][0].fila,vSIMPLE[jug][i][0].columna,1,jug,0)==0);
        tableroaux[jug][vSIMPLE[jug][i][0].fila][vSIMPLE[jug][i][0].columna]=1;
        system("cls");
    }

    // Rellenamos los barcos dobles.

    system("cls");
    printf("Ahora toca rellenar los barcos dobles. Constan de dos partes por cada barco.\n(Valores del 0 al 9).\n Ejemplo:\n\tFila 1 del barco doble (1): 1\n\tColumna 1 del barco doble (1): 1\n\tFila 2 del barco doble (1):1\n\tColumna 2 del barco doble (1): 2\n\n");
    printf("\nLos barcos dobles no pueden estar en diagonal. Solamente en horizontal o en vertical.\n\n");
    system("PAUSE");
    system("cls");

    for (i=0;i<3;i++){
        for(j=0;j<2;j++){

            do{
                muestraTableroCreacion(jug);
                do{
                    printf("\nFila %d del barco doble (%d): ",j+1,i+1);
                    scanf("%d",&vDOBLE[jug][i][j].fila);
                }while(evaluaentrada(vDOBLE[jug][i][j].fila)!=1);

                do{
                    printf("\nColumna %d del barco doble (%d): ",j+1,i+1);
                    scanf("%d",&vDOBLE[jug][i][j].columna);
                }while(evaluaentrada(vDOBLE[jug][i][j].columna)!=1);



            }while(sepuede(vDOBLE[jug][i][j].fila,vDOBLE[jug][i][j].columna,1,jug,j)==0);

            if(j==0){
                tableroaux[jug][vDOBLE[jug][i][j].fila][vDOBLE[jug][i][j].columna]=2;

            }else{
                tableroaux[jug][vDOBLE[jug][i][0].fila][vDOBLE[jug][i][0].columna]=1;
                tableroaux[jug][vDOBLE[jug][i][1].fila][vDOBLE[jug][i][1].columna]=1;
            }
            system("cls");

        } //for de las partes del barco
    } // for cantidad barcos

    system("cls");
    printf("Y por ultimo, toca el triple. Consta de tres partes.\n(Valores del 0 al 9).\n Ejemplo:\n\tFila 1 del barco triple (1): 1\n\tColumna 1 del barco triple (1): 1\n\tFila 2 del barco triple (1):1\n\tColumna 2 del barco triple (1): 2\n\tFila 3 del barco triple (1): 1\n\tColumna 3 del barco triple (1): 3\n\n");
    printf("\nLos barcos triples no pueden estar en diagonal. Solamente en horizontal o en vertical.\n\n");
    system("pause");
    system("cls");
    for (i=0;i<1;i++){
        for(j=0;j<3;j++){

            do{
                muestraTableroCreacion(jug);
                do{
                    printf("\nFila %d del barco triple (%d): ",j+1,i+1);
                    scanf("%d",&vTRIPLE[jug][i][j].fila);
                }while(evaluaentrada(vTRIPLE[jug][i][j].fila)!=1);

                do{
                    printf("\nColumna %d del barco triple (%d): ",j+1,i+1);
                    scanf("%d",&vTRIPLE[jug][i][j].columna);
                }while(evaluaentrada(vTRIPLE[jug][i][j].columna)!=1);



            }while(sepuede(vTRIPLE[jug][i][j].fila,vTRIPLE[jug][i][j].columna,1,jug,j)==0);

            if(j!=2){
                tableroaux[jug][vTRIPLE[jug][i][j].fila][vTRIPLE[jug][i][j].columna]=2;

            }else{
                tableroaux[jug][vTRIPLE[jug][i][0].fila][vTRIPLE[jug][i][0].columna]=1;
                tableroaux[jug][vTRIPLE[jug][i][1].fila][vTRIPLE[jug][i][1].columna]=1;
                tableroaux[jug][vTRIPLE[jug][i][2].fila][vTRIPLE[jug][i][2].columna]=1;
            }
            system("cls");

        } //for de las partes del barco
    } // for cantidad barcos

}






void muestraTablero (int jug){

    int i,j;

    for (i=0;i<10;i++){
        if(i==0)printf("  0 1 2 3 4 5 6 7 8 9 \n");
        printf("%d ",i);
        for(j=0;j<10;j++){

            printf("%c ",tablero[jug][i][j]);

        }
        printf("\n");
    }





}

void muestraTableroCreacion (int jug){
    int i,j;
    for (i=0;i<10;i++){
        if(i==0)printf("  0 1 2 3 4 5 6 7 8 9 \n");
        printf("%d ",i);
        for(j=0;j<10;j++){

            if(tableroaux[jug][i][j]==1 || tableroaux[jug][i][j]==2){
                printf("%c ",HUNDIDO);
                }else{

                    printf("%c ",BLANK);
                }

        }
        printf("\n");
    }


}
int evaluaentrada (int num){

    if (num>=0 && num <=9){
         return 1;
    }else{
     return 0;
     }

}

int sepuede (int fila, int columna, int tipo, int jug,int j){

    if(!tableroaux[jug][fila][columna]==1){
                            // En este if, busco si ya hay un barco;

       if(j==2){
            if(!( (tableroaux[jug][fila+2][columna]==2 && tableroaux[jug][fila+1][columna]==2)
                 || (tableroaux[jug][fila-2][columna] ==2 && tableroaux[jug][fila-1][columna] ==2)
                 || (tableroaux[jug][fila][columna+2]==2 && tableroaux[jug][fila][columna+1]==2)
                 || (tableroaux[jug][fila][columna-2] ==2 && tableroaux[jug][fila][columna-1]==2)  ) ){

                    printf("Recuerda que solo pueden estar en horizontal o en vertical");
                    return 0;

                    }else{

                    if(!(tableroaux[jug][fila+1][columna]==1 || tableroaux[jug][fila-1][columna]==1 || tableroaux[jug][fila][columna+1]==1 ||
                     tableroaux[jug][fila][columna-1]==1 || tableroaux[jug][fila+1][columna+1]==1 || tableroaux[jug][fila-1][columna-1]==1 ||
                     tableroaux[jug][fila+1][columna-1]==1 || tableroaux[jug][fila-1][columna+1]==1)){
                                // En este if, busco si en las posiciones adjacentes hay un barco y lo niego.

                    return 1;
                }else{
                    printf("\nNo pueden haber barcos adyacentes.\n");
                    return 0;
                }
                    }

        }else{

            if(j==1){
                    if(!(tableroaux[jug][fila+1][columna]==2 || tableroaux[jug][fila-1][columna] ==2 ||
                       tableroaux[jug][fila][columna+1]==2 || tableroaux[jug][fila][columna-1] ==2) ){

                                        /*vDOBLE[jug][i][j].fila== vDOBLE[jug][i][j-1].fila+1 || vDOBLE[jug][i][j].fila == vDOBLE[jug][i][j+1].fila+1 ||
                                        vDOBLE[jug][i][j].columna == vDOBLE[jug][i][j-1].columna+1 || vDOBLE[jug][i][j-1].columna+1*/




                        printf("Recuerda que solo pueden estar en horizontal o en vertical");
                        return 0;
                    }else{

                                        if(!(tableroaux[jug][fila+1][columna]==1 || tableroaux[jug][fila-1][columna]==1 || tableroaux[jug][fila][columna+1]==1 ||
                     tableroaux[jug][fila][columna-1]==1 || tableroaux[jug][fila+1][columna+1]==1 || tableroaux[jug][fila-1][columna-1]==1 ||
                     tableroaux[jug][fila+1][columna-1]==1 || tableroaux[jug][fila-1][columna+1]==1)){
                                // En este if, busco si en las posiciones adjacentes hay un barco y lo niego.

                    return 1;
                }else{
                    printf("\nNo pueden haber barcos adyacentes.\n");
                    return 0;
                }
                    }
            }else{

                if(!(tableroaux[jug][fila+1][columna]==1 || tableroaux[jug][fila-1][columna]==1 || tableroaux[jug][fila][columna+1]==1 ||
                     tableroaux[jug][fila][columna-1]==1 || tableroaux[jug][fila+1][columna+1]==1 || tableroaux[jug][fila-1][columna-1]==1 ||
                     tableroaux[jug][fila+1][columna-1]==1 || tableroaux[jug][fila-1][columna+1]==1)){
                                // En este if, busco si en las posiciones adjacentes hay un barco y lo niego.

                    return 1;
                }else{
                    printf("\nNo pueden haber barcos adyacentes.\n");
                    return 0;
                }
            }
        }

    }else{
        printf("\nYa existe un barco en esta posicion.\n");
        return 0;
    }



}

void disparar(int jug){

printf("Turno del jugador: %s\n\n",jugador[turno]);

printf("Este es el tablero de tu enemigo:\n\n");

if(turno==0) muestraTablero(1);
if(turno==1) muestraTablero(0);

system("cls");

}

int tocadoHundido (int fila, int columna){


/*






        for(si=0;si<3;si++){
            if(fila == vSIMPLE[si].fila && columna == vSIMPLE[si].columna ){
                tablero [fila][columna] = HUNDIDO;
            } else{
                tablero [fila][columna] = AGUA;
            }
        }


    for(di=0;di<2;di++){
        for(dp=0;dp<2;dp++){
            if( (fila == vDOBLE[di].fila[dp] && columna == vDOBLE[di].columna[dp]) || (fila==vDOBLE[di].fila[dp] && columna==vDOBLE[di].columna[dp]) ){

                if (vDOBLE[di].cont!=2){
                    tablero [fila][columna] = TOCADO;
                    vDOBLE[di].cont++;

                        if(vDOBLE[di].cont==2){
                    tablero [vDOBLE[di].fila[dp]][vDOBLE[di].columna[dp]] = HUNDIDO;

                    }
                }
            }
        }
    }

*/

return 0;
}

void siguienteTurno (void){
    if(turno==0) turno=1;
    if(turno==1) turno=0;
}

int jugadorContrario (int turno){
    int opuesto;

    if(turno==0) opuesto=1;
    if(turno==1) opuesto=0;
    return opuesto;

}
