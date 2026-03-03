// Factovisors

#include <bits/stdc++.h>
using namespace std;

int vp(int p, int n) {   // Legendre's formula
  int ans = 0;
  for (long long pi = p; pi <= n; pi *= p)
    ans += n / pi;
  return ans;
}

int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {

    bool possible;

    if (m == 0) 
      possible = false;

    else {
      unordered_map<int, int> factor_m;
      int temp = m;

      for (int PF = 2; (long long)PF * PF <= temp; ++PF) {
        while (temp % PF == 0) {
          factor_m[PF]++;
          temp /= PF;
        }
      }

      if (temp > 1)
        factor_m[temp]++;

      possible = true;

      for (auto &[p, e] : factor_m) {
        if (vp(p, n) < e) {
          possible = false;
          break;
        }
      }
    }

    printf("%d %s %d!\n", m,
           possible ? "divides" : "does not divide",
           n);
  }

  return 0;
}