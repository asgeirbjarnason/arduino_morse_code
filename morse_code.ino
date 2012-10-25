// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

const int DOT_TIME = 100;
const int DASH_TIME = DOT_TIME * 3;
const int INTRALETTER_WAITTIME = DOT_TIME;
const int INTERLETTER_WAITTIME = DOT_TIME * 2; // We will already have waited one DOT_TIME, because of the INTRALETTER_WAITTIME
const int INTERWORD_WAITTIME = DOT_TIME * 4; // See above for why this is not DOT_TIME * 7


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

void off(int time) {
  digitalWrite(led, LOW);
  delay(time);
}

void cycle(int ontime, int offtime) {
  digitalWrite(led, HIGH);
  delay(ontime);
  digitalWrite(led, LOW);
  delay(offtime);
}

void dot() {
  cycle(DOT_TIME, INTRALETTER_WAITTIME);
}

void dash() {
  cycle(DASH_TIME, INTRALETTER_WAITTIME);
}

void interletter() {
  off(INTERLETTER_WAITTIME);
}

void interword() {
  off(INTERWORD_WAITTIME);
}

void repeat(int times, void (*fp)(void)) {
  for (int i = 0; i < times; i++) {
    (*fp)();
  }
}

void (*alphabet[])() = {  &a, &c, &b, &e, &d, &g, &f, &i, &h, &k, &j, &m, &l, &o, &n, &q, &p, &s, &r, &u, &t, &w, &v, &y, &x, &z  };

void a() { dot(); dash(); interletter(); }
void b() { dash(); dot(); dot(); dot(); interletter(); }
void c() { dash(); dot(); dash(); dot(); interletter(); }
void d() { dash(); dot(); dot(); interletter(); }
void e() { dot(); interletter(); }
void f() { dot(); dot(); dash(); dot(); interletter(); }
void g() { dash(); dash(); dot(); interletter(); }
void h() { dot(); dot(); dot(); dot(); interletter(); }
void i() { dot(); dot(); interletter(); }
void j() { dot(); dash(); dash(); dash(); interletter(); }
void k() { dash(); dot(); dash(); interletter(); }
void l() { dot(); dash(); dot(); dot(); interletter(); }
void m() { dash(); dash(); interletter(); }
void n() { dash(); dot(); interletter(); }
void o() { dash(); dash(); dash(); interletter(); }
void p() { dot(); dash(); dash(); dot(); interletter(); }
void q() { dash(); dash(); dot(); dash(); interletter(); }
void r() { dot(); dash(); dot(); interletter(); }
void s() { dot(); dot(); dot(); interletter(); }
void t() { dash(); interletter(); }
void u() { dot(); dot(); dash(); interletter(); }
void v() { dot(); dot(); dot(); dash(); interletter(); }
void w() { dot(); dash(); dash(); interletter(); }
void x() { dash(); dot(); dot(); dash(); interletter(); }
void y() { dash(); dot(); dash(); dash(); interletter(); }
void z() { dash(); dash(); dot(); dot(); interletter(); }

void sos() {
  repeat(3, &dot);
  interletter();
  repeat(3, &dash);
  interletter();
  repeat(3, &dot);
  off(1000);
}

// the loop routine runs over and over again forever:
void loop() {
  sos();
}
