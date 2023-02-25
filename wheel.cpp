#include <bits/stdc++.h>

using namespace std;

void print(vector<int>& v) {
    for (int a : v) cout << a << " ";
    cout << endl;
}

int argmin(const vector<int>& v) {
    int m = INT_MAX;
    int ret = -1;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < m) {
            m = v[i];
            ret = i;
        }
    }
    return ret;
}

int vecmin(const vector<int>& v) {
    int m = INT_MAX;
    for (int a : v) {
        if (a < m) m = a;
    }
    return m;
}

int main() {
    int n, m, C;
    cin >> n >> m >> C;
    vector<int> R(n);
    for (int i = 0; i < n; ++i) {
        cin >> R[i];
    }
    vector<int> A(m), W(m);
    for (int i = 0; i < m; ++i) {
        cin >> A[i] >> W[i];
    }

    vector<vector<int>> T(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int ar = (A[j] - R[i]);
            T[i][j] = ar * ar + W[j];
        }
    }

    int total = 0;
    int curWheel = argmin(T[0]);  // start with best wheel

    // for (auto x : T) print(x);

    // For each segment
    int changemin = vecmin(T[0]) + C;
    for (int j = 0; j < m; ++j) {
        T[0][j] = min(T[0][j], changemin);
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            T[i][j] += T[i-1][j];
        }
        changemin = vecmin(T[i]) + C;
        for (int j = 0; j < m; ++j) {
            T[i][j] = min(T[i][j], changemin);
        }
    }

    cout << vecmin(T[n-1]) << endl;
    return 0;
}