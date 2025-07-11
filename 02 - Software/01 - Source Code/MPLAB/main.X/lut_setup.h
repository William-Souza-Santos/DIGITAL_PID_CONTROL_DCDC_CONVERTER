//--------------------------------------------------------------
// Define a structure for error-output pairs
typedef struct{
    float error;
    float output;
}error_lu_output;

// Define your lookup table
const error_lu_output lut[] = {
    {-1.000000,  0.085919},
    {-0.984252,  0.085919},
    {-0.968504,  0.085919},
    {-0.952756,  0.085919},
    {-0.937008,  0.085919},
    {-0.921260,  0.085919},
    {-0.905512,  0.085919},
    {-0.889764,  0.085919},
    {-0.874016,  0.085919},
    {-0.858268,  0.085919},
    {-0.842520,  0.085919},
    {-0.826772,  0.085919},
    {-0.811024,  0.085919},
    {-0.795276,  0.085919},
    {-0.779528,  0.085919},
    {-0.763780,  0.085919},
    {-0.748031,  0.085919},
    {-0.732283,  0.085919},
    {-0.716535,  0.085919},
    {-0.700787,  0.085919},
    {-0.685039,  0.085919},
    {-0.669291,  0.085919},
    {-0.653543,  0.085919},
    {-0.637795,  0.085919},
    {-0.622047,  0.085919},
    {-0.606299,  0.085919},
    {-0.590551,  0.085919},
    {-0.574803,  0.085919},
    {-0.559055,  0.085919},
    {-0.543307,  0.085919},
    {-0.527559,  0.085919},
    {-0.511811,  0.085919},
    {-0.496063,  0.085919},
    {-0.480315,  0.085919},
    {-0.464567,  0.085919},
    {-0.448819,  0.085919},
    {-0.433071,  0.085919},
    {-0.417323,  0.084644},
    {-0.401575,  0.080309},
    {-0.385827,  0.074164},
    {-0.370079,  0.068051},
    {-0.354331,  0.062067},
    {-0.338583,  0.056239},
    {-0.322835,  0.050601},
    {-0.307087,  0.045187},
    {-0.291339,  0.040012},
    {-0.275591,  0.035088},
    {-0.259843,  0.030474},
    {-0.244094,  0.026128},
    {-0.228346,  0.022071},
    {-0.212598,  0.018357},
    {-0.196850,  0.014960},
    {-0.181102,  0.012084},
    {-0.165354,  0.009719},
    {-0.149606,  0.007823},
    {-0.133858,  0.006239},
    {-0.118110,  0.004886},
    {-0.102362,  0.003844},
    {-0.086614,  0.002928},
    {-0.070866,  0.002219},
    {-0.055118,  0.001587},
    {-0.039370,  0.001083},
    {-0.023622,  0.000609},
    {-0.007874,  0.000209},
    {0.007874, -0.000209},
    {0.023622, -0.000609},
    {0.039370, -0.001083},
    {0.055118, -0.001587},
    {0.070866, -0.002219},
    {0.086614, -0.002928},
    {0.102362, -0.003844},
    {0.118110, -0.004886},
    {0.133858, -0.006239},
    {0.149606, -0.007823},
    {0.165354, -0.009719},
    {0.181102, -0.012084},
    {0.196850, -0.014960},
    {0.212598, -0.018357},
    {0.228346, -0.022071},
    {0.244094, -0.026128},
    {0.259843, -0.030474},
    {0.275591, -0.035088},
    {0.291339, -0.040012},
    {0.307087, -0.045187},
    {0.322835, -0.050601},
    {0.338583, -0.056239},
    {0.354331, -0.062067},
    {0.370079, -0.068051},
    {0.385827, -0.074164},
    {0.401575, -0.080309},
    {0.417323, -0.084644},
    {0.433071, -0.085919},
    {0.448819, -0.085919},
    {0.464567, -0.085919},
    {0.480315, -0.085919},
    {0.496063, -0.085919},
    {0.511811, -0.085919},
    {0.527559, -0.085919},
    {0.543307, -0.085919},
    {0.559055, -0.085919},
    {0.574803, -0.085919},
    {0.590551, -0.085919},
    {0.606299, -0.085919},
    {0.622047, -0.085919},
    {0.637795, -0.085919},
    {0.653543, -0.085919},
    {0.669291, -0.085919},
    {0.685039, -0.085919},
    {0.700787, -0.085919},
    {0.716535, -0.085919},
    {0.732283, -0.085919},
    {0.748031, -0.085919},
    {0.763780, -0.085919},
    {0.779528, -0.085919},
    {0.795276, -0.085919},
    {0.811024, -0.085919},
    {0.826772, -0.085919},
    {0.842520, -0.085919},
    {0.858268, -0.085919},
    {0.874016, -0.085919},
    {0.889764, -0.085919},
    {0.905512, -0.085919},
    {0.921260, -0.085919},
    {0.937008, -0.085919},
    {0.952756, -0.085919},
    {0.968504, -0.085919},
    {0.984252, -0.085919},
    {1.000000, -0.085919}
};

const uint8_t lut_size = sizeof(lut)/sizeof(error_lu_output);
//--------------------------------------------------------------
void fis_output(){
	float lu_output, hold;
	
    // Check if error is below minimum
    if(error <= lut[0].error) {
        lu_output = lut[0].output;
    }
    // Check if error is above maximum
    if(error >= lut[lut_size-1].error){
        lu_output = lut[lut_size-1].output;
    }
    // Find the interval where the error lies
    for(uint8_t i=0;i<lut_size-1;i++){
        if (error >= lut[i].error && error <= lut[i+1].error){
            // Linear interpolation
            float error_0 = lut[i].error;
            float error_1 = lut[i+1].error;
            float output_0 = lut[i].output;
            float output_1 = lut[i+1].output;
            
            lu_output = output_0 + (error - error_0)*(output_1 - output_0)/(error_1 - error_0);
        }
    }
	hold = lu_output*0.1;
	fis_duty += hold;
}
//--------------------------------------------------------------