import cv2
import imutils

cap = cv2.VideoCapture('http://192.168.43.41:8080/video')

while(True):
    ret, frame = cap.read()
    resized = imutils.resize(frame, 500)
    cv2.imshow("frame",resized)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        cv2.destroyAllWindows()
        break