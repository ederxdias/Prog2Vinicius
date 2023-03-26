#include <stdio.h>
#define MAX 1000
typedef struct 
{
    char nome[MAX];
    int matricula;
    float presenca;
    float notas[3];
    float provaf;
}tEstudante;

tEstudante LerDadosDoEstudante();
void ImprimirEstudante(tEstudante estudante);
int EhAprovado(tEstudante estudante);
float RetornaNotaDoEstudante(tEstudante estudante);

int main(){
    int n;
    scanf("%d\n", &n);
    float per_apr_s=0, per_apr_c=0, per_not_q=0;
    for(int i=0;i<n;i++){
        tEstudante estudante;
        estudante = LerDadosDoEstudante();
        ImprimirEstudante(estudante);
        if(EhAprovado(estudante)==1){
            printf("Aprovado\n");
            per_apr_s++;
        }else if(EhAprovado(estudante)==2){
            per_apr_c++;
            printf("Aprovado\n");
        }else {
            printf("Reprovado\n");
        }
        per_not_q += RetornaNotaDoEstudante(estudante);
    
    }
    per_apr_c /=n;
    per_apr_s /=n;
    per_not_q /=n; 
    return 0;
}
// Crie uma estrutura Estudante com nome, matricula, percentual de presenças, e notas de 3
// avaliações e da prova final. Em seguida, crie funções para:
// • Ler dados de um estudante.
// • Mostrar dados de um estudante na tela.
// • Verificar se ele foi aprovado ou não. Assuma que as regras de aprovação são iguais as
// regras da Ufes com média parcial de 7.0 e número mínimo de presenças igual a 75%. A
// função deve retornar 0 se o aluno não foi aprovado e 1 se foi.
// O programa deve ler um número n e em seguida ler os dados de n estudantes. Para cada um deles, o
// programa deve mostrar na tela se o aluno foi aprovado ou não. Ao final, devem ser exibidas
// algumas estatísticas: o percentual de aprovados sem prova final, o percentual de aprovados com
// prova final e a nota final média (com ou sem prova final).
tEstudante LerDadosDoEstudante(){
    tEstudante estudante;
    scanf("%[^;];%d;%f;%f;%f;%f;%f", estudante.nome, &estudante.matricula,&estudante.presenca,
    &estudante.notas[0], &estudante.notas[1], &estudante.notas[2], &estudante.provaf);
    return estudante;
}
void ImprimirEstudante(tEstudante estudante){
    printf("%s\n%d\n%.2f\n", estudante.nome, estudante.matricula, estudante.presenca);
    printf("%f %f %f %f\n", estudante.notas[0], estudante.notas[1],
     estudante.notas[2], estudante.provaf);
}
int EhAprovado(tEstudante estudante){
    float media=0;
    media = RetornaNotaDoEstudante(estudante);
    if(media>=7)
        return 1;
    else {
        media = RetornaNotaDoEstudante(estudante);
        if(media>=7)
            return 2;
        else return 0;
    }
}
float RetornaNotaDoEstudante(tEstudante estudante){
    float media=0;
    media = (estudante.nome[0]+estudante.nome[1]+estudante.nome[2])/3;
    if(media>=7)
        return media;
    else {
        media = media + (estudante.provaf)/2;
        return media;
    }
}