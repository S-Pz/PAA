#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

long long max(long long a, long long b) {
    return (a > b) ? a : b;
}

// Estratégia D: programação dinâmica
// Coisas para verificar:
// - Se o array será cíclilco
// - Se o array atualiza a cada escolha(considerei que ele nao muda a cada escolha)
// - Testar se realmente isso funciona
long long solve_dp(int *a, int n) {
    if (n == 0) return 0;
    if (n == 1) return a[0];

    long long *dp = malloc(n * sizeof(long long));

    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + a[i]);
    }

    long long result = dp[n-1];
    free(dp);
    return result;
}

// TODO: Estratégia A: 
long long A(int *a, int n) {
    if (n == 0) return 0;
    if (n == 1) return a[0];
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: ./tp2 <D|A> entrada.txt\n");
        return 1;
    }

    char estrategia = argv[1][0];
    FILE *entrada = fopen(argv[2], "r");
    FILE *saida = fopen("saida.txt", "w");

    if (!entrada) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    int n;
    fscanf(entrada, "%d", &n);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(entrada, "%d", &a[i]);
    }

    struct timeval start, end;
    struct rusage usage;

    gettimeofday(&start, NULL);

    long long resultado;
    if (estrategia == 'D') {
        resultado = solve_dp(a, n);
    } else {
        resultado = A(a, n);
    }

    gettimeofday(&end, NULL);
    getrusage(RUSAGE_SELF, &usage);

    fprintf(saida, "%lld\n", resultado);

    printf("User time: %ld.%06ld\n",
           usage.ru_utime.tv_sec,
           usage.ru_utime.tv_usec);

    printf("System time: %ld.%06ld\n",
           usage.ru_stime.tv_sec,
           usage.ru_stime.tv_usec);

    fclose(entrada);
    fclose(saida);
    free(a);

    return 0;
}
