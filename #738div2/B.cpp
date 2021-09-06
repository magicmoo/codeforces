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

int main(){
    IOS;
    int n;
    string str;
    CAS {
        cin>>n;
        cin>>str;
        int first = -1;
        rep(i,0,n){
            if(str[i] != '?'){
                first = i; break;
            }
        }
        if(first == -1){
            str[0] = 'B';
            rep(i,1,n){
                if(str[i-1] == 'R') str[i] = 'B';
                else str[i] = 'R';
            }
            cout<<str<<"\n";
        }else{
            rep(i,first+1,n){
                if(str[i] != '?') continue;
                if(str[i-1] == 'R') str[i] = 'B';
                else str[i] = 'R';
            }
            Dep(i,first-1,0){
                if(str[i] != '?') continue;
                if(str[i+1] == 'R') str[i] = 'B';
                else str[i] = 'R';
            }
            cout<<str<<"\n";
        }
    }
    return 0;
}
