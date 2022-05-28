#include "pidControl.h"
#include <iostream>

#define CONSTRAIN(x,lower,upper)    ((x)<(lower)?(lower):((x)>(upper)?(upper):(x)))

pidControl::pidControl(float kp, float ki, float kd, float sampleTime){
    sampleTime_ = sampleTime;
    lastError_ = 0.0f;
    pidTuningSet(kp, ki, kd);
}

bool pidControl::pidCompute(){
    float error, dTerm;

    //误差
    error = target_ - current_;

    //累计误差
    iTerm_ += error;
    
    //对积分项添加约束
    // iTerm_ = CONSTRAIN(iTerm_, -2, 8);

    //e(k)-e(k-1)
    dTerm = error - lastError_;
    
    //pid输出
    current_ = kp_*error + ki_*iTerm_*sampleTime_ - kd_*dTerm/sampleTime_;

    //对输出项添加约束
    // output_ = CONSTRAIN(output_, -1.4, 8.5);

    lastError_ = error;

    return true;
}

void pidControl::pidTuningSet(float kp, float ki, float kd){
    kp_ = kp;
    ki_ = ki;
    kd_ = kd;
}
