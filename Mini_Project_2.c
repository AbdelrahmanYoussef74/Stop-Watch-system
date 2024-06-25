#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void Timer_Init(void);                       // All Function Prototype
void Reset_Button_INT0_Init(void);          //
void Pause_Button_INT1_Init(void);         //
void Resume_Button_INT2_Init(void);       //

unsigned char sec = 0, min =0,hour = 0 ;  //global variables to increment then display

int main (){

	DDRC  |= 0x0F; // make PORTC as an output
	PORTC = 0;    // initialize the PORTC with zeroes

	DDRA  = 0XFF;   //make PORTA as an output
	PORTA = 0XFF;  // allow the all se7en segments to display
	_delay_ms(400);

	Timer_Init();                     //   All Functions Call
	Reset_Button_INT0_Init();        //
	Pause_Button_INT1_Init();       //
    Resume_Button_INT2_Init();     //

    SREG  |= (1<<7);     // Enable interrupts by setting I-bit

while (1)
{

	PORTA = (1<<5);    //to display the number on the sixth segment
	PORTC = sec%10;   // to make the number display on the right segment
	_delay_ms(3);    // to let the system stable

	PORTA = (1<<4);  //to display the number on the fifth segment
	PORTC = sec/10; // to make the number display on the right segment
	_delay_ms(3);  // to let the system stable

if(sec > 59)    //this condition to clear the seconds section and start the display of min section
{
	min ++;
    sec =0;
}

    PORTA = (1<<3);    //to display the number on the fourth segment
    PORTC = min%10;   // to make the number display on the right segment
    _delay_ms(3);    // to let the system stable

    PORTA = (1<<2);    //to display the number on the third segment
    PORTC = min/10;   // to make the number display on the right segment
    _delay_ms(3);    // to let the system stable

if(min > 59)
{
	min = 0;
	sec = 0;
	hour ++ ;
}

    PORTA = (1<<1);     //to display the number on the second segment
    PORTC = hour%10;   // to make the number display on the right segment
    _delay_ms(3);     // to let the system stable

    PORTA = (1<<0);     //to display the number on the first segment
    PORTC = hour/10;   // to make the number display on the right segment
    _delay_ms(3);     // to let the system stable
}

}
void Timer_Init(void){
	TCNT1 = 0 ;      //set the initial value

	TCCR1A |= (1<<FOC1A); // choose compare mode
	TCCR1A &= ~ (1<<WGM11) &~ (1<<WGM10);

	TCCR1B = (1<<CS12) | (1<<CS10)| (1<<WGM12); //choose prescalar (1024)
	TCCR1B &= ~ (1<<CS11);

	TIMSK |= (1<<OCIE1A) ; // enable compare match TIMER1A interrupt
	OCR1A = 980 ;         //set compare value

}

ISR(TIMER1_COMPA_vect)
{
	sec++;    //increment the variable sec each interrupt (each interrupt takes place every 1 second)

}


void Reset_Button_INT0_Init(void)
	{
		DDRD  &= (~(1<<PD2));                   // Configure INT0/PD2 as input pin
		MCUCR |= (1<<ISC01);                    // Trigger INT0 with the falling edge
		MCUCR &= ~(1<<ISC00);

		GICR  |= (1<<INT0);                  // Enable external interrupt pin INT0
		PORTD |= (1<<PD2);
	}

	ISR(INT0_vect)
	{
		sec = 0;     // by clearing all variables the segments will display zeros only (as a reset)
		min = 0;
		hour = 0;


	}

	void Pause_Button_INT1_Init(void)
	{

			DDRD  &= (~(1<<PD3));  // Configure INT1/PD3 as input pin
			MCUCR |= (1<<ISC11) | (1<<ISC10); //Trigger INT1 with raising edge
			GICR  |= (1<<INT1);    // Enable external interrupt pin INT1
	}

	ISR(INT1_vect)
	{
		TIMSK &= ~ (1<<OCIE1A);  //disable the compare match interrupt


	}

	void Resume_Button_INT2_Init(void)
	{
		DDRB   &= (~(1<<PB2));     // Configure INT2/PB2 as input pin
		MCUCSR &= ~(1<<ISC2);     // Trigger INT2 with the raising edge
		GICR   |= (1<<INT2);	 // Enable external interrupt pin INT2
	}

	ISR(INT2_vect)
	{
		TIMSK |= (1<<OCIE1A); //enable the compare match interrupt again to resume the main function
		TCNT1 = 0 ;
	}
