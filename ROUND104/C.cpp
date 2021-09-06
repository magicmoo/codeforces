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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        bool flag = true;
        cin>>n;
        if(n%2 == 1){
            for(int i=0;i<n;i++){
                flag = true;
                for(int j=i+1;j<n;j++){
                    if(flag) cout<<"1 ";
                    else cout<<"-1 ";
                    flag = !flag;
                }
            }
            cout<<"\n";
        }else{
            flag = true;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(i%2==0 && j==i+1){ cout<<"0 "; continue; }
                    else if(flag) cout<<"1 ";
                    else cout<<"-1 ";
                    flag = !flag;
                }
                flag = !flag;
            }
            cout<<"\n";
        }
    }
    return 0;
}
