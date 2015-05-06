#define AUDIO_IN A1
#define CALIBRATION_SAMPLES 200
#define RED 12
#define GREEN 10

float sensor = 0;
int prev = 0;
int calibration = 0;
float calibration_avg = 0.;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  if (calibration < CALIBRATION_SAMPLES) {
    sensor = analogRead(AUDIO_IN);
    calibration_avg = abs((calibration_avg * calibration) + (sensor - prev)) /
                                           ++calibration;
    prev = sensor;
    //Serial.print("Calibrating steps left: ");
    //Serial.println((CALIBRATION_SAMPLES - calibration));
    
  } else {
    sensor = int(analogRead(AUDIO_IN) - prev);                    
    Serial.println(int(sensor));
    if(abs(sensor) > calibration_avg/4) {
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);  
    } else {
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, HIGH);  
    }
    //delay(10);
  }
}
