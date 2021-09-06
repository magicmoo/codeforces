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
const int maxn = 2e5+5;

struct node{
    int r,c;
}a[maxn];

bool cmp(node n1,node n2){ return n1.c<n2.c; }
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n,m;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        cin>>n>>m;
        for(int i=0;i<m;i++) cin>>a[i].r>>a[i].c;
        if(m%2 == 1){
            cout<<"NO\n"; continue;
        }
        sort(a,a+m,cmp);
        bool flag = true;
        for(int i=0;i<m;i+=2){
            if(a[i+1].c==a[i+2].c){
                flag = false; break;
            }
            else if(a[i].r!=a[i+1].r && (a[i+1].c-a[i].c)%2 == 1){
                flag = false; break;
            }
            else if(a[i].r==a[i+1].r && (a[i+1].c-a[i].c)%2 == 0){
                flag = false; break;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
