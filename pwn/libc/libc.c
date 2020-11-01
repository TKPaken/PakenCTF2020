#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("printf's address : %p\n",printf);
    printf("Input something : ");fflush(stdout);
    char c[16];
    fgets(c,256,stdin);
}