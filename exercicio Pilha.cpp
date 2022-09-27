#include <stdio.h>
#define tam 10

// Estrutura heterogênea - Criando novo tipo de dado chamado "Pilha"
struct Pilha
{
	   int elementos[tam];
	   int topo;
};

// Protótipos das funções
void iniciaPilha(struct Pilha *P);

void push(struct Pilha *P, int c);

void pop(struct Pilha *P);

void comparaPilha(struct Pilha P1, struct Pilha P2);


int main()
{
	struct Pilha P1;
	struct Pilha P2;
	int op, numPilha; 
	int c;
	
	// Menu em loop
	do
	{
		printf("\n Opcoes para usar o menu: ");
		printf("\n 1 - Iniciar nova pilha ");
		printf("\n 2 - Adicionar novo elemento ");
		printf("\n 3 - Retirar um elemento ");
		printf("\n 4 - Comparar as pilhas ");
		printf("\n 5 - Sair do menu");
		printf("\n Digite sua escolha: ");
		scanf("%d", &op);
		
		switch(op)
		{
		case 1:
			printf("\n Deseja iniciar a Pilha 1 ou a Pilha 2? ");
			scanf("%d", &numPilha);
			if(numPilha == 1)
			{
				iniciaPilha(&P1);
				printf("\n Voce esta na Pilha 1");
			}
			else 
			{
				iniciaPilha(&P2);
				printf("\n Voce esta na Pilha 2");
			}
			
			break;
		
		case 2:
			// Empilhar : PUSH
			
			printf("\n Deseja empilhar na Pilha 1 ou na Pilha 2? ");
			scanf("%d", &numPilha);
			
			printf("\n Digite um numero inteiro a ser inserido na pilha: ");
			scanf(" %d", &c);
			
			if(numPilha == 1)
			{
				push(&P1, c);
			}
			else 
			{
				push(&P2, c);
			}
			
			break;
		
		case 3:
			// Desempilhar : POP
			
			printf("\n Deseja desempilhar da Pilha 1 ou da Pilha 2? ");
			scanf("%d", &numPilha);
			
			if(numPilha == 1)
			{
				pop(&P1);
			}
			else 
			{
				pop(&P2);
			}
			
			break;
		
		case 4:
			//Comparar Pilhas
			comparaPilha(P1, P2);
			break;
		
		default:
			break;
		}
	}while(op!=7); // Encerra o loop
	
	return 0;
}

// Métodos 
void iniciaPilha(struct Pilha *P)
{
	P->topo = -1;
}

void push(struct Pilha *P, int c)
{
	if(P->topo == tam -1)
	{
		printf("\n Pilha cheia - Impossivel adicionar mais elementos");
	}
	else
	{
		P->topo++;
		P->elementos[P->topo] = c;
	}
} 

void pop(struct Pilha *P)
{
	if(P->topo == -1)
	{
		printf("Pilha vazia");
	}
	else
	{
		P->topo--;
	}
} 

void comparaPilha(struct Pilha P1, struct Pilha P2)
{
	if(P1.topo == P2.topo)
	{
		printf("\n As pilhas sao iguais");
	}
	else if(P1.topo < P2.topo)
	{
		printf("\n A Pilha 1 e menor que a Pilha 2");
	}
	else if(P1.topo > P2.topo)
	{
		printf("\n A Pilha 2 e menor que a Pilha 1");
	}
}

