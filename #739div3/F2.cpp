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
ll book[10];
ll n,k;
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
bool dfs(vector<ll>& v,set<ll>& s,ll now){
    bool flag = 1;
    ll Min = *(s.begin()),Max = *(--s.end());
    ll mid = -1;
    rep(i,now,v.size()){
        if(v[i] > Max){
            flag = 0; break;
        }
        for(auto val : s){
            if(v[i] < val){
                flag = 1;
                v[i] = val;
                rep(j,i+1,v.size()) v[j] = Min;
                return 1;
            }else if(v[i]!=Max && v[i]==val){
                mid = i;
            }
            if(v[i]==val) break;
        }
    }
    if(!flag){
        if(mid == -1) return 0;
        ll num = 0;
        for(auto val : s){
            if(num){
                num = val;
                break;
            }
            if(val == v[mid]) num = 1;
        }
        v[mid] = num;
        rep(j,mid+1,v.size()) v[j] = Min;
    }
    return 1;
}
int main(){
    IOS;
    CAS {
        memset(book,0,sizeof(book));
        cin>>n>>k;
        vector<ll> v;
        solve(n,v);
        ll cnt = 0,now = -1;
        rep(i,0,v.size()){
            if(cnt==k-1 && !book[v[i]]){ 
                now = i; break;
            }
            if(!book[v[i]]){
                cnt++; book[v[i]] = 1;
            }
        }
        if(now == -1) cout<<n<<"\n";
        else{
            ll ans = 1e18;
            vector<ll> tmp;
            set<ll> s;
            Rep(i,0,9) if(book[i]) s.insert(i);
            bool flag = 0;
            Rep(i,0,9){
                flag = 0;
                tmp.clear();
                rep(j,0,v.size()) tmp.push_back(v[j]);
                if(s.count(i)) flag = 1;
                else s.insert(i);
                ll temp = 0;
                if(dfs(tmp,s,now)){
                    rep(j,0,tmp.size()){
                        temp *= 10;
                        temp += tmp[j];
                    }
                    ans = min(ans,temp);
                }
                if(!flag) s.erase(i);
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
