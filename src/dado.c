#include <pic14/pic12f683.h>

// Se desabilita el MCLR (se pone el MCLRE en OFF) y el WDT (se pone el WDTE en OFF)
unsigned int __at 0x2007 __CONFIG = (_MCLRE_OFF&_WDTE_OFF);

// Declaración de las funciones
void lfsr16(unsigned short *rnd_number);
void display_time(unsigned int time);

// Declaración de la función main
void main(void) {
	// Se pone GP0, GP1, GP2, GP4 y GP5 como salidas
	// Se pone GP3 como entrada
	// Se pone los demás pines como salidas
	TRISIO = 0b00001000;

	// Se pone las salidas en bajo
	GPIO = 0b00000000;

	// Con time = 1000 es aprox 1 segundo de delay en simulador
	unsigned int time = 2000;
	unsigned short rnd_number = 1;
	unsigned short *ptr_rnd = &rnd_number;
	unsigned short dice_number = 0;

	// Ciclo infinito
	while (1)
	{
		// Si el botón es presionado
		if (GP3) {
			// Se hace una comparación de dice_number con los casos
			// En caso de coincidir se ejecuta lo siguiente:
			// Se pone el o los pines correspondientes en alto para encender
			// el o los LEDs correspondiente
			// Se espera un cierto tiempo
			// Se pone en bajo el o los pines encendidos
			switch (dice_number) {
			case 1:
				GPIO = 0b00000010;
				display_time(time);
				GPIO = 0b00000000;
				break;
			case 2:
				GPIO = 0b00000100;
				display_time(time);
				GPIO = 0b00000000;
				break;
			case 3:
				GPIO = 0b00000110;
				display_time(time);
				GPIO = 0b00000000;
				break;
			case 4:
				GPIO = 0b00010100;
				display_time(time);
				GPIO = 0b00000000;
				break;
			case 5:
				GPIO = 0b00010110;
				display_time(time);
				GPIO = 0b00000000;
				break;
			case 6:
				GPIO = 0b00110100;
				display_time(time);
				GPIO = 0b00000000;
				break;
			default:
				break;
			}
		}
		else {
			// Se mantiene las salidas en bajo
			GPIO = 0b00000000;
			// Se genera un nuevo número aleatorio
			lfsr16(ptr_rnd);
			// Se ajusta el número aleatorio a
			// un valor entre 1 y 6
			dice_number = 1 + (rnd_number % 6);
		}
	}
}

void lfsr16(unsigned short *rnd_number) {
	// Se pregunta si el último bit es 1
	if ((*rnd_number) & 1) {
		// Se desplaza el número un bit a la derecha
    	(*rnd_number) >>= 1;
		// Se hace un XOR del número con la máscara y
		// se actualiza a sí mismp
    	(*rnd_number) ^= (1<<15) + (1<<14) + (1<<12) + (1<<3);
	}
	else {
		// Se desplaza el número un bit a la derecha
    	(*rnd_number) >>= 1;
	}
}

void display_time(unsigned int time) {
	unsigned int i, j;
	for (i = 0; i < time; i++) {
		for (j = 0; j < 256; j++);
	}
}