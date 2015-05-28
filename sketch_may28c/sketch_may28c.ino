const int TRIG_1 = 2;
const int ECHO_1 = 3;
const int TRIG_2 = 4;
const int ECHO_2 = 5;

int lastProbe = -1;

void setup() {
  pinMode(TRIG_1, OUTPUT);
  pinMode(ECHO_1, INPUT);
  pinMode(TRIG_2, OUTPUT);
  pinMode(ECHO_2, INPUT);
  digitalWrite(TRIG_1, LOW);
  digitalWrite(TRIG_2, LOW);
  Serial.begin(9600);
}

void loop() {
  int delay1;
  int delay2;
  digitalWrite(TRIG_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_1, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIG_1, LOW);
  
  delay1 = pulseIn(ECHO_1, HIGH);
  
  digitalWrite(TRIG_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_2, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIG_2, LOW);
  
  delay2 = pulseIn(ECHO_2, HIGH);
  
  if (delay1 > 800 && delay2 > 800) {
    Serial.println("Away");
  } else if (delay1 < delay2) {
    Serial.println("Near delay 1");
  } else {
    Serial.println("Near delay 2");
  } 
}
