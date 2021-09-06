#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 3e5+5;
struct Node{
    int a,i;
    char dir;
}nodes[maxn];
vector<Node> v1,v2;
int ans[maxn],n,m;
bool cmp(Node a,Node b){
    return a.a < b.a;
}
void solve(vector<Node>& v){
    stack<int> s;
    for(int i=0;i<v.size();i++){
        if(v[i].dir == 'R') s.push(i);
        else if(!s.empty()){
            int last = s.top(); s.pop();
            ans[v[last].i] = ans[v[i].i] = (v[i].a-v[last].a)/2;
        }
    }
    int last = -1;
    for(int i=0;i<v.size();i++){
        if(ans[v[i].i]!=-1 || v[i].dir=='R') continue;
        if(last==-1) last = i;
        else{
            ans[v[last].i] = ans[v[i].i] = v[last].a+(v[i].a-v[last].a)/2;
            last = -1;
        }
    }
    int nex = -1;
    for(int i=v.size()-1;i>=0;i--){
        if(ans[v[i].i]!=-1 || v[i].dir=='L') continue;
        if(nex==-1) nex = i;
        else{
            ans[v[nex].i] = ans[v[i].i] = (m-v[nex].a)+(v[nex].a-v[i].a)/2;
            nex = -1;
        }
    }
    if(nex!=-1 && last!=-1){
        ans[v[nex].i] = ans[v[last].i] = (m+v[last].a+m-v[nex].a)/2;
    }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        cin>>n>>m;
        for(int i=1;i<=n;i++) ans[i] = -1;
        v1.clear(); v2.clear();
        for(int i=1;i<=n;i++){
            cin>>nodes[i].a;
            nodes[i].i = i;
        }
        for(int i=1;i<=n;i++) cin>>nodes[i].dir;
        sort(nodes+1,nodes+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(nodes[i].a%2 == 0) v1.push_back(nodes[i]);
            else v2.push_back(nodes[i]); 
        }
        solve(v1);
        solve(v2);
        for(int i=1;i<=n;i++){
            cout<<ans[i];
            if(i != n) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
