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
const int maxn = 55;
struct Node{
    int num,id;
}a[maxn];
int book[maxn];
bool cmp(Node n1,Node n2){
    return n1.num < n2.num;
}
struct Node1{
    int l,r,d;
};
vector<Node1> ans;
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i].num;
        Rep(i,1,n) a[i].id = i;
        sort(a+1,a+1+n,cmp);
        Rep(i,1,n) book[i] = a[i].id;
        ans.clear();
        Rep(i,1,n){
            if(book[i]==i) continue;
            int d = book[i]-i;
            ans.push_back({i,n,d});
            Rep(j,i,n){
                if(book[j]-d >= i) book[j] -= d;
                else book[j] = n+(book[j]-d-i+1);
            }
        }
        cout<<ans.size()<<"\n";
        rep(i,0,ans.size()){
            cout<<ans[i].l<<" "<<ans[i].r<<" "<<ans[i].d<<"\n";
        }
    }
    return 0;
}
