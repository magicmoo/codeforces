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
const int maxn = 105;
int ans[maxn][maxn];
int a[3] = {0,2,1};
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,num;
    cin>>n;
    int nowa1 = 1,nowb1 = 1,temp1 = 2;
    int nowa2 = 1,nowb2 = 2,temp2 = 1;

    for(int i=1;i<=n*n;i++){
        cin>>num;
        if(nowa1<=n && nowa2<=n){
            if(num == 1){
                cout<<"2 "<<nowa2<<" "<<nowb2<<"\n";
                nowb2 += 2;
                if(nowb2 > n){
                    nowa2++;
                    nowb2 = temp2;
                    temp2 = a[temp2];
                }
            }else if(num==2 || num==3){
                cout<<"1 "<<nowa1<<" "<<nowb1<<"\n";
                nowb1 += 2;
                if(nowb1 > n){
                    nowa1++;
                    nowb1 = temp1;
                    temp1 = a[temp1];
                }
            }
        }else if(nowa1 <= n){
            if(num == 1){
                cout<<"3 "<<nowa1<<" "<<nowb1<<"\n";
                nowb1 += 2;
                if(nowb1 > n){
                    nowa1++;
                    nowb1 = temp1;
                    temp1 = a[temp1];
                }
            }else if(num==2 || num==3){
                cout<<"1 "<<nowa1<<" "<<nowb1<<"\n";
                nowb1 += 2;
                if(nowb1 > n){
                    nowa1++;
                    nowb1 = temp1;
                    temp1 = a[temp1];
                }
            }
        }else if(nowa2 <= n){
            if(num == 2){
                cout<<"3 "<<nowa2<<" "<<nowb2<<"\n";
                nowb2 += 2;
                if(nowb2 > n){
                    nowa2++;
                    nowb2 = temp2;
                    temp2 = a[temp2];
                }
            }else{
                cout<<"2 "<<nowa2<<" "<<nowb2<<"\n";
                nowb2 += 2;
                if(nowb2 > n){
                    nowa2++;
                    nowb2 = temp2;
                    temp2 = a[temp2];
                }
            }
        }
        cout<<"\n";
        cout.flush();
    }
    return 0;
}
