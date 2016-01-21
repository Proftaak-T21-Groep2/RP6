/*-----( Import needed libraries )-----*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN   9
#define CSN_PIN 10
/*-----( Communication Protocol )-----*/
typedef struct {
   int commandType;
   int param1;
   char param2[9];
   int param3;
} COMMAND;

#define COMMAND_MOVE_TO_PUMP 1
#define COMMAND_START_FUELING 2
#define COMMAND_PAYMENT_COMPLETE 3
#define COMMAND_MOVE_TO_EXIT 4
#define COMMAND_ARRIVED_AT_PUMP 5
#define COMMAND_FINISHED_FUELING 6
/*-----( Communication Pipes )-----*/
const uint64_t pipeTX = 0xE8E8F0F0D2LL; // Define the transmit pipe
const uint64_t pipeRX = 0xE8E8F0F0E1LL; // Define the receive pipe

const char[] numberPlate = {'A','B','-','1','2','C','D'};

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

COMMAND received_command;
COMMAND command_to_send;

void sendCommand()
{
  radio.stopListening();
  radio.write(&command_to_send, sizeof(COMMAND));
  radio.startListening();
}

bool checkNumberplate(){
  for(int i = 0
}

void receiveCommand()
{
  if(radio.available()){
     radio.read(&received_command, sizeof(COMMAND));
     Serial.print("{");
     Serial.print("\n\tCommandType: "); Serial.print(received_command.commandType);
     Serial.print("\n\tP1: "); Serial.print(received_command.param1);
     Serial.print("\n\tP2: "); Serial.print(received_command.param2);
     Serial.print("\n\tP3: "); Serial.print(received_command.param3);
     Serial.println("\n}");
     
     if(received_command.param2[0] == 'D' && received_command.param2[1] == 'A'){
       Serial.println("Its Mine!"); 
     }
     
     if(received_command.commandType == COMMAND_MOVE_TO_PUMP){
       delay(1000);
       command_to_send.commandType = COMMAND_ARRIVED_AT_PUMP;
       command_to_send.param1 = received_command.param1;
//       command_to_send.param2 = received_command.param2;
       command_to_send.param3 = 0;
       sendCommand();
     }
  }
}

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipeTX);
  radio.openReadingPipe(1, pipeRX);
  radio.startListening();
  Serial.println("RP6 Awake");
}

void loop() {
  receiveCommand();
  delay(5);
}



