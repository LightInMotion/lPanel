/*
	File:

		LPNet.h

	Description:

		Defines for LivePanel Network API
*/

#ifndef _LPNET_H
#define _LPNET_H

#ifndef U8
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned long U32;
typedef signed char S8;
typedef signed short S16;
typedef signed long S32;
#endif

#ifndef TRUE
#define TRUE (1)
#endif

#ifndef FALSE
#define FALSE (0)
#endif

// LP Net Discovery .............................................................

// Protocol ID
#define LPNET_PROTO_ID "LIMSClp"

// Interface Version
#define LPNET_VERSION (1)

// UDP Discovery Port
#define LPNET_DISCOVERY (0x1936)

// Standard Service Port
#define LPNET_SERVICE (0x1001)

// OpCodes
#define LPNET_OPCODE_POLL (0x4000)
#define LPNET_OPCODE_POLLREPLY (0x4100)

// Flags
#define LPNET_FLAG_INUSE (0x100)

// Poll Structures
#pragma pack(push,1)

// All in BIG Endian !!!!
typedef struct {
	U8 ProtoID[8];               // protocol ID = "LIMSClp"
	U16 OpCode;                  // == LPNET_OPCODE_POLL
	U8 VersionH;                 // 0
	U8 VersionL;                 // protocol version, set to LPNET_VERSION
} LPNET_POLL;

typedef struct {
	U8 ProtoID[8];               // protocol ID = "LIMSClp"
	U16 OpCode;                  // == LPNET_OPCODE_POLLREPLY
	U8 VersionH;                 // 0
	U8 VersionL;                 // protocol version, set to LPNET_VERSION
	U32 Address;				 // IP Address
	U16 Port;					 // Port for service
	U16 Flags;					 // See Flags above
	U32 Info;					 // When LPNET_FLAG_INUSE, IP Address of user
} LPNET_POLLREPLY;

#pragma pack(pop)

// LP Commands ...............................................................

/*
	Most commands are syntax 0xFF, <command>, <valH 7 bits>, <valL 7 bits>, <parH 7 bits>, <parL 7 bits>
	This permits easy syncing to the byte stream

	LPCMD_CUES is the exception, the parameter is a null terminated string
*/
                                //									VAL			PAR
#define LPCMD_GM (0)			// Set GM						0-8192		unused
#define LPCMD_GM_FADE (1)		// Fade GM						+/-time		unused

	// Time
	#define	LP_1SEC (1)
	#define	LP_2SEC (2)
	#define	LP_3SEC (3)

#define LPCMD_GM_GET (2)		// Current GM value			unused		unused
										//	Response: LPCMD_GM_GET, <GM high byte>, <GM low byte>

#define LPCMD_DIR (3)			// Set Chaser dir.			chaser		direction

	// Chaser
	#define	LP_CHASER_ACTIVE (0)
	#define	LP_CHASER_1 (1)
	#define	LP_CHASER_2 (2)
	#define	LP_CHASER_3 (3)
	#define	LP_CHASER_4 (4)

	// Direction
	#define	LP_STOP (0)
	#define	LP_REVERSE (1)
	#define	LP_BALLY (2)
	#define	LP_FORWARD (3)
	#define	LP_STEP (4)

#define LPCMD_DIR_GET (4)		// Get chaser dir.			chaser		unused
										// Response: LPCMD_DIR_GET, <dir high byte>, <dir low byte>

#define LPCMD_FADE (5)			// Set Fade						chaser		fade

	// Fade values
	#define	LP_FADE_ON (1)
	#define	LP_FADE_OFF (0)

#define LPCMD_FADE_GET (6)		// Get fade						chaser		unused
										// Response: LPCMD_FADE_GET, <fade high byte>, <fade low byte>

#define LPCMD_ONCE (7)			// Set once flag				chaser		once

	// Once values
	#define	LP_ONCE_ON (1)
	#define	LP_ONCE_OFF (0)

#define LPCMD_ONCE_GET (8)		// Get once						chaser		unused
										// Response: LPCMD_ONCE_GET, <once high byte>,<once low byte>

#define LPCMD_SPEED (9)			// Set Speed					chaser		0-8192
#define LPCMD_SPEED_FADE (10)	// Fade Speed					chaser		+/-time
#define LPCMD_SPEED_GET (11)	// Get Current Speed			chaser		unused

#define LPCMD_LEVEL (12)		// Set Level					chaser		0-8192
#define LPCMD_LEVEL_FADE (13)	// Fade Level					chaser		+/-time
#define LPCMD_LEVEL_GET (14)	// Get Current Level			chaser		unused

#define LPCMD_TAP (15)			// 'Tap' for speed			chaser		unused

#define LPCMD_CUES (16)			// Set cue list				chaser		cue list a null terminated c string
										// Example: "100 200 300"

#define LPCMD_CUES_GET (17)	// Get cue list				chaser		unused
										// Response: LPCMD_CUES_GET,<Big Endian U32, length><Big Endian U32, cue>...

#define LPCMD_PAGE (18)			// Set active page			0-23			unused
#define LPCMD_PAGE_GET (19)	// Get active page			unused		unused
										// Response: LPCMD_PAGE_GET, <page MSB>,<page LSB>

#define LPCMD_RECALL (20)		// Recall a sequence			0-47			unused
#define LPCMD_RECALL_GET (21)	// Get a sequence				0-47			unused
										// Response: LPCMD_RECALL_GET,<active flag>,<name as null term c string>
	#define LP_INACTIVE (0)
	#define LP_ACTIVE (1)

#define LPCMD_BPM (22)			// Set BPM Lock				chaser		BMP_state

	// States
	#define LP_BPM_ON (1)
	#define LP_BPM_OFF (0)

#define LPCMD_BPM_GET (23)		// Get the BPM lock			chaser		unused
										// Response: LPCMD_BPM_GET,<state msb>,<state lsb>

#define LPCMD_DISABLE (24)		// Set Crossfade disable	crossfader	disable

	// Crossfaders
	#define LP_CROSSFADE_12 (0)
	#define LP_CROSSFADE_34 (1)

	// disable flag
	#define LP_DISABLE_ON (1)
	#define LP_DISABLE_OFF (0)

#define LPCMD_DISABLE_GET (25)	// Get disable flag		crossfader	unused
										// Response: LPCMD_DISABLE_GET, <dis msb>,<dis lsb>

#define LPCMD_CROSS (26)		// Set crossfade level		crossfader	0-8192
#define LPCMD_CROSS_FADE (27)	// Fade crossfader			crossfader	+/-time
#define LPCMD_CROSS_GET (28)	// Get crossfade level		crossfader
										// Response: LPCMD_CROSS_GET, <cross msb>,<cross lsb>

#define LPCMD_ACTIVE (29)		// Set active chaser			chaser		unused
#define LPCMD_ACTIVE_GET (30)	// Get active chaser			unused		unused
										// Response: LPCMD_ACTIVE_GET,<chase msb>,<chase lsb>
#define LPCMD_TOGGLE (31)		// Set toggle button			toggle		state

	// Toggle
	#define LP_TOGGLE_1 (0)
	#define LP_TOGGLE_2 (1)
	#define LP_TOGGLE_3 (2)
	#define LP_TOGGLE_4 (3)

	// State
	#define LP_TOGGLE_ON (1)
	#define LP_TOGGLE_OFF (0)

#define LPCMD_TOGGLE_GET (32)	// Get toggle button			toggle		unused
										// Response: LPCMD_TOGGLE_GET,<Big Endian State as Word><Big Endian Cue as long>
#endif // LPNET_H
