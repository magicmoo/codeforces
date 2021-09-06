#include<bits/stdc++.h>
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
ll a[maxn],b[maxn];
bool cmp(ll aa,ll bb){
    return aa>bb;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        ll n;
        cin>>n;
        for(ll i=0;i<=n+1;i++) a[i]=b[i]=0;
        for(ll i=1;i<=n;i++) cin>>a[i];
        for(ll i=1;i<=n;i++) cin>>b[i];
        sort(a+1,a+n+1,cmp); sort(b+1,b+n+1,cmp);
        ll ans = 0,num = n;
        ll suma=0,sumb=0;
        ll nowa = n-(n/4),nowb = n-(n/4)+1;
        for(ll i=1;i<=nowa;i++){
            suma += a[i];
            sumb += b[i];
        }
        while(suma < sumb){
            ans++; num++;
            if(nowb<=n && num%4!=0) sumb += b[nowb++];
            if(num%4 == 0) suma -= a[nowa--];
            suma += 100;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
