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
const int maxn = 1e5+5;
int a[maxn];
struct Node{
    int a,b,c;
};
vector<Node> ans;
int main(){
    IOS;
    int n;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    if(n%2){
        cout<<"YES\n";
        for(int i=3;i<=n;i+=2){
            ans.push_back({i-2,i-1,i});
        }
        for(int i=2;i<=n-2;i+=2){
            ans.push_back({i-1,i,n});
        }
        cout<<ans.size()<<"\n";
        rep(i,0,ans.size()){
            cout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].c<<"\n";
        }
    }else{
        int tmp = 0;
        Rep(i,1,n) tmp ^= a[i];
        if(tmp){
            cout<<"NO\n";
            return 0;
        }
        cout<<"YES\n";
        for(int i=3;i<=n-1;i+=2) ans.push_back({i-2,i-1,i});
        for(int i=2;i<=n-3;i+=2){
            ans.push_back({i-1,i,n});
        }
        cout<<ans.size()<<"\n";
        rep(i,0,ans.size()){
            cout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].c<<"\n";
        }
    } 
    return 0;
}
