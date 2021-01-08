/*
  This program blinks pin 13 of the Arduino (the
  built-in LED)
*/

#define NOTE_A 220
#define NOTE_B 247
#define NOTE_C 131
#define NOTE_D 147
#define NOTE_E 165

volatile int recordedNotes[100];
volatile int nbOfNotesInSong;

volatile int startButton;
volatile int stopButton;

void setup()
{
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);
  
  //note buttons
  pinMode(7, INPUT); //button 1
  pinMode(8, INPUT); //button 2
  pinMode(4, INPUT); //button 3
  pinMode(5, INPUT); //button 4
  pinMode(6, INPUT); //button 5
  
  //start button
  pinMode(2, INPUT); //button 6 - interrupt
  
  //stop recording button
  pinMode(3, INPUT); //button 7 - interrupt
  
  //rgb led
  pinMode(13, OUTPUT); //red
  pinMode(12, OUTPUT); //blue
  pinMode(11, OUTPUT); //green
  
  //piezo
  pinMode(9, OUTPUT); //piezo1
  
  attachInterrupt(digitalPinToInterrupt(2), startRecording, RISING);
  attachInterrupt(digitalPinToInterrupt(3), stopRecording, RISING);
  
  startButton = 0;
  stopButton = 0;
  nbOfNotesInSong = 0;
}

void loop()
{
  if(digitalRead(7) == 1){
  	tone(9, NOTE_A, 100);
    displayRed();
    
    if(startButton == 1){
      recordedNotes[nbOfNotesInSong] = NOTE_A;
      nbOfNotesInSong++;
    }
  }
  
  if(digitalRead(8) == 1){
  	tone(9, NOTE_B, 100);
    displayBlue();
    
    if(startButton == 1){
      recordedNotes[nbOfNotesInSong] = NOTE_B;
      nbOfNotesInSong++;
    }
  }
  
  if(digitalRead(4) == 1){
  	tone(9, NOTE_C, 100);
    displayGreen();
    
    if(startButton == 1){
      recordedNotes[nbOfNotesInSong] = NOTE_C;
      nbOfNotesInSong++;
    }
  }
  
  if(digitalRead(5) == 1){
  	tone(9, NOTE_D, 100);
    displayYellow();
    
    if(startButton == 1){
      recordedNotes[nbOfNotesInSong] = NOTE_D;
      nbOfNotesInSong++;
    }
  }
  
  if(digitalRead(6) == 1){
  	tone(9, NOTE_E, 100);
    displayPurple();
    
    if(startButton == 1){
      recordedNotes[nbOfNotesInSong] = NOTE_E;
      nbOfNotesInSong++;
    }
  }
}

void startRecording(){
  startButton = 1;
  stopButton = 0;
  nbOfNotesInSong = 0;
  
  Serial.println("Recording!");
}

void stopRecording(){
  startButton = 0;
  stopButton = 1;
  
  Serial.println("Recording stopped!");
  Serial.println(nbOfNotesInSong);
  for(int i = 0; i < nbOfNotesInSong; i++){
  	tone(9, recordedNotes[i], 100);
  }
}

void displayRed(){
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
}

void displayBlue(){
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
}

void displayGreen(){
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
}

void displayYellow(){
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
}

void displayPurple(){
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
}