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

int a[maxn],book[maxn];
void put(int l,int r){
    for(int i=l;i<=r;i++) cout<<a[i]<<" ";
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        memset(book,0,sizeof(book));
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        int max = 0,maxi = -1;
        int last = n,now = n;
        for(int i=n-1;i>=0;i--){
            book[a[i]] = 1;
            if(a[i] == now){
                put(i,last-1);
                last = i;
                for(int i=now;i>=0;i--) if(!book[i]){ now = i; break;}
            }
        }
        cout<<"\n";
    }
    return 0;
}
