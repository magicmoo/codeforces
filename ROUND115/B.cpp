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
const int maxn = 1e3+5;
int a[maxn][5],n;
bool solve(int x,int y){
    int cnt1 = 0,cnt2 = 0,cnt3 = 0;
    Rep(i,1,n){
        if(a[i][x]==1){
            cnt1++;
            if(a[i][y]==1) cnt2++;
        }else if(a[i][y]==1) cnt3++;
    }
    if(cnt1 < n/2) return 0;
    cnt3 += min(cnt1-n/2,cnt2);
    if(cnt3 < n/2) return 0;
    return 1;
}
int main(){
    IOS;
    CAS {
        cin>>n;
        Rep(i,1,n){
            Rep(j,1,5){
                cin>>a[i][j];
            }
        }
        bool flag = 0;
        Rep(i,1,5){
            Rep(j,i+1,5){
                if(solve(i,j)) flag = 1;
            }
        }
        YON;
    }
    return 0;
}
