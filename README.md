# sistemaMercadoEmC

Sistema de Supermercado em C
Introdução
Este projeto consiste em um sistema simples de supermercado desenvolvido em linguagem de programação C. O objetivo é implementar funcionalidades básicas de um supermercado, como cadastro de produtos, listagem, compra, visualização do carrinho e fechamento de pedido, utilizando conceitos fundamentais de programação e estruturas de dados.

Como o Sistema foi Desenvolvido
O sistema foi desenvolvido seguindo os requisitos propostos, utilizando:

Linguagem C: Para implementar as funcionalidades básicas e estruturas de dados.
Structs: Para definir as estruturas de Produto e ItemCarrinho.
Arrays Estáticos: Para armazenar os produtos cadastrados e os itens no carrinho.
Funções Modulares: Cada funcionalidade principal foi implementada em uma função separada para melhor organização e manutenção do código.
Tratamento de Erros: Foram implementadas validações de entrada para garantir que o usuário insira dados válidos, prevenindo comportamentos inesperados.
Interação com o Usuário: O programa utiliza entradas e saídas padrão para interação, exibindo menus e solicitando informações conforme necessário.
Estrutura do Código
Definições de Struct
Produto: Armazena informações de um produto, incluindo código, nome e preço.

c
Copiar código
typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;
ItemCarrinho: Representa um item no carrinho de compras, contendo o produto e a quantidade desejada.

c
Copiar código
typedef struct {
    Produto produto;
    int quantidade;
} ItemCarrinho;
Variáveis Globais
produtos[100]: Array para armazenar até 100 produtos cadastrados.
contadorProdutos: Mantém o número de produtos cadastrados.
carrinho[100]: Array para armazenar até 100 itens no carrinho.
contadorCarrinho: Mantém o número de itens no carrinho.
Funções Principais
main(): Função principal que exibe o menu e gerencia o fluxo do programa.
cadastrarProduto(): Permite o cadastro de novos produtos com código, nome e preço.
listarProdutos(): Lista todos os produtos cadastrados.
atualizarProduto(): Permite atualizar o nome e preço de um produto existente.
comprarProduto(): Adiciona produtos ao carrinho com a quantidade desejada.
visualizarCarrinho(): Exibe os produtos adicionados ao carrinho.
removerProdutoCarrinho(): Remove um produto do carrinho com base no código.
fecharPedido(): Calcula o total da compra, exibe a fatura e esvazia o carrinho.
Tratamento de Entradas
Validação de Dados: Todas as entradas do usuário são validadas para garantir que correspondam ao tipo esperado (inteiros ou floats positivos).
Limpeza de Buffer: O uso de espaço antes do especificador no scanf e o scanf("%*[^\n]") ajudam a limpar o buffer de entrada sem a necessidade de funções adicionais.
Instruções para Compilar e Executar
Pré-requisitos
Compilador C: Certifique-se de ter um compilador C instalado em seu sistema, como o GCC.
Passos
Salvar o Código

Salve o código em um arquivo com o nome supermercado.c.

Compilar o Código

Abra o terminal, navegue até o diretório onde o arquivo foi salvo e execute o seguinte comando:

bash
Copiar código
gcc supermercado.c -o supermercado
Isso irá compilar o código e gerar um executável chamado supermercado.

Executar o Programa

Ainda no terminal, execute o programa com o comando:

bash
Copiar código
./supermercado
O programa irá iniciar e exibir o menu principal.

Funcionalidades Implementadas
1. Cadastrar Produto
Descrição: Permite cadastrar novos produtos, solicitando código, nome e preço.
Uso: Escolha a opção 1 no menu principal.
Validações:
O código deve ser um número inteiro único.
O nome não pode ser vazio.
O preço deve ser um número positivo.
2. Listar Produtos
Descrição: Lista todos os produtos cadastrados com suas informações.
Uso: Escolha a opção 2 no menu principal.
Validações: Informa se não houver produtos cadastrados.
3. Atualizar Produto
Descrição: Permite atualizar o nome e o preço de um produto já cadastrado.
Uso: Escolha a opção 3 no menu principal.
Validações:
Verifica se o código inserido corresponde a um produto existente.
O nome não pode ser vazio.
O preço deve ser um número positivo.
4. Comprar Produto
Descrição: Adiciona produtos ao carrinho de compras.
Uso: Escolha a opção 4 no menu principal.
Validações:
O código do produto deve corresponder a um produto cadastrado.
A quantidade deve ser um número inteiro positivo.
5. Visualizar Carrinho
Descrição: Exibe todos os produtos no carrinho com suas quantidades e preços.
Uso: Escolha a opção 5 no menu principal.
Validações: Informa se o carrinho estiver vazio.
6. Remover Produto do Carrinho
Descrição: Remove um produto do carrinho com base no código.
Uso: Escolha a opção 6 no menu principal.
Validações:
O código do produto deve corresponder a um item no carrinho.
7. Fechar Pedido
Descrição: Calcula o total da compra, exibe uma fatura detalhada e esvazia o carrinho.
Uso: Escolha a opção 7 no menu principal.
Validações: Informa se o carrinho estiver vazio.
8. Sair
Descrição: Encerra a execução do programa.
Uso: Escolha a opção 8 no menu principal.
Exemplos de Uso
Cadastrando um Produto
plaintext
Copiar código
=== Sistema de Supermercado ===
1. Cadastrar Produto
...

Escolha uma opcao: 1

=== Cadastrar Produto ===
Codigo: 101
Nome: Leite Integral
Preco: 4.50
Produto cadastrado com sucesso!
Comprando um Produto
plaintext
Copiar código
=== Sistema de Supermercado ===
1. Comprar Produto
...

Escolha uma opcao: 4

=== Comprar Produto ===
Digite o codigo do produto: 101
Quantidade: 2
Produto adicionado ao carrinho.
Visualizando o Carrinho
plaintext
Copiar código
=== Sistema de Supermercado ===
1. Visualizar Carrinho
...

Escolha uma opcao: 5

=== Carrinho de Compras ===
Codigo: 101 | Nome: Leite Integral | Preco: R$ 4.50 | Quantidade: 2
Fechando o Pedido
plaintext
Copiar código
=== Sistema de Supermercado ===
1. Fechar Pedido
...

Escolha uma opcao: 7

=== Fechar Pedido ===
Leite Integral | Quantidade: 2 | Subtotal: R$ 9.00
Total da compra: R$ 9.00
Pedido fechado com sucesso!
Considerações Finais
Tratamento de Erros: O sistema inclui validações para garantir que o usuário insira dados válidos, exibindo mensagens de erro claras quando necessário.
Extensibilidade: O código foi escrito de forma modular, facilitando futuras extensões e melhorias, como a implementação de persistência de dados ou novas funcionalidades.
Simples e Intuitivo: O programa oferece uma interface simples e intuitiva, permitindo que o usuário interaja facilmente com as funcionalidades disponíveis.
