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

int b[maxn],book[2*maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        deque<int> q;
        memset(book,0,sizeof(book));
        cin>>n;
        int num1 = 0,num2 = 0;
        for(int i=0;i<n;i++){ cin>>b[i]; book[b[i]] = 1; }
        for(int i=1;i<=2*n;i++)
            if(!book[i]) q.push_back(i);
        for(int i=0;i<n;i++){
            int num = q.front();
            if(num > b[i]){
                q.pop_back();
                num1++;
            }else{
                q.pop_front();
            }
        }
        for(int i=1;i<=2*n;i++)
            if(!book[i]) q.push_back(i);
        for(int i=n-1;i>=0;i--){
            int num = q.back();
            if(num < b[i]){
                q.pop_front();
            }else{
                q.pop_back();
                num2++;
            }
        }
        cout<<abs(num2-num1)+1<<"\n";
    }
    return 0;
}
