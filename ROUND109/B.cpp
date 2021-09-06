#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 55;
int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    CAS {
        cin>>n;
        bool flag = true;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) if(a[i] != i) flag = false;
        if(flag) cout<<"0\n";
        else{
            if(a[1] == 1 || a[n] == n) cout<<"1\n";
            else if(a[1]==n && a[n]==1) cout<<"3\n";
            else cout<<"2\n";
        }
    }
    return 0;
}
