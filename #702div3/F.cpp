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
const int maxn = 2e5+5;

int a[maxn],book[maxn];
int sum1[maxn],sum2[maxn],sum3[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        memset(book,0,sizeof(book));
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
        memset(sum3,0,sizeof(sum3));
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        int temp = 1;
        int ans = INF;
        int N;
        sort(a,a+n);
        for(int i=1;i<n;i++){
            if(a[i] == a[i-1]){
                temp++;
            }else{
                book[temp]++;
                N = max(temp,N);
                temp = 1;
            }
        }
        book[temp]++;
        N = max(temp,N);
        for(int i=1;i<=N;i++){
            sum1[i] = sum1[i-1]+book[i-1]*(i-1);
        }
        for(int i=N;i>0;i--){
            sum2[i] = sum2[i+1]+book[i+1];
        }
        for(int i=N;i>0;i--){
            sum3[i] = sum3[i+1]+book[i+1]*(i+1);
        }
        for(int i=1;i<=N;i++){
            int temp = sum1[i]+(sum3[i]-sum2[i]*i);
            ans = min(ans,temp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
