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
int book[maxn];
int main(){
    IOS;
    int a,b;
    CAS {
        cin>>a>>b;
        int n = a+b;
        Rep(i,0,n) book[i] = 0;
        if(n%2 == 0){
            Rep(i,max(0,a-n/2),min(a,n/2)){
                int tmp = (n/2-i)+(a-i);
                book[tmp] = 1;
            }
        }else{
            Rep(i,max(0,a-n/2),min(a,n/2+1)){
                int tmp = (n/2+1-i)+(a-i);
                book[tmp] = 1;
            }
            Rep(i,max(0,a-n/2-1),min(a,n/2)){
                int tmp = (n/2-i)+(a-i);
                book[tmp] = 1;
            }
        }
        int cnt = 0;
        Rep(i,0,n) if(book[i]) cnt++;
        cout<<cnt<<"\n";
        Rep(i,0,n){
            if(book[i]) cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
