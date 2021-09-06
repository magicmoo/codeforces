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
const int maxn = 1e4+5;
int ans[maxn];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    CAS {
        memset(ans,0,sizeof(ans));
        cin>>n;
        int nn = -1,tmp;
        bool flag = false;
        for(int i=1;i<n;i+=2){
            cout<<"? 1 "<<i<<" "<<i+1<<" "<<n-1<<"\n";
            cout.flush();
            cin>>tmp;
            if(tmp == n){
                nn = i+1;
                ans[nn] = n;
                break;
            }else if(tmp == n-1){
                cout<<"? 1 "<<i+1<<" "<<i<<" "<<n-1<<"\n";
                cout.flush();
                cin>>tmp;
                if(tmp == n){
                    nn = i;
                    ans[nn] = n;
                    break;
                }else{
                    flag = true;
                    cout<<"? 1 "<<i<<" "<<i+1<<" "<<n-2<<"\n";
                    cout.flush();
                    cin>>tmp;
                    if(tmp == n-2){
                        nn = i;
                        ans[nn] = n-1;
                        break;
                    }else{
                        nn = i+1;
                        ans[nn] = n-1;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(i == nn) continue;
            cout<<"? 2 "<<i<<" "<<nn<<" "<<1<<"\n";
            cout.flush();
            cin>>tmp;
            ans[i] = tmp;
        }
        cout<<"! ";
        for(int i=1;i<=n;i++){
            if(ans[i]==n-1 && nn!=i && flag) cout<<n<<" ";
            else cout<<ans[i]<<" ";
        }
        cout<<"\n";
        cout.flush();
    }
    return 0;
}
