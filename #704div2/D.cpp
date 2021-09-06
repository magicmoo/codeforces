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
    int a,b,k;
    cin>>a>>b>>k;
    if(b==1 && k!=0){
        cout<<"No\n";
    }else if(k == 0){
        cout<<"Yes\n";
        for(int i=0;i<b;i++) cout<<1;
        for(int i=0;i<a;i++) cout<<0;
        cout<<"\n";
        for(int i=0;i<b;i++) cout<<1;
        for(int i=0;i<a;i++) cout<<0;
        cout<<"\n";
    }else{
        int pre = b-1;
        if(a < k){
            if(a == 0) cout<<"No\n";
            else if(a+b-2 < k) cout<<"No\n";
            else{
                cout<<"Yes\n";
                pre = b - (k-a+1);
                for(int i=0;i<b;i++) cout<<1;
                for(int i=0;i<a;i++) cout<<0;
                cout<<"\n";
                for(int i=0;i<pre;i++) cout<<1;
                cout<<0;
                for(int i=0;i<b-pre-1;i++) cout<<1;
                for(int i=0;i<a-1;i++) cout<<0;
                cout<<1;
                cout<<"\n";
            }
        }else{
            cout<<"Yes\n";
            for(int i=0;i<pre+1;i++) cout<<1;
            for(int i=0;i<a;i++) cout<<0;
            cout<<"\n";
            for(int i=0;i<pre;i++) cout<<1;
            for(int i=0;i<k;i++) cout<<0;
            cout<<1;
            for(int i=0;i<a-k;i++) cout<<0;
            cout<<"\n";
        }
    }
    return 0;
}
