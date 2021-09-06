#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+5;
int a[maxn];
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        if(a[1] != 0){
            cout<<n+1<<" ";
            Rep(i,1,n) cout<<i<<" ";
            cout<<"\n";
        }else if(a[n] == 0){
            Rep(i,1,n) cout<<i<<" ";
            cout<<n+1<<"\n";
        }else{
            int mid = -1;
            Rep(i,2,n){
                if(a[i-1]==0 && a[i]!=0){
                    mid = i;
                    break;
                }
            }
            if(mid == -1) cout<<"-1\n";
            else{
                rep(i,1,mid) cout<<i<<" ";
                cout<<n+1<<" ";
                Rep(i,mid,n) cout<<i<<" ";
                cout<<"\n";
            }
        }
    }
    return 0;
}
