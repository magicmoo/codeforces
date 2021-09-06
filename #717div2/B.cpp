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
const int maxn = 2e3+5;
int a[maxn],n;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int cnt = 0;
        for(int i=1;i<=n;i++){
            cnt ^= a[i];
        }
        if(cnt == 0){
            cout<<"YES\n";
            continue;
        }
        int cnt2 = 0,i;
        bool flag = false;
        for(i=1;i<n;i++){
            cnt2 ^= a[i];
            if(cnt2 == cnt){
                flag = true;
                break;
            }
        }
        if(!flag){ 
            cout<<"NO\n";
            continue;
        }
        i++; cnt2 = 0; flag = false;
        for(;i<n;i++){
            cnt2 ^= a[i];
            if(cnt2 == cnt){
                flag = true;
                break;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
