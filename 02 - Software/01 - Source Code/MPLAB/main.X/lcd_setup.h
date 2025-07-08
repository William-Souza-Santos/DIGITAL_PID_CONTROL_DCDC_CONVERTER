//--------------------------------------------------------------
void lcd_setup(){
	// Define pins as output
	DDRD |= (1<<PD2) | (1<<PD3);		// E (D2), RS (D3)
	DDRD |= (1<<PD4) | (1<<PD5) | (1<<PD6) | (1<<PD7);	// Data path
	
	// Initializes the LCD
	inic_LCD_4bits();				// From "LCD.h" header
	cmd_LCD(0x01,0);				// Clear the LCD
}
//--------------------------------------------------------------
void lcd_sub(){
	char buffer[6] = "";
	
	sprintf(buffer, "%.1f", ref);
	cmd_LCD(0x80,0);
	escreve_LCD(buffer);
	
	sprintf(buffer, "%.1f", source);
	cmd_LCD(0x85,0);
	escreve_LCD(buffer);
	
	cmd_LCD(0x8A,0);
	if(!b)escreve_LCD("-");
	else if(a)escreve_LCD("+");
	else escreve_LCD("*");
	
	sprintf(buffer, "%.1f", output);
    cmd_LCD(0x8C,0);
	escreve_LCD(buffer);
	
	sprintf(buffer, "%.1f", error);
    cmd_LCD(0xC0,0);
	escreve_LCD(buffer);
	
	sprintf(buffer, "%.2f", fis_duty);
    cmd_LCD(0xC5,0);
	escreve_LCD(buffer);
	
	sprintf(buffer, "%.2f", duty);
    cmd_LCD(0xCB,0);
	escreve_LCD(buffer);
}
//--------------------------------------------------------------