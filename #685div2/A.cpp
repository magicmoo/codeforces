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
const int maxn = 1e5+5;  //注意修改maxn数值
int vis[maxn],prime[maxn],tol;
// void liner_shai(){
//     memset(vis,0,sizeof(vis));
//     for(int i=2;i<maxn;i++){
//         if(!vis[i])
//             prime[tol++] = i;
//         for(int j=0;j<tol&&i*prime[j]<maxn;j++){
//             vis[i*prime[j]] = 1;
//             if(i%prime[j] == 0)
//                 break;
//         }
//     }
// }
// bool isPrime(int x){
//     if(x==1) return 1;
//     if(x==2) return 1;
//     for(int i=2;i*i<=x;i++)
//         if(x%i==0) return 0;
//     return 1;
// }
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        if(n==1) cout<<"0\n";
        else if(n==2) cout<<"1\n";
        else if(n==3) cout<<"2\n";
        else if(n%2 == 0){
            cout<<"2\n";
        }else cout<<"3\n";
    }
    return 0;
}
