//Projeto de L�gica feito por Emilly Raiane, Jo�o Pedro Mendes, Guilherme Omena e Leonardo Nogueira.
#include <locale.h>
#include <stdio.h>
#include <string.h>

//Criando structs para o Cadastro
typedef struct {
	char Nome[50];
	int Quantidade;
	float Preco;
}Produto;

typedef struct {
	int Id;
	Produto Produtos[50];
	float Total;
}Pedido;

int main () {
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	//Definindo Vari�veis
	Pedido pedidos[50];
	int status = 1, id = 0, i, j, limp;
	int menuPrincipal;
	
	//Iniciando o c�digo
	while(status){
		system("cls");
		puts("\n-------- RAIMARKET --------");
		printf("Digite a op��o desejada: \n");
		printf("1. Cadastrar produto.\n");
		printf("2. Buscar produto.\n");
		printf("3. Sair.\n");
		printf("---------------------------\n");
		scanf("%d", &menuPrincipal);
		switch (menuPrincipal) {
			case 1:
				system("cls");
				pedidos[id].Id = id;
				printf("N�mero do Pedido: #%d \n", id+1);
				float total = 0;
				for(i = 0; i < 100; i++){
					while((limp = getchar()) != '\n' && limp != EOF); //C�digo para limpar o Enter e n�o dar erro.
					
					printf("\nDigite o nome do produto: \n");
					char nome[50];
					fgets(nome, sizeof(nome), stdin); //Usamos fgets ao inv�s de scanf porque ele permite especificar exatamente quantos caracteres no m�ximo devem ser lidos.
					
					printf("Digite o valor do produto (em R$): \n");
					float preco;
					scanf("%f", &preco);
					
					printf("Digite a quantidade do produto: \n");
					int quantidade;
					scanf("%d", &quantidade);
					
					Produto produto = {.Preco = preco, .Quantidade = quantidade};
					strcpy(produto.Nome, nome);
					
					pedidos[id].Produtos[i] = produto;
					total += preco * quantidade;
					
					printf("Voc� deseja adicionar outro produto? [s/n] ");
					char novoProduto;
					scanf(" %c", &novoProduto);
					if (novoProduto != 's') {
						break;
					}
				}
				pedidos[id].Total = total;
				id++; 
				break;
			case 2:
				system("cls");
				for (i = 0; i < id; i++) {
					printf("-----------------------------------\n");
					printf(">>> PEDIDO n�%d <<<\n", i+1);
					for(j = 0; j < 50; j++) {
						printf("\n> Produto #%d <\n", j+1);
						printf("|Nome do produto: %s \n", pedidos[i].Produtos[j].Nome);
						printf("|Pre�o do produto: %.2f reais", pedidos[i].Produtos[j].Preco);
						printf("|Quantidade do produto: %d\n", pedidos[i].Produtos[j].Quantidade);
						if(pedidos[i].Produtos[j + 1].Quantidade == 0) {
							break;
						}
					}
					printf("> TOTAL: %.2f reais. <\n", pedidos[i].Total);
					printf("-----------------------------------\n");
				}
				printf("Pressione alguma tecla para continuar.");
				while((limp = getchar()) != '\n' && limp != EOF);
				getchar();
				break;
			case 3:
				system("cls");
				puts("Encerrando...\n");
				status = 0;
				break;
			default: 
				printf("Op��o Inv�lida.");
				break;
		}	
	}
	
	return 0;
}
