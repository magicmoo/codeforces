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
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        bool flag = false;
        for(int i=0;i<2020&&i<=n/2020;i++){
            if((n-i)%2020 == 0){
                cout<<"YES\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout<<"NO\n";
    }
    return 0;
}
