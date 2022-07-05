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




#define sensepin 2                       // A0 DETECTS REGION OF GAME FOR VIDEOMODE
#define NTSCpin 15                          // NTSC XTAL pin to PSXTAL PCB (A1)
#define PALpin 16                           // PAL XTAL  pin to PSXTAL PCB (A2)
int counter = 0;
String NTSC_MODE = "LAUNCH";




void setup() {
  
  DDRD = 0xFF;    // clear every port / pin and pull them all low as outputs temporarily  (The Port D stuff is especially important for videomode sensing to work)
  PORTD = 0x00;   // any pins requiring different states are set up just after this,
  pinMode (sensepin, INPUT);

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

void loop() {

  checkvideomode();

}
