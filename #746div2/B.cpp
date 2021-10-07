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
int b[maxn];
int main(){
    IOS;
    int n,x;
    CAS {
        cin>>n>>x;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n) b[i] = a[i];
        sort(b+1,b+1+n);
        bool flag = 1;
        Rep(i,1,n){
            if(i-1<x && n-i<x){
                if(a[i] != b[i]){
                    flag = 0;
                    break;
                }
            }
        }
        YON;
    }
    return 0;
}
