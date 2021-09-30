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
struct Node{
    int sum,id;
    bool operator<(const Node& n1)const{
        return sum < n1.sum;
    }
}a[maxn];
bool cmp(Node n1,Node n2){
    return n1.sum > n2.sum;
}
vector<pair<int,int>> ans;
priority_queue<Node> q;
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        ans.clear();
        while(!q.empty()) q.pop();
        Rep(i,1,n) cin>>a[i].sum;
        Rep(i,1,n) a[i].id = i;
        Rep(i,1,n){
            if(a[i].sum == 0) continue;
            q.push(a[i]);
        }
        while(q.size()>=2){
            int sum1 = q.top().sum,id1 = q.top().id;
            q.pop();
            int sum2 = q.top().sum,id2 = q.top().id;
            q.pop();
            ans.push_back({id1,id2});
            if(sum1-1>0) q.push({sum1-1,id1});
            if(sum2-1>0) q.push({sum2-1,id2});
        }
        cout<<ans.size()<<"\n";
        rep(i,0,ans.size()){
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }
    }
    return 0;
}
