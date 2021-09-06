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
const ll INF = 0x3f3f3f3f;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,h,c,t;
    cin>>T; while(T--){
        cin>>h>>c>>t;
        ll n = max(1.0*(t-h)/(h+c-2*t),0.0);
        double tem1,tem2,tem3;
        tem1 = abs(1.0*((n+1)*h+n*c)/(2*n+1)-t);
        tem2 = abs(1.0*((n+2)*h+(n+1)*c)/(2*n+3)-t);
        tem3 = abs(1.0*(h+c)/2-t);
        if(tem1<=tem2){
            if(tem1<tem3) cout<<(2*n+1)<<"\n";
            else cout<<"2\n";
        }else{
            if(tem2<tem3) cout<<(2*n+3)<<"\n";
            else cout<<"2\n";
        }
    }
    return 0;
}

 