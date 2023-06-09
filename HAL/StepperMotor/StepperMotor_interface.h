#ifndef STEPPERMOTOR_INTERFACE_H
#define STEPPERMOTOR_INTERFACE_H


typedef struct{
	DIO_Port_t StepperMotor_PORT;
	DIO_Pin_t  StepperMotor_BPIN;
	DIO_Pin_t  StepperMotor_PPIN;
	DIO_Pin_t  StepperMotor_YPIN;
	DIO_Pin_t  StepperMotor_OPIN;
}StepperMotor_Config_t;

#define StepperMotor_CW				1U
#define StepperMotor_CCW			2U

uint8 StepperMotor_u8Rotate(const StepperMotor_Config_t* copy_pStepperConfig,uint16 copy_u16Angle,uint8 copy_u8Dir);

#endif
