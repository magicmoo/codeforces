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
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    int T,w,h,n;
    cin>>T;
    while(T--){
        cin>>w>>h>>n;
        int ans = 1;
        while(ans>0&&w%2 == 0){w/=2; ans*=2;}
        while(ans>0&&h%2 == 0){h/=2; ans*=2;}
        if(ans>=n || ans<=0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
