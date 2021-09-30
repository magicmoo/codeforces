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
const int maxv = 1e5; //注意修改maxv数值
int vis[maxv],prime[maxv],tol;
void liner_shai(){
    memset(vis,0,sizeof(vis));
    for(int i=2;i<maxv;i++){
        if(!vis[i])
            prime[tol++] = i;
        for(int j=0;j<tol&&i*prime[j]<maxv;j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}
vector<pair<int,int>> vec;
vector<int> ans;
int last;
void dfs(int now,int num){
    if(now == vec.size()){
        if(num != last) ans.push_back(num);
        return;
    }
    Rep(i,0,vec[now].second){
        dfs(now+1,num*pow(vec[now].first,i));
    }
}
int main(){
    IOS;
    int n;
    liner_shai();
    CAS {
        cin>>n;
        vec.clear();
        ans.clear();
        for(int i=0;i<tol&&prime[i]*prime[i]<=n;i++){
            pair<int,int> p = {prime[i],0};
            while(n%prime[i] == 0){
                n /= prime[i];
                p.second++;
            }
            if(p.second) vec.push_back(p);
        }
        if(n!=1) vec.push_back({n,1});
        last = vec[0].first*vec[vec.size()-1].first;
        rep(i,0,vec.size()){
            Rep(j,1,vec[i].second){
                dfs(i+1,pow(vec[i].first,j));
            }
        }
        ans.push_back(last);
        int cnt = 0;
        rep(i,1,ans.size()){
            if(__gcd(ans[i],ans[i-1])==1) cnt++;
        }
        if(__gcd(ans[0],ans[ans.size()-1])==1) cnt++;
        rep(i,0,ans.size()) cout<<ans[i]<<" ";
        cout<<"\n";
        cout<<cnt<<"\n";
    }
    return 0;
}
