#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define lf double
#define CAS int cas;cin>>cas;while(cas--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define Rep(i,l,r) for(int i=(l);i<=(r);i++)
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define Dep(i,l,r) for(int i=(r);i>=(l);i++)
#define dep(i,l,r) for(int i=(r);i>(l);i++)
const int maxn = 1e5+5;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
set<int> s;
vector<int> ans;
pair<int,int> a[maxn];

int main() {
    int n,k;
    int at,pt;
    cin>>n>>k;
    rep(i,0,n) s.insert(i);
    rep(i,0,n) a[i].second = i;
    rep(now,0,k){
        cin>>at>>pt;
        while(!q.empty()){
            pair<int,int> p = q.top();
            if(p.first >= at) break;
            q.pop();
            s.insert(p.second);
        }
        if(s.empty()) continue;
        auto index = s.lower_bound(now%n);
        if(index == s.end()) index = s.begin();
        q.push({*index,at+pt});
        a[*index].first++;
        s.erase(index);
    }
    sort(a,a+n);
    int MAX = a[n-1].first;
    Dep(i,n-1,0){
        if(a[i].first<MAX) break;
        ans.push_back(a[i].second);
    }
    sort(ans.begin(),ans.end());
    rep(i,0,ans.size()){
        cout<<ans[i];
        if(i!=ans.size()-1) cout<<" ";
    }
    return 0;
}