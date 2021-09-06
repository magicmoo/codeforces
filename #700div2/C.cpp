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

void check(int l,int r,int nl,int nr){
    int num[20] = {0};
    num[0] = nl; num[r-l] = nr;
    for(int i=l+1;i<r;i++){
        cout<<"? "<<i<<"\n";
        cin>>num[i-l];
        fflush(stdout);
    }
    for(int i=1;i<r-l;i++){
        if(num[i] < min(num[i-1],num[i+1])){
            cout<<"! "<<l+i<<"\n";
            break;
        }
    }
}
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int n;
    cin>>n;
    int l = 0, r = n+1;
    int mid = (l+r)>>1;
    int num[5] = {0};
    num[0] = num[4] = INF;
    cout<<"? "<<mid<<"\n";
    cin>>num[2];
    fflush(stdout);
    while(1){
        if(r-l <= 10){
            check(l,r,num[0],num[4]);
            break;
        }
        mid = (l+r)>>1;
        int mid1 = (l+mid)>>1;
        cout<<"? "<<mid1<<"\n";
        cin>>num[1];
        fflush(stdout);
        int mid2 = (mid+r)>>1;
        cout<<"? "<<mid2<<"\n";
        cin>>num[3];
        fflush(stdout);
        if(num[1] < min(num[0],num[2])){
            r = mid;
            num[4] = num[2];
            num[2] = num[1];
        }else if(num[2] < min(num[1],num[3])){
            l = mid1; r = mid2;
            num[0] = num[1];
            num[4] = num[3];
        }else if(num[3] < min(num[2],num[4])){
            l = mid;
            num[0] = num[2];
            num[2] = num[3];
        }
    }
    return 0;
}
