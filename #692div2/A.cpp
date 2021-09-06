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
    int T,n,sum;
    string str;
    cin>>T; while(T--){
        cin>>n;
        cin>>str;
        sum = 0;
        for(int i=0;i<n;i++){
            if(str[i] == ')'){
                sum++;
            }else sum = 0;
        }
        if(sum > n-sum) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
