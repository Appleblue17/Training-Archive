#include <bits/stdc++.h>
using namespace std;

using i128 = __int128_t;
using LL = long long;

constexpr int P = 998244353;

int power(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1, a = LL(a) * a % P) {
    if (b & 1) ret = LL(ret) * a % P;
  }
  return ret;
}

void Main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int& x : p) cin >> x;
  if (p[0] != 1) {
    cout << 0 << "\n";
    return;
  }

  int m = n + 1;
  vector<int> fac(m), ifac(m), w(m), iw(m);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = LL(fac[i - 1]) * i % P;
  ifac[n] = power(fac[n], P - 2);
  for (int i = n; i; i--) ifac[i - 1] = LL(ifac[i]) * i % P;
  for (int i = 0; i <= n; i++) {
    w[i] = LL(ifac[i]) * ifac[n - i] % P;
    if ((n - i) & 1) w[i] = P - w[i];
    iw[i] = power(w[i], P - 2);
  }

  vector<int> inv(m), derMat(m * m);
  for (int i = 1; i <= n; i++) inv[i] = power(i, P - 2);
  for (int i = 0; i <= n; i++) {
    int sum = 0;
    for (int j = 0; j <= n; j++) {
      if (i == j) continue;
      int invDiff = i > j ? inv[i - j] : P - inv[j - i];
      int value = LL(w[j]) * iw[i] % P * invDiff % P;
      derMat[i * m + j] = value;
      sum += value;
      if (sum >= P) sum -= P;
    }
    derMat[i * m + i] = sum ? P - sum : 0;
  }

  vector<int> pre(m);
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + (i && p[i - 1] > p[i]);
  }

  size_t size = size_t(m) * m * m;
  vector<int> B(size), X(size), A(m);
  auto get = [m](vector<int>& f, int l, int r) {
    return f.data() + (size_t(l) * m + r) * m;
  };

  for (int len = 1; len <= n; len++) {
    for (int g = 0, r = len; r <= n; g++, r++) {
      int empty = pre[r] == pre[g + 1];

      if (r < n && (g == 0 || p[g] > p[r])) {
        fill(A.begin(), A.end(), empty);
        for (int k = g + 1; k < r; k++) {
          if (p[k] >= p[r]) continue;
          const int* lhs = get(X, g, k);
          const int* rhs = get(B, k, r);
          for (int z = 1; z <= n; z++) {
            A[z] = (A[z] + LL(lhs[z]) * rhs[z]) % P;
          }
        }

        int* cur = get(X, g, r);
        int base = r - g - (g == 0);
        for (int z = 1; z <= n; z++) {
          const int* row = derMat.data() + z * m;
          i128 sum = 0;
          for (int j = 0; j <= n; j++) sum += LL(row[j]) * A[j];
          int derivative = int(sum % P);
          LL value = LL(base) * A[z] - LL(z) * derivative;
          value %= P;
          if (value < 0) value += P;
          cur[z] = LL(z) * value % P;
        }
      }

      int* cur = get(B, g, r);
      fill(cur, cur + m, empty);
      for (int k = g + 1; k < r; k++) {
        if (g && p[k] >= p[g]) continue;
        const int* lhs = get(X, g, k);
        const int* rhs = get(B, k, r);
        for (int z = 1; z <= n; z++) {
          cur[z] = (cur[z] + LL(lhs[z]) * rhs[z]) % P;
        }
      }
    }
  }

  cout << get(B, 0, n)[1] << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) Main();
  return 0;
}
