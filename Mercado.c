#include <stdio.h>
#include <string.h>

// Definição da estrutura Produto
typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

// Definição da estrutura ItemCarrinho
typedef struct {
    Produto produto;
    int quantidade;
} ItemCarrinho;

// Arrays para armazenar produtos e itens do carrinho
Produto produtos[100];
int contadorProdutos = 0;

ItemCarrinho carrinho[100];
int contadorCarrinho = 0;

// Protótipos das funções
void cadastrarProduto();
void listarProdutos();
void atualizarProduto();
void comprarProduto();
void visualizarCarrinho();
void removerProdutoCarrinho();
void fecharPedido();

int main() {
    int opcao;
    do {
        printf("\n=== Sistema de Supermercado ===\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Atualizar Produto\n");
        printf("4. Comprar Produto\n");
        printf("5. Visualizar Carrinho\n");
        printf("6. Remover Produto do Carrinho\n");
        printf("7. Fechar Pedido\n");
        printf("8. Sair\n");
        printf("\nEscolha uma opcao: ");
        // Validação da entrada do usuário
        if (scanf(" %d", &opcao) != 1 || opcao < 1 || opcao > 8) {
            printf("Entrada invalida. Por favor, insira um número entre 1 e 8.\n");
            scanf("%*[^\n]"); // Descarta a entrada inválida
            opcao = 0; // Reseta a opção para continuar no loop
            continue;
        }

        // Execução da opção escolhida
        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                atualizarProduto();
                break;
            case 4:
                comprarProduto();
                break;
            case 5:
                visualizarCarrinho();
                break;
            case 6:
                removerProdutoCarrinho();
                break;
            case 7:
                fecharPedido();
                break;
            case 8:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Oppco invalida. Tente novamente.\n");
        }
    } while (opcao != 8);
    return 0;
}

// Função para cadastrar um novo produto
void cadastrarProduto() {
    Produto p;
    printf("\n=== Cadastrar Produto ===\n");
    // Entrada e validação do código
    printf("Codigo: ");
    if (scanf(" %d", &p.codigo) != 1) {
        printf("Entrada invalida. O codigo deve ser um número inteiro.\n");
        scanf("%*[^\n]");
        return;
    }

    // Verificar se o código já existe
    for (int i = 0; i < contadorProdutos; i++) {
        if (produtos[i].codigo == p.codigo) {
            printf("Codigo ja cadastrado. Por favor, insira um codigo unico.\n");
            return;
        }
    }

    // Limpar o buffer e entrada do nome do produto
    printf("Nome: ");
    scanf(" %[^\n]s", p.nome);
    if (strlen(p.nome) == 0) {
        printf("Nome nao pode ser vazio.\n");
        return;
    }

    // Entrada e validação do preço
    printf("Preco: ");
    if (scanf(" %f", &p.preco) != 1 || p.preco < 0) {
        printf("Entrada invalida. O preço deve ser um numero positivo.\n");
        scanf("%*[^\n]");
        return;
    }

    // Adiciona o produto ao array de produtos
    produtos[contadorProdutos++] = p;
    printf("Produto cadastrado com sucesso!\n");
}

