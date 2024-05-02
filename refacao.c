#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*

Nome: Guilherme Henrique da Silva Teodoro
Matricula: 836279
Data: 02/05/2024

*/

int f_01(char p[]){

    int x = 0 , y = 0;
    bool r = false, s = false , t = false;
    bool u = false, v = false , w = false;

    int len = strlen(p);

    for (x = 0; x < len; x++)
    {
        r = ('a' <= p[x] && p[x] <= 'z');
        s = ('A' <= p[x] && p[x] <= 'Z');
        t = ('0' < p[x] && p[x] <= '9');
        u = (r||s) && !w; v = !u && t; w = !v;
        if (u)
        {
            y = y + 1;
        }
        else if (v)
        {
            y = y - 1;
        }
    }

    return y;  

}

int f_02(int a,int b){

    if (a % 2 == 0 && b % 2 == 0)
    {
        return(f_02(a/2,b/2));
    }
    else if (a % 2 != 0 && b % 2 == 0)
    {
        return (f_02(b % a, b/2));
    }
    else if (a%2 == 0 && b%2 != 0)
    {
        return (f_02(a/2, a%b));
    }
    return ((a-1) % (b-1)/2);

}

void p_03(int a, int b, int c) {

  printf("\nPrimeira Repeticao: ");

  printf("\n");

  for (int x = 1; x <= 5; x = x + 1) 
  { printf("\nx = %d", 2*x+1); }


    printf("\nSegunda Repeticao: ");

  for (int x = a; x <= b; x = x + 3)
  { printf("\nx = %d", c = (2*x+3)/3); } 

    printf("\nAmbas as repeticoes sao iguais quando: a =3, b = 5*3 e c = (2*x+3)/3.");

}

void p_04(void){

    int x = 1, y= 1, v = 0, w = 0, m = 2, n = 0;

    printf("\nn=");
    scanf("%d" ,&n);
    getchar();

    printf("%d%d" ,x,y);

    while (m < n)
    {
        v=x+y;
        m=m+1;
        printf("%d" ,v);

        if (m < n-1)
        {
            w = x + y + v;
            m=m+1;
            printf("%d" ,w);
        }

        x = v; y = w;
    }
    

}

int f_05 (char *s) {
   int x = 0, y =strlen(s)-1;

  while (x <= y && s[x] == s[y]){

    x = x + 1;
    y = y - 1;
    
  }

  return (x - y + s[x]-s[y]);
  
}

int numeroPrimos(int num){

   for (int i = 2; i < num; i++)
   {
    if (num % i == 0)
    {
        return 0;
    }
   }

   return 1;
}

void numSheldon(){

     int j = 0;

    for (int i = 11; i <= 99; i++)
    {
        int numero = 0;
    
        if (numeroPrimos(i) == 1)
        {
            numero = (i % 10) * 10;
            numero += i / 10;

            if (numeroPrimos(numero) == 1)
            {
                printf("%d e primo e seu par de numero de sheldon e %d\n" ,i ,numero);
                j++;
            }
        }
    }

        j = j / 2;
        j = j + 1;
        printf("existem %d pares de numero de sheldon" ,j);
}

int analisar(char *nucleotideos)
{
    int u = 0, t = 0;

    int tamanho = strlen(nucleotideos);

    for (int i = 0; i < tamanho; i++)
    {
        if (nucleotideos[i] == 'U')
        {
            u++;
        }
        if (nucleotideos[i] == 'T')
        {
            t++;
        }
    }

    if (u == 0 && t > 0)
    {
        return 1;
    }
    else if (u > 0 && t == 0)
    {
        return 2;
    }
    else if (u == 0 && t == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
    

}

int quadrado(char *palavra) {
    int tamanho = strlen(palavra) - 1;
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        int digito = palavra[i] - '0';
        soma += digito;
    }

    soma = soma * soma;

    return soma;
}

int cubo(char *palavra) {
    int tamanho = strlen(palavra) - 1;
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        int digito = palavra[i] - '0';
        soma += digito * digito * digito;
    }

    return soma;
}

int main()
{

    int x = 0;

    printf("Qual o exercicio voce deseja testar?\n");
    scanf("%d" ,&x);
    getchar();

    switch (x)
    {

    case 1:{
        printf("%d" ,f_01("5aP4+0_8r4nK0"));

        break;
    }

    case 2:{

        printf("\nf_02(30,72) = %d\n" ,f_02(30,72));

        break;

    }

    case 3:

    p_03(3 , 5*3 , 0);

    break;

    case 4:

    p_04();

    break;

    case 5:

    printf("\nresultado: %d",f_05("14641"));
    
    break;

    case 6:{

        numSheldon();

        break;
        
    }

    case 7:{

        int resultado;
        char nucleotideos[50];

        fgets(nucleotideos, 50, stdin);

        resultado = analisar(nucleotideos);

        if (resultado == 1)
        {
            printf("DNA");
        }
        else if (resultado == 2)
        {
            printf("RNA");
        }
        else if (resultado == 0)
        {
            printf("Indefinida");
        }
        else if (resultado == -1)
        {
            printf("ERRO");
        }
    
        break;
    }

    case 8:{
        
        char palavra[100];
        printf("digite sua sequecia de algarimos\n");
        fgets(palavra, 100 , stdin);

        int quadrados = quadrado(palavra);

        int cubos = cubo(palavra);

        if (quadrados == cubos)
        {
            printf("Sao iguais");
        }
        else
        {
            printf("Nao sao iguais");
        }
        
        break;

    }
    
    default:
        break;
    }

    return 0;
}
