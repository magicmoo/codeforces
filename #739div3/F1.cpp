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
void solve(ll num,vector<ll>& v){
    stack<ll> s;
    while(num){
        s.push(num%10);
        num /= 10;
    }
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
}
int main(){
    IOS;
    ll n,k;
    CAS {
        cin>>n>>k;
        vector<ll> v;
        solve(n,v);
        if(k == 1){
            ll flag = 1;
            rep(i,1,v.size()){
                if(v[i] < v[0]){
                    break;
                }else if(v[i]>v[0]){
                    flag = 0; break;
                }
            }
            if(flag){
                rep(i,0,v.size()) cout<<v[0];
                cout<<"\n";
            }else{
                rep(i,0,v.size()) cout<<(v[0]+1);
                cout<<"\n";
            }
        }else{
            ll now = 1;
            rep(i,1,v.size()) if(v[i]==v[0]) now++; else break;
            if(now>=v.size()-1){
                cout<<n<<"\n";
                continue;
            }
            bool flag = 1;
            ll mid = -1;
            ll Min = min(v[now],v[0]);
            ll Max = max(v[now],v[0]);
            rep(i,now+1,v.size()){
                if(v[i]>Max){
                    flag = 0; break;
                }else if(v[i] < Min){
                    rep(j,i,v.size()) v[j] = Min;
                    break;
                }else if(v[i]>Min && v[i]<Max){
                    v[i] = Max;
                    rep(j,i+1,v.size()) v[j] = Min;
                    break;
                }else if(v[i]==Min){
                    mid = i;
                }
            }
            if(flag){
                rep(i,0,v.size()) cout<<v[i];
            }else if(mid==-1){
                if(v[now]==v[0]-1){
                    Rep(i,0,now) cout<<v[0];
                    rep(i,now+1,v.size()) cout<<"0";
                }else{
                    rep(i,0,now) cout<<v[0];
                    cout<<(v[now]+1);
                    if(v[0]>v[now]) rep(i,now+1,v.size()) cout<<(v[now]+1);
                    else rep(i,now+1,v.size()) cout<<v[0];
                }
            }else{
                rep(i,0,mid) cout<<v[i];
                cout<<Max;
                rep(i,mid+1,v.size()) cout<<Min;
            }
            cout<<"\n";
        }
    }
    return 0;
}