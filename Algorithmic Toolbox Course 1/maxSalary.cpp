#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool mYcompare(string i1, string i2)
{
  string i1i2, i2i1;
  i1i2 = i1.append(i2);
  i2i1 = i2.append(i1);
  return i1i2.compare(i2i1) > 0 ? 1 : 0;
}

int main()
{
  int n;
  cin >> n;
  vector<string> value;
  vector<string>::iterator k;

  for (int k = 0; k < n; k++)
  {
    string temp;
    cin >> temp;
    value.push_back(temp);
  }
  sort(value.begin(), value.end(), mYcompare);
  for (k = value.begin(); k != value.end(); ++k)
  {
    std::cout << *k;
  }
  cout << endl;
  return 0;
}