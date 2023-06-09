#ifndef EXTI_CFG_H
#define EXTI_CFG_H

/*configure Interruption trigger source 1-LOW_LEVEL
						 	 	 	 	2-ON_CHANGE
						 	 	 	 	3-FALLING_EDGE
						 	 	 	 	4-RISING_EDGE	*/
						 
#define EXTI_u8INT0_TRIG			FALLING_EDGE

#define EXTI_u8INT1_TRIG			FALLING_EDGE

/*configure Interruption trigger source 1-FALLING_EDGE
						 	 	 	 	2-RISING_EDGE
						 	 	 	 		*/
#define EXTI_u8INT2_TRIG			FALLING_EDGE

/*configure Interruption intial state 	1-ENABLED
										2-DISABLED
*/		

#define EXTI_u8INT0_INIT_STATE			ENABLED

#define EXTI_u8INT1_INIT_STATE			ENABLED

#define EXTI_u8INT2_INIT_STATE			ENABLED



#endif
