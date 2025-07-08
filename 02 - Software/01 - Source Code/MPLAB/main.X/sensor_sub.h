//--------------------------------------------------------------
void sensor_sub(){
	x[0] = le_ADC(0);		// Read analogic pin A0
	x[1] = le_ADC(1);		// Read analogic pin A1
	x[2] = le_ADC(2);		// Read analogic pin A2
	
	// Decodifies true range of variables
    ref = (x[0]*49)/1023.0 + 6;			
	source = (x[1]*12)/1023.0 + 18;
	output = (x[2]*55)/1023.0;
}
//--------------------------------------------------------------