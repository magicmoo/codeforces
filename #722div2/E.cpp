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
const int maxn = 3e5+5;
int st[maxn],ft[maxn];
vector<int> vec1[maxn],vec2[maxn];
int len,ans;
set<PII> s;
void dfs1(int now,int last){
    st[now] = ++len;
    for(int nxt : vec2[now]){
        if(nxt == last) continue;
        dfs1(nxt,now);
    }
    ft[now] = len;
}
void dfs2(int now,int last){
    bool flag = 1;
    PII tmp = {st[now],now};
    PII tmp1 = {0,0};
    auto index = s.lower_bound(tmp);
    if(index!=s.end() && ft[(*index).second]<=ft[now]){
        flag = 0;
    }
    if(flag && index!=s.begin()){
        index--;
        if(ft[(*index).second]>=ft[now]){
            tmp1 = *index;
            s.erase(index);
        }
    }
    if(flag) s.insert(tmp);
    ans = max(ans,(int)s.size());
    for(int nxt : vec1[now]){
        if(nxt == last) continue;
        dfs2(nxt,now);
    }
    if(flag){
        s.erase(tmp);
        if(tmp1 != make_pair(0,0)) s.insert(tmp1);
    }
}
int main(){
    IOS;
    int n,num;
    CAS {
        cin>>n;
        len = 0;
        ans = 0;
        Rep(i,1,n){
            vec1[i].clear();
            vec2[i].clear();
        }
        Rep(i,2,n){
            cin>>num;
            vec1[i].push_back(num);
            vec1[num].push_back(i);
        }
        Rep(i,2,n){
            cin>>num;
            vec2[i].push_back(num);
            vec2[num].push_back(i);
        }
        dfs1(1,-1);
        dfs2(1,-1);
        cout<<ans<<"\n";
    }
    return 0;
}
