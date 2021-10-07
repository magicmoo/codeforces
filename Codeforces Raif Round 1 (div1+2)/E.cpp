#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll a[maxn];
struct Node{
    ll num,now,cnt;
    ll cal(const ll cnt)const{
        ll cnt1 = num%cnt;
        ll cnt2 = cnt-cnt1;
        ll ans = cnt1*(num/cnt+1)*(num/cnt+1);
        ans += cnt2*(num/cnt)*(num/cnt);
        return ans;
    }
    bool operator<(const Node n1)const{
        return (this->cal(cnt))-(this->cal(cnt+1)) < (n1.cal(n1.cnt)-n1.cal(n1.cnt+1));
    }
};
priority_queue<Node> q;
int main(){
    IOS;
    ll n,k;
    cin>>n>>k;
    Rep(i,1,n) cin>>a[i];
    Rep(i,1,n){
        q.push({a[i],a[i],1});
    }
    while(n<k){
        Node tmp = q.top();
        q.pop();
        tmp = {tmp.num,(tmp.num+tmp.cnt)/(tmp.cnt+1),tmp.cnt+1};
        q.push(tmp);
        n++;
    }
    ll ans = 0;
    while(!q.empty()){
        Node tmp = q.top();
        q.pop();
        ll cnt = tmp.num%tmp.cnt;
        ll cnt2 = tmp.cnt-cnt;
        ans += cnt*(tmp.num/tmp.cnt+1)*(tmp.num/tmp.cnt+1);
        ans += cnt2*(tmp.num/tmp.cnt)*(tmp.num/tmp.cnt);
    }
    cout<<ans<<"\n";
    return 0;
}
