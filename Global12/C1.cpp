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
const int maxn = 305;
char a[maxn][maxn];
int n;
bool check(int num,int cnt){
    int ans = 0;
    Rep(i,1,n){
        for(int j=(i+num)%3;j<=n;j+=3){
            if(a[i][j] == 'X') ans++;
        }
    }
    return ans <= cnt/3;
}
int main(){
    IOS;
    CAS {
        cin>>n;
        Rep(i,1,n) Rep(j,1,n) cin>>a[i][j];
        int cnt = 0;
        Rep(i,1,n){
            Rep(j,1,n){
                if(a[i][j] == 'X') cnt++;
            }
        }
        int ans = 0;
        rep(i,0,3){
            if(check(i,cnt)){
                ans = i;
                break;
            }
        }
        Rep(i,1,n){
            for(int j=(i+ans)%3;j<=n;j+=3){
                if(a[i][j] == 'X') a[i][j] = 'O';
            }
        }
        Rep(i,1,n){
            Rep(j,1,n){
                cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
