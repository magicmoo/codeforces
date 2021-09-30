#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m, k; scanf("%d %d %d", &n, &m, &k);
        vector<int> v(n), h(m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &h[i]);
        }
        map<int, int> vip, hip;
        map<pair<int, int>, int> vipr, hipr;
        long long resp = 0;
        for (int i = 0; i < k; i++) {
            int x, y; scanf("%d %d", &x, &y);
            int vi = lower_bound(v.begin(), v.end(), x) - v.begin();
            int hi = lower_bound(h.begin(), h.end(), y) - h.begin();
            if (v[vi] == x && h[hi] == y) {
                continue;
            }
            if (v[vi] == x) {
                //printf("i = %d, going to hip = %d\n", i, hi);
                resp += hip[hi]++;
                resp -= hipr[{vi, hi}]++;
            }
            if (h[hi] == y) {
                //printf("i = %d, going to vip = %d\n", i, vi);
                resp += vip[vi]++;
                resp -= vipr[{vi, hi}]++;
            }
        }
        printf("%lld\n", resp);
    }
}