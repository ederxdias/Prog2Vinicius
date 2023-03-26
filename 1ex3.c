#include <stdio.h>
#include <ctype.h>
int strlenI(const char *str);
int strlenR(const char *str);
char *strcpyI(char *dest, char *orig);
char *strcpyR(char *dest, char *orig, int i);
char *strwr(char *str);
char *strupr(char *str);

int main(){
    char orig[100];
    char dest[100];
    scanf("%[^\n]", orig);

    printf("%s\n", strupr(orig));
    return 0;
}
// Implemente as funções strlen, strcpy, strcat, strlwr e strupr usando comandos de repetição e
// usando recursão. 
int strlenI(const char *str){
    int i=0;
    while(*str++)
        i++;
    return i;
}
int strlenR(const char *str){
    if(!*str)
        return 0;
    int soma=0;
    soma = 1+strlenI(++str);
    return soma;
}
char *strcpyI(char *dest, char *orig){
    int i=0;
    while(orig[i]){
        dest[i] = orig[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
// tá ocorrendo falha na segmentação não entendo
char *strcpyR(char *dest, char *orig, int i){
    if(!orig[i]){
        dest[i]= '\0';
        return &dest[0];
    }
    dest[i] = orig[i];
    return strcpyR(dest, orig, i++);

}
char *strwr(char *str){
    int i=0;
    while(str[i]){
        str[i] = tolower(str[i]);
        i++;
    }
    str[i]='\0';
    return str;
}
char *strupr(char *str){
    int i=0;
    while(str[i]){
        str[i] = toupper(str[i]);
        i++;
    }
    str[i]='\0';
    return str;
}