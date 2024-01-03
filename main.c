#include <tamtypes.h>

#if NTSC_U_PROTOTYPE // if NTSC-U Prototype
#define DNAS_BYPASS (0x00498830)
#elif PAL_PROTOTYPE // else if PAL Prototype
#define DNAS_BYPASS (0x004B7730)
#elif NTSC_U || PAL // else if NTSC_U or PAL
#define DNAS_BYPASS (0x00498CB0)
#elif KOREA // else if Korean
#define DNAS_BYPASS (0x004E0B30)
#else // else (leaves only NTSC-J)
#define DNAS_BYPASS (0)
#endif

#if DEADLOCKED // Can also use: NTSC_U, AMERICA, AMERICAN
#define FRAMELIMITER (0x0021DF60)
#elif GLADIATOR // Can also use: PAL, EUROPE, EUROPEAN
#define FRAMELIMITER (0x0021DFE8)
#elif NTSC_U_PROTOTYPE // Can also use: NTSC_U_PROTO
#define FRAMELIMITER (0x0021E160)
#elif PAL_PROTOTYPE // Can also use: PAL_PROTO
#define FRAMELIMITER (0)
#elif WRENCHCHAMP // Can also use: NTSC_K, KOREAN, KOREA
#define FRAMELIMITER (0)
#elif GIRIGIRI // Can also use: NTSC_J, JAPAN, JAPANESE
#define FRAMELIMITER (0x00238768)
#endif

int main(void)
{
	// This is the Same for all games
#if PAL_PROTO
	((void (*)(void))0x00126F80)();
#else
	((void (*)(void))0x001270C0)();
#endif

	// DNAS Bypass (For NTSC and PAL)
	if (DNAS_BYPASS && (*(u8*)DNAS_BYPASS == 7 || *(u8*)DNAS_BYPASS == 6 || *(u8*)DNAS_BYPASS == 9))
		*(u8*)DNAS_BYPASS = 5;

	// Disable Framelimiter
	if (FRAMELIMITER && *(u32*)FRAMELIMITER == 0x1e)
		*(u32*)FRAMELIMITER = 0x3c;

	return 0;
}
