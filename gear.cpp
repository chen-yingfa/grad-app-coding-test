#include <bits/stdc++.h>

using namespace std;


void print(const vector<double>& v) {
    for (double d : v) cout << d << " ";
    cout << endl;
}


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

    vector<vector<double>> ratio(n, vector<double>(m + 1));
    // vector<double> ratio(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // ratio[i * m + j] = (double) C[i] / G[j];
            ratio[i][j] = (double) C[i] / G[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        ratio[i][m] = 100000000;
    }

    // sort(ratio.begin(), ratio.end());
    double eps = 1e-7;
    int lo = 0;
    int hi = m + 1;
    for (int i = 0; i < n; ++i) {
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            double r = ratio[i][mid];
            // cout << mid << " " << r << endl;
            int numGreater = 0;
            for (int i = 0; i < n; ++i) {
                int idx = lower_bound(ratio[i].begin(), ratio[i].end(), r + eps) - ratio[i].begin();
                numGreater += m - idx;

                // cout << m - idx << endl;
            }

            // cout << "num greater: " << numGreater << endl;
            if (numGreater == k - 1) {
                // Found
                cout << C[i] << " " << G[mid] << endl;
                return 0;
            }
            if (numGreater > k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        hi = lo;
        lo = 0;
        
        // cout << "lo, hi: " << lo << ", " << hi << endl;
    }

    return 0;
}