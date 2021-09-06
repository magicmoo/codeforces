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
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,k;
    string s;
    cin>>T; while(T--){
        cin>>n>>k;
        cin>>s;
        if(n <= k*2){
            cout<<"NO\n";
            continue;
        }else{
            bool flag = true;
            for(int i=0;i<k;i++){
                if(s[i] != s[n-i-1]){
                    flag = false;
                }
            }
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
