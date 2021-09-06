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
const int maxv = 2e5+5;
const int maxn = 2e5+5;
const int mod = 1e9+7;

int vis[maxv],prime[maxv],tol;
void line_shai(){
    memset(vis,0,sizeof(vis));
    for(int i=2;i<maxv;i++){
        if(!vis[i]) prime[tol++] = i;
        for(int j=0;j<tol&&i*prime[j]<maxv;j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0) break;
        }
    }
}


ll Pow(int a,int b){
    int ans = 1;
    int base = a;
    while(b){
        if(b & 1) ans *= base;
        base *= base;
        b >>= 1;
        ans %= mod;
        base %= mod;
    }
    return ans;
}
int a[maxn];
map<int,int> mp[maxn];
multiset<int> s[maxv];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,q,index,mul;
    cin>>n>>q;
    line_shai();
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<tol&&prime[j]*prime[j]<=a[i];j++){
            while(a[i]%prime[j] == 0){
                mp[i][prime[j]]++;
                a[i] /= prime[j];
            }
            if(mp[i].count(prime[j])) s[prime[j]].insert(mp[i][prime[j]]);
        }
        if(a[i] != 1){
            mp[i][a[i]]++;
            if(mp[i][a[i]] > 1){
                auto it = s[a[i]].find(mp[i][a[i]]-1);
                s[a[i]].erase(it);
            }
            s[a[i]].insert(mp[i][a[i]]);
            a[i] = 1;
        }
    }
    ll ans = 1;
    for(int i=0;i<tol;i++){
        if(s[prime[i]].size() == n){
            ans *= Pow(prime[i],*(s[prime[i]].begin()));
            ans %= mod;
        }
    }
    while(q--){
        cin>>index>>mul;
        index--;
        bool flag = false;
        for(int j=0;j<tol&&prime[j]*prime[j]<=mul;j++){
            flag = false;
            int last = 0;
            if(mp[index].count(prime[j])) last = mp[index][prime[j]];
            while(mul%prime[j] == 0){
                flag = true;
                mp[index][prime[j]]++;
                mul /= prime[j];
            }
            int num1 = 0;
            if(flag && s[prime[j]].size() == n) num1 = *(s[prime[j]].begin());  
            if(last > 0 && flag){
                auto it = s[prime[j]].find(last);
                s[prime[j]].erase(it);
            }
            if(flag) s[prime[j]].insert(mp[index][prime[j]]);
            int num2 = *(s[prime[j]].begin());
            if(flag && num2>num1 && s[prime[j]].size() == n){
                ans *= (Pow(prime[j],num2-num1));
                ans %= mod;
            }
        }
        if(mul != 1){
            int last = mp[index][mul];
            int num1 = 0;
            if(s[mul].size() == n) num1 = *(s[mul].begin());
            if(last>0){
                auto it = s[mul].find(last);
                s[mul].erase(it);
            }
            mp[index][mul]++;
            s[mul].insert(mp[index][mul]);
            int num2 = *(s[mul].begin());
            if(s[mul].size() == n){
                ans *= (Pow(mul,num2-num1));
                ans %= mod;
            }
            
        }
        cout<<ans<<"\n";
    }
    return 0;
}
