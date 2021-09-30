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
const int maxn = 105;
struct Node{
    int num,id;
}a[maxn];
bool cmp(Node n1,Node n2){
    return n1.num < n2.num;
}
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i].num;
        Rep(i,1,n) a[i].id = i;
        sort(a+1,a+1+n,cmp);
        if(a[1].num != a[2].num){
            cout<<a[1].id<<"\n";
        }else{
            cout<<a[n].id<<"\n";
        }
    }
    return 0;
}
