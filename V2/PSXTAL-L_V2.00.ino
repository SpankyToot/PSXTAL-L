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

  Lightened version of VajSkids PSXTAL project to prepare for my combined video region switching modchip project.
*/

const int SENSOR_PIN = A0; //A0 from GPU pin 157
const int NTSC = A1; // Power output to DFO NTSC Crystal
const int PAL = A2; // Power output to DFO PAL Crystal
const int BENCHMARK = 500; // Value sensed between PAL and NTSC values. PAL=0, NTSC=750 and Off-250

void setup() {
  //Serial.begin(115200); //Dev stuff
  pinMode(NTSC, OUTPUT);
  pinMode(PAL, OUTPUT);
  // No pinMode() needed for analogRead()
}
void loop() {
  // 1. reading the input from the analog pin to which sensor is connected
  int input = analogRead(SENSOR_PIN);
  
  // 2. if sensor value less than "benchmark" - powere PAL Crystal
  if (input <= BENCHMARK){
    digitalWrite(PAL, HIGH);
    digitalWrite(NTSC, LOW);
  }
  //2bis. if sensor value is more than "benchmark" - Power the NTSC Crystal
  if (input >= BENCHMARK){
    digitalWrite(NTSC, HIGH);
    digitalWrite(PAL, LOW);
  }
}
