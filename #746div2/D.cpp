#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
set<int> s,tmps;
vector<int> v[maxn];
int sum;
inline void out(set<int>& ss){
    cout<<"? ";
    cout<<ss.size()<<" ";
    for(auto i=ss.begin();i!=ss.end();i++) cout<<*i<<" ";
    cout<<"\n";
    cout.flush();
}
void dfs(int now,int last,int& cnt){
    if(s.count(now)){
        cnt++;
        tmps.insert(now);
    }
    if(cnt >= (sum+1)/2) return;
    rep(i,0,v[now].size()){
        int nxt = v[now][i];
        if(nxt == last) continue;
        if(cnt >= (sum+1)/2){
            return;
        }
        dfs(nxt,now,cnt);
    }
}
bool check(int now){
    rep(i,0,v[now].size()){
        int nxt = v[now][i];
        if(s.count(nxt) && !tmps.count(nxt)) return 1;
    }
    return 0;
}
int main(){
    IOS;
    int n,l,r,Max,num;
    cin>>n;
    sum = 0;
    Rep(i,1,n-1){
        cin>>l>>r;
        v[l].push_back(r);
        v[r].push_back(l);
    }
    Rep(i,1,n) s.insert(i);
    out(s);
    cin>>Max;
    sum = s.size();
    while(s.size()>2){
        tmps.clear();
        int cnt = 0;
        dfs(1,-1,cnt);
        out(tmps);
        cin>>num;
        if(num == Max){
            s.clear();
            for(auto i=tmps.begin();i!=tmps.end();i++) s.insert(*i);
            sum = s.size();
        }else{
            for(auto i=tmps.begin();i!=tmps.end();i++){
                if(check(*i)) continue;
                s.erase(*i);
            }
            sum = s.size();
        }
    }
    cout<<"! ";
    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }
    cout<<"\n";
    cout.flush();
    return 0;
}