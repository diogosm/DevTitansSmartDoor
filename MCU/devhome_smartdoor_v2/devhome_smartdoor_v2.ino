#define MODE_MANUAL 0
#define MODE_AUTO 1

int relay = 16;
int relaychannel = 0;
int relaymode = MODE_MANUAL;

int thresholdValue= 50;

void setup(){
  Serial.begin(9600);



  pinMode(relay, OUTPUT);
  //ledcSetup(relaychannel, 5000, 8);
  //ledcAttachPin(relay, relaychannel);
  digitalWrite(relay, LOW);
  
  Serial.printf("DBG SmartLamp Initialized.\n");
  
}


void loop() {
    String serialCommand;

    while (Serial.available() > 0) {
        char serialChar = Serial.read();
        serialCommand += serialChar; 

        if (serialChar == '\n') {
            processCommand(serialCommand);
            serialCommand = "";
        }
    }

    //ledUpdate();
    delay(100);
}

void processCommand(String command) {
    command.trim();
    command.toUpperCase();

    // Serial.println("DBG Received command: " + command);

    if (command.startsWith("set-door ")) {
        int ledTmp = command.substring(8).toInt();
        if (ledTmp) {
            digitalWrite(relay, HIGH);
            Serial.printf("RES SET_DOOR 1\n");
        }else{
          digitalWrite(relay, LOW);
          Serial.printf("RES SET_DOOR 0\n");
        }
    }else if (command == "get-door "){
      //@todo
    }
}
