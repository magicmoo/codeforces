#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
int a[maxn],book[maxn],arr[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    CAS {
        cin>>n;
        for(int i=1;i<=n;i++) book[i] = arr[i] = 0;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(!book[a[i]]){
                arr[i] = a[i];
                ans++;
                book[a[i]] = i;
            }
        }
        multiset<int> s1,s2;
        for(int i=1;i<=n;i++){
            if(book[i]) continue;
            if(arr[i]) s1.insert(i);
            else s2.insert(i);
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++){
            if(arr[i]) continue;
            bool flag = false;
            for(auto j=s2.begin();j!=s2.end();j++){
                if(*j != i){
                    flag = true;
                    arr[i] = *j;
                    s2.erase(j);
                    break;
                }
            }
            if(!flag && !s1.empty()){
                arr[i] = *(s1.begin());
                s1.erase(s1.begin());
            }else if(!flag){
                arr[i] = a[i];
                arr[book[a[i]]] = i;
            }
        }
        for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
