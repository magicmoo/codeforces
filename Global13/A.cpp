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
int num1,num0;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,q,num,t,x;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(1 == a[i]) num1++;
        else num0++;
    }
    while(q--){
        cin>>t>>x;
        if(t == 1){
            if(a[x] == 1){
                num1--; num0++;
                a[x] = 0;
            }else{
                num1++; num0--;
                a[x] = 1;
            }
        }else{
            if(x <= num1){
                cout<<"1\n";
            }else cout<<"0\n";
        }
    }
    return 0;
}
