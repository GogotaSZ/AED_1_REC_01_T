#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int lerN();
void lerAB(int *A, int *B);
int *lerX(int N);
int *ex1(int *vet, int N);
int *primos(int *vet, int N, int *quantidade);
double media(double *vet, int N, int *tipo);
int preencherVetor(int *vet, int n);
double divInv(int *vet, int n, int *A, int *B);
double *lerVetFloat(int N);
void lerFloat(double *numFloat1, double *numFloat2);

int lerN() {
  int N = 0;
  printf("Qual a quantidade de valores deseja?\n");
  scanf("%d", &N);
  return N;
}

void lerAB(int *A, int *B) {

  printf("Digite o valor de A: \n");
  scanf("%d", A);
  printf("Digite o valor de B: \n");
  scanf("%d", B);
}

void lerFloat(double *numFloat1, double *numFloat2) {

  printf("Digite o valor de A: \n");
  scanf("%lf", numFloat1);
  printf("Digite o valor de B: \n");
  scanf("%lf", numFloat2);
}

int *lerX(int N) {
  int *vet = malloc(N * sizeof(int));
  if (vet == NULL) {
    printf("Erro ao alocar memória\n");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < N; i++) {
    printf("Digite um valor:\n");
    scanf("%d", &vet[i]);
  }
  return vet;
}

double *lerVetFloat(int N) {

  double *vet = malloc(N * sizeof(double));
  if (vet == NULL) {
    printf("Erro ao alocar memória\n");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < N; i++) {
    printf("Digite um valor:\n");
    scanf("%lf", &vet[i]);
  }
  return vet;
}

double *lerVetDouble(int *aux) {

  double *vet = malloc(100 * sizeof(double));
  if (vet == NULL) {
    printf("Erro ao alocar memória\n");
    exit(EXIT_FAILURE);
  }

  int i = 0;
  double j = 1;

  while (j != 0) {

    printf("Digite um numero\n");
    scanf("%lf", &j);

    if (j == 0) {
      break;
    }

    vet[i] = j;

    i++;
  }

  *aux = i;

  return vet;
}

void ler3Valores(double *a, double *b, double *c){

  printf("Digite o valor de A: \n");
  scanf("%lf", a);
  printf("Digite o valor de B: \n");
  scanf("%lf", b);
  printf("Digite o valor de C: \n");
  scanf("%lf", c);

}

void ler3ValoreChar(char *a, char *b, char *c){

  printf("Digite o valor de A: \n");
  scanf(" %c", a);
  printf("Digite o valor de B: \n");
  scanf(" %c", b);
  printf("Digite o valor de C: \n");
  scanf(" %c", c);

}

char preencherCadeia(char *cadeia){

  printf("digite o conteudo do seu vetor:/\n");
  fgets(cadeia, 100 , stdin);

  return *cadeia;
}



int preencherVetor(int *vet, int n) {

  int x;

  printf("digite um numero qualquer:\n");
  scanf("%d", &x);

  if (x != -1) {
    int *teste = malloc(n + 1 * sizeof(int));
    if (teste == NULL) {
      printf("Erro ao alocar memória\n");
      exit(EXIT_FAILURE);
    } else {
      free(teste);
      realloc(vet, n + 1 * sizeof(int));

      vet[n] = x;

      n = n + 1;
    }

    return preencherVetor(vet, n);
  } else {
    vet[n] = x;
    return n;
  }
}

double divInv(int *vet, int n, int *A, int *B) {

  double soma = 0.0;

  for (int i = 0; i <= n; i++) {
    if ((vet[i] >= *A && vet[i] <= *B) || (vet[i] <= *A && vet[i] >= *B)) {
      if (vet[i] % 2 != 0 && vet[i] != 0) {
        soma += 1.0 / pow(vet[i], 3);
      }
    }
  }

  return soma;
}

int *ex1(int *vet, int N) {
  int *soma = malloc(N * sizeof(int));
  if (soma == NULL) {
    printf("Erro ao alocar memória\n");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < N; i++) {
    soma[i] = 0;
    for (int j = 3; j < vet[i]; j += 2) {
      if (vet[i] % j == 0) {
        soma[i] += j;
      }
    }
  }
  return soma;
}

int *primos(int *vet, int N, int *quantidade) {

  int aux = 0;

  int *resultado = malloc(N * sizeof(int));
  if (resultado == NULL) {
    printf("Erro ao alocar memória\n");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < N; i++) {
    int primo = 1;

    for (int j = 2; j < vet[i]; j++) {
      if (vet[i] % j == 0) {
        primo = 0;
        break;
      }
    }

    if (primo) {
      resultado[aux] = vet[i];
      aux++;
    }
  }

  *quantidade = aux;
  return resultado;
}

