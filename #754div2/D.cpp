#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<int,int>
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
vector<int> vec[maxn];
int vis[maxn],ans[maxn];
void dfs(int now,int last,int flag){
    vis[now] = flag;
    for(int nxt : vec[now]){
        if(nxt==last) continue;
        dfs(nxt,now,-flag);
    }
}
vector<int> v1,v2;
int main(){
    IOS;
    int n,l,r;
    CAS {
        cin>>n;
        Rep(i,1,n) vec[i].clear();
        Rep(i,1,n-1){
            cin>>l>>r;
            vec[l].push_back(r);
            vec[r].push_back(l);
        }
        dfs(1,-1,1);
        int cnt = 0,flag = 1;
        Rep(i,1,n) if(vis[i]==1) cnt++;
        if(cnt > n/2){
            cnt = n-cnt;
            flag = -1;
        }
        v1.clear(); v2.clear();
        rep(i,0,20){
            if((cnt>>i)&1){
                Rep(j,1<<i,(1<<(i+1))-1) v1.push_back(j);
            }
        }
        int now = 0;
        Rep(i,1,n){
            if(now<v1.size() && v1[now]==i){
                now++;
            }else{
                v2.push_back(i);
            }
        }
        int now1 = 0,now2 = 0;
        Rep(i,1,n){
            if(vis[i]==flag){
                ans[i] = v1[now1++];
            }else{
                ans[i] = v2[now2++];
            }
        }
        Rep(i,1,n) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
