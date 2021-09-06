#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const ll maxn = 1000 + 5;
ll C[maxn][maxn];

void get_C(ll x) {
    C[0][0] = 1;
    for (ll i = 1; i <= x; i++) {
        C[i][0] = 1;
        for (ll j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
}
bool cmp(ll a, ll b) { return a > b; }
ll a[maxn];
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("../in.txt", "r", stdin);
    // freopen("../out.txt", "w", stdout);
    ll T, n, k;
    cin >> T;
    get_C(1000);
    while (T--) {
        cin >> n >> k;
        for (ll i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, cmp);
        ll Min = a[k - 1], sum = 1, num = 1;
        for (ll i = k; i < n; i++)
            if (Min == a[i]) sum++;
        for (ll i = k - 2; i >= 0; i--)
            if (Min == a[i]) {
                sum++;
                num++;
            }
        // cout<<num<<" "<<sum<<"\n";
        cout<<C[sum][num]<<"\n";
    }
    return 0;
}
