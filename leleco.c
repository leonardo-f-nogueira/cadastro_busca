//Projeto de Lógica de Programação feito por Emilly Raiane e Leonardo Nogueira.
#include <stdio.h>
#include <string.h>
#include <locale.h>



struct produto {
	char nome[50];
	float preco;
	int quant;
};
typedef struct produto produto;

int main () {
	setlocale(LC_ALL, "Portuguese_Brazil");
	//Declarando Variáveis
	int menuPrincipal, menuSecundario;
	int status = 1;
	
	//Iniciando o programa
	while(status) {
	
		puts("\n-------- RAIMARKET --------");
		printf("Digite a opção desejada: \n");
		printf("1. Cadastrar produto.\n");
		printf("2. Buscar produto.\n");
		printf("3. Sair.\n");
		printf("---------------------------\n");
		scanf("%d", &menuPrincipal);
		system("cls");
		
		switch (menuPrincipal) {
			case 1: 
				printf("Digite o nome do produto: \n");
				printf("Digite o valor do produto (em R$): \n");
				printf("Digite a quantidade do produto: \n");
				break;
			case 2:
			    puts("-------- MENU 2 --------");
				printf("\n1. Mostrar produto\n");
				printf("\n2. Retirar produto\n");
				scanf("%d", &menuSecundario);
				switch(menuSecundario) {
					case 1:
						printf("Mostrar produto.");
						break;
					case 2:
						printf("Retirar produto.");
						break;
					default:
						printf("Opção Inválida.");
						break;
				}
				break;
			case 3:
				puts("Encerrando...\n");
				puts("Pressione qualquer tecla para encerrar.\n");
				status = 0;
				break;
			default: 
				printf("Opção Inválida.");
				break;
		}
	}
}
