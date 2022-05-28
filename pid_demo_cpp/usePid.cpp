#include <iostream>
#include "pidControl.h"

using namespace std;

int main(){
    float initValue = 0;
    float targetValue = 2;
    //实例化pidControl对象
    //输入参数：kp, ki, kd, sampleTime
    pidControl myPid(0.6, 0.4, 0.05, 0.5);

    //设置初始值
    myPid.pidCurrentSet(initValue);

    //设置目标值
    myPid.pidTargetSet(targetValue);

    for(int i=0; i<100; ++i){
        myPid.pidCompute();
        if(i == 0)
            cout<<"#"<<i+1<<":"<<initValue<<endl;
        else{
            cout<<"#"<<i+1<<":";
            cout<<myPid.pidCurrentGet()<<endl;
        }
    }
    return 0;
}