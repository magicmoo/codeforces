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
const ll maxn = 505;
ll book[maxn];
vector<ll> v;
int main(){
    IOS;
    ll n,l,r,s;
    CAS {
        cin>>n>>l>>r>>s;
        ll cnt = (r-l+1);
        ll Max=0,Min=0;
        Rep(i,1,cnt) Min += i;
        Rep(i,n-cnt+1,n) Max += i;
        if(s<Min || s>Max){
            cout<<"-1\n";
            continue;
        }
        ll last = s-Min;
        v.clear();
        Rep(i,1,cnt) v.push_back(i);
        ll dis = n-cnt;
        Dep(i,cnt-1,0){
            if(last > dis){
                last -= dis;
                v[i] += dis;
            }else{
                v[i] += last;
                break;
            }
        }
        Rep(i,1,n) book[i] = 0;
        rep(i,0,cnt) book[v[i]] = 1;
        ll now = 1;
        Rep(i,1,l-1){
            while(book[now]) now++;
            cout<<now++<<" ";
        }
        rep(i,0,cnt) cout<<v[i]<<" ";
        Rep(i,r+1,n){
            while(book[now]) now++;
            cout<<now++<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
