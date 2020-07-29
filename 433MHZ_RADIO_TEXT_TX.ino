const char *msgPkt = "Hi radio receiver\n";
long pblePkt = 0x55;
byte addrPkt = 0x00;
byte chkPkt;

void setup() 
{
  Serial.begin(2400);
}

void loop() 
{
  sendMsgOverRadio(msgPkt);
}

void sendMsgOverRadio(const char *msgPkt)
{
  for (int m = 0; m <= strlen(msgPkt) - 1; m++)
    for (int n = 0; n < 5; n++)
    {
      Serial.write(pblePkt);
      Serial.write(addrPkt);
      Serial.write(*(msgPkt + m));
      chkPkt = addrPkt + *(msgPkt + m);
      Serial.write(chkPkt);
    }
}