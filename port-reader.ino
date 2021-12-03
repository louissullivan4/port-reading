#define red 11
#define green 12
void setup() {
  // initialise pinmodes and port d
  Serial.begin(9600);
  PIND = 0b00000000;     
  pinMode(green,OUTPUT);   
  pinMode(red,OUTPUT); 
  }  
  void loop() 
  {
    // read in Port D 
    unsigned char first_read = PIND;
    unsigned char second_read = PIND;
    //Right shift 1, if 1 and 1, output is 1 else is 0
    int adjacent_zero = (first_read | (first_read >> 1));
    //Right shift 1, if 1 and 1, output is 1 else is 0
    int adjacent_one = (second_read & (second_read >> 1));
    Serial.println(PIND);
    // if two adjacents pins are high and another two are low both lights are on
    if ((adjacent_zero > 0) && (adjacent_one > 0)){     
      digitalWrite(green,HIGH);
      digitalWrite(red,HIGH); 
      }
     // if two adjacents pins are high and no other adjacent pins are low, turn on red light only
    else if (!(adjacent_one > 0)){
        digitalWrite(green,LOW);
    }
    // if two adjacents pins are low and no other adjacent pins are high, turn on green light only
    else if (!(adjacent_zero > 0)){
        digitalWrite(red,LOW);
    }
}
