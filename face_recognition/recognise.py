# import the required libraries
import cv2
import pickle
from datetime import datetime
from time import sleep

video = cv2.VideoCapture(0)
cascade = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

recognise = cv2.face.LBPHFaceRecognizer_create()
recognise.read("trainner.yml")

labels = {}
with open("labels.pickle", "rb") as f:  ##
    og_label = pickle.load(f)  ##
    labels = {v: k for k, v in og_label.items()}  ##
    print("Module Running!")


while True:
    check, frame = video.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    face = cascade.detectMultiScale(gray, scaleFactor=1.2, minNeighbors=5)

    for x, y, w, h in face:
        face_save = gray[y : y + h, x : x + w]

        ID, conf = recognise.predict(face_save)

        if conf >= 20 and conf <= 115:
            cv2.putText(
                frame,
                labels[ID],
                (x - 10, y - 10),
                cv2.FONT_HERSHEY_COMPLEX,
                1,
                (18, 5, 255),
                2,
                cv2.LINE_AA,
            )
        frame = cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 255), 4)
        print(ID, labels[ID])

    cv2.imshow("Video", frame)
    key = cv2.waitKey(1)
    if key == ord("q"):
        break

video.release()
cv2.destroyAllWindows()
