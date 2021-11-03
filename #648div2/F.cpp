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
const int maxn = 505;
int a[maxn],b[maxn];
map<pair<int,int>,int> s;
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n) cin>>b[i];
        if(n%2==1 && a[n/2+1]!=b[n/2+1]){
            cout<<"NO\n";
            continue;
        }
        s.clear();
        Rep(i,1,n/2){
            s[{a[i],a[n-i+1]}]++;
        }
        bool flag = 1;
        Rep(i,1,n/2){
            if(s[{b[i],b[n-i+1]}]){
                s[{b[i],b[n-i+1]}]--;
            }else if(s[{b[n-i+1],b[i]}]){
                s[{b[n-i+1],b[i]}]--;
            }else{
                flag = 0;
                break;
            }
        }
        YON;
    }
    return 0;
}
