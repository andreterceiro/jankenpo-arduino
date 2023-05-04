
int pin6Value = 0;
int pin7Value = 0;
int pin8Value = 0;
int computerChoice = 0;

void setup() {
    // First RGB LED - computer choice
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);

    // Second RGB LED - show who is the winner
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);

    // User choice - buttons
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
}

void loop() {
    initOutput();

    pin6Value = LOW;
    pin7Value = LOW;
    pin8Value = LOW;

    // Waiting the user input
    while (pin6Value == LOW && pin7Value == LOW && pin8Value == LOW) {
        // Reading the user INPUT
        pin6Value = digitalRead(6);
        pin7Value = digitalRead(7);
        pin8Value = digitalRead(8);
    }
    
    // The 2 LEDs are off in the start
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    computerChoice = random(1, 4);

    // Writing the first RGB LED -computer choice
    if (computerChoice == 1) {
        digitalWrite(2, HIGH);
    } else if (computerChoice == 2) {
        digitalWrite(1, HIGH);
    } else {
        digitalWrite(0, HIGH);
    }

    // Writing who is the winner - the second LED
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
    // Before user press a button, we set off all the colors of the first RGB LED
    // and set white all the colors of the second RGB LED
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
}
