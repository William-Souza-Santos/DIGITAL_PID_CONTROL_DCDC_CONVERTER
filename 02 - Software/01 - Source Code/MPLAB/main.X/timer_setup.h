//--------------------------------------------------------------
/*
void timer_setup(){
	// Define pins as output
    DDRB |= (1<<PB3);			// OC2A (PB3 = D11)
	
	// Registers
    TCCR2A = (1<<WGM21);  		// CTC mode	
    TCCR2B = (1<<CS21);  		// Prescaler = 8
	
	// OCR2A = (F_CPU/(prescaler*frequency)) - 1
    OCR2A = 199;				// (16000000/(8*10000)) - 1 = 199
	TIMSK2 |= (1 << OCIE2A);	// Enable compare match interrupt
}
*/
//--------------------------------------------------------------

void timer_setup(){
	// Define pins as output
    DDRB |= (1<<PB3);			// OC2A (PB3 = D11)
	
	// Registers
    TCCR2A = (1<<WGM21);  		// CTC mode	
    TCCR2B = (1<<CS22);  		// Prescaler = 64
	
	// OCR2A = (F_CPU/(prescaler*frequency)) - 1
    OCR2A = 249;				// (16000000/(64*1000)) - 1 = 199
	TIMSK2 |= (1 << OCIE2A);	// Enable compare match interrupt
}

//--------------------------------------------------------------