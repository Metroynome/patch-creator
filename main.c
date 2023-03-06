#include <tamtypes.h>

#define DNAS_BYPASS (*(u8*)0x00498CB0)

#if GLADIATOR
#define FRAMELIMITER (*(u32*)0x0021DFE8)
#else
#define FRAMELIMITER (*(u32*)0x0021DF60)
#endif

int main(void)
{
	// This is the Same for NTSC and PAL
	// Patch.bin hook: 0x00138DD0
	// run original jal that patch.bin hook took over
	((void (*)(void))0x001270C0)();

	// DNAS Bypass (For NTSC and PAL)
	if (DNAS_BYPASS == 7 || DNAS_BYPASS == 6)
		DNAS_BYPASS = 5;

	// Disable Framelimiter (PAL)
	if (FRAMELIMITER == 0x1e)
		FRAMELIMITER = 0x3c;

	return 0;
}
