#include <pic14/pic12f683.h>

void lfsr16(unsigned short *rnd_number);
void display_time(unsigned int time);

void main(void) {
	// Se pone GP0, GP1, GP2, GP3 y GP4 como salidas
	// Se pone GP5 como entrada
	// Se pone los demás pines como salidas
	TRISIO = 0b00001000;

	// Se pone las salidas en bajo
	GPIO = 0b00000000;

	unsigned int time = 1000;
	unsigned short rnd_number = 1;
	unsigned int dice_number = 0;

	while (1)
	{
		lfsr16(&rnd_number);
		if (GP3)
		{
			dice_number = 1 + (rnd_number % 6);
			switch (dice_number)
			{
			case 1:
				GP1 = ~GP1;
				display_time(time);
				GP1 = ~GP1;
				break;
			
			case 2:
				GP2 = ~GP2;
				display_time(time);
				GP2 = ~GP2;
				break;
			case 3:
				GP1 = ~GP1;
				GP2 = ~GP2;
				display_time(time);
				GP1 = ~GP1;
				GP2 = ~GP2;
				break;
			case 4:
				GP2 = ~GP2;
				GP4 = ~GP4;
				display_time(time);
				GP2 = ~GP3;
				GP4 = ~GP4;
				break;
			case 5:
				GP1 = ~GP1;
				GP2 = ~GP2;
				GP4 = ~GP4;
				display_time(time);
				GP1 = ~GP1;
				GP2 = ~GP3;
				GP4 = ~GP4;
				break;
			case 6:
				GP2 = ~GP2;
				GP4 = ~GP4;
				GP5 = ~GP5;
				display_time(time);
				GP2 = ~GP3;
				GP4 = ~GP4;
				GP5 = ~GP5;
				break;
			default:
				break;
			}
		}
		
	}
	

}

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