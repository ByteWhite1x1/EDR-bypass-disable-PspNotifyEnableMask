/*
The origin of the source code must not be misrepresented. The original author of the source code is White Byte at overlayhack.com
*/

// The undocumented struct is for Windows 10 22H2 Build: 19045 (I've no idea about any other version as I haven't time to reverse and test other versions of windows)

typedef union _pNotifyRoutines
{

	UCHAR value;

	// Bitfield in a struct
	struct
	{
		UCHAR PsCallImageNotifyRoutines : 1;		// Load vulnerable or blacklisted drivers (STATUS_IMAGE_CERT_REVOKED). Also shows loaded DLL's
		UCHAR unk1 : 1;
		UCHAR PspCallProcessNotifyRoutines : 1;		// This is exactly how the anti-virus (Windows Defender for example) scans every loaded process for malware		
		UCHAR PspCallThreadNotifyRoutines : 1;		// Create a thread in the manually mapped DLL
		UCHAR unk2 : 1;
		UCHAR unk3 : 1;
		UCHAR unk4 : 1;
		UCHAR unk5 : 1;
	};

} NotifyRoutines, * pNotifyRoutines;

PVOID pPspNotifyEnableMask;
extern PVOID pPspNotifyEnableMask;
