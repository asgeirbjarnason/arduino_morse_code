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

// --autogen--
void morse_a() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_b() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_c() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_d() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_e() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_f() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_g() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_h() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_i() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_j() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &dash; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_k() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_l() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_m() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_n() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_o() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dash; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_p() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_q() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_r() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_s() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};
void morse_t() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_u() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_v() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_w() { token_count = 0; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_x() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_y() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &dash; tokens[token_count++] = &dash; tokens[token_count++] = &interletter;};
void morse_z() { token_count = 0; tokens[token_count++] = &dash; tokens[token_count++] = &dash; tokens[token_count++] = &dot; tokens[token_count++] = &dot; tokens[token_count++] = &interletter;};


void (*alphabet[])() = { &morse_a, &morse_b, &morse_c, &morse_d, &morse_e, &morse_f, &morse_g, &morse_h, &morse_i, &morse_j, &morse_k, &morse_l, &morse_m, &morse_n, &morse_o, &morse_p, &morse_q, &morse_r, &morse_s, &morse_t, &morse_u, &morse_v, &morse_w, &morse_x, &morse_y, &morse_z };
// --autogen--

void morse(char* text) {
  for (char* t = text; *t != 0; t++) {
    char c = *t;
    if (char2index(c)) {
      (*alphabet[c])();
    }
    else {
      interword(); // We will assume everything outside the [A-Za-z] range is whitespace.
    }
    interletter();
  }
}

boolean char2index(char& c) {
  if (c >= 'a' && c <= 'z') { c -= 'a' - 'A'; } // If the letter is in the lowercase range, we will translate it to lowercase.
  if (!(c >= 'A' && c <= 'Z')) { return false; } // If it isn't in lowercase now, then it isn't a letter.
  c -= 'A'; // A is the zeroth index in the func array.
  return true;
}

// the loop routine runs over and over again forever:
void loop() {
  char* input = "sos ";
  morse(input);
}


