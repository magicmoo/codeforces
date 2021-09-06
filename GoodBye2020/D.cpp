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
// #include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;

ll w[maxn],book[maxn];
ll map[maxn];
bool cmp(ll a,ll b) {return a>b;}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,n,num1,num2;
    cin>>T;
    while(T--){
        memset(map,0,sizeof(map));
        cin>>n;
        ll sum = 0;
        for(ll i=1;i<=n;i++){ cin>>w[i]; sum+=w[i]; }
        for(ll i=1;i<=n-1;i++){
            cin>>num1>>num2;
            map[num1]++; map[num2]++;
        }
        ll len = 0;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<map[i];j++){
                book[len++] = w[i];
            }
        }
        sort(book,book+len,cmp);
        for(ll i=0;i<n-1;i++){
            cout<<sum<<" ";
            sum += book[i];
        }
        cout<<"\n";
    }
    return 0;
}
