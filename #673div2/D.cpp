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
const int maxn = 1e4+5;
int a[maxn];
struct Node{
    int a,b,c;
};
vector<Node> ans;
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        ans.clear();
        Rep(i,1,n) cin>>a[i];
        int sum = 0;
        Rep(i,1,n) sum += a[i];
        if(sum%n != 0){
            cout<<"-1\n";
            continue;
        }
        sum /= n;
        bool flag = 1;
        Rep(i,2,n){
            if(a[i]%i==0){
                ans.push_back({i,1,a[i]/i});
            }else{
                ans.push_back({1,i,i-a[i]%i});
                ans.push_back({i,1,a[i]/i+1});
            }
        }
        Rep(i,2,n){
            ans.push_back({1,i,sum});
        }
        cout<<ans.size()<<"\n";
        rep(i,0,ans.size()){
            cout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].c<<"\n";
        }
    }
    return 0;
}
