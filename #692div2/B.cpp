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

ll gcd(ll a,ll b){ return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b){ return a/gcd(a,b)*b; }

bool check(ll num){
    ll temp = num;
    while(temp){
        if( temp%10 && num % (temp%10) != 0) return false;
        temp /= 10;
    }
    return true;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n;
    cin>>T; while(T--){
        cin>>n;
        while(1){
            if(check(n)) break;
            n++;
        }
        cout<<n<<"\n";
    }
    return 0;
}
