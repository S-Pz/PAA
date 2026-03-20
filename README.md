# Trabalho Prático 2

## Integrantes
- Lívia Carvalho Dâmaso  
- Lucas de Lima Bergami  
- Rian Wagner Costa  
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
TODO
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

## Geração de Entradas

O Makefile possui comandos para gerar arquivos de entrada automaticamente:

### Entrada padrão
```bash
make input
```

### Entrada simples
```bash
make input2
```

### Entrada grande (100.000 elementos aleatórios)
```bash
make input_big
```

---

## Saída

- O resultado da execução é salvo em:
```text
saida.txt
```

- No terminal são exibidos:
  - Tempo de usuário (user time)
  - Tempo de sistema (system time)

---

## Observações

- O programa também pode ser executado diretamente:

```bash
./tp2 <D|A> entrada.txt
```

- `D` → Programação Dinâmica  
- `A` → Estratégia Alternativa  
