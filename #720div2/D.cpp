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
const int maxn = 1e5+5;
vector<pair<int,int>> del,add;
vector<pair<int,int>> edges;
set<int> s[maxn];
int d[maxn],temp[maxn],book[maxn],book2[maxn];
int dfs(int last,int now){
    if(d[now] == 1) return now;
    for(auto i=s[now].begin();i!=s[now].end();i++){
        if(*i != last) return dfs(now,*i);
    }
    return -1;
}
void dele(int l,int r){
    del.push_back(make_pair(l,r));
    d[l]--; d[r]--;
    s[l].erase(r); s[r].erase(l);
}
void dfs2(int last,int now){
    set<int> se = s[now];
    for(auto i=se.begin();i!=se.end();i++){
        int nex = *i;
        if(nex != last) dfs2(now,nex);
    }
    if(last == -1){
        int cnt = 0;
        for(auto i=s[now].begin();i!=s[now].end()&&d[now]>2;i++){
            temp[cnt++] = *i;
            d[now]--;
        }
        for(int i=0;i<cnt;i++){
            dele(now,temp[i]);
            d[now]++;
        }
    }else if(d[now] > 2){
        dele(last,now);
        int cnt = 0;
        for(auto i=s[now].begin();i!=s[now].end()&&d[now]>2;i++){
            temp[cnt++] = *i;
            d[now]--;
        }
        for(int i=0;i<cnt;i++){
            dele(now,temp[i]);
            d[now]++;
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,l,r,ans;
    CAS {
        ans = 0;
        cin>>n;
        edges.clear();
        for(int i=1;i<=n;i++){
            d[i] = book[i] = book2[i] = 0;
            s[i].clear();
        }
        del.clear(); add.clear();
        for(int i=0;i<n-1;i++){
            cin>>l>>r;
            d[l]++; d[r]++;
            edges.push_back(make_pair(l,r));
            s[l].insert(r); s[r].insert(l);
        }
        
        dfs2(-1,1);

        vector<pair<int,int>> v;
        for(int i=1;i<=n;i++){
            if(book[i]) continue;
            if(d[i] == 0) v.push_back(make_pair(i,i));
            else if(d[i] == 1){
                int nex = dfs(i,*(s[i].begin()));
                book[nex] = 1;
                v.push_back(make_pair(i,nex));
            }
        }
        for(int i=1;i<v.size();i++){
            add.push_back(make_pair(v[i-1].second,v[i].first));
        }
        cout<<del.size()<<"\n";
        for(int i=0;i<del.size();i++){
            cout<<del[i].first<<" "<<del[i].second<<" "<<add[i].first<<" "<<add[i].second<<"\n";
        }
    }
    return 0;
}
