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
const int maxn = 1e5+5;

int a[maxn];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,m,r;
    double p;
    cin>>T; while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        int num = n;
        for(int i=n;i>0;i--){
            if(a[i] == i) num--;
            else break;
        }
        double ans = 1;
        bool flag = false;
        while(m--){
            cin>>r>>p;
            if(r >= num){
                flag = true;
                ans *= (1-p);
            }
        }
        ans = 1-ans;
        if(num == 0) cout<<"1.000000\n";
        else if(flag) printf("%.6lf\n",ans);
        else cout<<"0.000000\n";
    }
    return 0;
}
