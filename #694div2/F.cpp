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
const int maxn = 3e5+5;
vector<int> vec[maxn];
int book[maxn],cnt[maxn],book2[maxn];
void solve(int now){
    book[now] = 1;
    rep(i,0,vec[now].size()){
        book[vec[now][i]] = -1;
    }
}
void dfs(int now){
    if(book2[now]!=0) return;
    book2[now] = 1;
    if(book[now]==0) solve(now);
    rep(i,0,vec[now].size()){
        dfs(vec[now][i]);
    }
}
int main(){
    IOS;
    int n,m,l,r;
    CAS{
        cin>>n>>m;
        Rep(i,1,n) vec[i].clear();
        Rep(i,1,m){
            cin>>l>>r;
            vec[l].push_back(r);
            vec[r].push_back(l);
            cnt[l]++; cnt[r]++;
        }
        bool flag = 1;
        if(!flag){
            cout<<"NO\n";
            continue;
        }
        Rep(i,1,n) book2[i] = book[i] = 0;
        dfs(1);
        int cnt = 0;
        Rep(i,1,n){
            if(book[i] == 1) cnt++;
            else if(book[i] == 0) flag = 0;
        }
        if(!flag){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n"<<cnt<<"\n";
        Rep(i,1,n){
            if(book[i] == 1) cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
