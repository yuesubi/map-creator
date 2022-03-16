#include "raylib.h"


#define DEBUG

#ifdef DEBUG
	#define INFO(x) printf("[i]   (%s::%d) %s\n",   __FILE__, __LINE__, x)
	#define WARN(x) printf("[!]   (%s::%d) %s\n",   __FILE__, __LINE__, x)
	#define ERR(x)  printf("[ERR] (%s::%d) %s\n", __FILE__, __LINE__, x)
#else
	#define INFO(_)
	#define WARN(_)
	#define ERR(_)
#endif


#define DRACULA
#ifdef DRACULA
	#define SHM_BG     (Color) {  40,  42,  54, 255 }
	#define SHM_CL     (Color) {  68,  71,  90, 255 }
	#define SHM_SEL    (Color) {  68,  71,  90, 255 }
	#define SHM_FG     (Color) { 248, 248, 242, 255 }
	#define SHM_COM    (Color) {  98, 114, 164, 255 }
	#define SHM_CYAN   (Color) { 139, 233, 253, 255 }
	#define SHM_GREEN  (Color) {  80, 250, 123, 255 }
	#define SHM_ORANGE (Color) { 255, 184, 108, 255 }
	#define SHM_PINK   (Color) { 255, 121, 198, 255 }
	#define SHM_PURPLE (Color) { 189, 147, 249, 255 }
	#define SHM_RED    (Color) { 255,  85,  85, 255 }
	#define SHM_YELLOW (Color) { 241, 250, 140, 255 }
#endif