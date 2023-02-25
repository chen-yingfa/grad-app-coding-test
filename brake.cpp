#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    long long mn, md;

    cin >> n >> mn >> md;
    double dmn = (double) mn;
    double dmd = (double) md;
    double mu = dmn / dmd;

    for (int i = 0; i < n; ++i) {
        long long b, p;
        cin >> b >> p;
        double db = (double) b;
        double dp = (double) p;
        if (b > mu * p) cout << "D\n";
        else cout << "S\n";
    }

    return 0;
}