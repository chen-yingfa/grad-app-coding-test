#include <bits/stdc++.h>

using namespace std;


void print(const vector<double>& v) {
    for (double d : v) cout << d << " ";
    cout << endl;
}

vector<double> dc (10010);


int numGreater(double val, int clo, int chi, int glo, int ghi, 
               vector<int>& C, vector<int>& G) {
    if (chi - clo < 1) return 0;
    if (ghi - glo < 1) return 0;

    int cm = (clo + chi) / 2;
    int curc = C[cm];
    for (int j = glo; j < ghi; ++j) {
        dc[j] = (double) C[cm] / G[j];
    }

    int idx = lower_bound(dc.begin() + glo, dc.begin() + ghi, val + 1e-9) - dc.begin();
    int BR = (ghi - idx) * (chi - cm);
    int TR = numGreater(val, clo, cm, idx, ghi, C, G);
    int BL = numGreater(val, cm + 1, chi, glo, idx, C, G);
    // cout << cm << ": " << idx << " " << TR << " " << BR << " " << BL << endl;
    return BR + TR + BL;
}

bool binsearch(int k, int clo, int chi, int glo, int ghi,
            vector<int>& C, vector<int>& G) {
    
    if (chi - clo < 1) return false;
    if (ghi - glo < 1) return false;

    int cm = (clo + chi) / 2;
    int gm = (glo + ghi) / 2;
    double val = (double) C[cm] / G[gm];

    int num = numGreater(val, clo, chi, glo, ghi, C, G);
    if (num == k-1) {
        // Top right
        if (binsearch(k, clo, cm, gm + 1, ghi, C, G)) return true;
        cout << C[cm] << " " << G[gm] << endl;
        return true;
    } else if (num < k-1) { // Too large
        // Top half
        if (binsearch(k, clo, cm, glo, ghi, C, G)) return true;
        // Bottom left
        if (binsearch(k, cm, chi, glo, gm, C, G)) return true;
    } else { // Too small
        // top right
        if (binsearch(k, clo, cm + 1, gm + 1, ghi, C, G)) return true;
        // bottom half
        if (binsearch(k, cm + 1, chi, glo, ghi, C, G)) return true;
    }
    return false;
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

    binsearch(k, 0, C.size(), 0, G.size(), C, G);
    return 0;
}