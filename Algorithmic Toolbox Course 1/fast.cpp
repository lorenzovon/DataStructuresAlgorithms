#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string i1, string i2)
{
  if (i1.length() == 1 && i2.length() == 1)
  {

    if (i1[0] == i2[0])
    {
      return (i1[0] - 0 >= i2[0] - 0);
    }
    else
    {
      return (i1[0] - 0 > i2[0] - 0);
    }
  }
  // else if (i1.length() == 1 && i2.length() != 1)
  // {
  //   int x = 0;
  //   while (x < i2.length())
  //   {
  //     if (i2[x] - 0 == i1[0] - 0)
  //     {
  //       x++;
  //       continue;
  //     }
  //     else
  //     {
  //       return (i2[x] - 0 > i1[0] - 0);
  //       break;
  //     }
  //   };
  // }
  // else if (i2.length() == 1 && i1.length() != 1)
  // {
  //   int x = 0;
  //   while (x < i1.length())
  //   {
  //     if (i1[x] - 0 == i2[0] - 0)
  //     {
  //       x++;
  //       continue;
  //     }
  //     else
  //     {
  //       return (i1[x] - 0 > i2[0] - 0);
  //       break;
  //     }
  //   };
  // }
  else
  {
    if (i1.length() == i2.length())
    {
      for (int t = 0; t < i1.length(); t++)
      {
        if (i1[t] == i2[t])
        {
          continue;
        }
        else
        {
          return (i1[t] - 0 > i2[t] - 0);
        }
      }
    }
    else
    {
      if (i1.length() < i2.length())
      {
        for (int t = 0; t < i1.length(); t++)
        {
          if (i1[t] == i2[t])
          {
            continue;
          }
          else
          {
            return (i1[t] - 0 > i2[t] - 0);
          }
        }
        return (i1[0] - 0 > i2[0] - 0);
      }
      else
      {
        for (int t = 0; t < i2.length(); t++)
        {
          if (i1[t] == i2[t])
          {
            continue;
          }
          else
          {
            return (i1[t] - 0 > i2[t] - 0);
          }
        }
      }
    }
  }
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
  sort(value.begin(), value.end(), compare);
  for (k = value.begin(); k != value.end(); ++k)
  {
    std::cout << *k;
  }
  cout << endl;
  return 0;
}