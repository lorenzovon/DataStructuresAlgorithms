#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int minNoCoins(int currentValue,int nOfDenom,int denom[]);

int main(){
    int nOfDenom,amount;
    // cin >> nOfDenom ;
    nOfDenom=3;    
    int denom[nOfDenom]={1,3,4};    
    // for(int i=0;i<nOfDenom;i++){
    //     cin >> denom[i];
    // }
    cin >> amount;
    int k = minNoCoins(amount,nOfDenom,denom);
    cout << k << endl ;
    return 0;
}

int minNoCoins(int currentValue,int nOfDenom,int denom[]){
    int dynamicData[currentValue+1];
    dynamicData[0]=0;

    int maximum = INT_MAX;
    for(int i=1;i<=currentValue;i++){
        dynamicData[i]=maximum;
    }

    for(int i=1;i<=currentValue;i++){
        for(int j=0;j<nOfDenom;j++){
            if(denom[j]<=i){
                int leftOver=dynamicData[i-denom[j]];
                if(leftOver!=maximum && leftOver + 1 < dynamicData[i] ){
                    dynamicData[i]=leftOver+1;
                }
            }
        }
    }

    return dynamicData[currentValue];    
}
