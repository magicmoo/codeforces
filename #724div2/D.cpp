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
const int maxn = 2e5+5;
int a[maxn];
set<int> s;
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        bool flag = 1;
        s.clear();
        s.insert(a[1]);
        Rep(i,2,n){
            s.insert(a[i]);
            auto index = s.lower_bound(a[i-1]);
            if(a[i]>a[i-1]){
                index++;
                if(*index != a[i]){
                    flag = 0;
                    break;
                }
            }else if(a[i]<a[i-1]){
                index--;
                if(*index != a[i]){
                    flag = 0;
                    break;
                }
            }
        }
        YON;
    }
    return 0;
}
