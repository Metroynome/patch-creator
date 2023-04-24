#include <tamtypes.h>

#if PROTOTYPE // if Prototype
#define DNAS_BYPASS (0x00498830)
#elif !NTSC_J // else if anything but NTSC-J
#define DNAS_BYPASS (0x00498CB0)
#else // else (leaves only NTSC-J)
#define DNAS_BYPASS (0)
#endif

#if DEADLOCKED // Can also use: NTSC_U
#define FRAMELIMITER (*(u32*)0x0021DF60)
#elif GLADIATOR // Can also use: PAL
#define FRAMELIMITER (*(u32*)0x0021DFE8)
#elif PROTOTYPE // Can also use: PROTO
#define FRAMELIMITER (*(u32*)0x0021E160)
#elif GIRIGIRI // Can also use: NTSC_J
#define FRAMELIMITER (*(u32*)0x00238768)
#endif

int main(void)
{
	// This is the Same for NTSC and PAL
	// Patch.bin hook: 0x00138DD0
	// run original jal that patch.bin hook took over
	((void (*)(void))0x001270C0)();

	// DNAS Bypass (For NTSC and PAL)
	if (!DNAS_BYPASS && (*(u8*)DNAS_BYPASS == 7 || *(u8*)DNAS_BYPASS == 6))
		*(u8*)DNAS_BYPASS = 5;

	// Disable Framelimiter
	if (FRAMELIMITER == 0x1e)
		FRAMELIMITER = 0x3c;

	return 0;
}
