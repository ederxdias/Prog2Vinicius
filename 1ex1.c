#include <stdio.h>

float CalcularProdutoInternoI(float *vet1, float *vet2, int tam);
float CalcularProdutoInternoR(float *vet1, float *vet2, int tam);

int main(){
    float vet1[5] = {1,1,1,1,1};
    float vet2[5] = {2,2,2,2,2};
    printf("%8.2f\n", CalcularProdutoInternoI(vet1,vet2,5));
    return 0;
}

// 1. Faça uma função que calcule o produto interno entre dois vetores de números de ponto flutuante
// com mesmo tamanho. A função deve receber como entrada os dois vetores e o seu tamanho, e
// deve retornar o valor do produto interno. Implemente a função usando comandos de repetição e
// de forma recursiva. 
float CalcularProdutoInternoI(float *vet1, float *vet2, int tam){
    float soma=0;
    for(int i=0; i<tam;i++){
        soma += vet1[i]*vet2[i];
    }
    return soma;
}
float CalcularProdutoInternoR(float *vet1, float *vet2, int tam){
    if(tam <1){
        return 0;
    }
    int soma;
    soma = vet1[tam] + vet1[tam]+ CalcularProdutoInternoI(vet1,vet2,tam-1);
    return soma;
}