#include<stdio.h>
#include<stdbool.h>
#define _USE_MATH_DEFINES
#include<math.h>


char buffer[256];

int request(){
    
    int a;
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%d", &a);
    return a;

}

void binario(int a){
    
    int i;
    char x;

    for (i = 32; i > 0; i-- ){

        x = a >> i-1;

        x = x & 1;

        printf("%d", x);
        if ((i+3)%4 == 0 && i != 1){
            printf(" ");
        }


    }

    return;
}

void mostrarNumeros(int a, int b){

    
    if (b == 1){ //decimal
        
        printf("%d en decimal es: ", a);
        printf("%d", a);

    } else if(b == 2){ //binario

        int i;
        char x;

        printf("%d en binario es: ", a);

        for (i = 32; i > 0; i-- ){

            x = a >> i-1;

            x = x & 1;

            if (a > pow(2, i-1)){
                printf("%d", x);
                if ((i+3)%4 == 0 && i != 1){
                    printf(" ");
                } else if(i == 1){
                printf("\n");
                }
            } else if(a < 0){
                printf("%d", x);
                if ((i+3)%4 == 0 && i != 1){
                    printf(" ");
                } else if(i == 1){
                printf("\n");
                }
            }

        }

    
    } else if(b == 3){      //hexadecimal
        
        printf("%d en hexadecimal es: ", a);
        printf("0x%X\n", a);

    } else if("Respuesta invalida\n");
    
    return;
}

void mostrarAnd(int c){

    if(c == 1){
        char a = 0;
        char b = 0;
        printf("=================\n");
        printf("| A | B |A AND B|\n");
        printf("=================\n");
        printf("| 0 | 0 |   %d   |\n", a&b);
        printf("=================\n");
        b++;
        printf("| 0 | 1 |   %d   |\n", a&b);
        printf("=================\n");
        a++;
        b--;
        printf("| 1 | 0 |   %d   |\n", a&b);
        printf("=================\n");
        b++;
        printf("| 1 | 1 |   %d   |\n", a&b);
        printf("=================\n");
    }

    if(c == 2){

        printf("Introduce el numero 1: ");
        int a = request();
        printf("Introduce el numero 2: ");
        int b = request();

        printf("\n=================================================\n");
        printf("|   A   |");

        //Imprime int a en binario
        binario(a);
        printf("|");


        printf("\n=================================================\n");
        printf("|   B   |");

        //Imprimer int b en binario
        binario(b);
        printf("|");
        
        printf("\n=================================================\n");
        printf("|A AND B|");

        //Imprime a%b en binario
        binario(a&b);
        printf("|");

        printf("\n=================================================\n");

        printf("\n%d AND %d = %d\n", a, b, a&b);
    }
   
    return;
}

void mostrarOr(int c){
    
    if(c == 1){
        char a = 0;
        char b = 0;
        printf("=================\n");
        printf("| A | B |A  OR B|\n");
        printf("=================\n");
        printf("| 0 | 0 |   %d   |\n", a|b);
        printf("=================\n");
        b++;
        printf("| 0 | 1 |   %d   |\n", a|b);
        printf("=================\n");
        a++;
        b--;
        printf("| 1 | 0 |   %d   |\n", a|b);
        printf("=================\n");
        b++;
        printf("| 1 | 1 |   %d   |\n", a|b);
        printf("=================\n");
    }

    if(c == 2){

        printf("Introduce el numero 1: ");
        int a = request();
        printf("Introduce el numero 2: ");
        int b = request(); 

        printf("\n=================================================\n");
        printf("|   A   |");

        //Imprime int a en binario
        binario(a);
        printf("|");


        printf("\n=================================================\n");
        printf("|   B   |");

        //Imprimer int b en binario
        binario(b);
        printf("|");
        
        printf("\n=================================================\n");
        printf("|A  OR B|");

        //Imprime a%b en binario
        binario(a|b);
        printf("|");

        printf("\n=================================================\n");

        printf("\n%d OR %d = %d\n", a, b, a|b);

    }

    return;
}

void mostrarNot(){

    bool a = false;
    bool b = false;

    printf("=====================\n");
    printf("| A | B |NOT A|NOT B|\n");
    printf("=====================\n");
    printf("| 0 | 0 |  %d  |  %d  |\n", ~a+2, ~b+2);
    printf("=====================\n");
    b = ~b;
    printf("| 0 | 1 |  %d  |  %d  |\n", ~a+2, ~b+2);
    printf("=====================\n");
    a = ~a;
    printf("| 1 | 0 |  %d  |  %d  |\n", ~a+2, ~b+2);
    printf("=====================\n");
    a = ~a;
    b = ~b;
    printf("| 1 | 1 |  %d  |  %d  |\n", ~a+2, ~b+2);
    printf("=====================\n");

    return;
}

