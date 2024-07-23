Arduino LafvinW2(robot) bridge program Python -> Arduino for control using PySerial

lv = Lafvin("/dev/ttyUSB1")  #connect to Arduino
print(lv.read_distance())  #read distance from sensor
lv.move_servo(0)  #rotate servo 0°-180°
lv.go_forward()  #set all engines in motion 0-255


#async
lv = AsyncLafvin()  #connect to Arduino
print(await lv.read_distance())  #read distance from sensor
await lv.move_servo(0) #rotate servo 0°-180°  
await lv.go_forward() #set all engines in motion 0-255
