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
const int maxn = 2e5+5;
int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        int temp = 1,Max = 0;
        for(int i=2;i<=n;i++){
            if(a[i] == a[i-1]) temp++;
            else{
                Max = max(temp,Max);
                temp = 1;
            }
        }
        Max = max(temp,Max);
        if(n%2 == 0) cout<<max(0,2*Max-n)<<"\n";
        else cout<<max(1,2*Max-n)<<"\n";
    }
    return 0;
}
