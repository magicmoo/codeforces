#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
ll cal(ll num){
    return num*(num+1)/2;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    string str;
    CAS {
        cin>>str;
        ll now=0,temp=0,ans = 0;
        char last;
        while(now<str.length() && str[now]=='?'){ now++; }
        if(now<str.length()){ last = str[now]; now++; }
        for(ll i=now;i<str.length();i++){
            now++;
            if(str[i]=='?'){
                temp++;
            }
            else if(str[i]=='1'){
                if(temp%2==1 && last=='0'){
                    ans += cal(now-1);
                    now = temp+1;
                    ans -= cal(now-1);
                }else if(temp%2==0 && last=='1'){
                    ans += cal(now-1);
                    now = temp+1;
                    ans -= cal(now-1);
                }
                last = '1';
                temp = 0;
            }else if(str[i]=='0'){
                if(temp%2==1 && last=='1'){
                    ans += cal(now-1);
                    now = temp+1;
                    ans -= cal(now-1);
                }else if(temp%2==0 && last=='0'){
                    ans += cal(now-1);
                    now = temp+1;
                    ans -= cal(now-1);
                }
                last = '0';
                temp = 0;
            }
        }
        ans += cal(now);
        cout<<ans<<"\n";
    }
    return 0;
}
