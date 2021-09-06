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
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll ans,a[maxn],b[maxn];
string s,anss;
map<char,ll> book,mp,mp2;
vector<ll> v[4],v2[4];
char chars[4] = {'A','O','T','N'};
ll merge(ll l,ll r){
    if(l == r) return 0;
    ll m = (l+r)/2;
    ll now = r,temp = 0;
    temp += merge(l,m); temp += merge(m+1,r);
    for(ll i=m;i>=l;i--){
        while(now>m && a[i]<a[now]) now--;
        temp += (now-m);
    }
    ll nl = l,nr = m+1,cnt = 0;
    while(nl<=m && nr<=r){
        if(a[nl]<a[nr]) b[cnt++] = a[nl++];
        else b[cnt++] = a[nr++];
    }
    while(nl<=m) b[cnt++] = a[nl++];
    while(nr<=r) b[cnt++] = a[nr++];
    for(ll i=0;i<cnt;i++) a[i+l] = b[i];
    return temp;
}
ll cal(string str){
    ll cnt = 0;
    for(ll i=0;i<4;i++) v2[i].clear();
    for(ll i=0;i<s.length();i++){
        v2[mp2[s[i]]].push_back(i);
    }
    for(ll i=0;i<4;i++){
        ll now = 0;
        for(ll j=0;j<mp[str[i]];j++){
            a[cnt++] = v2[mp2[str[i]]][now++];
        }
    }
    return merge(0,s.length()-1);
}
void dfs(ll now,string str){
    if(now == 4){
        ll temp = cal(str);
        if(temp > ans){
            ans = temp;
            anss = str;
        }
    }
    for(ll i=0;i<4;i++){
        if(book[chars[i]]) continue;
        str += chars[i];
        book[chars[i]] = 1;
        dfs(now+1,str);
        str.pop_back();
        book[chars[i]] = 0;
    }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    for(ll i=0;i<4;i++) mp2[chars[i]] = i;
    CAS {
        ans = -1;
        book.clear(); mp.clear();
        cin>>s;
        for(ll i=0;i<s.length();i++){
            mp[s[i]]++;
            v[mp2[s[i]]].push_back(i);
        }
        dfs(0,"");
        // cal("TONA");
        for(ll i=0;i<4;i++){
            for(ll j=0;j<mp[anss[i]];j++) cout<<anss[i];
        }
        cout<<"\n";
    }
    return 0;
}
