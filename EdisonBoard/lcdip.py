import pyupm_i2clcd as lcd 
import time,os 
Lcd = lcd.Jhd1313m1(0, 0x3E, 0x62)
Lcd.clear()  
Lcd.setColor(255, 255, 0)
Lcd.setCursor(0,0)


def checa():
	return ((os.popen("ifconfig wlan0").read()).split("\n")[1]).split(" ")[11].split("addr:")[1] 

while True:
 Lcd.write(checa())  # escreve no LCD o IP
 time.sleep(5*60) # Espera durante 10 segundos ligado depois desliga
 Lcd.clear()  # Limpa tela
 time.sleep(1*60)
