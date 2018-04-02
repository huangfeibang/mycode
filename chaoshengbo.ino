/*
SR04超声波传感器驱动
串口显示检测距离
*/
/*
SR04超声波传感器驱动
串口显示检测距离
*/

// 设定SR04连接的Arduino引脚
const int AO = A1;
const int TrigPin = 2; 
const int EchoPin = 3;
const int LED = 5;
float distance(); 
int liangdu=255;
void setup() 
{   // 初始化串口通信及连接SR04的引脚
  Serial.begin(9600); 
  pinMode(TrigPin, OUTPUT); 
    // 要检测引脚上输入的脉冲宽度，需要先设置为输入状态
  pinMode(EchoPin, INPUT); 
    Serial.println("Ultrasonic sensor:");
    pinModxe(A1, INPUT);
    pinMode(LED, OUTPUT);
} 
float distance();
void loop() 
{ 
  float juli,juli1,jul,ld1,ld2,lightness;
  int i;
  lightness=analogRead(A1);
  lightness=lightness/950*255;
    Serial.print(lightness); 
    Serial.print("a ");
    if(lightness>100)
    {
      while(distance()<30&&distance()>3)
     {
      /*for(i=1;i<=20;i++)
      {
        analogWrite(LED,liangdu);
        delay(50);
        if(distance()>=30&&distance()<=5)    break;
      }*/
  
      ld1=distance();
      /*Serial.print(ld1); 
      Serial.print("a "); */
      analogWrite(LED,liangdu);
      delay(50);
      ld2=distance();
      //if(abs(ld1-ld2)<5&&abs(ld1-ld2)>3 )    liangdu=liangdu+(ld1-ld)*15;
      if(abs(ld1-ld2)>2)    break;
      else  liangdu=liangdu+(ld1-ld2)*10;
      if(liangdu<0)    liangdu=0;
      if(liangdu>255)    liangdu=255;
    }
    if(distance()>=200)
    {
      for(i=1;i<=50;i++)
      {
        analogWrite(LED,liangdu);
        delay(100);
        if(distance()<200)    break;
      }
    }
    while(i==51)
    {
      analogWrite(5,0);
      delay(100);
      if(distance()<200)    break;
    }
    analogWrite(LED,liangdu);
    delay(50);  
    }
    else digitalWrite(LED,0);

}
float distance()
{
 digitalWrite(TrigPin, LOW); 
  delayMicroseconds(2);     // 产生一个10us的高脉冲去触发TrigPin 
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  return pulseIn(EchoPin, HIGH)/ 58.00;  // 检测脉冲宽度，并计算出距离
}
