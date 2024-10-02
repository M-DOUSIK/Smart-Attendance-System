import cv2

video = cv2.VideoCapture(0)


cascade = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

while True:
    check, frame = video.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    face = cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=6)

    for x, y, w, h in face:
        frame = cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 255), 3)

    cv2.imshow("Video", frame)
    key = cv2.waitKey(1)
    if key == ord("q"):
        break

video.release()
cv2.destroyAllWindows()
