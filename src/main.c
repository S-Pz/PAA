#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "solver.h"
#include "timer.h"

int main(int argc, char *argv[]) {

  Time start_real, end_cpu, start_cpu, end_real;

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
    
    start_real = get_real_time();
    start_cpu = get_cpu_time();
    
    resultado = solve_dp(a, n);
    
    end_cpu = get_cpu_time();
    end_real = get_real_time();

  } else {

    start_real = get_real_time();
    start_cpu = get_cpu_time();
    
    resultado = solve_alternative(a, n);
    
    end_cpu = get_cpu_time();
    end_real = get_real_time();
  }

  write_output(resultado);

  print_elapsed_time("Total (CPU) ", start_cpu, end_cpu);
  print_elapsed_time("Total (Real)", start_real, end_real);

  free(a);

  return 0;
}
