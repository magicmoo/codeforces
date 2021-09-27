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
const int maxn = 2e5+5;
int v[maxn],t[maxn],book[maxn];
int sum[5];
bool flag;
vector<int> vec[maxn];
void dfs(int now,int num){
    if(flag) return;
    if(book[now]){
        if(book[now]!=num) flag = 1;
        return;
    }
    sum[num] += t[now]-v[now];
    book[now] = num;
    rep(i,0,vec[now].size()){
        int nxt = vec[now][i];
        dfs(nxt,num==1?2:1);
    }
}
int main(){
    IOS;
    int n,m,l,r;
    CAS {
        cin>>n>>m;
        flag = 0;
        Rep(i,1,n) cin>>v[i];
        Rep(i,1,n) cin>>t[i];
        Rep(i,1,n) vec[i].clear();
        Rep(i,1,n) book[i] = 0;
        sum[1] = sum[2] = 0;
        Rep(i,1,m){
            cin>>l>>r;
            vec[l].push_back(r);
            vec[r].push_back(l);
        }
        ll sss = 0;
        Rep(i,1,n) sss += t[i]-v[i];
        if(sss%2 != 0){
            cout<<"NO\n";
            continue;
        }
        dfs(1,1);
        if(flag) cout<<"YES\n";
        else{
            if(sum[1] == sum[2]) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
