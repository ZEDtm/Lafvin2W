from lafvin import Lafvin

l = Lafvin("/dev/ttyUSB1")


def go_dancing(l):
    l.rotate_right(255)
    l.move_servo(0)
    l.rotate_left(255)
    l.move_servo(180)
    l.rotate_right(255)
    l.move_servo()
    l.stop()


go_dancing(l)
def ai_moving(l):
    while True:
        if l.wall_forward():
            left, right = l.wall_left_or_right()
            if left and right:
                l.go_backward()
                l.rotate_left()
                l.stop()
            else:
                if right:
                    l.rotate_left()
                    l.go_forward()
                    l.stop()
                else:
                    l.rotate_right()
                    l.go_forward()
                    l.stop()
        else:
            l.go_forward()
            l.stop()
