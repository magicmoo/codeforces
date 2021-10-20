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
const int maxn = 105;
int a[maxn];
bool isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 0;
    }
    return 1;
}
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        int sum = 0,index = 0;
        Rep(i,1,n){
            sum+=a[i];
        }
        Rep(i,1,n){
            if(a[i]%2==1) index = i;
        }
        if(!isPrime(sum)){
            cout<<n<<"\n";
            Rep(i,1,n) cout<<i<<" ";
            cout<<"\n";
        }else{
            cout<<n-1<<"\n";
            Rep(i,1,n){
                if(i == index) continue;
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
