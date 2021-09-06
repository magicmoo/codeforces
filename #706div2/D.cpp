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

int a[maxn],pre[maxn],post[maxn];
int q[maxn],h[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,maxq = 0,maxh = 0,numq = 0,numh = 0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        if(a[i] > a[i-1]) pre[i] = pre[i-1]+1;
        else pre[i] = 0;
        if(pre[i] > maxq){
            numq = 0;
            q[numq++] = i;
            maxq = pre[i];
        }else if(pre[i] == maxq){
            q[numq++] = i;
        }
    }

    for(int i=n-1;i>0;i--){
        if(a[i] > a[i+1]) post[i] = post[i+1]+1;
        else post[i] = 0;
        if(post[i] > maxh){
            numh = 0;
            h[numh++] = i;
            maxh = post[i];
        }else if(post[i] == maxh){
            h[numh++] = i;
        }
    }

    if(maxq > maxh){
        if(numq > 1) cout<<"0\n";
        else if(numq%2 || post[q[0]]==0) cout<<"0\n";
        else cout<<"1\n";
    }else if(maxq < maxh){
        if(numh > 1) cout<<"0\n";
        else if(numh%2 || pre[h[0]]==0) cout<<"0\n";
        else cout<<"1\n";
    }else{
        if(numq>1 || numh>1) cout<<"0\n";
        else if(q[0]==h[0] && maxq%2==0) cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;
}
