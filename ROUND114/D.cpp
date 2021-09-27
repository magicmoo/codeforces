#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS int CASE; \
            cin>>CASE; \
            Rep(__,1,CASE)
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 2e18;
const int maxn = 15;
const int maxv = 1e5+5;
vector<int> v[maxn];
vector<int> tmp;
int now[maxn],n,m,c[maxn],num,sum;
vector<int> ans;
set<vector<int>> s,used;
priority_queue<pair<int,vector<int>>> q;
int main(){
    IOS;
    cin>>n;
    Rep(i,1,n) v[i].push_back(-1);
    Rep(i,1,n){
        cin>>c[i];
        now[i] = c[i];
        int cc = c[i];
        while(cc--){
            cin>>num;
            v[i].push_back(num);
        }
    }
    cin>>m;
    Rep(i,1,m){
        tmp.clear();
        Rep(j,1,n){
            cin>>num;
            tmp.push_back(num);
        }
        s.insert(tmp);
    }
    tmp.clear();
    Rep(i,1,n) tmp.push_back(c[i]);
    Rep(i,1,n) sum += v[i][c[i]];
    q.push({sum,tmp});
    while(!q.empty()){
        tmp = q.top().second;
        sum = q.top().first;
        q.pop();
        if(!s.count(tmp)){
            break;
        }
        rep(i,0,n){
            if(tmp[i]<=1) continue;
            sum -= v[i+1][tmp[i]];
            tmp[i]--;
            sum += v[i+1][tmp[i]];
            if(!used.count(tmp)) 
                q.push({sum,tmp});
            used.insert(tmp);
            sum -= v[i+1][tmp[i]];
            tmp[i]++;
            sum += v[i+1][tmp[i]];
        }
    }
    rep(i,0,n) cout<<tmp[i]<<" ";
    cout<<"\n";
    return 0;
}