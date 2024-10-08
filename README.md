# Sistema de Mercado em C

## Introdução
Este projeto consiste em um sistema simples de supermercado desenvolvido em linguagem C. O objetivo é implementar funcionalidades básicas de um supermercado, como:

- Cadastro de produtos
- Listagem de produtos
- Compra de produtos
- Visualização do carrinho
- Fechamento de pedido

Utilizando conceitos fundamentais de programação e estruturas de dados.

## Como o Sistema foi Desenvolvido
O sistema foi desenvolvido seguindo os requisitos propostos, utilizando:

- **Linguagem C**: Para implementar as funcionalidades básicas e estruturas de dados.
- **Structs**: Para definir as estruturas de produto e item do carrinho.
- **Arrays Estáticos**: Para armazenar os produtos cadastrados e os itens no carrinho.
- **Funções Modulares**: Cada funcionalidade principal foi implementada em uma função separada para melhor organização e manutenção do código.
- **Tratamento de Erros**: Foram implementadas validações de entrada para garantir que o usuário insira dados válidos, prevenindo comportamentos inesperados.
- **Interação com o Usuário**: O programa utiliza entradas e saídas padrão para interação, exibindo menus e solicitando informações conforme necessário.

## Estrutura do Sistema

### Estruturas Utilizadas
O sistema conta com estruturas para armazenar informações dos produtos e dos itens no carrinho de compras.

### Variáveis Globais
- Array para armazenar os produtos cadastrados.
- Contadores para manter o número de produtos e itens no carrinho.

## Funções Principais
- **cadastrarProduto**: Permite o cadastro de novos produtos com código, nome e preço. Inclui validações para garantir que o código do produto seja único e que o preço seja positivo.
- **listarProdutos**: Lista todos os produtos cadastrados no sistema, exibindo informações detalhadas, como código, nome e preço, utilizando a função auxiliar infoProduto.
- **atualizarProduto**: Permite atualizar o nome e o preço de um produto existente. O produto é identificado pelo seu código, e o usuário pode modificar as informações conforme necessário.
- **comprarProduto**: Adiciona produtos ao carrinho com a quantidade desejada. A função verifica se o produto já está no carrinho usando a função auxiliar temNoCarrinho. Se estiver, atualiza a quantidade; caso contrário, adiciona um novo item ao carrinho.
- **visualizarCarrinho**: Exibe os produtos adicionados ao carrinho, mostrando detalhes como o código, nome, preço e quantidade de cada produto.
- **removerProdutoCarrinho**: Permite a remoção de um produto do carrinho com base no código informado pelo usuário. Se o produto estiver no carrinho, ele é removido, e o carrinho é atualizado.
- **fecharPedido**: Calcula o total da compra, exibe a fatura dos produtos comprados e esvazia o carrinho para futuras operações.

## Funções Auxiliares
- **infoProduto**: Recebe um produto e exibe suas informações, incluindo o código, nome e preço, formatando o preço com o símbolo R$.
- **temNoCarrinho**:  Verifica se um produto, identificado pelo código, já está presente no carrinho. Retorna um ponteiro para o item no carrinho se encontrado, ou NULL caso contrário. Utilizada pela função Comprar Produto para decidir se deve atualizar um item existente ou adicionar um novo.

## Tratamento de Entradas
- **Validação de Dados**: Todas as entradas do usuário são validadas para garantir que correspondam ao tipo esperado (inteiros ou floats positivos).
- **Limpeza de Buffer**: Técnicas para limpar o buffer de entrada são utilizadas para evitar problemas com a leitura de dados.

## Instruções para Compilar e Executar

### Pré-requisitos

- Um compilador C instalado em seu sistema, como o GCC.
- Eu utilizei o CodeBlocks para fazer, não recomendo o VsCode pois ele dá uma bugada na hora de executar

### Passos

1. Salve o código em um arquivo com o nome `mercado.c`.
2. Abra o terminal, navegue até o diretório onde o arquivo foi salvo e execute o comando para compilar o código:
   ```bash
   gcc mercado.c -o mercado
Execute o programa com o comando:
./mercado
O programa irá iniciar e exibir o menu principal.

## Funcionalidades Implementadas

### 1. Cadastrar Produto
Permite cadastrar novos produtos, solicitando código, nome e preço.

**Validações:**
- O código deve ser único.
- O nome não pode ser vazio.
- O preço deve ser um número positivo.

### 2. Listar Produtos
Lista todos os produtos cadastrados com suas informações.

- Exibe mensagem caso não haja produtos cadastrados.

### 3. Atualizar Produto
Permite atualizar o nome e o preço de um produto já cadastrado.

**Validações:**
- O código inserido deve corresponder a um produto existente.
- O nome não pode ser vazio.
- O preço deve ser um número positivo.

### 4. Comprar Produto
Adiciona produtos ao carrinho de compras.

**Validações:**
- O código do produto deve corresponder a um produto cadastrado.
- A quantidade deve ser um número inteiro positivo.

### 5. Visualizar Carrinho
Exibe todos os produtos no carrinho com suas quantidades e preços.

- Exibe mensagem caso o carrinho esteja vazio.

### 6. Remover Produto do Carrinho
Remove um produto do carrinho com base no código.

**Validações:**
- O código do produto deve corresponder a um item no carrinho.

### 7. Fechar Pedido
Calcula o total da compra, exibe uma fatura detalhada e esvazia o carrinho.

- Exibe mensagem caso o carrinho esteja vazio.

### 8. Sair
Encerra a execução do programa.