double media(double *vet, int N, int *tipo) {

  double mediaInferior = 0.0, mediaMeio = 0.0, mediaSuperior = 0.0;
  int aux1 = 0, aux2 = 0, aux3 = 0;

  for (int i = 0; i < N; i++) {
    if (vet[i] < -17.25) {
      mediaInferior += vet[i];
      aux1++;
    } else if (vet[i] >= -17.25 && vet[i] <= 93.75) {
      mediaMeio += vet[i];
      aux2++;
    } else if (vet[i] > 93.75) {
      mediaSuperior += vet[i];
      aux3++;
    }
  }

  if (aux1 != 0)
    mediaInferior = mediaInferior / aux1;
  if (aux2 != 0)
    mediaMeio = mediaMeio / aux2;
  if (aux3 != 0)
    mediaSuperior = mediaSuperior / aux3;

  if (mediaInferior > mediaMeio && mediaInferior > mediaSuperior) {
    *tipo = 1;
    return mediaInferior;
  } else if (mediaMeio > mediaInferior && mediaMeio > mediaSuperior) {
    *tipo = 2;
    return mediaMeio;
  } else if (mediaSuperior > mediaInferior && mediaSuperior > mediaMeio) {
    *tipo = 3;
    return mediaSuperior;
  }

  return 0;
}

void testar(double *a,double *b,double *c){
  
    if(*a > *b){
      if(*b > *c){
        printf("Ordem decrescente");
  }
  }else if(*c > *b){
      if(*b > *a){
        printf("Ordem crescente");
  }
  }if (*a > *b && *a > *c){
    printf("\n%lf e o maior numero" ,*a);
  }if (*b > *a && *b > *c){
    printf("\n%lf e o maior numero" ,*b);
  }if (*c > *b && *a < *c){
    printf("\n%lf e o maior numero" ,*c);
  }if (*a < *b && *a < *c){
    printf("\n%lf e o menor número" ,*a);
  }if (*b < *a && *b < *c){
    printf("\n%lf e o menor numero" ,*b);
  }if (*c < *b && *a > *c){
    printf("\n%lf e o menor numero" ,*c);
  }if(*a == *b && *a == *c)
    printf("\nOs numeros sao iguais");
}

void testarChar(char a, char b, char c){
    if (a < b && b < c) {
        printf("Ordem crescente\n");
    } else if (a > b && b > c) {
        printf("Ordem decrescente\n");
    } else {
        printf("Nenhuma ordem especifica\n");
    }
    if (a == b && b == c) {
        printf("Os caracteres sao iguais\n");
    }
}

void testarEExibirResultado(double numFloat1, double numFloat2, double *vet, int aux) {
    int resultado = 0.0;
    int dentro = 0, acima = 0, abaixo = 0;

    for (int i = 0; i < aux; i++) {
        if (numFloat1 > numFloat2) {
            if (vet[i] <= numFloat1 && vet[i] >= numFloat2) {
                dentro++;
            } else if (vet[i] > numFloat1) {
                acima++;
            } else if (vet[i] < numFloat2) {
                abaixo++;
            }
        } else if (numFloat2 > numFloat1) {
            if (vet[i] >= numFloat1 && vet[i] <= numFloat2) {
                dentro++;
            } else if (vet[i] > numFloat2) {
                acima++;
            } else if (vet[i] < numFloat1) {
                abaixo++;
            }
        }
    }

    resultado = 100 / aux;
    abaixo = abaixo * resultado;
    acima = acima * resultado;
    dentro = dentro * resultado;

    printf("\n%d%% está acima", acima);
    printf("\n%d%% está abaixo", abaixo);
    printf("\n%d%% está dentro", dentro);
}

int main() {
  int x = 0;
  printf("Qual exercicio deseja testar?\n");
  scanf("%d", &x);

  switch (x) {
  case 1: {
    int N = lerN();
    int *vet = lerX(N);
    int *resultado = ex1(vet, N);
    for (int i = 0; i < N; i++) {
      printf("%d\n", resultado[i]);
    }
    free(vet);
    free(resultado);
    break;
  }
  case 2: {

    int N = lerN();
    int *vet = lerX(N);
    int quantidade;
    int *resultado = primos(vet, N, &quantidade);

    printf("\nOs numero primos sao:\n");

    for (int i = 0; i < quantidade; i++) {
      printf("%d\n", resultado[i]);
    }
    free(vet);
    free(resultado);

    break;
  }

  case 3:{

    char cadeia[100];

    preencherCadeia(cadeia);

  }

  case 4:

  case 5: {

    int N = lerN();
    double *vet = lerVetFloat(N);
    int tipo;
    double resultado = media(vet, N, &tipo);

    if (tipo == 1) {
      printf("A maior media é a inferior e seu valor e: %lf", resultado);
    } else if (tipo == 2) {
      printf("A maior media é a do meio e seu valor e: %lf", resultado);
    } else if (tipo == 3) {
      printf("A maior media é a superior e seu valor e: %lf", resultado);
    }

    free(vet);

    break;
  }
  case 6: {

    int A, B;
    double resultado = 0.0;

    lerAB(&A, &B);

    int n = 0;

    int *vet = malloc(1 * sizeof(int));

    n = preencherVetor(vet, n);

    resultado = divInv(vet, n, &A, &B);

    printf("%lf", resultado);

    break;
  }

  case 7: {

    double numFloat1, numFloat2;
    int aux = 0;

    lerFloat(&numFloat1, &numFloat2);

    double *vet = lerVetDouble(&aux);

    testarEExibirResultado(numFloat1, numFloat2, vet, aux);

    break;

  }

    case 8:{

      double a,b,c;
      
      ler3Valores(&a,&b,&c);

      testar(&a,&b,&c);

      break;
    
    }
    case 9:{

        char a , b , c;

        ler3ValoreChar(&a,&b,&c);

        testarChar(a,b,c);

        break;

    }

    
  default:
    break;
  }

  return 0;
}