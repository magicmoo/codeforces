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
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,k;
    CAS {
        cin>>n>>k;
        if(k > (n-1)/2) cout<<"-1\n";
        else if(k == 0){
            for(int i=1;i<=n;i++) cout<<i<<" ";
            cout<<"\n";
        }else{
            int i;
            k--; cout<<"1 3 2 ";
            for(i=4;i<=n&&k>0;i+=2,k--){
                cout<<i+1<<" "<<i<<" ";
            }
            for(;i<=n;i++) cout<<i<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
