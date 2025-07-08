//--------------------------------------------------------------
void pwm_setup(){
	// Define pins as output
    DDRB |= (1<<PB1) | (1<<PB2);	// OC1A (PB1 = D9), OC1B (PB2 = D10)
    
    // Fast PWM with ICR1 as TOP (Mode 14)
    TCCR1A = (1<<COM1A1) | (1<<COM1B1) | (1<<COM1B0) | (1<<WGM11);
    TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS10);	// No prescaler
    
	// ICR1 = (F_CPU/(prescaler*frequency)) - 1
    ICR1 = 1599;				// ICR1 = (16000000/(1*10000)) - 1 = 1599
    
    // Set initial duty cycle
    OCR1A = 0;
    OCR1B = 0;
}
//--------------------------------------------------------------
// Base para o Bidirecional
/*
void pwm_setup(){
	int invert = 1;
	
	
	TCCR1A = (1 << WGM11); // WGM11 é a única parte do TCCR1A que não mudará
  	
	// Define pins as output
    DDRB |= (1<<PB1) | (1<<PB2);	// OC1A (PB1 = D9), OC1B (PB2 = D10)
    
    // Fast PWM with ICR1 as TOP (Mode 14)
    TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS10);	// No prescaler
    
	// ICR1 = (F_CPU/(prescaler*frequency)) - 1
    ICR1 = 1599;				// ICR1 = (16000000/(1*10000)) - 1 = 1599
    
	if(invert != 0){
		
		TCCR1A &= ~((1 << COM1A1) | (1 << COM1A0) | (1 << COM1B1) | (1 << COM1B0));

        // MODO INVERTIDO: D10 = PWM padrão, D9 = PWM complementar
        // OC1A (D9) -> Modo Invertido (set on compare, clear at BOTTOM)
        // OC1B (D10) -> Modo Não-Invertido (clear on compare, set at BOTTOM)
        TCCR1A |= (1 << COM1A1) | (1 << COM1A0) | (1 << COM1B1);
    }
	else{		
        // MODO PADRÃO: D9 = PWM padrão, D10 = PWM complementar
        // OC1A (D9) -> Modo Não-Invertido (clear on compare, set at BOTTOM)
        // OC1B (D10) -> Modo Invertido (set on compare, clear at BOTTOM)
        TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << COM1B0);
    }
	
	
    // Set initial duty cycle
    OCR1A = 0;
    OCR1B = 0;
}
*/
//--------------------------------------------------------------