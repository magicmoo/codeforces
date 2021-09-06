#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS ll CASE; \
            cin>>CASE; \
            while(CASE--)
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 0x3f3f3f3f;
 
int main(){
    IOS;
	int n;
    string str;
	CAS {
		cin>>n;
		cin>>str;
		int mid = -1;
		rep(i,n/2,n){
			if(str[i] == '0'){
				mid = i; break;
			}
		}
		if(mid != -1){
			cout<<"1 "<<mid+1<<" 1 "<<mid<<"\n";
		}else{
			if(str[n/2-1] == '1'){
				cout<<(n/2)<<" "<<(n-1)<<" "<<(n/2+1)<<" "<<n<<"\n";
			}else{
				cout<<(n/2)<<" "<<n<<" "<<(n/2+1)<<" "<<n<<"\n";
			}
		}
	}
    return 0;
}
// 1110 1111
 
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