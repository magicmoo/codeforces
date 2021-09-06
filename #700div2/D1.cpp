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
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

int a[maxn];
// int b[maxn],c[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int A,B,ans;
    A = B = ans = 0;
    for(int i=0;i<n;i++){
        if(A == B){
            if(A != a[i]) ans++;
            A = a[i];
        }else if(A == a[i]){
            B = a[i];
            ans++;
        }else if(B == a[i]){
            A = a[i];
            ans++;
        }else{
            if(a[i+1] == A){
                A = a[i];
                ans++;
            }else{
                B = a[i];
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
