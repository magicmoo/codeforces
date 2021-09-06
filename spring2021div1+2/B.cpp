#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
int n,a[maxn];
void out1(int a,int b){
    cout<<"1 "<<a<<" "<<b<<"\n";
}
void out2(int a,int b){
    cout<<"2 "<<a<<" "<<b<<"\n";
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<3*n<<"\n";
        for(int i=1;i<=n;i+=2){
            out1(i,i+1);
            out1(i,i+1);
            out2(i,i+1);
            out1(i,i+1);
            out1(i,i+1);
            out2(i,i+1);
        }
    }
    return 0;
}
