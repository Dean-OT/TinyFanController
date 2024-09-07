#ifndef PIDController_H
#define PIDController_H

typedef struct
{
	// Controller Gains
	float KP;
	float KI;
	float KD;
	
	//Time Constant for the LPF on the derivative
	float tau;
	
	//Setting limits on the outputs
	float LimMax;
	float LimMin;
	
	//clamping limits on the integrator
	float IntLimMax;
	float IntLimMin;
	
	//sampling time
	float T;
	
	//Controller variables
	float Integrator;
	float Differentiator;
	float PrevError;
	float PrevMeasurement;
	
	//Output
	float Out;
} PIDController;

void PIDController_Init(PIDController *pid);
float PIDController_Update(PIDController *pid, float SetPoint, float Measurement);

#endif