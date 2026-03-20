TARGET = tp2

CC = gcc

CFLAGS = -Wall -Wextra -O2

SRC = tp2.c

all: $(TARGET)

# Compilar
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Rodar com estratégia D
runD: $(TARGET)
	./$(TARGET) D entrada.txt

# Rodar com estratégia A
runA: $(TARGET)
	./$(TARGET) A entrada.txt

clean:
	rm -f $(TARGET) saida.txt

rebuild: clean all

# Gerar entrada padrão
input:
	echo -e "9\n1 2 1 3 2 2 2 2 3" > entrada.txt

# Gerar entrada simples
input2:
	echo -e "5\n1 2 3 4 5" > entrada.txt

# Gerar entrada grande (exemplo)
input_big:
	echo "100000" > entrada.txt
	for i in `seq 1 100000`; do echo -n "$$((RANDOM % 10)) " >> entrada.txt; done
	echo "" >> entrada.txt
