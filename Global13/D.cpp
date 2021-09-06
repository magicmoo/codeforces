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
    int q,u,v;
    cin>>q; while(q--){
        cin>>u>>v;
        queue<int> a,b;
        if(v < u){
            cout<<"NO\n";
            continue;
        }
        if(v == u){
            cout<<"YES\n";
            continue;
        }
        while(u){
            a.push(u%2);
            u /= 2;
        }
        while(v){
            b.push(v%2);
            v /= 2;
        }
        bool flag = true;
        int nowa = 0,nowb = 0;
        while(!a.empty() && a.front()==0){
            if(b.front() == 1){
                flag = false;
                break;
            }else b.pop();
            a.pop();
        }
        if(!flag){
            cout<<"NO\n";
            continue;
        }
        while(!b.empty() && flag){
            int temp = b.front();
            b.pop();
            if(temp == 1){
                flag = false;
                while(!a.empty() && nowa<= nowb){
                    nowa++;
                    int temp2 = a.front();
                    a.pop();
                    if(temp2 == 1){
                        flag = true;
                        break;
                    }
                }
            }
            nowb++;
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
