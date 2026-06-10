#include "solver.h"
#include <stdlib.h>

#define MAX 100001

static long long memo[MAX];

static long long max(long long a, long long b) { return a > b ? a : b; }

long long solve_dp(int *a, int n) {

  if (n == 0)
    return 0;

  if (n == 1)
    return a[0];

  long long *dp = malloc(n * sizeof(long long));

  dp[0] = a[0];

  dp[1] = max(a[0], a[1]);

  for (int i = 2; i < n; i++) {

    dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
  }

  long long result = dp[n - 1];

  free(dp);

  return result;
}

static long long solve_topdown(int *a, int n, int i) {

  if (i >= n)
    return 0;

  if (memo[i] != -1)
    return memo[i];

  long long pegar = a[i] + solve_topdown(a, n, i + 2);

  long long nao_pegar = solve_topdown(a, n, i + 1);

  memo[i] = max(pegar, nao_pegar);

  return memo[i];
}

long long solve_alternative(int *a, int n) {

  for (int i = 0; i < MAX; i++)
    memo[i] = -1;

  return solve_topdown(a, n, 0);
}
