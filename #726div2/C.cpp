#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS int CASE; \
            cin>>CASE; \
            while(CASE--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
int a[maxn];
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        if(n == 2){
            cout<<a[1]<<" "<<a[2]<<"\n";
            continue;
        }
        int Min = INF,index = -1;
        for(int i=2;i<=n;i++){
            if(a[i]-a[i-1] < Min){
                Min = a[i]-a[i-1];
                index = i;
            }
        }
        for(int i=index;i<=n;i++) cout<<a[i]<<" ";
        for(int i=1;i<index;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}