Arduino LafvinW2(robot) bridge program Python -> Arduino for control using PySerial

#Example use
from lafvin import Lafvin, AsyncLafvin
import asyncio


def main():
    lv = Lafvin("/dev/ttyUSB1")
    print(lv.read_distance())  #read distance from sensor
    lv.move_servo(0)  #rotate servo 0°-180°
    lv.go_forward()  #set all engines in motion 0-255


async def async_main():
    lv = AsyncLafvin()
    print(await lv.read_distance())  #read distance from sensor
    await lv.move_servo(0) #rotate servo 0°-180°  
    await lv.go_forward() #set all engines in motion 0-255


if __name__ == "__main__":
    # Example run
    main()
    asyncio.run(async_main)
