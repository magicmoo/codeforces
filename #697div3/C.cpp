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
const int maxn = 2e5+5;

int a[maxn],b[maxn];
int booka[maxn],bookb[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,A,B,K;
    cin>>T;
    while(T--){
        memset(booka,0,sizeof(a)); memset(bookb,0,sizeof(b));
        cin>>A>>B>>K;
        for(int i=0;i<K;i++){ cin>>a[i]; booka[a[i]]++; }
        for(int i=0;i<K;i++){ cin>>b[i]; bookb[b[i]]++; }
        ll ans = 0;
        for(int i=0;i<K;i++){
            ans += K-booka[a[i]]-bookb[b[i]]+1;
        }
        ans /= 2;
        cout<<ans<<"\n";
    }
    return 0;
}
