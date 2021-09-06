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
    int T,n,k;
    cin>>T; while(T--){
        cin>>n>>k;
        if(k == 3){
            if(n%2==1) cout<<"1 "<<(n-1)/2<<" "<<(n-1)/2<<"\n";
            else{
                if(n%4==0){
                    cout<<n/4<<" "<<n/4<<" "<<n/2<<"\n";
                }else{
                    cout<<"2 "<<(n-2)/2<<" "<<(n-2)/2<<"\n";
                }
            }
            continue;
        }
        if(n%k == 0){
            for(int i=0;i<k;i++) cout<<n/k<<" ";
            cout<<"\n";
            continue;
        }
        int cnt = k/2;
        int pre = n/(cnt*2)*2;
        int last = n-pre*cnt;
        if(last >= (k+1)/2){
            int next = (k+1)/2;
            for(int i=0;i<cnt;i++) cout<<pre<<" ";
            for(int i=0;i<last-next;i++) cout<<"2 ";
            for(int i=0;i<next*2-last;i++) cout<<"1 ";
        }else if(last!=0){
            int next = (k+1)/2;
            for(int i=0;i<last;i++) cout<<"1 ";
            for(int i=0;i<cnt-(next-last);i++) cout<<pre<<" ";
            for(int i=0;i<(next-last)*2;i++) cout<<pre/2<<" ";
        }else{
            if(pre%2 == 0){
                for(int i=0;i<cnt-1;i++) cout<<(pre-2)<<" 2 ";
                cout<<(pre-2)/2<<" 2 "<<(pre-2)/2;
            }else{
                for(int i=0;i<cnt-1;i++) cout<<(pre-1)<<" 1 ";
                cout<<(pre-1)/2<<" 2 "<<(pre-1)/2;
            }
        }
        cout<<"\n";
    }
    return 0;
}
