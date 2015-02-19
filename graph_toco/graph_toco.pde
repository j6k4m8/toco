import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port
int left = 0;
float last = 0;

void setup() 
{
    size(800, 400);
    String portName = Serial.list()[0];
    myPort = new Serial(this, portName, 9600);
}

void serialEvent(Serial myPort) {
    val = myPort.read();
    
    line(left, height - last, left++, height - val);
    
    last = val;
    System.out.println(last);
   
    if (left >= width) {
        background(255);
        left = 0;
    }
}

