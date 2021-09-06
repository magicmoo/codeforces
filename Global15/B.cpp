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
const int maxn = 5e5+5;
int a[maxn][10];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n)
            Rep(j,1,5) cin>>a[i][j];
        bool flag = true;
        int now = 1;
        Rep(i,2,n){
            int temp = 0;
            Rep(j,1,5){
                if(a[now][j] < a[i][j]) temp++;
            }
            if(temp < 3) now = i;
        }
        Rep(i,1,n){
            if(i == now) continue;
            int temp = 0;
            Rep(j,1,5){
                if(a[now][j] < a[i][j]) temp++;
            }
            if(temp < 3){
                flag = false;
                break;
            }
        }
        if(flag) cout<<now<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
