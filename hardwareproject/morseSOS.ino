int button1 = 3;
int button2 = 4;
boolean led = false;
int delayms = 1;

int holdtime = 0;
String output = "";

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the button1's pin an input:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(13, OUTPUT);
  led = false;
  digitalWrite(13, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(button1);
  if(buttonState == 1)
  {
    holdtime += delayms;
      if(led == false)
      {
         digitalWrite(13, HIGH);
         led = true;
      }
  }
  else if(buttonState == 0)
  {
     if(led == true)
     {
      digitalWrite(13, LOW);
      led = false; 
      if(holdtime > 300)
        output += "-";
      else
        output += ".";
       holdtime = 0;
      }
      if(output != "" && digitalRead(button2) == 1)
      {
        Serial.println("Output:");
        Serial.println(output);
        if(output == "...---...")
          Serial.println("SOS!");
        output = "";
      }
  }
  delay(delayms);
}
