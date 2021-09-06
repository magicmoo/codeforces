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

int Num1[maxn],Num2[maxn],Max1[maxn],Max2[maxn],Min1[maxn],Min2[maxn];
char Map[maxn];
int T,n,m,l,r;
void init(){
    for(int i=1;i<=n;i++){
            if(Map[i] == '+') Num1[i] = Num1[i-1]+1;
            else Num1[i] = Num1[i-1]-1;
        }
        for(int i=n;i>0;i--){
            if(Map[i] == '+') Num2[i] = Num2[i+1]+1;
            else Num2[i] = Num2[i+1]-1;
        }
        int Max = 0,Min = 0;
        for(int i=1;i<=n;i++){
            Max = max(Max,Num1[i]);
            Min = min(Min,Num1[i]);
            Max1[i] = Max;
            Min1[i] = Min;
        }
        Max = 0,Min = INF;
        for(int i=n;i>0;i--){
            if(Map[i] == '+'){
                Max2[i] = max(Max2[i+1]+1,0);
                Min2[i] = min(Min2[i+1]+1,0);
            }else{
                Max2[i] = max(Max2[i+1]-1,0);
                Min2[i] = min(Min2[i+1]-1,0);
            }
        }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    cin>>T;
    while(T--){
        memset(Max2,0,sizeof(Max2)); 
        memset(Min2,0,sizeof(Min2)); 
        memset(Num2,0,sizeof(Num2));
        cin>>n>>m;
        char ch;
        for(int i=1;i<=n;i++) cin>>Map[i];
        init();
        // for(int i=1;i<=n;i++) cout<<Max2[i]<<" "<<Min2[i]<<"\n";
        while(m--){
            cin>>l>>r;
            int Max = max(Max1[l-1],Max2[r+1]+Num1[l-1]);
            int Min = min(Min1[l-1],Min2[r+1]+Num1[l-1]);
            cout<<Max-Min+1<<"\n";
        }
        // cout<<"\n";
    }
    return 0;
}
