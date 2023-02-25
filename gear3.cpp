#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> C(n);
    vector<int> G(m);
    for (int i = 0; i < n; ++i) {
        cin >> C[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> G[i];
    }

    sort(C.begin(), C.end());
    sort(G.begin(), G.end(), greater<int>());

    int maxc = C[n - 1];
    int ming = G[m - 1];
    int maxg = G[0];
    for (int c = 1; c < maxc; ++c) {
        for (int g = maxg; g >= ming; --g) {
            double val = (double) c / g;
            
        }
    }

    return 0;
}