//--------------------------------------------------------------
void mode_setup(){
	// Define pins as output
	DDRB |= (1<<PB4) | (1<<PB5);	// SW1 and SW2 (D0 and D1)
	DDRD |= (1<<PD0) | (1<<PD1);	// SW3 and SW4 (D12 and D13)
}
//--------------------------------------------------------------
void mode_sub(){
	// Temporary variable
	float hold;
	// Operation mode logic variable
	hold = source/ref;
	// Buck Mode
	if(hold > 1.25){
		if(!(a == 0 && b == 0))fis_duty = 0;
		a = 0, b = 0;						// Logic inputs
		//if(fis_duty > 0.3)fis_duty = 0.3;
		//if(fis_duty < -0.3)fis_duty = -0.3;
		duty = ref/source + fis_duty;		// Duty calculation
		if(invert != 0){
		PORTB |= (1<<PB4) | (1<<PB5);		// SW3 and SW4 relay control
		PORTD &= ~(1<<PD0) & ~(1<<PD1);		// SW1 and SW2 relay control
		}
		else{
		PORTB &= ~(1<<PB4) & ~(1<<PB5);		// SW3 and SW4 relay control
		PORTD |= (1<<PD0) | (1<<PD1);		// SW1 and SW2 relay control
		}
	}
	// Buck-Boost Mode
	else if(hold > 0.8){
		if(!(a == 0 && b == 1))fis_duty = 0;
		a = 0, b = 1;					 		// Logic inputs
		if(fis_duty > 0.2)fis_duty = 0.2;
		if(fis_duty < -0.2)fis_duty = -0.2;
		duty = ref/(ref + source) + fis_duty; 	// Duty calculation
		PORTB |= (1<<PB4) | (1<<PB5);    		// SW3 and SW4 relay control
		PORTD |= (1<<PD0) | (1<<PD1);    		// SW1 and SW2 relay control
	}
	// Boost Mode
	else if(hold <= 0.8){
		if(!(a == 1 && b == 1))fis_duty = 0;
		a = 1, b = 1;							// Logic inputs
		//if(fis_duty > 0.3)fis_duty = 0.3;
		//if(fis_duty < -0.3)fis_duty = -0.3;
		duty = (ref - source)/ref + fis_duty;   // Duty calculation
		PORTB |= (1<<PB4) | (1<<PB5);   		// SW3 and SW4 relay control
		PORTD &= ~(1<<PD0) & ~(1<<PD1); 		// SW1 and SW2 relay control
	}
	// Duty compensation
	//duty = duty + fis_duty;
	if(duty > 0.8)duty = 0.8;
	if(duty < 0.2)duty = 0.2;
	// PWM control
	OCR1A = 1599*duty;	// Base PWM
	OCR1B = OCR1A;		// Complement PWM
}
//--------------------------------------------------------------