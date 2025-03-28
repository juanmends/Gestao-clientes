# Gestao-clientes
Projeto de estrutura de dados em C++ para gestão de clientes

Código feito para a aula de estrutura de dados. A proposta era que criássemos um sistema simples de gestão de clientes para um estabelecimento fictício, utilizando listas encadeadas(simples e duplas).

*Struct no_d*
Representa um nó de uma lista encadeada dupla que guarda as informações de um cliente. Possui um ponteiro para o próximo cliente da lista e um para o cliente anterior. Além disso, possui o campo "info" que indica o código do cliente(que começa em 100 e segue o padrão 100,200,300,400,...). Por fim, possui um ponteiro para uma lista encadeada simples formada pelos produtos que o cliente consumiu(começando vazia).

*Struct no_s*
Representa um nó de uma lista encadeada simples que guarda as informações dos produtos consumidos por um cliente. O campo "cod" indica o código do produto e o ponteiro "pr" aponta para o próximo produto da lista.

*Função chegada_cliente()*
Utilizada para adicionar um novo cliente à lista duplamente encadeada.

*Função consumo_cliente|()*
O usuário indica o código do cliente e código do produto. Depois, o programa percorre a lista de clientes em busca do código indicado. Caso ele seja encontrado, o produto é adicionado a lista de produtos desse cliente e uma mensagem indica que o pedido foi realizado com sucesso.

*Função saida_cliente()*
O usuário informa o código do cliente. Depois, o programa percorre a lista de clientes em busca do código indicado. Caso seja encontrado, o código de cada produto que ele consumiu é impresso na tela e, por fim, o cliente é liberado da lista e uma mensagem aparece confirmando a operação.

*Função main()*
Une todas as funções do programa por meio de um menu que permite a interação do usuário com o mesmo.
