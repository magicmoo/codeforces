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
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 3e5+5;
int a[maxn],book[55];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,q,num;    
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=50;i++) book[i] = 0;
    for(int i=1;i<=n;i++){
        if(book[a[i]] == 0) book[a[i]] = i;
    }
    while(q--){
        cin>>num;
        cout<<book[num]<<" ";
        for(int i=1;i<=50;i++){
            if(book[i] < book[num]) book[i]++;
        }
        book[num] = 1;
        }
    return 0;
}
