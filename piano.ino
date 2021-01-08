#include <Servo.h>

//notele folosite pentru melodiile 1, 2 si 3

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0

//tempourile melodiilor 1, 2 si 3
int tempo_hedwig = 144, tempo_take_on_me = 140, tempo_fur_elise = 85;

//array-ul de note si durate ale fiecarei note din prima melodie
int hedwig[] = {
   
  REST, 2, NOTE_D4, 4,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_C5, -2, 
  NOTE_A4, -2,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_F4, 2, NOTE_GS4, 4,
  NOTE_D4, -1, 
  NOTE_D4, 4,

  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_B4, 4,
  NOTE_G4, -1,
  NOTE_AS4, 4,
  
};

//array-ul de note si durate ale fiecarei note din a doua melodie
int take_on_me[] = {

  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  
};

//array-ul de note si durate ale fiecarei note din prima melodie
const int fur_elise[] = {

  // Fur Elise - Ludwig van Beethovem
  // Score available at https://musescore.com/user/28149610/scores/5281944

  //starts from 1 ending on 9
  NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, 
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, 
  NOTE_A4 , 4, REST, 8, 
  
};

//notele corespunzatoare butoanelor folosite
#define NOTE_A 220
#define NOTE_B 247
#define NOTE_C 139
#define NOTE_D 147
#define NOTE_E 165

volatile int recordedNotes[300]; //array pentru notele care pot fi inregistrare
volatile int nbOfNotesInSong; //numarul de note dintr-o melodie

volatile int durations[10]; //duratele notelor dintr-o melodie
volatile int song[10]; //o melodie

volatile int startButton; //butonul de pe care se incepe inregistrarea
volatile int stopButton; //butonul de pe care se opreste intregistrarea si se reda mai apoi melodia 
//de cate ori se doreste pana la apasarea butonului de start din nou

volatile int cnt = 0; //variabila folosita pentru a contoriza array-uri

Servo srv; //servomotorul

void setup()
{
  Serial.begin(9600);
  
  //note buttons
  pinMode(7, INPUT); //button 1
  pinMode(8, INPUT); //button 2
  pinMode(4, INPUT); //button 3
  pinMode(5, INPUT); //button 4
  pinMode(6, INPUT); //button 5
  
  //reset and start button
  pinMode(2, INPUT); //button 6 - interrupt
  
  //stop and replay recording button
  pinMode(3, INPUT); //button 7 - interrupt
  
  //change song in play mode
  pinMode(15, INPUT);
  
  //rgb led
  pinMode(13, OUTPUT); //red
  pinMode(12, OUTPUT); //blue
  pinMode(11, OUTPUT); //green
  
  //piezo
  pinMode(9, OUTPUT); //piezo1
  
  //switch - se poate seta daca se doreste inregistrarea unei melodii sau folosirea notelor sau redarea celor 3 melodii deja existente
  pinMode(10, INPUT_PULLUP);
  
  //se ataseaza intreruperile pentru pinii 2 si 3 (butoanele start si stop rrecording)
  attachInterrupt(digitalPinToInterrupt(2), startRecording, RISING);
  attachInterrupt(digitalPinToInterrupt(3), stopRecording, RISING);
  
  startButton = 0;
  stopButton = 0;
  nbOfNotesInSong = 0;
}

void loop()
{
  //cazul in care switch-ul este pornit -> se inregistreaza melodie cu propriile note
  if(digitalRead(10) == 1){ //daca pinul 10, butonul 1, este apasat
    
    ledOut();
    
    //se va reda nota a si, in cazul in care este pornita inregistrarea va fi adaugata la melodie; se va aprinde led rosu;
    //aceeasi situatie este si pentru celelalte 4 butoane corespunzatoare notelor
    if(digitalRead(7) == 1){
       tone(9, NOTE_A, 100);
       displayRed();
       if(startButton == 1 && nbOfNotesInSong <= 500){
         recordedNotes[nbOfNotesInSong] = 220;
         nbOfNotesInSong++;
       }
     }
  
    if(digitalRead(8) == 1){
       tone(9, NOTE_B, 100);
       displayBlue();
    
       if(startButton == 1 && nbOfNotesInSong <= 500){
          recordedNotes[nbOfNotesInSong] = 247;
          nbOfNotesInSong++;
       }
    }
  
    if(digitalRead(4) == 1){
       tone(9, NOTE_C, 100);
       displayGreen();
    
       if(startButton == 1 && nbOfNotesInSong <= 500){
         recordedNotes[nbOfNotesInSong] = 139;
         nbOfNotesInSong++;
       }
    }
  
    if(digitalRead(5) == 1){
       tone(9, NOTE_D, 100);
       displayYellow();
    
       if(startButton == 1 && nbOfNotesInSong <= 500){
         recordedNotes[nbOfNotesInSong] = 147;
         nbOfNotesInSong++;
       }
    }
  
    if(digitalRead(6) == 1){
       tone(9, NOTE_E, 100);
       displayPurple();
    
       if(startButton == 1 && nbOfNotesInSong <= 500){
         recordedNotes[nbOfNotesInSong] = 165;
         nbOfNotesInSong++;
       }
    }
  
    if(stopButton == 1){ //daca se va mai apasa buttonul de stop dupa intrerupere, se va reda melodia curenta
      replay();
    }
  }
  
  //cazul in care switch-ul nu este pornit -> se redau melodiile deja memorate
  if(digitalRead(10) == 0){
    ledOut();
    
    if(digitalRead(15) == 0){
      song1();
      noTone(9);
      delay(1000);
      song2();
      noTone(9);
      delay(1000);
      song3();
      noTone(9);
    } 
  }
}

