# import the required libraries
import cv2
import os
import numpy as np
from PIL import Image
import pickle


cascade = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

recognise = cv2.face.LBPHFaceRecognizer_create()


def getdata():
    current_id = 0
    label_id = {}
    face_train = []
    face_label = []

    BASE_DIR = os.path.dirname(os.path.abspath(__file__))

    my_face_dir = os.path.join(BASE_DIR, "image_data")

    for root, dirs, files in os.walk(my_face_dir):
        for file in files:
            if file.endswith("png") or file.endswith("jpg"):
                path = os.path.join(root, file)

                label = os.path.basename(root).lower()

                if not label in label_id:
                    label_id[label] = current_id
                    current_id += 1
                ID = label_id[label]

                pil_image = Image.open(path).convert("L")

                image_array = np.array(pil_image, "uint8")

                face = cascade.detectMultiScale(image_array)

                for x, y, w, h in face:
                    img = image_array[y : y + h, x : x + w]

                    cv2.imshow("Test", img)
                    cv2.waitKey(1)
                    face_train.append(img)
                    face_label.append(ID)

    with open("labels.pickle", "wb") as f:
        pickle.dump(label_id, f)

    return face_train, face_label


face, ids = getdata()
recognise.train(face, np.array(ids))
recognise.save("trainner.yml")
