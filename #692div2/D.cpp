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
const ll maxn = 1e5+5;

ll sum0[maxn],sum1[maxn],sum2[maxn];
vector<ll> v;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    string str;
    ll x,y,ans = 0,m = 0;
    cin>>str>>x>>y;
    for(ll i=0;i<str.length();i++){
        if(str[i] == '0'){
            ans += y*(sum1[i]+sum2[i]);
            sum0[i+1] = sum0[i]+1;
            sum1[i+1] = sum1[i];
            sum2[i+1] = sum2[i];
        }else if(str[i] == '1'){
            ans += x*sum0[i];
            sum0[i+1] = sum0[i];
            sum1[i+1] = sum1[i]+1;
            sum2[i+1] = sum2[i];
        }else{
            ans += x*sum0[i];
            sum0[i+1] = sum0[i];
            sum1[i+1] = sum1[i];
            sum2[i+1] = sum2[i]+1;
            v.push_back(i);
        }
    }
    if(x < y){
        ll temp = ans;
        for(ll now=0;now<v.size();now++){
            ll i = v[now];
            temp -= x*(sum0[i]+now)+y*(sum0[str.length()]-sum0[i]);
            temp += y*sum1[i]+x*(sum1[str.length()]-sum1[i]+v.size()-now-1);
            ans = min(temp,ans);
        }
    }else{
        ll temp = ans;
        for(ll now=v.size()-1;now>=0;now--){
            ll i = v[now];
            temp -= x*sum0[i]+y*(sum0[str.length()]-sum0[i]+v.size()-now-1);
            temp += y*(sum1[i]+now)+x*(sum1[str.length()]-sum1[i]);
            ans = min(temp,ans);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
