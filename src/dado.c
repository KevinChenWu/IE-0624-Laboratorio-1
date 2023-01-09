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

void display_time(unsigned int time) {
	unsigned int i, j;
	for (i = 0; i < time; i++)
	{
		for (j = 0; j < 5000; j++)
		{
		}
		
	}
	
}