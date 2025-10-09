# import opencv
import cv2

# Load the Cascade Classifier
face_cascade = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

# start  web cam
cap = cv2.VideoCapture(0)

while True:

    # read image from webcam
    respose, color_img = cap.read()

    # Convert to grayscale
    gray_img = cv2.cvtColor(color_img, cv2.COLOR_BGR2GRAY)

    # Detect the faces
    faces = face_cascade.detectMultiScale(gray_img, 1.4, 7)

    # display rectangle
    for (x, y, w, h) in faces:
        cv2.rectangle(color_img, (x, y), (x + w, y + h), (0, 0, 255), 3)

    # display image
    cv2.imshow('img', color_img)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the VideoCapture object
cap.release()
cv2.destroyAllWindows()
