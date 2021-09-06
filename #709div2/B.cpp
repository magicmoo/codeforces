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
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        bool flag = true;
        for(int i=1;i<=n;i++) cin>>a[i];
        int c = -1,m = 0;
        for(int i=2;i<=n;i++){
            if(a[i] >= a[i-1]){
                if(c!=-1 && a[i]-a[i-1]!=c){
                    flag = false;
                    break;
                }else c = a[i]-a[i-1];
            }
        }
        if(c!=-1){
            for(int i=2;i<=n;i++){
                if(a[i] < a[i-1]){
                    if(m!=0 && a[i-1]+c-a[i]!=m){
                        flag = false;
                        break;
                    }else m = a[i-1]+c-a[i];
                }
            }
        }else{
            c = a[1]-a[2];
            for(int i=2;i<=n;i++){
                if(a[i-1]-a[i] != c){
                    flag = false;
                    break;
                }
            }
        }
        if(m != 0){
            for(int i=1;i<=n;i++) if(a[i] >= m) flag = false;
        }
        if(!flag) cout<<"-1\n";
        else if(m==0) cout<<"0\n";
        else cout<<m<<" "<<c<<"\n";
    }
    return 0;
}
