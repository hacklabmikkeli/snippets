const int DETECT_DIST = 100;
const int TRIG_TIMEOUT = 3000;

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
  
  unsigned long currentMillis = millis();
  
  int dist1;
  int dist2;
  digitalWrite(TRIG_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_1, LOW);
  
  dist1 = pulseIn(ECHO_1, HIGH) / 58.2;
  
  digitalWrite(TRIG_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_2, LOW);
  
  dist2 = pulseIn(ECHO_2, HIGH) / 58.2;
  
  if(dist1 > DETECT_DIST && dist2 > DETECT_DIST && lastProbe > -1){
    lastProbe = -1;
    directionFound = false;
  }
  
  if (dist1 < DETECT_DIST) {
    if(lastProbe < 0){
      lastProbe = 0;
      echo1Activated = 
    }else if(lastProbe == 1){
      Serial.println("Left");
      directionFound = true;
    }
  } 
  if(dist2 < DETECT_DIST) {
    if(lastProbe < 0){
      lastProbe = 1;
    }else if(lastProbe == 0){
      Serial.println("Right");
      directionFound = true;
    }
  }
}
