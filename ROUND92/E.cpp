#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
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
int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}
int main(){
    IOS;
    int m,d,w;
    CAS {
        cin>>m>>d>>w;
        int num = min(m,d);
        int g = __gcd(w,d-1);
        if(g==1){
            cout<<(num-1)*num/2<<"\n";
            continue
        }
    }
    return 0;
}
