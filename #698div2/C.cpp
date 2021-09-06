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
const ll INF = 0x3f3f3f3f;
const ll maxn = 2e5+5;

ll d[maxn];

bool cmp(ll a,ll b){ return a>b; }
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(ll i=1;i<=2*n;i++){
            cin>>d[i];
        }
        bool flag = true;
        sort(d+1,d+2*n+1,cmp);
        ll now = 0;
        for(ll i=1;i<2*n;i+=2){
            if(i>1 && d[i] == d[i-2]){ flag = false; break;}
            if(d[i+1] != d[i] || d[i]%2 == 1){
                flag = false;
                break;
            }
            if((d[i]/2-now)%(n-i/2) != 0 || d[i]/2-now <= 0){ flag = false; break;}
            now += (d[i]/2-now)/(n-i/2);
            // cout<<now<<"\n";
        }
        if(!flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}



