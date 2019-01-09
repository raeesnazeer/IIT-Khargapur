import cv2
import imutils

#cap = cv2.VideoCapture('http://192.168.43.25:8080/video')
cap = cv2.VideoCapture(0)

while(True):
    ret, frame = cap.read()
    image = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    blurred = cv2.GaussianBlur(image, (9, 9), 0)

    (T, thresh) = cv2.threshold(blurred, 155, 255, cv2.THRESH_BINARY)
    cv2.imshow("Threshold Binary", thresh)
    (T, threshInv) = cv2.threshold(blurred, 155, 255, cv2.THRESH_BINARY_INV)
    blurred = imutils.resize(blurred, 500)

    canny = cv2.Canny(blurred, 30, 150)
    cv2.imshow("Canny", canny)
    resized = imutils.resize(frame, 500)
    cv2.imshow("frame",resized)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        cv2.destroyAllWindows()
        break