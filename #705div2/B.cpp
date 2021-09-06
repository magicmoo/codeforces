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
int T,n,m,sh,sm;
bool check1(int nh){
    int a = nh/10;
    int b = nh%10;
    if(a==0){
        if(b==0) return true;
        if(b==1 && m>10) return true;
        if(b==2 && m>50) return true;
        if(b==5 && m>20) return true;
        if(b==8 && m>80) return true;
    }
    if(a==1){
        if(b==0 && m>1) return true;
        if(b==1 && m>11) return true;
        if(b==2 && m>51) return true;
        if(b==5 && m>21) return true;
        if(b==8 && m>81) return true;
    }
    if(a==2){
        if(b==0 && m>5) return true;
        if(b==1 && m>15) return true;
        if(b==2 && m>55) return true;
        if(b==5 && m>25) return true;
        if(b==8 && m>85) return true; 
    }
    if(a==5){
        if(b==0 && m>2) return true;
        if(b==1 && m>12) return true;
        if(b==2 && m>52) return true;
        if(b==5 && m>22) return true;
        if(b==8 && m>82) return true;
    }
    if(a==8){
        if(b==0 && m>8) return true;
        if(b==1 && m>18) return true;
        if(b==2 && m>58) return true;
        if(b==5 && m>28) return true;
        if(b==8 && m>88) return true;
    }
    return false;
}

bool check2(int nm){
    int a = nm/10;
    int b = nm%10;
    if(a==0){
        if(b==0) return true;
        if(b==1 && n>10) return true;
        if(b==2 && n>50) return true;
        if(b==5 && n>20) return true;
        if(b==8 && n>80) return true;
    }
    if(a==1){
        if(b==0 && n>1) return true;
        if(b==1 && n>11) return true;
        if(b==2 && n>51) return true;
        if(b==5 && n>21) return true;
        if(b==8 && n>81) return true;
    }
    if(a==2){
        if(b==0 && n>5) return true;
        if(b==1 && n>15) return true;
        if(b==2 && n>55) return true;
        if(b==5 && n>25) return true;
        if(b==8 && n>85) return true; 
    }
    if(a==5){
        if(b==0 && n>2) return true;
        if(b==1 && n>12) return true;
        if(b==2 && n>52) return true;
        if(b==5 && n>22) return true;
        if(b==8 && n>82) return true;
    }
    if(a==8){
        if(b==0 && n>8) return true;
        if(b==1 && n>18) return true;
        if(b==2 && n>58) return true;
        if(b==5 && n>28) return true;
        if(b==8 && n>88) return true;
    }
    return false;
}
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    scanf("%d",&T); while(T--){
        scanf("%d%d",&n,&m);
        scanf("%d:%d",&sh,&sm);
        bool flag = false;
        if(check1(sh)){
            for(int i=sm;i<m;i++){
                if(check2(i)){
                    if(sh < 10) cout<<"0"<<sh;
                    else cout<<sh;
                    cout<<":";
                    if(i < 10) cout<<"0"<<i;
                    else cout<<i;
                    cout<<"\n";
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
        }
        for(int i=sh+1;i<n;i++){
            if(!check1(i)) continue;
            for(int j=0;j<m;j++){
                if(check2(j)){
                    if(i < 10) cout<<"0"<<i;
                    else cout<<i;
                    cout<<":";
                    if(j < 10) cout<<"0"<<j;
                    else cout<<j;
                    cout<<"\n";
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) continue;
        for(int i=0;i<sh;i++){
            if(!check1(i)) continue;
            for(int j=0;j<m;j++){
                if(check2(j)){
                    if(i < 10) cout<<"0"<<i;
                    else cout<<i;
                    cout<<":";
                    if(j < 10) cout<<"0"<<j;
                    else cout<<j;
                    cout<<"\n";
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) continue;
        for(int i=0;i<sm;i++){
            if(check2(i)){
                    if(sh < 10) cout<<"0"<<sh;
                    else cout<<sh;
                    cout<<":";
                    if(i < 10) cout<<"0"<<i;
                    else cout<<i;
                    cout<<"\n";
                    flag = true;
                    break;
                }
        }
    }
    return 0;
}
