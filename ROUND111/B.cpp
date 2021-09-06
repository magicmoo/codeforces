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
const int maxn = 105;
int arr[maxn];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        int n,a,b;
        cin>>n>>a>>b;
        for(int i=1;i<=n;i++) scanf("%1d",&arr[i]);
        if(b >= 0) cout<<n*(a+b)<<"\n";
        else{
            int num = 0;
            for(int i=2;i<=n;i++){
                if(arr[i]!=arr[i-1]) num++;
            }
            cout<<n*a+(num+3)/2*b<<"\n";
        }
    }
    return 0;
}
