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
    string str;
    CAS {
        cin>>str;
        int cnt = 0;
        rep(i,1,str.size()){
            if(str[i] != str[i-1]){
                if(str[i]=='a') cnt++;
                else cnt--;
            }
        }
        if(cnt==0) cout<<str<<"\n";
        else{
            if(str[0]=='a') str[0] = 'b';
            else str[0] = 'a';
            cout<<str<<"\n";
        }
    }
    return 0;
}
