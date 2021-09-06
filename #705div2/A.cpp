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
    cin>>T; while(T--){
        cin>>n>>k;
        if(n > k) cout<<(n-k)+(k/2)<<"\n";
        else cout<<(k/2)<<"\n";
        for(int i=n;i>k;i--) cout<<i<<" ";
        if(k%2 == 0){
            for(int i=k-1;i>=k/2;i--){
                cout<<i<<" ";
            }
        }else{
            for(int i=k-1;i>k/2;i--){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
