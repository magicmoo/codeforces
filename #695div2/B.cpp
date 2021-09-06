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
const ll MAXN = 3e5+5;

ll num[MAXN];
ll book[MAXN];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    ll T; cin>>T;
    while(T--){
        memset(book,0,sizeof(book));
        ll n; cin>>n;
        ll ans = 0;
        ll _ = 0;
        for(ll i=0;i<n;i++) cin>>num[i];
        for(ll i=1;i<n-1;i++){
            if(num[i-1]>num[i] && num[i+1]>num[i]){
                book[i] = 1;
                ans++;
            }else if(num[i-1]<num[i] && num[i+1]<num[i]){
                book[i] = 1;
                ans++;
            }
        }
        //(num[i]>num[i+1] && num[i+2]>num[i+1]) || (num[i]<num[i+1] && num[i+2]<num[i+1])
        //(num[i-2]>num[i-1] && num[i]>num[i-1]) || (num[i-2]<num[i-1] && num[i]<num[i-1])
        ll oans = ans;
        ll tans = oans;
        for(ll i=0;i<n;i++){
            ll temp = num[i];
            if(i>0){
                tans = oans; num[i] = num[i-1];
                for(ll j=-1;j<=1;j++){
                    if(book[i+j]) tans--;
                }
                if(i<n-2 && ((num[i]>num[i+1] && num[i+2]>num[i+1]) || (num[i]<num[i+1] && num[i+2]<num[i+1]))) tans++;
                ans = min(ans,tans);
            }
            if(i<n-1){
                tans = oans; num[i] = num[i+1];
                for(ll j=-1;j<=1;j++){
                    if(book[i+j]) tans--;
                }
                if(i>1 && ((num[i-2]>num[i-1] && num[i]>num[i-1]) || (num[i-2]<num[i-1] && num[i]<num[i-1]))) tans++;
                ans = min(ans,tans);
            }
            num[i] = temp;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
