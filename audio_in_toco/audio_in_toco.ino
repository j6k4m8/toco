#define AUDIO_IN A1
#define CALIBRATION_SAMPLES 200
#define RED 12
#define GREEN 10

float sensor = 0;
int calibration = 0;
float calibration_avg = 0.;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  if (calibration < CALIBRATION_SAMPLES) {
    calibration_avg = ((calibration_avg * calibration) + analogRead(AUDIO_IN)) /
                                           ++calibration;
    //Serial.print("Calibrating steps left: ");
    //Serial.println((CALIBRATION_SAMPLES - calibration));
    
  } else {
    sensor = int(analogRead(AUDIO_IN) - calibration_avg);                    
    Serial.println(sensor);
    if(sensor != 0) {
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);  
    } else {
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, HIGH);  
    }
    delay(10);
  }
}
