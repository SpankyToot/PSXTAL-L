/*                                          ,----,                ,--,                ,--,    
,-.----.                                  ,/   .`|             ,---.'|             ,---.'|    
\    /  \    .--.--.   ,--,     ,--,    ,`   .'  : ,---,       |   | :             |   | :    
|   :    \  /  /    '. |'. \   / .`|  ;    ;     /'  .' \      :   : |             :   : |    
|   |  .\ :|  :  /`. / ; \ `\ /' / ;.'___,/    ,'/  ;    '.    |   ' :       ,---,.|   ' :    
.   :  |: |;  |  |--`  `. \  /  / .'|    :     |:  :       \   ;   ; '     ,'  .' |;   ; '    
|   |   \ :|  :  ;_     \  \/  / ./ ;    |.';  ;:  |   /\   \  '   | |__ ,---.'   ,'   | |__  
|   : .   / \  \    `.   \  \.'  /  `----'  |  ||  :  ' ;.   : |   | :.'||   |    ||   | :.'| 
;   | |`-'   `----.   \   \  ;  ;       '   :  ;|  |  ;/  \   \'   :    ;:   :  .' '   :    ; 
|   | ;      __ \  \  |  / \  \  \      |   |  ''  :  | \  \ ,'|   |  ./ :   |.'   |   |  ./  
:   ' |     /  /`--'  / ;  /\  \  \     '   :  ||  |  '  '--'  ;   : ;   `---'     ;   : ;    
:   : :    '--'.     /./__;  \  ;  \    ;   |.' |  :  :        |   ,/              |   ,/     
|   | :      `--'---' |   : / \  \  ;   '---'   |  | ,'        '---'               '---'      
`---'.|               ;   |/   \  ' |           `--''                                         
  `---`               `---'     `--`                                                          
  NTSC / PAL wireless mode change (Automatic dual frequency selector)
  This version is for PSX models using XTALS, not later models with a clock synth
  Origional work by VajskiDs Consoles
  PSXTAL dual PCB Version!
  Lightened version of VajSkids PSXTAL project to remove IGR for Xstation while retaining full auto region switching functionality.
  A stepping stone for my compined video region switching and modchip project.
*/




//#include <Adafruit_SI5351.h>
//#include<SPI.h>
//#define reset 9                          // NOTE: THIS RESET PIN HAS BEING CHANGED FROM 2 TO 9 ON THIS VERSION!
#define sensepin 2                       // PIN 2 NOW DETECTS REGION OF GAME FOR VIDEOMODE
#define NTSCpin 15                          // NTSC XTAL pin to PSXTAL PCB (A1)
#define PALpin 16                           // PAL XTAL  pin to PSXTAL PCB (A2)
volatile byte buffer = 0x00;
int counter = 0;
String NTSC_MODE = "LAUNCH";
//Adafruit_SI5351 clockgen = Adafruit_SI5351();



void setup() {
//  clockgen.begin();
//  clockgen.enableOutputs(true);
  DDRD = 0xFF;    // clear every port / pin and pull them all low as outputs temporarily  (The Port D stuff is especially important for videomode sensing to work)
  PORTD = 0x00;   // any pins requiring different states are set up just after this,
//  DDRB = 0xFF;    // leaves no floating inputs
//  PORTB = 0x00;
//  DDRC = 0xFF;
//  PORTC = 0x00;
  pinMode (sensepin, INPUT);
//  pinMode (reset, INPUT);
  //Serial.begin(74880);    // only for dev monitoring


}



void NTSC() {

  pinMode (PALpin, INPUT);
  pinMode (NTSCpin, OUTPUT);
  digitalWrite (NTSCpin, 1);
  NTSC_MODE = "TRUE";

}


void PAL() {

  pinMode (NTSCpin, INPUT);
  pinMode (PALpin, OUTPUT);
  digitalWrite (PALpin, 1);
  NTSC_MODE = "FALSE";

}


void checkvideomode() {


  if (PIND == 0x4 && NTSC_MODE == "FALSE" || PIND == 0x4 && NTSC_MODE == "LAUNCH") { //digital read on sensepin causes video interference each read, using port status instead.

    NTSC();

  }


  if (PIND == 0x00 && NTSC_MODE == "TRUE" || PIND ==  0x00 && NTSC_MODE == "LAUNCH") {

    PAL();

  }

}



//ISR (SPI_STC_vect) {            // interrupt routine function


  //capture IGR packets only
//  if (SPDR == 0xF3 || SPDR == 0xDB || SPDR == 0xEB || SPDR == 0xDD || SPDR == 0x87 || SPDR == 0xC7) {
//    buffer = SPDR;              // take a snap shot of the SPDR register and store it in 'buffer', but only if it's an error free combo capture byte
// }
//
  // capture correctable packets for long reset (SCPH1200)
//  else  if (SPDR == 0xC3 || SPDR == 0xE1 || SPDR == 0xF0) {
//    buffer = 0x87; //correct the packet
//  }
  // capture correctable packets for short reset (SCPH1200)
//  else if (SPDR == 0xE3 || SPDR == 0x8F) {
//    buffer = 0xC7; // correct the packet
//  }
//  else {
//    buffer = 0x00; // miscommunicated packet or no combo detected ! clear the buffer and continue monitoring.
//  }
//}


// buffer = SPDR;              dev/ debug, star out above code in interrupt function and uncomment
//}



//void shortrst() {             // short reset

//  buffer = 0x00;
//  pinMode (reset, OUTPUT);
//  digitalWrite (reset, 0);
//  delay (40);
//  pinMode (reset, INPUT);
//}

//void longrst () {            // long reset

//  buffer = 0x00;
//  pinMode (reset, OUTPUT);
//  digitalWrite (reset, 0);
//  delay (2000);
//  pinMode (reset, INPUT);
//}


void loop() {


  checkvideomode();



//  if (counter == 10 && buffer ==  0xDB || counter == 10 && buffer ==  0xF3 || counter == 15 && buffer ==  0xC7) {        // short reset conditions
//    shortrst();
//  }



//  if (counter == 10 && buffer ==  0xEB || counter == 10 && buffer ==  0xDD || counter == 15 && buffer ==  0x87) {         // long reset conditions
//    longrst();
//  }



//  SPCR = 0xCB;                                                // SPI setup, 250khz, MSB (as slave), clock idle high, read on rising edge, SPI / SPI interrupts on,
//  delay (500);
  //Serial.print("Combo Received from Controller: ");         // dev stuff
  //Serial.println(buffer, BIN);
//  digitalWrite (SPE, 0);                                      // disable SPI




//  if (buffer ==  0xF3 || buffer ==  0xDB || buffer ==  0xEB || buffer ==  0xDD || buffer ==  0x87 || buffer ==  0xC7) { // ensure the combo has to be held for at least ~5s
//    counter++;
//    loop();
//  }
//  else {                                                      // if key combo is not being pressed, reset button combos 'pressed time' counter
//    counter = 0;
//    loop();
//  }
}
