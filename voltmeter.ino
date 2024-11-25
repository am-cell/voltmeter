/*
DC Voltmeter 
An Arduino DVM based on voltage divider concept
T.K.Hareendran
*/

int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // resistance of R2 (100K) -see text!
float R2 = 10000.0; // resistance of R1(10K) - see text!
int value = 0;
void setup(){
   pinMode(analogInput, INPUT);
   Serial.begin(9600);
   Serial.print("DC VOLTMETER");
}
void loop(){
   // read the value at analog input
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;//statement to quash undesired reading !
} 

Serial.print("INPUT V= ");
Serial.println(vin);
delay(500);
}
