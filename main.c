//Bibliotecas
#include<stdio.h>
#include<stdlib.h>

//constates
#define tamanho 100
#define E 0
#define D 1
#define R -1

//Estrutura
struct str_no{
	char dado;
	int esquerda;
	int direita;
	int pai;
};

//variaveis
struct str_no arvore[tamanho];
int lado,indice=0;
int opt =-1;
char pai,no;

//prototipação
void arvore_insere(int pai,char dado,int lado);
int arvore_procura(char dado);
void menu_mostrar();

//função principal
int main(void){
	int temp;
	do{
		menu_mostrar();
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nDigite o valor do PAI: ");
				scanf("%c",&pai);
				scanf("%c",&pai);
				printf("Digite o valor do NO:");
				scanf("%c",&no);
				scanf("%c",&no);
				printf("Digite o lado da suvarvore (E=%d/D=%d/R=%d):",E,D,R);
				scanf("%d",&lado);
				temp = arvore_procura(pai);
				arvore_insere(temp,no,pai);
			break;
			case 2:
				printf("Digite o valor do NO: ");
				scanf("%c",&no);
				scanf("%c",&no);
				temp = arvore_procura(no);
				printf("No %c\nFilho esquerda: %c\nFilhoDireita: %c\n\n",
				arvore[temp].dado,
				arvore[arvore[temp].esquerda].dado,
				arvore[arvore[temp].direita].dado);
				system("Pause");
			break;
		}
	}while(opt != 0);
	system("Pause");
	return(0);
}

//desenha o menu na tela;
void menu_mostrar(){
	system("cls");
	for(int i = 0;i<indice;i++){
		printf("| %c ",arvore[i].dado);
	}
	printf("\n1 - Insere um NO na arvore");
	printf("\n2 - Pesquisa um NO na arvore");
	printf("\n0 - Sair...\n\n");
}

//procura nó
int arvore_procura(char dado){
	if(indice != 0){
		for(int i =0;i<indice;i++){
			if(arvore[i].dado == dado){
				return(i);
			}
		}
	}
	else{
		return(0);
	}
}

//inserir no
void arvore_insere(int pai,char dado,int lado){
	switch(lado){
		case E:
			arvore[pai].esquerda = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
		break;
		case D:
			arvore[pai].direita = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
		break;
		case R:
			
			arvore[indice].dado = dado;
			arvore[indice].pai = -1;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
			
	}
}






















