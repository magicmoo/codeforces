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
const int maxn = 2e5+5;
int a[maxn];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    CAS {
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
        if(a[1]==0 || a[n]==0){
            cout<<"NO\n";
            continue;
        }
        int cnt = 0;
        for(int i=2;i<n;i++){
            if(a[i] == 0) cnt++;
        }
        if(cnt%2 == 1){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        cout<<'(';
        bool flag1,flag2;
        flag1 = flag2 = false;
        for(int i=2;i<n;i++){
            if(!flag1 && a[i]==1){
                cout<<"(";
                flag1 = true;
            }else if(flag1 && a[i]==1){
                cout<<")";
                flag1 = false;
            }else if(a[i]==0){
                if(flag2){
                    cout<<"(";
                    flag2 = false;
                }else{
                    cout<<")";
                    flag2 = true;
                }
            }
        }
        cout<<")\n";
        cout<<'(';
        flag1 = flag2 = false;
        for(int i=2;i<n;i++){
            if(!flag1 && a[i]==1){
                cout<<"(";
                flag1 = true;
            }else if(flag1 && a[i]==1){
                cout<<")";
                flag1 = false;
            }else if(a[i]==0){
                if(flag2){
                    cout<<")";
                    flag2 = false;
                }else{
                    cout<<"(";
                    flag2 = true;
                }
            }
        }
        cout<<")\n";
    }
    return 0;
}
