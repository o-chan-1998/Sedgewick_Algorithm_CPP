#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <bitset>
#include <numeric> // iota関数
#include <fstream>

using namespace std;

int main()
{
  // ファイル出力
  const char *fileName = "trace.txt";
  ofstream ofs(fileName);
  if (!ofs)
  {
    cout << "ファイルが開けませんでした。" << endl;
    cin.get();
    return 0;
  }
  ofs << "===" << endl;

  rep(i,M)
    ofs << dp[i] << " ";
  ofs << endl;

  ofs.close();

  return EXIT_SUCCESS;
}