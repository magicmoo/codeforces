#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
#define Rep(i,x,y) for(auto i=(x);i<=(y);i++)
#define rep(i,x,y) for(auto i=(x);i<(y);i++)
#define Dep(i,x,y) for(auto i=(x);i>=(y);i--)
#define dep(i,x,y) for(auto i=(x);i>(y);i--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 105;
int a[maxn*maxn],book[maxn];
int mp[maxn][maxn];
pair<int,int> ans[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    Rep(i,1,n*k) cin>>a[i];
    Rep(i,1,n*k){
        mp[a[i]][++mp[a[i]][0]] = i;
    }
    if(k == 2){
        Rep(i,1,n){
            cout<<mp[i][1]<<" "<<mp[i][2]<<"\n";
        }
    }else{
        int m = (n+k-2)/(k-1),cnt = 0;
        Rep(t,2,k){
            vector<pair<int,int>> v;
            Rep(i,1,n) if(!book[i]) v.push_back({mp[i][t],i});
            sort(v.begin(),v.end());
            rep(i,0,min(m,(int)v.size())){
                cnt++;
                int index = v[i].second;
                ans[index] = {mp[index][t-1],mp[index][t]};
                book[index] = 1;
            }
            if(cnt == n) break;
        }
        Rep(i,1,n) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    
    return 0;
}
