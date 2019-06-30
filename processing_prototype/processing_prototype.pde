import processing.serial.*;
import ddf.minim.*;
import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.KeyEvent;
 
Robot robot;

Minim minim;
AudioSample song;
Serial myPort;  
String val;     
String song_name;
int number=1;

PFont f;

Robot r;

void setup()
{
  try{
  r= new Robot();
  }
   catch (AWTException e)
    {
    e.printStackTrace();
    }
  myPort = new Serial(this, "COM5", 9600); 
  size(840,440);
  background(127,0,0);
  f = createFont("Arial",40,true); 
  minim = new Minim(this);
  stroke(204, 102, 50);
  strokeWeight(3);
  
}
                                                                                                                                                    
//
void draw()
{
  background(127,0,0);

  
  fill(250,250,250);
  
  val = myPort.readStringUntil('\n');  
  
  if(val!=null)
  {
    number=Integer.parseInt(val.trim());
    println(number);
  }
  
  if(number==1){
    r.keyPress(KeyEvent.VK_A);
  }
  else r.keyRelease(KeyEvent.VK_A);
  
  if(number==2){
    r.keyPress(KeyEvent.VK_S);
  }
  else r.keyRelease(KeyEvent.VK_S);
  
  if(number==3){
    r.keyPress(KeyEvent.VK_D);
  }
  else r.keyRelease(KeyEvent.VK_D);
  
  if(number==4){
    r.keyPress(KeyEvent.VK_Q);
  }
  else r.keyRelease(KeyEvent.VK_Q);
  //
  number=0;

}