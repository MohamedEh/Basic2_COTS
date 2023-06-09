#ifndef CLCD_PRV_H
#define CLCD_PRV_H

#define FOUR_BIT		1u
#define EIGHT_BIT		2u

#define ENALED			1u
#define DISABLED		2u

#if CLCD_u8CONNECTION_MODE == FOUR_BIT
static void voidSetHALFDataPort(uint8 copy_u8FourBitData);
#endif

static void voidSendEnablePulse();

#endif
