#ifndef PIDController_H
#define PIDController_H

typedef struct
{
	// Controller Gains
	int KP;
	int KI;
	int KD;
	
	//Time Constant for the LPF on the derivative
	int tau;
	
	//Setting limits on the outputs
	int LimMax;
	int LimMin;
	
	//clamping limits on the integrator
	int IntLimMax;
	int IntLimMin;
	
	//sampling time
	int T;
	
	//Controller variables
	int Integrator;
	int Differentiator;
	int PrevError;
	int PrevMeasurement;
	
	//Output
	int Out;
} PIDController;

void PIDController_Init(PIDController *pid);
int PIDController_Update(PIDController *pid, int SetPoint, int Measurement);

#endif