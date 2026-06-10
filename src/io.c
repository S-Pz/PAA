#include <stdio.h>
#include <stdlib.h>

#include "io.h"

int *read_input(FILE *entrada, int *n) {

  fscanf(entrada, "%d", n);

  int *a = malloc((*n) * sizeof(int));

  for (int i = 0; i < *n; i++) {

    fscanf(entrada, "%d", &a[i]);
  }

  return a;
}

void write_output(long long resultado) {

  FILE *saida = fopen("saida.txt", "w");

  if (!saida)
    return;

  fprintf(saida, "%lld\n", resultado);

  fclose(saida);
}
