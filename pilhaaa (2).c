#include <stdio.h>//biblioteca para n sei oq
#include <stdlib.h>//mesma coisa
#include <string.h>

typedef struct p{
    char nomep[50];
}Peca;

typedef struct no{
    Peca p;
    struct no *proximo;
}No;
Peca add(){
    Peca p;
    printf("\nDigite nome da peca\n");
    scanf(" %[^\n]", p.nomep);
    return p;
}
No* adicionar(No *topo){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = add();
        novo->proximo = topo;
        return novo;
    }
    else
        printf("\nErro ao alocar memoria...\n");
    return NULL;
}
No* apagar(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else
        printf("\n-Sem pecas-\n");
    return NULL;
}
void imprimir_peca(Peca p){
    printf("\nPeca: %s\n", p.nomep);
}
void imprimir_tpecas(No *topo){
	if(topo){
	printf("\n-----------PROXIMA PECA------------\n");
	imprimir_peca(topo->p);
}
    printf("\n----------- PECAS RESTANTES--------------\n");
    while(topo){
        imprimir_peca(topo->p);
        topo = topo->proximo;
    }
    printf("\n----------------------------\n");
}
void menu(){
	printf("\n1 - Add peca\n");
	printf("2 - Tirar peca\n");
	printf("3 - Imprimir\n");
	printf("0 - Sair\n");
}
int main(){
    No *remover, *topo = NULL;
    int op;
    do{
        menu();
        scanf("%d", &op);
        switch(op){
        case 1:
            topo = adicionar(topo);
            break;
        case 2:
            remover = apagar(&topo);
            if(remover){
                printf("\nPeca removida\n");
                imprimir_peca(remover->p);
                free(remover);
            }
            else
                printf("\nSem peca para remover\n");
            break;
        case 3:
            imprimir_tpecas(topo);
            break;
        default:
            if(op != 0)
                printf("\nOpcao invalida\n");
        }
    }while(op != 0);
    return 0;
}


