#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

int minNoCoins(int currentValue,int nOfDenom,int denom[]);

int main(){
    int nOfDenom,amount;    
    nOfDenom=3;    
    int denom[nOfDenom]={1,2,3};        
    cin >> amount;
    int k = minNoCoins(amount,nOfDenom,denom);
    cout << k << endl ;
    return 0;
}

int minNoCoins(int currentValue,int nOfDenom,int denom[]){
    int dynamicData[currentValue+1];
    dynamicData[0]=0;
    dynamicData[1]=0;

    int maximum = INT_MAX;
    for(int i=2;i<=currentValue;i++){
        dynamicData[i]=maximum;
    }

    vector<int>solutionSet;
    solutionSet.push_back(1);
    solutionSet.push_back(1);
    // solutionSet.push_back(currentValue);
    vector<int>operandSet;

    for(int i=2;i<=currentValue;i++){
        int leftOver;
        int nextPoint;
        for(int j=0;j<nOfDenom;j++){ 
            if(denom[j]<=i){                               
                switch (denom[j])
                {
                    case 1:
                        leftOver=dynamicData[i-denom[j]];
                        if(leftOver!=maximum && leftOver + 1 < dynamicData[i] ){
                            
                            dynamicData[i]=leftOver+1;
                            // solutionSet.push_back(i-denom[i]);
                            // if(i==currentValue){
                            //     operandSet.push_back(1);
                            //     cout << "hello world +1 ";
                            // }
                        }                        
                    case 2:
                        leftOver=dynamicData[i/denom[j]];
                        if( i%denom[j]==0 && leftOver!=maximum && leftOver + 1 < dynamicData[i] ){
                            
                            dynamicData[i]=leftOver+1;
                            // solutionSet.back()=i/denom[i];
                            // if(i==currentValue){
                            //     operandSet.push_back(2);
                            //     cout << "hello world +2 ";
                            // }
                        }
                    case 3:
                        leftOver=dynamicData[i/denom[j]];
                        if( i%denom[j]==0 && leftOver!=maximum && leftOver + 1 < dynamicData[i] ){
                            
                            dynamicData[i]=leftOver+1;
                            // solutionSet.back()=i/denom[i];
                            // if(i==currentValue){
                            //     operandSet.push_back(3);
                            //     cout << "hello world +3 ";
                            // }
                            
                        }
                    default:
                        break;
                }
                
            }           
            
        }        
    }    

    // int solutionSet[dynamicData[currentValue]];
    // for(int i=0;i<dynamicData[currentValue];i++){
    //     
    // }


    // for (auto ir = operandSet.begin(); ir != operandSet.end(); ++ir)
    // {
    //     cout << *ir << " ";
    // }
    // cout << endl;

    for (auto ir = solutionSet.begin(); ir != solutionSet.end(); ++ir)
    {
        cout << *ir << " ";
    }
    cout << endl;

    return dynamicData[currentValue];    
}
