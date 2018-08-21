/**
 * @example smartlink.ino
 * @brief The smartlink demo of library WeeESP8266. 
 * @author Alex 
 * @date 2016.01
 * 
 * @par Copyright:
 * Copyright (c) 2015 ITEAD Intelligent Systems Co., Ltd. \n\n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version. \n\n
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "ESP8266.h"
#include <SoftwareSerial.h>

#define HOST_NAME   "192.168.31.136"
#define HOST_PORT   (8080)

SoftwareSerial mySerial(3, 2); /* RX:D3, TX:D2 */
ESP8266 wifi(mySerial,115200);//刚开始默认波特率为115200
uint8_t buffer[128] = {0};

/*******************************************************************************
* 函 数 名 ：AutoLink
* 函数功能 ：自动连接，前10s自动连接，若连接失败则进入smartlink模式30s，若依然失败
*            则再次回到自动连接，直到连接成功
* 输    入 ：无
* 输    出 ：无
*******************************************************************************/
void AutoLink(void)
{
	int8_t status = STATUS_LOSTIP;
	while(status != STATUS_GETIP)
	{
		uint32_t start_time = millis();
		Serial.println("start auto link");
		//10s自动连接时间
		while((millis() - start_time < 10000) && status != STATUS_GETIP)
		{
			status = wifi.getSystemStatus();
			delay(500);
		}
		
		//连接失败进入smartlink模式 30s
		if(status != STATUS_GETIP)
		{
			String link_msg;
			Serial.println("start smartlink");
			wifi.stopSmartLink();
			
			if(true == wifi.smartLink((uint8_t)AIR_LINK,link_msg))
			{
				Serial.println(link_msg);
				start_time = millis();//等待获取IP
				while((millis() - start_time < 5000) && status != STATUS_GETIP)
				{
					status = wifi.getSystemStatus();
					delay(500);
				}				
			}else
			{
				wifi.stopSmartLink();
				delay(500);
				Serial.println("link AP fail");
			}
		 }			
	}
	Serial.println("link AP OK");
}

void setup(void)
{
	//delay(1000);
    Serial.begin(9600);
	Serial.print("setup begin\r\n");
	wifi.SetBaud(9600);//设置波特率
	wifi.SetBaud(9600);
	mySerial.begin(9600);
	
    wifi.restart();

    Serial.print("FW Version:");
    Serial.println(wifi.getVersion().c_str());
      
	 Serial.print("wifi status:");
	 Serial.println(wifi.getSystemStatus());

    if (wifi.setOprToStationSoftAP()) {
        Serial.print("to station + softap ok\r\n");
    } else {
        Serial.print("to station + softap err\r\n");
    }
	
	AutoLink();
    
    if (wifi.disableMUX()) {
        Serial.print("single ok\r\n");
    } else {
        Serial.print("single err\r\n");
    }
    Serial.print("setup end\r\n");
	
	Serial.print("wifi status:");
	Serial.println(wifi.getSystemStatus());
	 
	creattcp0:
	if (wifi.createTCP(HOST_NAME, HOST_PORT)) {//连接主机
		Serial.print("create tcp ok\r\n");
    } else {
        Serial.print("create tcp err\r\n");
		delay(2000);
		goto creattcp0;
    }
	
	Serial.print("wifi status:");
	Serial.println(wifi.getSystemStatus());
}
 
void loop(void)
{   
 //   char *hello = "Hello, this is client!";
 //   wifi.send((const uint8_t*)hello, strlen(hello));
 //
//   	creattcp1:
//	if (wifi.createTCP(HOST_NAME, HOST_PORT)) {//连接主机
//		Serial.print("create tcp ok\r\n");
//    } else {
//        Serial.print("create tcp err\r\n");
//		delay(2000);
//		goto creattcp1;
//    }
    
    uint32_t len = wifi.recv(buffer, sizeof(buffer),100);
    if (len > 0) {
        Serial.print("Received:[");
        for(uint32_t i = 0; i < len; i++) {
            Serial.print((char)buffer[i]);
        }
        Serial.print("]\r\n");
		wifi.send((const uint8_t*)"recv OK",7);
    }
    
/*     if (wifi.releaseTCP()) {
        Serial.print("release tcp ok\r\n");
    } else {
        Serial.print("release tcp err\r\n");
    }
    delay(5000); */
}
     










