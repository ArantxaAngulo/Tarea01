#include<stdio.h>
#include<stdbool.h>
#include<math.h>

void mostrarNumeros(int a, int b){

    //decimal
    if (b == 1){
        printf("%d", a);
    }


    //binario
    if(b == 2){

        int i;
        char x;
        //Empieza en 32 porque usamos y para saber la posición del bit que queremos leer
        for (i = 32; i > 0; i-- ){
            //Movemos el el bit que bsucamos hasta el final de la cadena de bits
            x = a >> i-1;
            //Amplicamos un and con una mascara para obtener su valor y guardarlo en x
            x = x & 1;

            //Este if es para no imprimir todos los ceros inesesarios del principio
            if (a > pow(2, i-1)){
                printf("%d", x);
                if ((i+3)%4 == 0){ //Da un espacio cada 8 bits
                    printf(" ");
                } else if(i == 0){ //Solo para dar un salto de renglon
                printf("\n");
                }
            //Por si el numero es negativo ya que no entrara al condicional de arriva
            } else if(a < 0){
                printf("%d", x);
                if ((i+3)%4 == 0){
                    printf(" ");
                } else if(i == 0){
                printf("\n");
                }
            }

        }

    
    }

    //hexadecimal
    if(b == 3){
        printf("0x%X\n", a);
    }
    
    return;
}

void mostrarAnd(int a, int b){

    int i = 32;
    char x;
    char y;

    
    printf("\n=================================================\n");
    printf("|   A   |");

    //Imprime int a en binario
    for(i; i > 0; i--){

        //Al igual que el anterior separa todo en una cadena de bits
        x = a >> i-1; 
        x = x & 1;


        printf("%d", x);
        if((i+3)%4 == 0 && i != 1){ //Da un espacio cada 4 bits
            printf(" ");
        } else if(i == 1){ //imprime una barra para darle formato de tabla
            printf("|");
        }
    }


    printf("\n=================================================\n"); //Separador
    printf("|   B   |");
    i = 32;

    //Imprimer int b en binario
    for(i; i > 0; i--){

        y = b >> i-1;
        y = y & 1;

        printf("%d", y);
        if((i+3)%4 == 0 && i != 1){
            printf(" ");
        } else if(i == 1){
            printf("|");
        }
    }

    
    printf("\n=================================================\n");//Separador
    printf("|A AND B|");
    i = 32;

    for(i; i > 0; i--){

        //Ahora obtenemos la cadena de bits de ambos numeros al mismo tiempo y les aplicamos un and
        x = a >> i-1;
        x = x & 1;

        y = b >> i-1;
        y = y & 1;

        printf("%d", y&x);
        if((i+3)%4 == 0 && i != 1){
            printf(" ");
        } else if(i == 1){
            printf("|");
        }

    }

    printf("\n=================================================\n");

    printf("\n%d AND %d = %d\n", a, b, a&b);
   

    return;
    
}

void mostrarOr(int, int);

void mostrarNot(int);

void perimetro(float);

void area(float);

void volumen(float);

int main(){

    printf("BIENVENIDO AL PROGRAMA\n"); 
    printf("1) Mostrar numero en otros formatos (Decimal, Binario y Hexadecimal)\n");
    printf("2) Mostrar tabla de verdad de AND\n");
    printf("3) Mostrar tabla de verdad de OR\n"); 
    printf("4) Mostrar tabla de verdad de NOT\n"); 
    printf("5) Calcular el perimetro, area y volumen\n");

    printf("Teclee el numero de la accion que desea resalizar: ");

    char buffer[256];
    int z;

    printf("Introduce un numero: ");
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%d", &z);

    if(z == 1){
        printf("1) Mostrar numero en otros formatos (Decimal, Binario y Hexadecimal)\n");
        int a;
        int b;

        printf("Introduce un numero: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%d", &a);

        printf("Como lo quieres imprimir?\n");
        printf("1) para decimal\n2) para binario\n3) para hexadecimal\nCual quieres?: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%d", &b);

        mostrarNumeros(a, b);
    }

    if(z == 2){
        
        int a;
        int b;

        printf("AND de 2 numeros:\n");
        printf("Introduce el numero 1: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%d", &a);

        printf("Introduce el numero 2: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%d", &b);

        mostrarAnd(a,b);
        
    }

    return 0;
}

