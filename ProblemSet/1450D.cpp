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
const int maxn = 3e5+5;
int a[maxn],book[maxn];   
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        int ans = 0,l=1,r=n,mid = n-1;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) book[i] = 0;
        for(int i=1;i<=n;i++) book[a[i]]++;
        bool flag = true;
        for(int i=1;i<=n;i++) if(book[i] != 1) flag = false;
        if(flag) cout<<"1"; else cout<<"0";
        for(int i=1;i<=n;i++){
            if(book[i] > 1){
                mid = i;
                break;
            }else if(book[i] == 0){
                mid = i-1;
                break;
            }
        }
        for(int i=1;i<=mid;i++){
            int L = a[l],R = a[r];
            if(L == i){
                ans++;
                l++;
            }else if(R == i){
                ans++;
                r--;
            }else break;
        }
        for(int i=n-1;i>min(ans+1,mid);i--) cout<<"0";
        for(int i=min(ans+1,mid);i>0;i--) cout<<"1";
        cout<<"\n";
    }
    return 0;
}
