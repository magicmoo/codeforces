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
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
int n,m,a[maxn];
vector<int> v;
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        cin>>n>>m;
        v.clear();
        for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
        for(int i=1;i<=n;i++){
            if(a[i] == 1) v.push_back(i);
        }
        if(v.size() == 0){
            for(int i=1;i<=n;i++) cout<<"0";
            cout<<"\n";
            continue;
        }
        int now = 0,l = -INF,r = INF;
        for(int i=1;i<=n;i++){
            while(now<v.size() && v[now]<i) now++;
            if(now<v.size()) r = v[now];
            else r = INF;
            if(now>0) l = v[now-1];
            else l = -INF;
            if(r-i == i-l) cout<<0;
            else if(r-i<=m || i-l<=m) cout<<1;
            else cout<<0;
        }
        cout<<"\n";
    }
    return 0;
}
