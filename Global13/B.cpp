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
const int maxn = 105;
int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,u,v;
    cin>>T; while(T--){
        cin>>n>>u>>v;
        for(int i=1;i<=n;i++) cin>>a[i];
        int flag = true,flag1 = true;
        for(int i=2;i<=n;i++){
            if(a[i] != a[i-1]){
                flag1 = false;
            }
            if(abs(a[i]-a[i-1]) > 1){
                flag = false;
                break;
            }
        }
        if(flag1){
            cout<<v+(u<v?u:v)<<"\n";
        }else if(flag){
            cout<<(u<v?u:v)<<"\n";
        }else cout<<"0\n";
    }
    return 0;
}
