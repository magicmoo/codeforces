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
const int maxn = 1005;

int r[maxn],b[maxn];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        for(int i=0;i<n;i++) scanf("%1d",&r[i]);
        for(int i=0;i<n;i++) scanf("%1d",&b[i]);
        int num = 0;
        // sort(r,r+n); sort(b,b+n);
        for(int i=0;i<n;i++){
            if(r[i] > b[i]) num++;
            else if(r[i] < b[i]) num--;
        }
        if(num > 0) cout<<"RED\n";
        else if(num == 0) cout<<"EQUAL\n";
        else cout<<"BLUE\n";
    }
    return 0;
}
