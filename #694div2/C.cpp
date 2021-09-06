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

//bool cmp(int a,int b){ return a>b; } 
int main(){
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    int T;
    cin>>T;
    int n,m;
    int K[300005],C[300005];
    int now,nowi;
    ll ans;
    //int book[300005];
    while(T--){
        ans = 0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&K[i]);
        for(int i=1;i<=m;i++) scanf("%d",&C[i]);
        sort(K+1,K+n+1);
        now = nowi = 1;
        //memset(book,0,sizeof(book));
        for(int i=1;i<=n;i++){
            if(now <= m && K[i] > now && C[now] <= C[K[nowi]]){
                ans += C[now];
                now++;
            }else{
                ans += C[K[nowi]];
                nowi++;
            }
            //cout<<now<<" "<<nowi<<" "<<ans<<endl;
        }
        cout<<ans<<"\n";
    }
    return 0;
}