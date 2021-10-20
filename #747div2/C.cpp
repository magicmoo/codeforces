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
const int maxn = 3e5+5;
char str[maxn];
int book[maxn];
int main(){
    // IOS;
    int n; char ch;
    CAS {
        scanf("%d %c",&n,&ch);
        getchar();
        scanf("%s",str+1);
        Rep(i,1,n) book[i] = 0;
        bool flag = 1;
        Rep(i,1,n){
            if(str[i] != ch) flag = 0;
        }
        if(flag){
            cout<<"0\n";
            continue;
        }
        if(str[n]==ch){
            cout<<"1\n"<<n<<"\n";
            continue;
        }
        Rep(i,1,n){
            if(str[i]==ch) continue;
            for(int j=1;j*j<=i;j++){
                if(i%j==0) book[i/j] = book[j] = 1;
            }
        }
        int ans = 0;
        Rep(i,1,n){
            if(book[i]==0){
                ans = i;
                break;
            }
        }
        if(ans) cout<<"1\n"<<ans<<"\n";
        else{
            cout<<"2\n";
            cout<<n-1<<" "<<n<<"\n";
        }
    }
    return 0;
}
