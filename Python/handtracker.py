#this project is a handtracker to detect the points on your hand and is based on open-cv
import cv2
import mediapipe as mp
import time
import os
import HandTracking as htm

cap=cv2.VideoCapture(0)
#create an object from the hand detection module
mpHands=mp.solutions.hands
hands=mpHands.Hands()
mpdraw=mp.solutions.drawing_utils


while True:
    success,img=cap.read()
    imgRGB=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
    results=hands.process(imgRGB)
    print(results.multi_hand_landmarks)

    if results.multi_hand_landmarks:
        for handLms in results.multi_hand_landmarks:
            mpdraw.draw_landmarks(img,handLms,mpHands.HAND_CONNECTIONS)

    cv2.imshow("Image",img)
    cv2.waitKey(1)
