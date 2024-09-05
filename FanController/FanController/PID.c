#include "PID.h"

void PIDController_Init(PIDController *pid)
{
	//Clear out old data
	pid ->Integrator = 0.0f;
	pid ->Differentiator = 0.0f;
	pid ->PrevError = 0.0f;
	pid ->PrevMeasurement = 0.0f;
	pid ->Out = 0.0f;
}

int PIDController_Update(PIDController *pid, int SetPoint, int Measurement)
{
	//Calculate the Error
	int Error = SetPoint-Measurement;
	
	//Calculate the Proportional term
	int Prop = pid ->KP * Error;
	
	//Calculate the Integral term
	pid ->Integrator += 0.5f*pid ->KI * pid ->T * (Error+pid ->PrevError);
	//anti-windup via clamper
	if (pid ->Integrator > pid ->IntLimMax)
	{
		pid ->Integrator = pid ->IntLimMax;
	}
	else if (pid ->Integrator < pid ->IntLimMin)
	{
		pid ->Integrator = pid ->IntLimMin;
	}
	
	//Calculate the Differentiator term
	pid ->Differentiator = -(2.0f *pid ->KD * (Measurement - pid ->PrevMeasurement)
						+ (2.0f * pid ->tau - pid ->T) * pid ->Differentiator)
						/ (2.0f * pid ->tau + pid ->T);
	
	//Calculate the output
	pid ->Out = Prop + pid ->Differentiator + pid ->Integrator;
	
	//Clamp output
	if (pid ->Out > pid ->LimMax)
	{
		pid ->Out = pid ->LimMax;
	}
	else if (pid ->Out < pid->LimMin)
	{
		pid ->Out = pid ->LimMin;
	}
	
	//Store errors and measurements
	pid ->PrevError = Error;
	pid ->PrevMeasurement = Measurement;
	
	return pid->Out;
}