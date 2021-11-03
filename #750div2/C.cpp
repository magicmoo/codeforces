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
char str[maxn];
int solve(int l,int r,char ch){
    int ans = 1;
    while(l<r){
        if(str[l]!=str[r]){
            if(str[l]==ch){
                l++; ans++;
            }else if(str[r]==ch){
                r--; ans++;
            }else return INF;
        }else{
            l++; r--;
        }
    }
    return ans;
}
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>str[i];
        int l=0,r=0;
        Rep(i,1,n){
            if(str[i]!=str[n-i+1]){
                l = i; r = n-i+1; break;
            }
        }
        if(l==0 && r==0) cout<<"0\n";
        else{
            int ans = min(solve(l+1,r,str[l]),solve(l,r-1,str[r]));
            if(ans==INF) cout<<"-1\n";
            else cout<<ans<<"\n";
        }
    }
    return 0;
}
