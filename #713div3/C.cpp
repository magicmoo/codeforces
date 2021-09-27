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
char str[maxn];
int main(){
    // IOS;
    int a,b;
    CAS {
        cin>>a>>b;
        scanf("%s",str+1);
        int n = strlen(str+1);
        bool flag = 1;
        int sum = 0;
        Rep(i,1,n/2){
            if(str[i]=='?'){
                if(str[n-i+1]=='?') sum++;
                else if(str[n-i+1]=='1'){
                    b-=2;
                    str[i] = '1';
                }else{
                    a-=2;
                    str[i] = '0';
                }
            }else if(str[n-i+1]=='?'){
                if(str[i]=='?') sum++;
                else if(str[i]=='1'){
                    b-=2;
                    str[n-i+1] = '1';
                }else{
                    a-=2;
                    str[n-i+1] = '0';
                }
            }else if(str[i]==str[n-i+1]){
                if(str[i] == '0') a-=2;
                else b-=2;
            }else{
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout<<"-1\n";
            continue;
        }
        Rep(i,1,n/2){
            if(str[i]!='?') continue;
            if(a>=2){
                str[i] = str[n-i+1] = '0';
                a -= 2;
            }else if(b>=2){
                str[i] = str[n-i+1] = '1';
                b -= 2;
            }else{
                flag = 0;
                break;
            }
        }
        if(n%2==1){
            if(str[n/2+1] == '?'){
                if(a) str[n/2+1] = '0',a--;
                else if(b) str[n/2+1] = '1',b--;
                else flag = 0;
            }else if(str[n/2+1] == '0') a--;
            else b--;
        }
        if(a!=0 || b!=0 || !flag) cout<<"-1\n";
        else{
            Rep(i,1,n) cout<<str[i];
            cout<<"\n";
        }
    }
    return 0;
}
