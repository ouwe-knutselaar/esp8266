#include <Adafruit_NeoPixel.h>

#define NUM_OF_LEDS 50
#define SPEED 1
#define MAXVAL 80
#define MINVAL 0
#define MAXSTEP 10

Adafruit_NeoPixel pixels(NUM_OF_LEDS, 2, NEO_GRB + NEO_KHZ800);

int current_value = 0;
int brightness = 0;
bool LOG=false;

void setup() {
  pixels.begin(); 
  if(LOG)Serial.begin(115200);
}

void loop() {
  log("Light up");
  light_up(random(50),random(MAXSTEP));
  
  log("Light down");
  light_down(random(50),random(MAXSTEP));
}



void light_up(int new_value, int timestep){
  int target_value=current_value + new_value;
  if(target_value > MAXVAL)target_value=MAXVAL;
  log("target "+String(target_value));
  
  while(current_value < target_value){
    set_flame(current_value);
    delay(timestep);
    current_value++;
    log("current value  "+String(current_value));
    if(current_value>MAXVAL)return;
  }
}


void light_down(int new_value, int timestep){
  int target_value = current_value - new_value;
  if(target_value < MINVAL )target_value=MINVAL;
  log("target "+String(target_value));

  while(current_value > target_value){
    set_flame(current_value);
    delay(timestep);
    current_value--;
    log("current value  "+String(current_value));
    if(current_value<MINVAL)return;
  }
}

void set_flame(int value){
  pixels.fill(pixels.Color(100+value,20+(value/5),0),0,50);  
  pixels.show(); 
}


void log(String msg){
  if(LOG)Serial.println(msg); 
}
