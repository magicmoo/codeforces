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
    int n;
    string str;
    CAS {
        cin>>str;
        int a=0,b=0,c=0;
        rep(i,0,str.size()){
            if(str[i]=='A') a++;
            if(str[i]=='B') b++;
            if(str[i]=='C') c++;
        }
        if(b==a+c) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
