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
const int MAXN = 3e5+5;

ll a1[MAXN],a2[MAXN],a3[MAXN];
ll n1,n2,n3;
// ll solve(ll a[],ll b[],ll c[],ll n1,ll n2,ll n3){
//     ll ans = 0;
//     ll tans = -a[0];
//     ll na,nb,nc;
//     na = 1; nb = nc = 0;
//     for(ll i=0;i<n1-1;i++){
//         if(nb<n2 && a[na]<b[nb]){
//             tans -= a[na]; na++;
//         }else if(nb<n2){
//             tans -= b[nb]; nb++;
//         }else{
//             tans -= a[na]; na++;
//         }
//     }
//     for(ll i=na;i<n1;i++) tans += a[i];
//     for(ll i=nb;i<n2;i++) tans += b[i];
//     for(ll i=nc;i<n3;i++) tans += c[i];
//     ans = max(tans,ans);
//     tans = -a[0]; na = 1; nb = nc = 0;
//     for(ll i=0;i<n1-1;i++){
//         if(nc<n3 && a[na]<c[nc]){
//             tans -= a[na]; na++;
//         }else if(nc<n3){
//             tans -= c[nc]; nc++;
//         }else{
//             tans -= a[na]; na++;
//         }
//     }
//     for(ll i=na;i<n1;i++) tans += a[i];
//     for(ll i=nb;i<n2;i++) tans += b[i];
//     for(ll i=nc;i<n3;i++) tans += c[i];
//     ans = max(tans,ans);
//     tans = -a[0]; na = 1; nb = nc = 0;
//     for(ll i=0;i<n1-1;i++){
//         if(nb<n2-1 && nc<n3-1){
//             if(a[na]<b[nb] && a[na]<c[nc]){
//                 tans -= a[na]; na++;
//             }else if(b[nb]<a[na] && b[nb]<c[nc]){
//                 tans -= b[nb]; nb++;
//             }else{
//                 tans -= c[nc]; nc++;
//             }
//         }else if(nb<n2-1){
//             if(a[na]<b[nb]){
//                 tans -= a[na]; na++;
//             }else{
//                 tans -= b[nb]; nb++;
//             }
//         }else if(nc<n3-1){
//             if(a[na]<c[nc]){
//                 tans -= a[na]; na++;
//             }else{
//                 tans -= c[nc]; nc++;
//             }
//         }else{
//             tans -= a[na]; na++;
//         }
//     }
//     ans = max(tans,ans);
//     return ans;
// }

ll solve(ll a[],ll b[],ll c[],ll n1,ll n2,ll n3){
    ll ans = 0;
    for(ll i=0;i<n1;i++) ans += a[i];
    for(ll i=0;i<n2;i++) ans += b[i];
    for(ll i=0;i<n3;i++) ans += c[i];
    if(n1 == 1)
        return ans-a[0]-a[0];
    ll num = 0;
    for(ll i=1;i<n1;i++) num += a[i];
    if(num<=b[0] && num<=c[0])
        return ans-(a[0]+num)*2;
    return ans-(a[0]+min(b[0],c[0]))*2;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    ll sum1,sum2,sum3;
    cin>>n1>>n2>>n3;
    sum1 = sum2 = sum3 = 0;
    for(ll i=0;i<n1;i++){ cin>>a1[i]; }
    for(ll i=0;i<n2;i++){ cin>>a2[i]; }
    for(ll i=0;i<n3;i++){ cin>>a3[i]; }
    sort(a1,a1+n1); sort(a2,a2+n2); sort(a3,a3+n3);
    // cout<<solve(a1,a2,a3,n1,n2,n3)<<"\n";
    // cout<<solve(a2,a1,a3,n2,n1,n3)<<"\n";
    // cout<<solve(a3,a1,a2,n3,n1,n2)<<"\n";
    cout<<max(solve(a1,a2,a3,n1,n2,n3),max(solve(a2,a1,a3,n2,n1,n3),solve(a3,a1,a2,n3,n1,n2)))<<"\n";
    return 0;
}
