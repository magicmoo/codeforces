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
    int T;
    cin>>T;
    int n,x;
    ll Min,Max;
    ll num[100005];
    while(T--){
        cin>>n>>x;
        for(int i=0;i<n;i++) cin>>num[i];
        Min = Max = 0;
        for(int i=0;i<n;i++){
            Min += num[i];
            Max += (num[i]+x-1)/x;
        }
        Min = (Min+x-1)/x;
        cout<<Min<<" "<<Max<<"\n";
    }

    return 0;
}
