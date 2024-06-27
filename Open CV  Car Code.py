import cv2
import serial
from cvzone.HandTrackingModule import HandDetector


cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon=0.5, maxHands=1)


bt = serial.Serial('COM7', 9600)  

while True:
    ret, frame = cap.read()
    flip_both = cv2.flip(frame, 1)
    hands, frame = detector.findHands(frame)

    if not hands:
        print("nothing")
    else:
        hand1 = hands[0]
        fingers = detector.fingersUp(hand1)
        count = fingers.count(1)
        print(count)

        if count == 1:
            command = 'F'  
        elif count == 2:
            command = 'B'  
        elif count == 3:
            command = 'L'  
        elif count == 4:
            command = 'R'  
        else:
            command = 'S'  

        print(f"Command: {command}")
        bt.write(command.encode("utf-8"))

    cv2.imshow("FRAME", frame)

    if cv2.waitKey(1) & 0xFF == 27:  
        break

cap.release()
cv2.destroyAllWindows()
