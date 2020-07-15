#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int testCases,n;
    cin>>testCases;
    for(int i=0;i<testCases;i++){
        cin>>n;
        uint64_t A[n];
        for(int j=0;j<n;j++){
            cin>>A[i];
        }
        for(int j=1;j<n;j++){
            if(A[j+1]-A[j]==j*j){
                
            }
        }
    }
    return 0;
}