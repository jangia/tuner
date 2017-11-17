float freq;
int lastBit;
int nowVal;
float start_t;
float stop_t;
int cnt;
int thr_up;
int thr_down;
int avg;
int avg_cnt;
int cnt_max;
int E;
int A;
int D;
int G;
int B;
int E_h;
int now_t;
float act_frq;
void setup() {
  // Print a message to the LCD.
  Serial.begin(9600);
  Serial.println("Started");
  delay(2000);
  pinMode(A1,INPUT);
  pinMode(3, OUTPUT);
  tone(3, 10);
  cnt = 0;
  freq = 0;
  thr_up = 580;
  thr_down = 578;
  start_t = millis();
  avg = 4;
  avg_cnt=0;
  cnt_max = 50;
  lastBit=0;
  E = 78;
  A = 104;
  D = 139;
  G = 185;
  B = 233;
  E_h = 311;
  act_frq = 0;
}
int x=0;
void loop() {

  nowVal = analogRead(A1);
  //Serial.println(nowVal);
  //delay(100);
  if (nowVal > thr_up && lastBit <= thr_up) {
    
    //Serial.println(nowVal);
    cnt++;
    lastBit=nowVal;
  }
  else if (nowVal < thr_down && lastBit >= thr_down){
    //Serial.println(nowVal);
    cnt++;
    lastBit=nowVal;
  }

  if (cnt == cnt_max){
    stop_t = millis();
    //Serial.println(stop_t);
    //Serial.println(start_t);
    //Serial.println(500*cnt/(stop_t-start_t));

    freq = freq + 500*cnt/(stop_t-start_t);
    //Serial.println(freq);
    avg_cnt++;
    cnt = 0;
    start_t = millis();
  }
  
  if (avg_cnt == avg){
    act_frq = freq/(avg);
    if (act_frq > 155 && act_frq < 170){
      Serial.println((2 * act_frq));
      act_frq = 2 * act_frq;
    }
    else {
      Serial.println((act_frq));
    }

    // E
    if (act_frq > 0.8 * E && act_frq < 1.2 * E) {
      Serial.println(("E"));
      now_t = E;
    }
    
    // A
    if (act_frq > 0.8 * A && act_frq < 1.2 * A) {
      Serial.println(("A"));
      now_t = A;
    }

    // D
    if (act_frq > 0.8 * D && act_frq < 1.2 * D) {
      Serial.println(("D"));
      now_t = D;
    }

    // G
    if (act_frq > 0.8 * G && act_frq < 1.2 * G) {
      Serial.println(("G"));
      now_t = G;
    }
    
    // B
    if (act_frq > 0.8 * B && act_frq < 1.2 * B) {
      Serial.println(("B"));
      now_t = B;
    }

    // E_h
    if (act_frq > 0.8 * E_h && act_frq < 1.2 * E_h) {
      Serial.println(("E2"));
      now_t = E_h;
    }

    // all
    if (act_frq > 0.9 * now_t && act_frq < 1.1 * now_t) {
      Serial.println(("OK"));
    }



    freq=0;
    avg_cnt=0;
      
  }

}
