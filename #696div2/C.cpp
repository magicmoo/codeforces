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
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2e3+5;

int a[maxn],b[maxn];
int ans[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n;
    cin>>T;
    while(T--){
        bool flag = false;
        memset(ans,0,sizeof(ans));
        cin>>n;
        for(int i=1;i<=2*n;i++) cin>>b[i];
        if(n == 1){
            cout<<"YES\n"<<b[1]+b[2]<<"\n";
            cout<<b[1]<<" "<<b[2]<<"\n";
            continue;
        }
        sort(b+1,b+2*n+1);
        for(int k=1;k<2*n;k++){
            for(int i=1;i<=2*n;i++) a[i] = b[i];
            ans[0] = a[2*n]; ans[1] = a[k]; a[k] = -1;
            int now = 2,x = a[2*n];
            for(int i=2*n-1;i>0;i--){
                flag = false;
                if(a[i] == -1) continue;
                for(int j=1;j<i;j++){
                    if(a[j] == -1) continue;
                    if(a[i]+a[j] == x){
                        flag = true;
                        x = a[i];
                        ans[now++] = a[i]; ans[now++] = a[j];
                        a[j] = -1;
                        break;
                    }else if(a[i]+a[j] > x) break;
                }
                if(now == 2*n){
                    break;
                }else if(!flag){
                    break;
                }
            }
            if(flag) break;
        }
        if(flag){
            cout<<"YES\n";
            cout<<ans[0]+ans[1]<<"\n";
            for(int i=0;i<2*n;i+=2){
                cout<<ans[i]<<" "<<ans[i+1]<<"\n";
            }
        }else cout<<"NO\n";
    }
    return 0;
}
