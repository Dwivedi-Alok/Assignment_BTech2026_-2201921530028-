#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, x, y, z;
    cin >> n >> m >> k >> x >> y >> z;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < k; l++) {
                if (i + j + l == x + y + z) {
                    ans++;
                    }
                    }
                    }
                    cout << ans << endl;
                    return 0;

    
}}