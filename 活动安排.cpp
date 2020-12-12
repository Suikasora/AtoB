#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Activity {
  int beg;//活动开始时间
  int end;//活动结束时间
  int num;//活动编号
} Act[100];
class setActivity {
public:
  void init();
  void solve();
private:
  int n;//活动总数
  int ans;//最大安排活动数
};
void setActivity::init() {
  int b, e;
  cout << "输入活动总数：" << endl;
  cin >> n;
  cout << "输入活动的开始时间和结束时间：" << endl;
  for (int i = 0; i < n; i++) {
    cin >> b >> e;
    Act[i].beg = b;
    Act[i].end = e;
    Act[i].num = i + 1;
  }
}
bool cmp (Activity x, Activity y) {
  if ( x.end == y.end )
    return x.beg > y.beg;
  return x.end < y.end;
}
void setActivity::solve() {
  sort (Act, Act + n, cmp);
  cout << "安排后的活动时间：" << endl;
  cout << "活动编号    开始时间    结束时间" << endl;
  for (int i = 0; i < n; i++)
    cout << Act[i].num << "    "
         << Act[i].beg << "    "
         << Act[i].end << endl;
  cout << "活动安排过程：" << endl;
  cout << "选择第" << Act[0].num << "个活动" << endl;
  ans = 1;
  int last = Act[0].end;
  for (int i = 1; i < n; i++) {
    if ( Act[i].beg >= last ) {
      ans++;
      last = Act[i].end;
      cout << "选择第" << Act[i].num << "个活动" << endl;
    }
  }
  cout << "最多可以安排" << ans << "个活动";
}
int main (void) {
  setActivity sa;
  sa.init();
  sa.solve();
  return 0;
}
