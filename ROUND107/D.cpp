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
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    string str = "";
    for(int i=0;i<k;i++){
        str += 'a'+i;
        for(int j=i+1;j<k;j++){
            str += 'a'+i;
            str += 'a'+j;
        }
    }
    for(int i=0;i<n;i++){
        cout<<str[i%str.length()];
    }
    cout<<"\n";
    return 0;
}
