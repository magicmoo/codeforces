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
const int maxn = 100+5;

int num[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    int T,n,d;
    cin>>T;
    while(T--){
        cin>>n>>d;
        for(int i=0;i<n;i++) cin>>num[i];
        sort(num,num+n);
        if(num[n-1]<=d || num[0]+num[1]<=d) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
