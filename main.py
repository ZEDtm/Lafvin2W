from lafvin import Lafvin


def go_dancing(lv: Lafvin) -> None:
    lv.rotate_right(255)
    lv.move_servo(0)
    lv.rotate_left(255)
    lv.move_servo(180)
    lv.rotate_right(255)
    lv.move_servo()
    lv.stop()


def ai_moving(lv: Lafvin):
    while True:
        if lv.wall_forward():
            left, right = lv.wall_left_or_right()
            if left and right:
                lv.go_backward()
                lv.rotate_left()
                lv.stop()
            else:
                if right:
                    lv.rotate_left()
                    lv.go_forward()
                    lv.stop()
                else:
                    lv.rotate_right()
                    lv.go_forward()
                    lv.stop()
        else:
            lv.go_forward()
            lv.stop()


if __name__ == "__main__":
    # Example
    lv = Lafvin("/dev/ttyUSB1")
    go_dancing(lv)
    ai_moving(lv)
