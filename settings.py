import serial
import time
import pyautogui

ArduinoSerial = serial.Serial('com4',9600) #Create Serial port object called arduinoSerialData
time.sleep(2) #wait for 2 seconds for the communication to get established

pyautogui.Failsafe = False

while True:
	incoming = str(ArduinoSerial.readline()) #read the serial data and print it as line
	print(incoming)
	#if "Play/Pause" in incoming:
	#	 pyautogui.typewrite(['space'], 0.2)
	if "Vup" in incoming:
		pyautogui.press('up');
	if "Vdown" in incoming:
		pyautogui.press('down');