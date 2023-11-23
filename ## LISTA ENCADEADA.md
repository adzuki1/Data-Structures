## LISTA ENCADEADA

Lista dinâmica, onde a alocação de memória é manual, tornando possível inserir quantos itens a memória suportar. Formado de uma estrutura

Uma lista encadeada pode ser:

- simples: os elementos são inseridos sequencialmente;
- ordenada: os elementos são inseridos em uma certa ordem (crescente, decrescente); 
- circular: o ponteiro do último nó aponta para o primeiro.

- LISTA SIMPLESMENTE ENCADEADA:

Numa lista simplesmente encadeada, cada nó aponta para o nó seguinte, formando uma sequência unidirecional. 

Uma estrutura que contém um dado e um ponteiro para o nó seguinte (um ponteiro é um tipo de variável que armazena o endereço de alguma outra variável).
É possível inserir ou deletar um elemento da lista, porém acessar os índices se torna ineficiente.

{código}


- LISTA DUPLAMENTE ENCADEADA:

Uma estrutura que contém um elemento dado e dois ponteiros, apontando para o próximo nó e para o anterior, possibilitando caminhar para dois lados.
As funções de inserir ou remover ficam um pouco mais complexas, comparadas às da lista simplesmente encadeada, pois é preciso atualizar quem é o próximo e o anterior por cada vez que caminhar na lista.

{código}