// Função para listar todos os produtos cadastrados
void listarProdutos() {
    if (contadorProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("\n=== Lista de Produtos ===\n");
    // Itera sobre o array de produtos e exibe as informações
    for (int i = 0; i < contadorProdutos; i++) {
        Produto p = produtos[i];
        printf("Código: %d | Nome: %s | Preço: R$ %.2f\n", p.codigo, p.nome, p.preco);
    }
}

// Função para atualizar informações de um produto existente
void atualizarProduto() {
    if (contadorProdutos == 0) {
        printf("Nenhum produto cadastrado para atualizar.\n");
        return;
    }
    int codigo;
    printf("\n=== Atualizar Produto ===\n");
    // Entrada e validação do código do produto
    printf("Digite o codigo do produto a ser atualizado: ");
    if (scanf(" %d", &codigo) != 1) {
        printf("Entrada invalida. O codigo deve ser um numero inteiro.\n");
        scanf("%*[^\n]");
        return;
    }

    int encontrado = 0;
    // Procura o produto pelo código
    for (int i = 0; i < contadorProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            encontrado = 1;
            // Limpar o buffer e entrada dos novos dados
            printf("Novo nome: ");
            scanf(" %[^\n]s", produtos[i].nome);
            if (strlen(produtos[i].nome) == 0) {
                printf("Nome nao pode ser vazio.\n");
                return;
            }
            printf("Novo preco: ");
            if (scanf(" %f", &produtos[i].preco) != 1 || produtos[i].preco < 0) {
                printf("Entrada invalida. O preco deve ser um numero positivo.\n");
                scanf("%*[^\n]");
                return;
            }
            printf("Produto atualizado com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }
}

// Função para comprar um produto (adicionar ao carrinho)
void comprarProduto() {
    if (contadorProdutos == 0) {
        printf("Nenhum produto disponivel para compra.\n");
        return;
    }
    int codigo, quantidade;
    printf("\n=== Comprar Produto ===\n");
    // Entrada e validação do código do produto
    printf("Digite o codigo do produto: ");
    if (scanf(" %d", &codigo) != 1) {
        printf("Entrada invalida. O código deve ser um numero inteiro.\n");
        scanf("%*[^\n]");
        return;
    }

    // Procurar o produto pelo código
    Produto prodSelecionado;
    int encontrado = 0;
    for (int i = 0; i < contadorProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            prodSelecionado = produtos[i];
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto nao encontrado.\n");
        return;
    }
    // Entrada e validação da quantidade
    printf("Quantidade: ");
    if (scanf(" %d", &quantidade) != 1 || quantidade <= 0) {
        printf("Entrada invalida. A quantidade deve ser um número inteiro positivo.\n");
        scanf("%*[^\n]");
        return;
    }

    // Verificar se o produto já está no carrinho
    encontrado = 0;
    for (int i = 0; i < contadorCarrinho; i++) {
        if (carrinho[i].produto.codigo == codigo) {
            carrinho[i].quantidade += quantidade;
            encontrado = 1;
            break;
        }
    }
    // Se não estiver no carrinho, adicionar novo item
    if (!encontrado) {
        carrinho[contadorCarrinho].produto = prodSelecionado;
        carrinho[contadorCarrinho].quantidade = quantidade;
        contadorCarrinho++;
    }
    printf("Produto adicionado ao carrinho.\n");
}

// Função para visualizar o carrinho de compras
void visualizarCarrinho() {
    if (contadorCarrinho == 0) {
        printf("O carrinho está vazio.\n");
        return;
    }
    printf("\n=== Carrinho de Compras ===\n");
    // Itera sobre o carrinho e exibe os itens
    for (int i = 0; i < contadorCarrinho; i++) {
        Produto p = carrinho[i].produto;
        int qtd = carrinho[i].quantidade;
        printf("Codigo: %d | Nome: %s | Preco: R$ %.2f | Quantidade: %d\n", p.codigo, p.nome, p.preco, qtd);
    }
}

// Função para remover um produto do carrinho
void removerProdutoCarrinho() {
    if (contadorCarrinho == 0) {
        printf("O carrinho esta vazio.\n");
        return;
    }
    int codigo;
    printf("\n=== Remover Produto do Carrinho ===\n");
    // Entrada e validação do código do produto
    printf("Digite o codigo do produto a ser removido: ");
    if (scanf(" %d", &codigo) != 1) {
        printf("Entrada invalida. O código deve ser um numero inteiro.\n");
        scanf("%*[^\n]");
        return;
    }

    int encontrado = 0;
    // Procura o produto no carrinho pelo código
    for (int i = 0; i < contadorCarrinho; i++) {
        if (carrinho[i].produto.codigo == codigo) {
            encontrado = 1;
            // Remove o produto do carrinho deslocando os itens
            for (int j = i; j < contadorCarrinho - 1; j++) {
                carrinho[j] = carrinho[j + 1];
            }
            contadorCarrinho--;
            printf("Produto removido do carrinho.\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Produto nao encontrado no carrinho.\n");
    }
}

// Função para fechar o pedido e exibir a fatura
void fecharPedido() {
    if (contadorCarrinho == 0) {
        printf("O carrinho esta vazio.\n");
        return;
    }
    float total = 0;
    printf("\n=== Fechar Pedido ===\n");
    // Itera sobre o carrinho e calcula o total
    for (int i = 0; i < contadorCarrinho; i++) {
        Produto p = carrinho[i].produto;
        int qtd = carrinho[i].quantidade;
        float subtotal = p.preco * qtd;
        total += subtotal;
        printf("%s | Quantidade: %d | Subtotal: R$ %.2f\n", p.nome, qtd, subtotal);
    }
    printf("Total da compra: R$ %.2f\n", total);
    contadorCarrinho = 0; // Limpa o carrinho
    printf("Pedido fechado com sucesso!\n");
}
