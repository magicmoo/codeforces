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
const int maxn = 4e5+5;
int ans[maxn],dis[maxn];
vector<int> vec[maxn];
struct Node{
    int now,dis,len;
    bool operator>(const Node& n1)const{
        if(dis == n1.dis) return len > n1.len;
        return dis>n1.dis;
    }
};
priority_queue<Node,vector<Node>,greater<Node>> q;
int main(){
    IOS;
    int n,k,l,r;
    CAS {
        cin>>n>>k;
        Rep(i,1,n) vec[i].clear(), ans[i] = 0;
        Rep(i,1,n-1){
            cin>>l>>r;
            vec[l].push_back(r);
            vec[r].push_back(l);
        }
        Rep(i,1,n) dis[i] = vec[i].size();
        Rep(i,1,n){
            q.push({i,dis[i],1});
        }
        while(!q.empty()){
            Node p = q.top();
            q.pop();
            int now = p.now;
            if(p.dis != 1) continue;
            if(ans[now]) continue;
            rep(i,0,vec[now].size()){
                int nxt = vec[now][i];
                if(ans[nxt]) continue;
                q.push({nxt,--dis[nxt],p.len+1});
            }
            ans[now] = p.len;
        }
        int cnt = 0;
        Rep(i,1,n){
            if(ans[i]>k) cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
