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
const int maxn = 1e2+5;

int num[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);   
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    int T,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<2*k-n;i++) cout<<i<<" ";
        for(int i=k;i>=2*k-n;i--) cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
