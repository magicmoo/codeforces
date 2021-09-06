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

int main(){
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    int a[100005];
    ll book[100005];
    int T;
    cin>>T;
    int n,x;
    while(T--){
        ll ans = 0;
        cin>>n>>x;
        for(int i=0;i<n;i++){ cin>>a[i]; book[i] = 1; }
        for(int i=0;;i++){
            if(i==n) i = 0;
            if(a[i]%x==0){
                ans += book[i]*a[i];
                //cout<<a[i]<<" "<<book[i]<<endl;
                a[i] = a[i]/x;
                book[i] *= x;
            }else break;
        }
        for(int i=0;i<n;i++) ans += book[i]*a[i];
        cout<<ans<<"\n";
    }
    return 0;
}
