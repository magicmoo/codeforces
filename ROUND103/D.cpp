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
const int maxn = 3e5+5;

int l[maxn],r[maxn];
char road[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        memset(road,0,sizeof(road));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for(int i=1;i<=n;i++) cin>>road[i];
        r[n] = l[0] = 0;
        if(road[n] == 'R') r[n-1] = 1;
        if(road[1] == 'L') l[1] = 1;
        for(int i=n-2;i>=0;i--){
            if(road[i+1] == 'R'){
                if(r[i+1] == 0){
                    r[i] = 2+r[i+2];
                }else{
                    r[i] = 1;
                }
            }else{
                r[i] = 0;
            }
        }
        for(int i=2;i<=n;i++){
            if(road[i] == 'L'){
                if(l[i-1] == 0){
                    l[i] = 2+l[i-2];
                }else{
                    l[i] = 1;
                }
            }else{
                l[i] = 0;
            }
        }
        for(int i=0;i<=n;i++){
            // cout<<l[i]<<" ";
            // cout<<r[i]; cout<<"\n";
            cout<<l[i]+r[i]+1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
