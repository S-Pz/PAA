# Trabalho Prático 2

## Integrantes
- Lívia Carvalho Dâmaso  
- Lucas de Lima Bergami  
- Sávio Francisco Cirino da Paz  

---

## Descrição do Problema

Dada uma sequência de `N` inteiros, o jogador pode realizar várias jogadas.  
Em cada jogada, ao escolher um elemento `a[k]`, os elementos `a[k-1]` e `a[k+1]` também são removidos da sequência.

O objetivo é determinar a **pontuação máxima possível**, onde cada jogada soma o valor do elemento escolhido.

---

## Estratégias Implementadas

### Programação Dinâmica (D)
Utiliza um vetor `dp` onde:

```
dp[i] = max(dp[i-1], dp[i-2] + a[i])
```

- `dp[i-1]`: não escolher o elemento atual  
- `dp[i-2] + a[i]`: escolher o elemento atual  

Complexidade:
- Tempo: O(n)
- Espaço: O(n)

---

### Estratégia Alternativa (A)

A estratégia alternativa utiliza **programação dinâmica top-down com memoização**.

O algoritmo decide, para cada posição `i`, entre:

- **Escolher `a[i]`** e pular para `i + 2`
- **Não escolher `a[i]`** e avançar para `i + 1`

A solução utiliza um vetor `memo` para armazenar resultados já calculados e evitar recomputações.

#### Recorrência
```
solve(i) = max(a[i] + solve(i + 2), solve(i + 1))
```
Complexidade:
- Tempo: O(n)
- Espaço: O(n)

---

## Compilação e Execução

O projeto utiliza **Makefile** para facilitar a execução.

### Compilar
```bash
make
```

---

### Executar Programação Dinâmica
```bash
make runD
```

---

### Executar Estratégia Alternativa
```bash
make runA
```

---

### Limpar arquivos gerados
```bash
make clean
```

---

## Saída

- O resultado da execução é salvo em:
```text
saida.txt
```

- No terminal são exibidos:
  - Tempo de cpu (user time)
  - Tempo de sistema (system time)

---

## Observações

- O programa também pode ser executado diretamente:

```bash
./bin/tp2 <D|A> entrada.txt
```

- `D` → Programação Dinâmica  
- `A` → Estratégia Alternativa  
