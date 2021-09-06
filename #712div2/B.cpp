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
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 3e5+5;
int a[maxn],b[maxn],book[2];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    CAS {
        cin>>n;
        book[1] = book[0] = 0;
        for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%1d",&b[i]);
        int mid = 0;
        for(int i=n;i>=1;i--){
            if(a[i] != b[i]){
                mid = i;
                break;
            }
        }
        bool flag = true;
        for(int i=mid;i>0;i--){
            book[b[i]]++;
        }
        if(book[0] != book[1]){
            cout<<"NO\n";
            continue;
        }
        book[1] = book[0] = 0;
        for(int i=mid;i>1;i--){
            book[a[i]]++;
            if(abs(a[i]-b[i]) != abs(a[i-1]-b[i-1]) && book[0]!=book[1]){
                flag = false;
                break;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
