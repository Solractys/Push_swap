# Push Swap Planning

Push Swap é um programa que ordena uma determinada [pilha](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) de dados. É simplesmente isso que o programa deve fazer.

## Detalhamento

- O Programa deve receber um argumento (lista de números)
- O Programa deve exibir uma mensagem de erro caso o argumento seja inválido
- O Resultado do programa deve ser uma lista de instruções que servirão para ordenar a lista
- Cada instrução deve ser acompanhada de um `\n` e nada mais

## Fluxo de Desenvolvimento

### Fase 1: Fundação

- [ ] Implementar uma pilha usando listas encadeadas
- [ ] Implementar o CRUD da stack
- [ ] Implementar as 11 operações da Push Swap
- [ ] Testar cada uma isoladamente
- [ ] **Checkpoint 1:** Aqui será possível executar qualquer sequência manualmente

### Fase 2: Casos Triviais

- [ ] Implementar solução para 2 números
- [ ] Implementar solução para 3 números
- [ ] Implementar solução para 4 números
- [ ] Implementar solução para 5 números

### Fase 3: Validação

- [ ] Entender o Checker

### Fase 4: Algoritmo Principal

- [ ] Implementar a função que divide a pilha usando o pivô
- [ ] Definir estratégia de divisão
- [ ] Decidir: Recursivo ou em Chunks?
- [ ] Implementar estratégia de reconstrução
- [ ] **Checkpoint 2:** Aqui o código já ordena

### Fase 5: Otimização

- [ ] Diminuir o número de operações
- [ ] Análise de complexidade básica

### Fase 6: Testes

- [ ] Bateria de testes completa

## Conceitos Relacionados

- **Quick Sort:** Conceito de pivô
- **Merge Sort:** Divisões de listas
- **Insertion Sort:** Como inserir elementos na posição correta

## Operações Disponíveis

| Operação | Descrição |
|----------|-----------|
| `sa` | Troca os dois primeiros elementos da pilha A |
| `sb` | Troca os dois primeiros elementos da pilha B |
| `ss` | Executa `sa` e `sb` simultaneamente |
| `pa` | Move o primeiro elemento de B para o topo de A |
| `pb` | Move o primeiro elemento de A para o topo de B |
| `ra` | Rotaciona todos os elementos de A uma posição para cima |
| `rb` | Rotaciona todos os elementos de B uma posição para cima |
| `rr` | Executa `ra` e `rb` simultaneamente |
| `rra` | Rotaciona todos os elementos de A uma posição para baixo |
| `rrb` | Rotaciona todos os elementos de B uma posição para baixo |
| `rrr` | Executa `rra` e `rrb` simultaneamente |

## Metas de Performance

- **3 números:** Máximo 3 operações
- **5 números:** Máximo 12 operações
- **100 números:** Máximo ~700 operações
- **500 números:** Máximo ~5500 operações
