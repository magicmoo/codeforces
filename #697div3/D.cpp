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

struct node{
    ll a,b;
}nodes[maxn];
bool cmp(node a,node b){
    if(a.b != b.b) return a.b<b.b;
    return a.a>b.a;
}

ll num1[maxn],num2[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,n,m,mid,ans,last;
    cin>>T;
    while(T--){
        ll sum = 0;
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        cin>>n>>m;
        ans = 0;
        for(ll i=1;i<=n;i++){ cin>>nodes[i].a; sum += nodes[i].a; }
        for(ll i=1;i<=n;i++) cin>>nodes[i].b;
        if(m > sum){
            cout<<"-1\n"; continue;
        }
        sort(nodes+1,nodes+n+1,cmp);
        mid = n+1;
        for(ll i=1;i<=n;i++) if(nodes[i].b == 2) {mid = i; break;}
        for(ll i=1;i<mid;i++){
            num1[i] = num1[i-1]+nodes[i].a;
        }
        for(ll i=mid;i<=n;i++){
            num2[i-mid+1] = num2[i-mid]+nodes[i].a;
        }
        ll end = lower_bound(num1+1,num1+mid,m)-num1;
        if(num1[end] != 0) ans = end;
        else{
            ans = INF;
        }
        last = n-mid+1;
        for(ll i=0;i<end;i++){
            ll mm = m-num1[i];
            int last1 = lower_bound(num2+1,num2+last+1,mm)-num2;
            if(last+1 == last1) continue;
            last = last1;
            ans = min(ans,i+2*last);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
