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

int main(){
    IOS;
    int n,m,k;
    CAS {
        cin>>n>>m>>k;
        if(n%2==0 && m%2==0){
            if(k%2==0) cout<<"YES\n";
            else cout<<"NO\n";
        }else if(n%2==1){
            int last = n*m/2-k;
            if(last%2==0){
                if(k >= m/2) cout<<"YES\n";
                else cout<<"NO\n";
            }else cout<<"NO\n";
        }else{
            int last = n*m/2-k;
            if(k%2==0){
                if(last >= n/2) cout<<"YES\n";
                else cout<<"NO\n";
            }else cout<<"NO\n";
        }
    }
    return 0;
}
