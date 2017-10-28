#include <SoftwareSerial.h>
SoftwareSerial Thermal(2, 3);
String income="";

void setup() 
{
 Serial.begin(9600); // 시리얼 포트 개방
 Thermal.begin(19200); // 프린터 통신용 포트 개방
}
void loop() {
  read_pi(); //읽고 프린터로 출력하는 함수
}

void read_pi()
{
    while(Serial.available()){ //시리얼 통신으로 문자가 들어오면 
    income += (char)Serial.read(); //String에 저장을 한다
    }

  if(income != 0) //String에 문자가 있으면
  {
    Serial.println(income); //시리얼 포트로 전달하고
    Thermal.println(income); //프린터로 출력 신호를 보낸다
    income=""; //출력을 한후 String 초기화
  }
  delay(10);
}

