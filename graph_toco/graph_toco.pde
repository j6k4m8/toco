import processing.serial.*;
import java.sql.Timestamp;
import java.util.Date;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port
float left = 0;
float last = 0;
PrintWriter writer;
long seconds;
long current_seconds;

void setup() 
{
    size(1400, 400);
    myPort = new Serial(this, Serial.list()[7], 9600);
    System.out.println(Serial.list()[7]);
    
    Date date= new java.util.Date();
    String ts = new Timestamp(date.getTime()).toString();
    
    String trial = "B";
    
    seconds = System.currentTimeMillis() / 1000;
    
    try {
      writer = new PrintWriter("Google Drive/toco-master/data/trial " + trial + " " + ts + ".txt","UTF-8");
    } catch (Exception e) { 
      e.printStackTrace();
    }
}

void draw() {
  
}

void serialEvent(Serial myPort) {
    //val = myPort.read()*20 - 800;
    val = myPort.read();
    
    try { 
      writer.println(val);
      //writer.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
    val = val*20 - 800;
    line(left, height - last, left+=0.5, height - val);
    
    last = val;
    //System.out.println(last);
    
    if (left >= width) {
        background(255);
        left = 0;
    }
    
    current_seconds = System.currentTimeMillis() / 1000;
    
    if(current_seconds - seconds > 180) {
      writer.close();
      exit();
    }
    if((current_seconds - seconds)%2 == 0)
      System.out.println(current_seconds - seconds);
}

