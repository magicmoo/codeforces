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

int h[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n,k;
    cin>>T;
    while(T--){
        memset(h,0,sizeof(h));
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>h[i];
        bool flag = true;
        while(flag){
            int i;
            for(i=1;i<=n;i++){
                if(i == n){
                    cout<<"-1\n";
                    flag = false;
                    break;
                }else if(h[i] < h[i+1]){
                    h[i]++;
                    k--;
                    break;
                }
            }
            if(!flag) break;
            if(k==0){
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}
