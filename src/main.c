#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "solver.h"
#include "timer.h"

int main(int argc, char *argv[]) {

  if (argc < 3) {

    printf("Uso: ./tp2 <D|A> entrada.txt\n");

    return 1;
  }

  FILE *entrada = fopen(argv[2], "r");

  if (!entrada) {

    printf("Erro ao abrir arquivo\n");

    return 1;
  }

  int n;

  int *a = read_input(entrada, &n);

  fclose(entrada);

  long long resultado;

  if (argv[1][0] == 'D') {

    resultado = solve_dp(a, n);

  } else {

    resultado = solve_alternative(a, n);
  }

  write_output(resultado);

  print_times();

  free(a);

  return 0;
}
