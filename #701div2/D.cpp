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
const int maxn = 500+5;
int GCD(int a, int b) {
	return b ? GCD(b, a % b) : a;
}
int LCM(int a, int b) {
	return a * b / GCD(a, b);
}
int map[maxn][maxn],ans[maxn][maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++)
            cin>>map[i][j];
    int x = 1;
    for(int i=1;i<=16;i++) x = LCM(x,i);
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++)
            ans[i][j] = x;
    for(int i=1;i<=n;i++){
        for(int j=1+i%2;j<=m;j+=2){
            ans[i][j] += map[i][j]*map[i][j]*map[i][j]*map[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
