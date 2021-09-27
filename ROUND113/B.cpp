#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS int CASE; \
            cin>>CASE; \
            Rep(__,1,CASE)
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 0x3f3f3f3f;
const int maxn = 55;
int a[maxn];
int ans[maxn][maxn],book[maxn];
vector<int> v;
int main(){
    // IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) book[i] = 0;
        Rep(i,1,n) scanf("%1d",&a[i]);
        Rep(i,1,n)
            Rep(j,1,n) ans[i][j] = 0;
        v.clear();
        Rep(i,1,n){
            if(a[i]==2) v.push_back(i);
        }
        if(v.size()>0 && v.size()<=2){
            cout<<"NO\n";
            continue;
        }
        rep(i,1,v.size()){
            ans[v[i]][v[i-1]] = 1;
            ans[v[i-1]][v[i]] = -1;
        }
        int num = v.size()-1;
        if(v.size() > 0){
            ans[v[0]][v[num]] = 1;
            ans[v[num]][v[0]] = -1;
        }
        cout<<"YES\n";
        Rep(i,1,n){
            Rep(j,1,n){
                if(i == j) cout<<"X";
                else if(ans[i][j]==1) cout<<"+";
                else if(ans[i][j]==0) cout<<"=";
                else if(ans[i][j]==-1) cout<<"-";
            }
            cout<<"\n";
        }
    }
    return 0;
}

//                    _ooOoo_
//                   o8888888o
//                   88" . "88
//                   (| -_- |)
//                   O\  =  /O
//                ____/`---'\____
//              .'  \\|     |//  `.
//             /  \\|||  :  |||//  \
//            /  _||||| -:- |||||-  \
//            |   | \\\  -  /// |   |
//            | \_|  ''\---/''  |   |
//            \  .-\__  `-`  ___/-. /
//          ___`. .'  /--.--\  `. . __
//       ."" '<  `.___\_<|>_/___.'  >'"".
//      | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//      \  \ `-.   \_ __\ /__ _/   .-` /  /
// ======`-.____`-.___\_____/___.-`____.-'======
//                    `=---='
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//             佛祖保佑      永无bug