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
const int maxn = 1e5+5;

int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%1d",&a[i]);
        int last = 0;
        for(int i=0;i<n;i++){
            if(a[i]==1 && last!=2){
                cout<<1;
                last = 2;
            }else if(a[i]==1 && last==2){
                cout<<0;
                last = 1;
            }else if(a[i]==0 && last==1){
                cout<<0;
                last = 0;
            }else if(a[i]==0 && last!=1){
                cout<<1;
                last = 1;
            }
        }
        cout<<"\n";
    }
    return 0;
}
