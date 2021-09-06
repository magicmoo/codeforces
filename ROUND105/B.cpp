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
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 105;

int T,U,R,D,L,n,u,r,l,d;

bool check(){
    if(min(2,L)+min(2,R)<u+d) return false;
    if(min(2,U)+min(2,D)<l+r) return false;
    if(u==2 || d==2){
        if(L==0 || R==0) return false;
    }
    if(l==2 || r==2){
        if(U==0 || D==0) return false;
    }
    return true;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    cin>>T; while(T--){
        cin>>n>>U>>R>>D>>L;
        if(n==1){
            if(R==U && U==L && L==D) cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        }
        if(U > n-2) u = U-n+2;
        else u = 0;
        if(R > n-2) r = R-n+2;
        else r = 0;
        if(D > n-2) d = D-n+2;
        else d = 0;
        if(L > n-2) l = L-n+2;
        else l = 0;
        if(check()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
