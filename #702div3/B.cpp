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
const int maxn = 3e4+5;

int a[3];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,num,ans;
    cin>>T; while(T--){
        cin>>n;
        a[0] = a[1] = a[2] = 0;
        ans = 0;
        for(int i=0;i<n;i++){
            cin>>num;
            a[num%3]++;
        }
        num = n/3;
        if(a[0] > num){
            if(a[1] > num){
                ans = 2*(a[0]-num)+(a[1]-num);
            }else{
                if(a[2] > num){
                    ans = (a[0]-num)+2*(a[2]-num);
                }else{
                    ans = (num-a[1])+2*(num-a[2]);
                }
            }
        }else{
            if(a[1] > num){
                if(a[2] > num){
                    ans = 2*(a[1]-num)+(a[2]-num);
                }else{
                    ans = 2*(num-a[0])+(num-a[2]);
                }
            }else{
                ans = (num-a[0])+2*(num-a[1]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
