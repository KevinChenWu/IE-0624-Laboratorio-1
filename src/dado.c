#include <pic14/pic12f683.h>

void lfsr16(unsigned short *rnd_number);
void display_time(unsigned int time);

void lfsr16(unsigned short *rnd_number) {
	if ((*rnd_number) & 1) {
    	(*rnd_number) >>= 1;
    	(*rnd_number) ^= (1<<15) + (1<<14) + (1<<12) + (1<<3);
	}
	else {
    	(*rnd_number) >>= 1;
	}
}