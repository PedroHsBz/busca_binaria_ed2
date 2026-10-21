# Algoritmos de Busca — Estrutura de Dados II

Busca linear e busca binária (iterativa e recursiva) em C++.
Seminário 02 — IFTM Campus Patrocínio.

## Arquivos

```
src/buscas.cpp       busca linear, binária iterativa e binária recursiva
src/exercicio1.cpp   Exercício 1 — busca clássica e os 3 erros comuns
src/exercicio2.cpp   Exercício 2 — lower/upper bound (quantos alunos tiraram cada nota)
entradas/            entradas de exemplo dos exercícios
docs/                slides da apresentação (seminario-busca.pptx)
```

## Como rodar

```bash
g++ -std=c++17 src/buscas.cpp -o buscas
./buscas

g++ -std=c++17 src/exercicio1.cpp -o exercicio1
./exercicio1 < entradas/exercicio1.txt

g++ -std=c++17 src/exercicio2.cpp -o exercicio2
./exercicio2 < entradas/exercicio2.txt
```

## Teste de mesa

Cada busca imprime o intervalo `[ini, fim]` a cada iteração. Exemplo, buscando 11 em `{1, 3, 5, 7, 9, 11, 13, 15}`:

```
it 1: ini=0 fim=7 meio=3 v[meio]=7    -> 7 < 11, vai para a direita
it 2: ini=4 fim=7 meio=5 v[meio]=11   -> achou na posição 5
```

## Resumo

|              | Linear | Binária iterativa | Binária recursiva |
| ------------ | ------ | ----------------- | ----------------- |
| Precisa ordenar? | não | sim | sim |
| Tempo        | O(n)   | O(log n)          | O(log n)          |
| Memória      | O(1)   | O(1)              | O(log n) (pilha)  |

## Autores

Karine, Pedro e Lucas — Estrutura de Dados II — IFTM Campus Patrocínio
