#define MODE_MANUAL 0
#define MODE_AUTO 1

int relay = 16;
int relaychannel = 0;
int relaymode = MODE_MANUAL;
int relayvalue = 0;

int thresholdValue= 0;

void setup(){
  Serial.begin(9600);



  pinMode(relay, OUTPUT);
  //ledcSetup(relaychannel, 5000, 8);
  //ledcAttachPin(relay, relaychannel);
  digitalWrite(relay, LOW);
  
  Serial.printf("DBG SmartDoor Initialized.\n");
  
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

    if (command.startsWith("set-door")) {
        int relaytmp = command.substring(8).toInt();
        if (relaytmp == 1 ) {
            relayvalue = relaytmp;
            relaymode = MODE_MANUAL;
            digitalWrite(relay, HIGH);
            Serial.printf("RES SET-DOOR 1\n");
        }else{
          digitalWrite(relay, LOW);
          Serial.printf("RES SET-DOOR 0\n");
        }
    } else if (command == "get-door ")
    Serial.printf("RES GET-DOOR %d\n",relayvalue);
      else
    Serial.println("ERR UNKNOWN COMMAND");
}
