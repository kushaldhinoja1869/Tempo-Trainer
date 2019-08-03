


const int output_pin = 13;         //output to the buzzer
const int plus_button_pin = 2;         //input pin for plus button
const int minus_button_pin = 3;        //input pin for minus button
const int start_button_pin = 4;        //input pin for start button
int timerlocal = 1000;                    //set the timer to 1000 ms
bool previous_state_plus = LOW;           //initialize previous state of the plus button to low 
bool previous_state_minus = LOW;          //initialize previous state of the minus button to low



void setup() {
  pinMode(output_pin, OUTPUT);                       //set pin 13 as the output to the buzzer
  pinMode(plus_button_pin, INPUT);                   //set pin 2 as the input of plus button
  pinMode(minus_button_pin, INPUT);                  //set pin 3 as the input of minus button     
  pinMode(start_button_pin, INPUT);                  //set pin 4 as the input of start/stop switch

}

void loop() {
  if (digitalRead(plus_button_pin) == HIGH && previous_state_plus == LOW) {
    delay(20);
    if (digitalRead(plus_button_pin) == HIGH) {
      if(timerlocal<5000){timerlocal += 100;}
      previous_state_plus = HIGH;
    }
  }
  if (digitalRead(plus_button_pin) == LOW && previous_state_plus == HIGH) {
    delay(20);
    if (digitalRead(plus_button_pin) == LOW) {
      previous_state_plus = LOW;
    }
  }
  if (digitalRead(minus_button_pin) == HIGH && previous_state_minus == LOW) {
    delay(20);
    if (digitalRead(minus_button_pin) == HIGH) {
      if(timerlocal>100){timerlocal -= 100;}
      previous_state_minus = HIGH;
    }
  }
  if (digitalRead(minus_button_pin) == LOW && previous_state_minus == HIGH) {
    delay(20);
    if (digitalRead(plus_button_pin) == LOW) {
      previous_state_minus = LOW;
    }
  }


  if (digitalRead(start_button_pin) == HIGH) {
    while (1) {
      digitalWrite(output_pin, HIGH);
      delay(10);
      digitalWrite(output_pin, LOW);
      delay(timerlocal - 10);
      if (digitalRead(start_button_pin) == LOW) {
        break;
      }
    }
  }
}


