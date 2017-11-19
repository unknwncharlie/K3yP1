import serial
print "Handling ctrl-alt-delete"
char = 222
ser = serial.Serial("/dev/ttyAMA0", 9600, timeout=2)
ser.write(chr(char))
f = open("/home/pi/K3yP1/test.txt", "w+")

