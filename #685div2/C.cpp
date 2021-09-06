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

int book[30],req[30];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,k;
    string a,b;
    cin>>T; while(T--){
        cin>>n>>k;
        cin>>a>>b;
        bool flag = true;
        memset(book,0,sizeof(book));
        memset(req,0,sizeof(req));
        for(int i=0;i<n;i++) book[a[i]-'a']++;
        for(int i=0;i<n;i++) req[b[i]-'a']++;
        for(int i=0;i<26;i++){
            if(book[i] >= req[i]) book[i] -= req[i];
            else if((req[i]-book[i])%k == 0){
                req[i] -= book[i];
                book[i] = 0;
                for(int j=0;j<i&&req[i];j++){
                   while(book[j] && book[j]%k == 0 && req[i]){
                       book[j] -= k;
                       req[i] -= k;
                   }
                }
                if(req[i]){
                    flag = false;
                    break;
                }
            }else{
                flag = false;
                break;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
