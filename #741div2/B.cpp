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
int book[10];
int main(){
    IOS;
    string s;
    int k;
    CAS {
        cin>>k>>s;
        bool flag = 0;
        rep(i,0,k){
            if(s[i]=='1' || s[i]=='4' || s[i]=='6' || s[i]=='8' || s[i]=='9'){
                flag = 1;
                cout<<"1\n"<<s[i]<<"\n";
                break;
            }
        }
        if(flag) continue;
        rep(i,1,k){
            if(s[i]=='2' || s[i]=='5'){
                flag = 1;
                cout<<"2\n"<<s[i-1]<<s[i]<<"\n";
                break;
            }
        }
        if(flag) continue;
        Rep(i,1,9) book[i] = 0;
        rep(i,0,k){
            if(book[s[i]-'0']){
                flag = 1;
                cout<<"2\n"<<s[i]<<s[i]<<"\n";
                break;
            }
            book[s[i]-'0'] = 1;
        }
        if(flag) continue;
        if(s[0]=='2' || s[0]=='5'){
            rep(i,1,k){
                if(s[i] == '7'){
                    flag = 1;
                    cout<<"2\n"<<s[0]<<7<<"\n";
                    break;
                }
            }
            continue;
        }
    }
    return 0;
}
