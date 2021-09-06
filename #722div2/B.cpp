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
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    CAS {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        int min = -1;
        for(int i=1;i<=n;i++){
            if(a[i] > 0){
                min = a[i];
                break;
            }
        }
        if(min == -1){
            cout<<n<<"\n";
        }else{
            int ans = 1,last = -INF,temp = 0;
            for(int i=1;i<=n;i++){
                if(a[i] > 0) break;
                temp++;
                if(last == -INF){
                    last = a[i];
                    ans++;
                }else if(a[i]-last >= min){
                    last = a[i];
                    ans++;
                }
            }
            cout<<max(ans,temp)<<"\n";
        }
    }
    return 0;
}
