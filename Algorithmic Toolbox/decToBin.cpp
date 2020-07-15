#include<bits/stdc++.h>

using namespace std;

int main(){
    int64_t n;
    cin >> n;    
    string binary=bitset<64>(n).to_string();
    cout << binary << endl ;
    int count0=0,count1=0,start1;
    for(int i=0;i<binary.length();i++){
        if(binary[i]-'0'==1){
            count1++;
            if(count1==1){
                start1=i;
            }
        }        
    }
    if(count1==1){
        count0=binary.length()-start1-1;                
    }
    if(count1==1 && count0%2==0){
        cout << "number is a power of 4";
    }
    else{
        cout << "number is not a power of 4";
    }
    cout << endl;
    return 0;
}