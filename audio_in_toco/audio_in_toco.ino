#define AUDIO_IN A1
#define CALIBRATION_SAMPLES 200

float sensor = 0;
int calibration = 0;
float calibration_avg = 0.;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  if (calibration < CALIBRATION_SAMPLES) {
    calibration_avg = ((calibration_avg * calibration) + analogRead(AUDIO_IN)) /
                                           ++calibration;
    //Serial.print("Calibrating steps left: ");
    //Serial.println((CALIBRATION_SAMPLES - calibration));
    
  } else {
    sensor = (analogRead(AUDIO_IN) - calibration_avg);                    
    Serial.println(int(sensor));
    delay(10);
  }
}
