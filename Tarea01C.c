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
        
        printf("%d en decimal es: %d\n", a, a);

    } else if(b == 2){ //binario

        int i;
        char x;

        //Empieza en 32 porque usamos y para saber la posición del bit que queremos leer
        printf("%d en binario es: ", a);

        for (i = 32; i > 0; i-- ){
            //Movemos el el bit que bsucamos hasta el final de la cadena de bits
            x = a >> i-1;
            //Amplicamos un and con una mascara para obtener su valor y guardarlo en x
            x = x & 1;

            //Este if es para no imprimir todos los ceros inesesarios del principio
            if (a > pow(2, i-1)){
                printf("%d", x);
                if ((i+3)%4 == 0 && i != 1){ //Da un espacio cada 8 bits
                    printf(" ");
                } else if(i == 1){ //Solo para dar un salto de renglon
                printf("\n");
                }
            //Por si el numero es negativo ya que no entrara al condicional de arriva
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

    } else {
        printf("Respuesta invalida\n");
    }
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
    } else if(c == 2){

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
    } else {
        printf("Respuesta no valida\n");
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
    } else if(c == 2){

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

    } else {
        printf("Respuesta no valida\n");
    }

    return;
}

void mostrarNot(int c){

    if(c == 1){
        bool a = false;
        bool b = false;

        printf("=====================\n");
        printf("| A | B |NOT A|NOT B|\n");
        printf("=====================\n");
        printf("| 0 | 0 |  %d  |  %d  |\n", !a, !b);
        printf("=====================\n");
        b = true;
        printf("| 0 | 1 |  %d  |  %d  |\n", !a, !b);
        printf("=====================\n");
        a = true;
        b = false;
        printf("| 1 | 0 |  %d  |  %d  |\n", !a, !b);
        printf("=====================\n");
        a = ~a;
        b = ~b;
        printf("| 1 | 1 |  %d  |  %d  |\n", !a, !b);
        printf("=====================\n");

    } else if(c == 2){

        int i = 32;
        char x, y;

        printf("Introduce el numero: ");
        int a = request();

        printf("\n=================================================\n");
        printf("|   %d  |",a);
        //Imprime int a en binario
            binario(a);
            printf("|");


        printf("\n=================================================\n");//Separador
        printf("| NOT %d|",a);
            binario(~a);
            printf("|");

        printf("\n=================================================\n");

    } else {
        printf("Respuesta no valida\n");
    }

    return;
}

int menu(){

    printf("\n");
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

    } else if(p == 2){
        
        double BLado1,BLado2,BLado3,altura;

        printf("Introduce el lado 1 de la base del prisma triangular: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%lf", &BLado1);
        printf("\nIntroduce el lado 2 de la base del prisma triangular: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%lf", &BLado2);
        printf("\nIntroduce el lado 3 de la base del prisma triangular: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%lf", &BLado3);
        printf("\nIntroduce la altura del prisma triangular: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%lf", &altura);

        double semiPeri = (BLado1 + BLado2 + BLado3 ) / ((double)2) ;
        double Heron = ((semiPeri)*(semiPeri-BLado1)*(semiPeri-BLado2)*(semiPeri-BLado3));
        double areaBase = (pow(Heron,(0.5)));
        double areaLat = (BLado1+BLado2+BLado3)*altura;

        double volumen = (areaBase * altura);
        printf("El volumen es %.2lf \n", volumen);

        double areaTot = (2 * areaBase) + areaLat;
        printf("El area es %.2lf \n", areaTot);

    } else if(p == 3){
        
        double BLado1,altura;

        printf("Introduce la longitud de uno de los lados de la base del prisma pentagonal: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%lf", &BLado1);
        printf("Introduce la altura del prisma pentagonal: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%lf", &altura);

            
        double radianes = 36*(M_PI/180);
        double apotema = BLado1/tan(radianes);

        double apH = apotema + altura;
        float areaTot = (5*BLado1)*apH;
        printf("El area es %.2f \n", areaTot);

        float volumen = apotema * BLado1 * altura;
        volumen = (2.5)*volumen;
        printf("El volumen es %.2f \n", volumen);

    } else if(p == 4){
        
        float BLado1;

        printf("Introduce la longitud de uno de los lados del tetraedro: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%f", &BLado1);
        
        float area = pow(BLado1, 2)*sqrt(3);
        float volumen =  ( pow(BLado1, 3) * sqrt(2) /12 );

        printf("Area    = %.2lf u^2\n", area);
        printf("Volumen = %.2lf u^3\n", volumen);

    } else if(p == 5){
        
        double radio;

        printf("Introduce el radio de la esfera: ");
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%lf", &radio);

        double area = 4 *M_PI* pow(radio, 2);
        double volumen = ((float) 4/3) * M_PI * pow(radio, 3);

        printf("Area    = %.2lf u^2\n", area);
        printf("Volumen = %.2lf u^3\n", volumen);

    } else {
        printf("Respuesta no valida\n");
    }

    return;
    
}

void programa(){

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

    } else if(x == 2){

        printf("Quieres la tabla o el AND de 2 numeros:\n");
        printf("1) Tabla de verdad\n2) AND de 2 numeros\n");
        printf("Tu eleccion es: ");
        int c = request();
        mostrarAnd(c);

    } else if(x == 3){

        printf("Quieres la tabla o el OR de 2 numeros:\n");
        printf("1) Tabla de verdad\n2) OR de 2 numeros\n");
        printf("Tu eleccion es: ");
        int r = request();
        mostrarOr(r);

    } else if(x == 4){

        printf("Quieres la tabla o el NOT de un numero\n");
        printf("1) Tabla de verdad\n2) NOT de 1 numero\n");
        printf("Tu eleccion es: ");
        int h = request();
        mostrarNot(h);

    } else if(x == 5){
        menuDos();
    } else {
        printf("Respuesta no valida\n");
    }

    int continuar;

    printf("\nPresiona 1 para continuar o cualquier otra tecla para salir  .  .  .  .  ");
    continuar = request();

    if (continuar == 1){
        programa();
    } else {
        printf("Bye...\nFin del programa");
    }

}


int main(){
    
    printf("\nBIENVENIDO AL PROGRAMA\n"); 
    programa();
    
    return 0;
}
