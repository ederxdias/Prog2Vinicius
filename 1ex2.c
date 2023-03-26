#include <stdio.h>
#include<limits.h>

void NormalizarVetor(float *vet, int tam);
float AcharMaximo(float *vet, int tam);
float AcharMinimo(float *vet, int tam);
void MultiplicarVetorPorConstante(float *vet, int tam, float c);
void SomarVetorPorConstante(float *vet, int tam, float c);
void ImprimirVetor(float *vet, int tam);

int main(){
    float vet[4]= {1,3,5,9};
    NormalizarVetor(vet, 4);
    ImprimirVetor(vet, 4);
    return 0;
}
// Uma forma de normalizar um vetor de números consiste em tornar o menor valor 0 e o maior
// valor 1. Esta operação pode ser realizada subtraindo o mínimo de todos os elementos e, em
// seguida, dividir todos os elementos pelo máximo. Faça funções para obter o mínimo e máximo
// de um vetor e para somar e multiplicar todos os elementos por constantes. Use essas funções
// para implementar uma função de normalização. Por fim, escreva um programa que leia um
// número n e em seguida um vetor de n elementos do tipo float e mostre na tela o vetor
// normalizado. 
// 1 minimo e maximo
// 2 somar e multiplicar;
// normalizacao

void NormalizarVetor(float *vet, int tam){
    float max,min;
    max = AcharMaximo(vet,tam);
    min = AcharMinimo(vet,tam);
    SomarVetorPorConstante(vet,tam,min);
    MultiplicarVetorPorConstante(vet,tam,max);
}
float AcharMaximo(float *vet, int tam){
    float max= INT_MIN;
    for(int i=0; i<tam;i++){
        if(vet[i]>max){
            max = vet[i];
        }
    }
    return max;
}
float AcharMinimo(float *vet, int tam){
    float min= INT_MAX;
    for(int i=0; i<tam;i++){
        if(vet[i]<min){
            min = vet[i];
        }
    }
    return min;
}
void SomarVetorPorConstante(float *vet, int tam, float c){
    for(int i=0; i<tam;i++){
        vet[i] -= c;
    }
}
void MultiplicarVetorPorConstante(float *vet, int tam, float c){
    for(int i=0; i<tam;i++){
        vet[i] *= 1/c;
    }
}
void ImprimirVetor(float *vet, int tam){
    for(int i=0; i<tam;i++){
       printf("%.2f ", vet[i]);
    }
}