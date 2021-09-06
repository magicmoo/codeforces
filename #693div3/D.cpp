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

bool cmp(ll a,ll b) { return a>b; }
ll a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    ll T,n;
    cin>>T;
    while(T--){
        ll ans = 0;
        ll flag = 1;
        cin>>n;
        for(ll i=0;i<n;i++) cin>>a[i];
        sort(a,a+n,cmp);
        for(ll i=0;i<n;i++){
            if(flag==1 && a[i]%2==0) ans += a[i];
            else if(flag==-1 && a[i]%2==1) ans -= a[i];
            flag *= -1;
        }
        if(ans >0 ) cout<<"Alice\n";
        else if(ans == 0) cout<<"Tie\n";
        else cout<<"Bob\n";
    }
    return 0;
}
