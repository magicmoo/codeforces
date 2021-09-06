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
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxv = 1e6+5; //注意修改maxv数值
ll vis[maxv],prime[maxv],tol;
void liner_shai(){
    memset(vis,0,sizeof(vis));
    for(ll i=2;i<maxv;i++){
        if(!vis[i])
            prime[tol++] = i;
        for(ll j=0;j<tol&&i*prime[j]<maxv;j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll A,B;
    CAS {
        cin>>A>>B;
        if(B==1) cout<<"NO\n";
        else if(B==2){
            cout<<"YES\n";
            cout<<3*A<<" "<<5*A<<" "<<8*A<<"\n";
        }
        else{
            cout<<"YES\n";
            cout<<A<<" "<<(B-1)*A<<" "<<A*B<<"\n";
        }
    }
    return 0;
}
