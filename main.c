#include <tamtypes.h>

#if PAL

#define MUSIC_LOADED (*(u32*)0x001CF8DC == 0x000FB3B2)

#else

#define MUSIC_LOADED (*(u32*)0x001CF85C == 0x000F8D29)

#endif

int main(void)
{
	// NTSC: if Music is Loaded
	if (!MUSIC_LOADED)
		return -1;

	// This is the Same for NTSC and PAL
	// Patch.bin hook: 0x00138DD0
	// run original jal that patch.bin hook took over
	((void (*)(void))0x001270C0)();

	// DNAS Bypass (For NTSC and PAL)
	if (*(u8*)0x00498CB0 == (7 || 6))
		*(u8*)0x00498CB0 = 5;


#if PAL
// PAL
	// Disable Framelimiter
	if (*(u32*)0x0021DFE8 == 0x1e)
		*(u32*)0x0021DFE8 = 0x3c;

#else

// NTSC
	// Disable Framelimiter
	if (*(u32*)0x0021DF60 == 0x1e)
		*(u32*)0x0021DF60 = 0x3c;

#endif

	return 0;
}
