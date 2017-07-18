      
/* This is a modification of code found at http://jamesonchrome.blogspot.com/2015/08/version-44-code-with-ctrl-alt-e.html to make use of a Teensy 3.2s and Teensy-LC for automated chromebook enrollment
   The modification handles all enrollment screens as of ChromeOS 54.*. The code does not however enter WiFi information as the expectation is
   that the Chromebook will be attached to ethernet for enrollment. WiFi info will be supplied by policy. 
   
   Depending on your network speed or other factors you may need to tweek the delay settings. These are the settings that I found in my envirmoment allowed enough time for screens to process 
   but not to much time you are waiting forever. You mus change the username and password in the code - lines 58 and 66
*/

#include <Bounce.h>

//Pin the button is attached to as well as the Red and Green leads on the LED
const int buttonPin = 2;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;


// Instantiate a Bounce object
Bounce button0 = Bounce(buttonPin, 10); 

void setup() {
  //Give the Chromebook time to register keyboard.
  delay(2000);
    
  //Set red and green pins to output. 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  ;

  //digitalWrite(buttonPower,HIGH);
  // Setup the button with an internal pull-up :
  pinMode(buttonPin, INPUT_PULLUP); //

  //Initialize LED to Green.
  setColor(0,255,0);
  
}

void loop() {
 
  // Update the Bounce instance :
  button0.update();

  //If button is not pressed set color of led to green (green means go). When pressed set color to red and peform runSteps();
  if (button0.risingEdge() ) {
    setColor(0,255,0);  
    }
  
  //If button is pressed set color of led to red (red means stop).    
  if (button0.fallingEdge()){       
      setColor(255,0,0);
      runSteps();
      }
}
  
//Sets color of LED
void setColor(int red, int green, int blue){
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void runSteps(){
//Welcome Screen******************************
delay(200);
Keyboard.set_key1(KEY_TAB); //the next for lines tell the computer to send the TAB key
Keyboard.send_now();
Keyboard.set_key1(0);  //these next two lines tell the comuputer to stop sending the TAB key
Keyboard.send_now();
delay(200);
Keyboard.set_key1(KEY_TAB); //the next for lines tell the computer to send the TAB key
Keyboard.send_now();
Keyboard.set_key1(0);  //these next two lines tell the comuputer to stop sending the TAB key
Keyboard.send_now();
delay(200);
Keyboard.set_key1(KEY_TAB); //the next for lines tell the computer to send the TAB key
Keyboard.send_now();
Keyboard.set_key1(0);  //these next two lines tell the comuputer to stop sending the TAB key
Keyboard.send_now();
delay(200);
Keyboard.set_key1(KEY_ENTER); //the next for lines tell the computer to send the Enter key
Keyboard.send_now();
Keyboard.set_key1(0);  //these next two lines tell the comuputer to stop sending the Enter key
Keyboard.send_now();
delay(5000);

//Chrome OS TERMS**************
Keyboard.set_key1(KEY_ENTER); //the next for lines tell the computer to send the Enter key
Keyboard.send_now();
Keyboard.set_key1(0);  //these next two lines tell the comuputer to stop sending the Enter key
Keyboard.send_now();
delay(5000);
  
//Sign In Screen (Enrollment Keys)**************************
Keyboard.set_modifier(MODIFIERKEY_CTRL); // press and hold CTRL
Keyboard.send_now();
Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT); // press ALT while still holding CTRL
Keyboard.send_now();
Keyboard.set_key1(KEY_E); // press E, while CLTR and ALT still held
Keyboard.send_now();
Keyboard.set_modifier(0); // release all the keys at the same instant
Keyboard.set_key1(0);
Keyboard.send_now();
delay(5000);

//Username screen*********************
Keyboard.print("YOURUSERNAME"); //types username
Keyboard.set_key1(KEY_ENTER); //the next for lines tell the computer to send the Enter key
Keyboard.send_now();
Keyboard.set_key1(0);  //these next two lines tell the comuputer to stop sending the Enter key
Keyboard.send_now();
delay(5000);
  
//Password Screen*********************   
Keyboard.print("YOURPASSWORD"); //types password
Keyboard.set_key1(KEY_ENTER); //the next for lines tell the computer to send the Enter key
Keyboard.send_now();
Keyboard.set_key1(0);  //these next two lines tell the comuputer to stop sending the Enter key
Keyboard.send_now();
delay(5000);

//Asset Screen*********************
Keyboard.set_key1(KEY_ENTER); //the next for lines tell the computer to send the Enter key
Keyboard.send_now();
Keyboard.set_key1(0);  //these next two lines tell the comuputer to stop sending the Enter key
Keyboard.send_now();
delay(200);

//Success Screen*********************
Keyboard.set_key1(KEY_ENTER); //the next for lines tell the computer to send the Enter key
Keyboard.send_now();
Keyboard.set_key1(0);  //these next two lines tell the comuputer to stop sending the Enter key
Keyboard.send_now();

}

/*Click your mouse cursor here when uploadingotherwise the teensy will type into your code
                      
*/
