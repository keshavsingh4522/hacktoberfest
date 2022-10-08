import urllib.request
import cv2

stream = cv2.VideoCapture('http://192.168.0.101:4747/video')

# Use the next line if your camera has a username and password
# stream=cv2.VideoCapture('protocol://username:password@IP:port/1')

while True:
    r, f = stream.read()
    print(r,f)
    cv2.imshow('IP Camera stream',f)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cv2.destroyAllWindows()