int menu(){

    printf("\nBIENVENIDO AL PROGRAMA\n"); 
    printf("1) Mostrar numero en otros formatos (Decimal, Binario y Hexadecimal)\n");
    printf("2) Mostrar tabla de verdad de AND\n");
    printf("3) Mostrar tabla de verdad de OR\n"); 
    printf("4) Mostrar tabla de verdad de NOT\n"); 
    printf("5) Calcular el perimetro, area y volumen\n");

    printf("\nTeclee el numero de la accion que desea resalizar: ");

    int z;

    fgets(buffer, 256, stdin);
    sscanf(buffer, "%d", &z);

    return z;

}

float datos(){
    
    float b;
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%f", &b);

    return b;

}

void menuDos(){

    printf("QUE FIGURA QUISIERAS CALCULAR?\n");
    printf("1) Cubo\n");
    printf("2) Prisma de base triangular\n");
    printf("3) Prisma de base con pentagono\n"); 
    printf("4) Tetaedro\n"); 
    printf("5) Esfera\n");

    printf("\nTeclee el numero de la accion que desea resalizar: ");

    int p = request();

    if(p == 1){
        
        float a;

        printf("Introduce la longitud de lado del cubo: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%f", &a);

        float perimetro = a * 12;
        printf("El perimetro es %.2f \n", perimetro);

        float area = 6*(pow(a,2));
        printf("El area es %.2f \n", area);

       float volumen = pow(a,3);
        printf("El volumen es %.2f \n", volumen);

    }


    if(p == 2){
        
        float BLado1,BLado2,BLado3,altura;

        printf("Introduce el lado 1 de la base del prisma triangular: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%f", &BLado1);
        printf("\nIntroduce el lado 2 de la base del prisma triangular: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%f", &BLado2);
        printf("\nIntroduce el lado 3 de la base del prisma triangular: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%f", &BLado3);
        printf("\nIntroduce la altura del prisma triangular: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%f", &altura);
    }

    if(p == 3){
        
        float BLado1,BLado2,altura;

        printf("Introduce la longitud de uno de los lados de la base del prisma pentagonal \n");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%f", &BLado1);
        printf("Introduce el apotema del prisma pentagonal \n");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%f", &BLado2);
        printf("Introduce la altura del prisma pentagonal \n");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%f", &altura); 
    }

    if(p == 4){
        
        float BLado1;

        printf("Introduce la longitud de uno de los lados del tetraedro: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%f", &BLado1);
        
        float area = pow(BLado1, 2)*pow(3, (1/2));
        float volumen =  ( pow(BLado1, 3) * pow(2, (1/2)) /12 );

        printf("Area    = %.2lf u^2\n", area);
        printf("Volumen = %.2lf u^3\n", volumen);


    }

    if(p == 5){
        
        double radio;

        printf("Introduce el radio de la esfera: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%lf", &radio);

        double area = 4 *M_PI* pow(radio, 2);
        double volumen = ((float) 4/3) * M_PI * pow(radio, 3);

        printf("Area    = %.2lf u^2\n", area);
        printf("Volumen = %.2lf u^3\n", volumen);

    }

    return;
    
}

int main(){
    
    int x = menu();

    if(x == 1){
        
        int a;
        int b;

        printf("1) Mostrar numero en otros formatos (Decimal, Binario y Hexadecimal)\n");

        printf("Introduce un numero: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%d", &a);

        printf("Como lo quieres imprimir?\n");
        printf("1) como decimal\n2) como binario\n3) como hexadecimal\nCual quieres?: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%d", &b);

        mostrarNumeros(a, b);

    }

    if(x == 2){

        printf("Quieres la tabla o el AND de 2 numeros:\n");
        printf("1) Tabla de verdad\n2) AND de 2 numeros\n");
        printf("Tu eleccion es: ");
        int c = request();
        mostrarAnd(c);

    }

    if(x == 3){

        printf("Quieres la tabla o el OR de 2 numeros:\n");
        printf("1) Tabla de verdad\n2) OR de 2 numeros\n");
        printf("Tu eleccion es: ");
        int r = request();
        mostrarOr(r);

    }

    if(x == 4){
        mostrarNot();
    }

    if(x == 5){
        menuDos();
    }


    return 0;
    
}

