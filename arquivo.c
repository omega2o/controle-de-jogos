#include <stdio.h>

int main(){

    FILE *fd_arq=NULL;

    fd_arq=fopen("dados.txt", "w");

    fprintf(fd_arq, "%s\n","isso ai");
    fclose(fd_arq);
    return 0;
}