//prima melodie
void song1()
{
  srv.attach(14);
  nbOfNotesInSong = sizeof(hedwig) / sizeof(hedwig[0]) / 2;
  
  int note = (60000 * 4) / tempo_hedwig;
  
  int divider = 0, duration = 0;
  
  //se redau toate sunetele timp de durata lor corespunzatoare si se misca servomotorul;
  for(int i = 0; i < nbOfNotesInSong * 2; i = i + 2){
    
    if(digitalRead(10) == 1 || digitalRead(15) == 1) {
      break;
    }
    
    divider = hedwig[i + 1];
    
    if(divider > 0){
      duration = note / divider;
    }
    else if (divider < 0){
      duration = note / abs(divider);
      duration *= 1.5;
    }
    
    tone(9, hedwig[i], duration * 0.9);
    
    if(divider != 0){
      srv.write(note / abs(divider));
    }
   
    displayPurple();
    delay(duration);
    noTone(9);
  }
  srv.detach();
}

//a doua melodie
void song2()
{
  srv.attach(14);
  nbOfNotesInSong = sizeof(take_on_me) / sizeof(take_on_me[0]) / 2;
  
  int note = (60000 * 4) / tempo_take_on_me;
  
  int divider = 0, duration = 0;
  
  for(int i = 0; i < nbOfNotesInSong * 2; i = i + 2){
    
    if(digitalRead(10) == 1 || digitalRead(15) == 1) break;
    
    divider = take_on_me[i + 1];
    
    if(divider > 0){
      duration = note / divider;
    }
    else if (divider < 0){
      duration = note / abs(divider);
      duration *= 1.5;
    }
    
    tone(9, take_on_me[i], duration * 0.9);
    
    srv.write(note / 100);
    
    displayYellow();
    delay(duration);
    noTone(9);
  }
  srv.detach();
}

// a treia melodie
void song3()
{
  srv.attach(14);
  nbOfNotesInSong = sizeof(fur_elise) / sizeof(fur_elise[0]) / 2;
  
  int note = (60000 * 4) / tempo_fur_elise;
  
  int divider = 0, duration = 0;
  
  for(int i = 0; i < nbOfNotesInSong * 2; i = i + 2){
    
    if(digitalRead(10) == 1 || digitalRead(15) == 1) break;
    
    divider = fur_elise[i+1];
    
    if(divider > 0){
      duration = note / divider;
    }
    else if (divider < 0){
      duration = note / abs(divider);
      duration *= 1.5;
    }
    
    tone(9, fur_elise[i], duration * 0.9);
    
    srv.write(note / 100);
    
    displayGreen();
    delay(duration);
    noTone(9);
  }
  srv.detach();
}

//metoda ce va reda melodia inregistrata la intrerupere
void replay(){
  
  srv.attach(14);
  
  int duration = 0;
  for(int i = 0; i < nbOfNotesInSong - 1; i++){
    duration = 0;
    while(recordedNotes[i] == recordedNotes[i+1]){
      i++;
      duration++;
    }
    
    song[cnt] = recordedNotes[i];
    durations[cnt] = duration;
    cnt++;
  }
  
  for(int i = 0; i < cnt; i++){
    
    if(song[i] == NOTE_A){
      
      srv.write(NOTE_A / 3.14);
      displayRed();
    }
    
    if(song[i] == NOTE_B){
      srv.write(NOTE_B / 3.14);
      displayBlue();
    }
    
    if(song[i] == NOTE_C){
      srv.write(NOTE_C / 3.14);
      displayGreen();
    }
    
    if(song[i] == NOTE_D){
      srv.write(NOTE_D / 3.14);
      displayYellow();
    }
    
    if(song[i] == NOTE_E){
      srv.write(NOTE_E / 3.14);
      displayPurple();
    }
    
    tone(9, song[i], durations[i] * 10);
    int pauseBetweenNotes = durations[i] * 13;
  delay(pauseBetweenNotes);
  }
  
  ledOut();
  
  noTone(9);
  stopButton = 0;
}

//ISR pentru butonul de start 
void startRecording(){
  startButton = 1;
  stopButton = 0;
  nbOfNotesInSong = 0;
  
  ledOut();
  
  Serial.println("Recording!");
}

//ISR pentru butonul de stop
void stopRecording(){
  startButton = 0;
  stopButton = 1;
  cnt = 0;
  
  ledOut();
  
  Serial.println("Recording stopped!");
}

//metode pentru setarea culorilor ledului RGB
void ledOut(){
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
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
