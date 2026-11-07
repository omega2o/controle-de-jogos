#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define T_STR 100
typedef char string[T_STR];

typedef struct dados_jogo{
    string nome;
    int ano_lasa;
    string genero;
    string produtora;
    float valor;
}jogo_t;

typedef struct no{
    jogo_t dados_jogo;
    struct no *prox;
}no_t;

int menu();
jogo_t novo_jogo();
no_t *novo_no(jogo_t jogo);
void inseri_jogo_lista_inicio(no_t *no, no_t **lista);
void inseri_jogo_lista_final(no_t *no, no_t **lista);
no_t *localizar_ultimo_no_lista(no_t *lista);
no_t *localizar_meio_no_lista(no_t *lista);
no_t *localizar_jogo_por_nome(string nome, no_t *lista);
void mostrar_dado_jogos(jogo_t dados_jogo);
void excluir_no_lista(no_t *no, no_t **lista);
void retirar_enter(string str); 
void tornar_maiusculo(string str);
void mostrar_jogos();
int sub_menu_cadastro();
void exportar_dados_arquivo_texto(char* nome, no_t *lista);


int main(){
    int opc_p,opc_s;
    no_t *lista=NULL;

    do{
        opc_p=menu();

        switch(opc_p){
            case 1:
                do{
                    opc_s=sub_menu_cadastro();

                    if(opc_s==1){
                        /*jogo_t novo=novo_jogo();
                        no_t *no_novo =novo_no(novo);
                        inseri_jogo_lista_inicio(novo_no);*/

                        inseri_jogo_lista_inicio(novo_no(novo_jogo()),&lista);
                    }else if(opc_s==2){

                        inseri_jogo_lista_final(novo_no(novo_jogo()),&lista);
                    }else if(opc_s==3){

                    }

                    
                }while(opc_s!=0);
            break;
            case 2:
                mostrar_jogos(lista);
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            exportar_dados_arquivo_texto("jogos.txt",lista); 
            break;
        }

    }while(opc_p!=0);


}

int menu(){
    int opc;

    printf("          principio        \n");
    printf("---------------------------\n");
    printf("1.cadastrar novo jogo\n");
    printf("2.listar jogos\n");
    printf("3.encontrar jogo por nome\n");
    printf("4.excluir jogo da lista\n");
    printf("5.exportar aequivos\n");
    printf("---------------------------\n");
    printf(":::::");
    scanf("%i",&opc);
    getchar();

    return opc;

}

int sub_menu_cadastro(){
    int opc;

    printf("      cadastrar jogo       \n");
    printf("---------------------------\n");
    printf("1.pelo inicio\n");
    printf("2.pelo fim\n");
    printf("3.pelo meio\n");
    printf("0.retorar para principal\n");
    printf("---------------------------\n");
    printf(":::::");
    scanf("%i",&opc);
    getchar();

    return opc;

}
jogo_t novo_jogo(){
    jogo_t novo;

    printf("Nome do jogo.............: ");
    fgets(novo.nome,T_STR,stdin);
    retirar_enter(novo.nome);
    tornar_maiusculo(novo.nome);

    printf("Ano de lansamento........: ");
    scanf("%i",&novo.ano_lasa);
    getchar();

    printf("Genero...................: ");
    fgets(novo.genero,T_STR,stdin);
    retirar_enter(novo.genero);
    tornar_maiusculo(novo.genero);

    printf("Produtora................: ");
    fgets(novo.produtora,T_STR,stdin);
    retirar_enter(novo.produtora);
    tornar_maiusculo(novo.produtora);

    printf("Valor....................: ");
    scanf("%f", &novo.valor);
    getchar();

    return novo;
}

no_t *novo_no(jogo_t jogo){
    no_t *novo=NULL;

    novo=(no_t*)calloc(1,sizeof(no_t));

    novo->dados_jogo=jogo;
    novo->prox=NULL;

    return novo;
}

void inseri_jogo_lista_inicio(no_t *no, no_t **lista){
    if(*lista!=NULL){
        no->prox=*lista;
    }
    *lista=no;


}
void inseri_jogo_lista_final(no_t *no, no_t **lista){
    no_t *ultimo=NULL;
    
    if(*lista==NULL){
        *lista=no;
    }else{
        ultimo= localizar_ultimo_no_lista(*lista);
        ultimo->prox=no;
    }
}
no_t *localizar_ultimo_no_lista(no_t *lista){
    for(lista;lista->prox!=NULL;lista=lista=lista->prox);

    return lista;
}
no_t *localizar_jogo_por_nome(string nome, no_t *lista){}
void mostrar_dado_jogos(jogo_t dados_jogo){
    printf("\n");
    printf("Nome do jogo.............: %s\n",dados_jogo.nome);
    printf("Ano de lansamento........: %i\n",dados_jogo.ano_lasa);
    printf("Genero...................: %s\n",dados_jogo.genero);
    printf("Produtora................: %s\n",dados_jogo.produtora);
    printf("Valor....................: %.2f\n\n",dados_jogo.valor);

}
void excluir_no_lista(no_t *no, no_t **lista){}
void retirar_enter(string str){
    *(str+strlen(str)-1)='\0';

}
void tornar_maiusculo(string str){
    for(int i=0;i<strlen(str);i++){
        *(str+i)=toupper(*(str+i));
    }
}
void mostrar_jogos(no_t *lista){
    while(lista){
        mostrar_dado_jogos(lista->dados_jogo);
        lista=lista->prox;
    }
}

void exportar_dados_arquivo_texto(char* nome, no_t *lista){
    FILE *fd=NULL;
    fd=fopen(nome,"w");

    if(!fd) return;

    for(lista;lista!=NULL;lista=lista->prox){
        printf("\n");
    fprintf(fd,"Nome do jogo.............: %s\n",lista->dados_jogo.nome);
    fprintf(fd,"Ano de lansamento........: %i\n",lista->dados_jogo.ano_lasa);
    fprintf(fd,"Genero...................: %s\n",lista->dados_jogo.genero);
    fprintf(fd,"Produtora................: %s\n",lista->dados_jogo.produtora);
    fprintf(fd,"Valor....................: %.2f\n\n",lista->dados_jogo.valor);
    }
}