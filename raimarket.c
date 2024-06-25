// Programa criado por Emilly Raiane, Jo�o Pedro Mendes, Guilherme Omena e Leonardo Nogueira.

#include <locale.h>
#include <stdio.h>
#include <string.h>

// Criando structs para o Cadastro
typedef struct {
    char Nome[50];
    int Quantidade;
    float Preco;
} Produto;

typedef struct {
    int Id;
    Produto Produtos[50];
    float Total;
} Pedido;

// Fun��o para mostrar o pedido pelo ID
void mostrarPedidoPorId(Pedido pedidos[], int id) {
    int j;
    if (id < 0) {
        printf("Pedido inv�lido!\n");
        return;
    }

    Pedido pedido = pedidos[id];
    printf("-----------------------------------\n");
    printf(">>> PEDIDO n�%d <<<\n", id + 1);
    for (j = 0; j < 50; j++) {
        if (pedido.Produtos[j].Quantidade == 0) {
            break;
        }
        printf("\n> Produto #%d <\n", j + 1);
        printf("|Nome do produto: %s \n", pedido.Produtos[j].Nome);
        printf("|Pre�o do produto: %.2f reais\n", pedido.Produtos[j].Preco);
        printf("|Quantidade do produto: %d\n", pedido.Produtos[j].Quantidade);
    }
    printf("\n> TOTAL: %.2f reais. <\n", pedido.Total);
    printf("-----------------------------------\n");
}

// Fun��o para mostrar todos os pedidos cadastrados
void mostrarTodosPedidos(Pedido pedidos[], int totalPedidos) {
    if (totalPedidos == 0) {
        printf("N�o h� pedidos cadastrados.\n");
        return;
    }
	int i;
    for (i = 0; i < totalPedidos; i++) {
        mostrarPedidoPorId(pedidos, i);
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");  // Configurando programa para PT-BR

    // Definindo Vari�veis
    Pedido pedidos[50];
    int status = 1, id = 0, i, j, limp;
    int menuPrincipal;

    // Iniciando o c�digo
    while (status) {
        system("cls");  // Para Windows; use "clear" no Linux ou macOS
        puts("\n-------- RAIMARKET --------");
        printf("Digite a op��o desejada: \n");
        printf("1. Cadastrar pedido.\n");
        printf("2. Buscar pedido.\n");
        printf("3. Sair.\n");
        printf("---------------------------\n");
        scanf("%d", &menuPrincipal);
        switch (menuPrincipal) {
            case 1:
                system("cls");
                pedidos[id].Id = id + 1;  // Para os pedidos come�arem em 1
                float total = 0;
                for (i = 0; i < 100; i++) {
                    while ((limp = getchar()) != '\n' && limp != EOF); // C�digo para limpar o Enter e n�o dar erro.
                    printf("\nDigite o nome do produto: \n");
                    char nome[50];
                    // Usamos fgets ao inv�s de scanf porque ele permite especificar exatamente quantos caracteres no m�ximo devem ser lidos.
                    fgets(nome, sizeof(nome), stdin); 
                    // Remove o '\n' lido pelo fgets
                    size_t len = strlen(nome);
                    if (len > 0 && nome[len-1] == '\n') {
                        nome[--len] = '\0';
                    }

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

                    printf("Voc� deseja adicionar outro produto ao pedido? [s/n] ");
                    char novoProduto;
                    scanf(" %c", &novoProduto);
                    if (novoProduto != 's') {
                        break;
                    }
                }
                pedidos[id].Total = total;
                system("cls");
                printf("PEDIDO n� %d cadastrado com sucesso!\n", pedidos[id].Id);
                printf("Pressione alguma tecla para continuar.");
                while ((limp = getchar()) != '\n' && limp != EOF);
                getchar();
                id++;
                break;
            case 2:
                system("cls");
                printf("Digite a op��o desejada: \n");
                printf("1. Buscar pedido pelo n�mero.\n");
                printf("2. Mostrar todos os pedidos.\n");
                int opcaoBusca;
                scanf("%d", &opcaoBusca);
                switch (opcaoBusca) {
                    case 1:
                        printf("Digite o n�mero do pedido: ");
                        int pedidoId;
                        scanf("%d", &pedidoId);
                        if (pedidoId > 0 && pedidoId <= id) {
                            mostrarPedidoPorId(pedidos, pedidoId - 1);  // Ajusta para �ndice do array
                        } else {
                            printf("Pedido n�o encontrado!\n");
                        }
                        break;
                    case 2:
                        mostrarTodosPedidos(pedidos, id);
                        break;
                    default:
                        printf("Op��o Inv�lida.\n");
                        break;
                }
                printf("Pressione alguma tecla para continuar.");
                while ((limp = getchar()) != '\n' && limp != EOF);
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
