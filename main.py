from lafvin import Lafvin, AsyncLafvin
import asyncio


def main():
    lv = Lafvin("/dev/ttyUSB1")
    print(lv.read_distance())
    lv.move_servo(0)
    lv.go_forward()


async def async_main():
    lv = AsyncLafvin()
    print(await lv.read_distance())
    await lv.move_servo(0)
    await lv.go_forward()


if __name__ == "__main__":
    # Example
    main()
    asyncio.run(async_main)
