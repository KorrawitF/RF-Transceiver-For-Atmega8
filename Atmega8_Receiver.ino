#include <RH_NRF24.h>
RH_NRF24 nrf24(8,10);
void setup()
{
  Serial.begin(115200);
  if(!nrf24.setChannel(1))
  Serial.println("Set Fail!");
  if(!nrf24.setRF(RH_NRF24::DataRate1Mbps,RH_NRF24::TransmitPower0dBm))
  Serial.println("RF Fail!");
  if(!nrf24.init())
  Serial.println("Init Fail!");
}
void loop()
{
  if(nrf24.available())
  {
    uint8_t buff[RH_NRF24_MAX_MESSAGE_LEN];
    uint8_t len=sizeof(buff);
    if(nrf24.recv(buff,&len))
    {
      Serial.println((char*)buff);
    }
  }
  else 
  {
    Serial.println("Fail!");
  }
}
