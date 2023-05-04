
int pin6Value = 0;
int pin7Value = 0;
int pin8Value = 0;
int computerChoice = 0;

void setup() {
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);

    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);

    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    // Serial.begin(9600);
}

void loop() {
    initOutput();

    pin6Value = LOW;
    pin7Value = LOW;
    pin8Value = LOW;

    while (pin6Value == LOW && pin7Value == LOW && pin8Value == LOW) {
        pin6Value = digitalRead(6);
        pin7Value = digitalRead(7);
        pin8Value = digitalRead(8);
        // Serial.println("waiting");
    }
    
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    computerChoice = random(1, 4);

    if (computerChoice == 1) {
        digitalWrite(2, HIGH);
    } else if (computerChoice == 2) {
        digitalWrite(1, HIGH);
    } else {
        digitalWrite(0, HIGH);
    }

    if ((computerChoice == 1 && pin8Value == HIGH) || (computerChoice == 2 && pin6Value  == HIGH) || (computerChoice == 3 && pin7Value  == HIGH)) {
        digitalWrite(4, HIGH);
    } else if ((computerChoice == 1 && pin6Value  == HIGH) || (computerChoice == 2 && pin7Value  == HIGH) || (computerChoice == 3 && pin8Value  == HIGH)) {
        digitalWrite(3, HIGH);
    } else {
         digitalWrite(5, HIGH);
    }

    delay(3000);
}

void initOutput() {
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
}
