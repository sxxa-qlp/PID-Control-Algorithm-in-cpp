#ifndef PIDCONTROL_H_
#define PIDCONTROL_H_
class pidControl{
    private:
        float current_;
        float target_;
        float sampleTime_;
        float kp_;
        float ki_;
        float kd_;
        float iTerm_;
        float lastError_;
    public:
        pidControl(float kp, float ki, float kd, float sampleTime);
        bool pidCompute();
        void pidTuningSet(float kp, float ki, float kd);
        inline void pidTargetSet( float target) { this->target_ = target;};
        inline void pidCurrentSet( float init) { this->current_ = init;};
        inline float pidCurrentGet(){return this->current_;};
};
#endif