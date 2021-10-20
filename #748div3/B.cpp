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
bool check(string str,string s){
    bool flag = 0;
    rep(i,0,str.size()){
        if(!flag && str[i]==s[0]) flag = 1;
        else if(flag && str[i]==s[1]) return 1;
    }
    return 0;
}
int solve(string str,string s){
    int cnt = 0;
    bool flag = 0;
    Dep(i,str.size()-1,0){
        if(!flag && str[i]==s[1]) flag = 1;
        else if(flag && str[i]==s[0]) return cnt;
        else cnt++;
    }
    return cnt;
}
int main(){
    IOS;
    string str;
    CAS {
        cin>>str;
        int ans = INF;
        if(check(str,"00")){
            ans = min(ans,solve(str,"00"));
        }
        if(check(str,"25")) ans = min(ans,solve(str,"25"));
        if(check(str,"50")) ans = min(ans,solve(str,"50"));
        if(check(str,"75")) ans = min(ans,solve(str,"75"));
        cout<<ans<<"\n";
    }
    return 0;
}
