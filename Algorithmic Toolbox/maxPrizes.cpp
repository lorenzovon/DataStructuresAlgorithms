#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
  uint64_t n;
  cin >> n;
  vector<uint64_t> value;
  vector<uint64_t>::iterator p;
  uint64_t temp = n, sum = 0;
  if (n == 1 || n == 2)
  {
    cout << 1 << endl;
    cout << n << endl;
  }
  else
  {
    for (uint64_t i = 1; i <= n; i++)
    {
      if (temp - i > i)
      {
        value.push_back(i);
        sum += i;
        temp -= i;
      }
      else
      {
        value.push_back(temp);
        break;
      }
    }
    cout << value.size() << endl;
    for (p = value.begin(); p != value.end(); ++p)
    {
      cout << *p << " ";
    }
    cout << endl;
  }
  return 0;
}