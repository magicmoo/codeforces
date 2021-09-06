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
const int maxn = 3e5+5;
int a[maxn],sum[maxn],mp[maxn],book[maxn];
int fa[maxn];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unit(int u,int v){
    int xx = find(u);
    int yy = find(v);
    if(xx != yy){
        fa[xx] = yy;
    }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,m;
    CAS {
        cin>>n>>m;
        Rep(i,1,n) cin>>a[i];
        Rep(i,0,n) sum[i] = 0;
        Rep(i,1,n){
            sum[(i-a[i]+n)%n]++;
            mp[a[i]] = i;
        }
        vector<int> ans,anss;
        Rep(i,0,n-1){
            if(n-sum[i] <= m*2) ans.push_back(i);
        }
        rep(i,0,ans.size()){
            Rep(j,1,n) fa[j] = j,book[j] = 0;
            int last = m,sub = ans[i];
            Rep(j,1,n){
                if(last < 0) break;
                if(book[j]) continue;
                int now = mp[j];
                now = (j+sub)%n;
                if(now == 0) now = n;
                while(last>=0 && find(j) != find(a[now])){
                    unit(j,a[now]);
                    int num = a[now];
                    book[num] == 1;
                    last--;
                    now = (num+sub)%n;
                    if(now == 0) now = n;
                }
            }
            if(last>=0) anss.push_back(ans[i]);
        }
        cout<<anss.size()<<" ";
        rep(i,0,anss.size()) cout<<anss[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
