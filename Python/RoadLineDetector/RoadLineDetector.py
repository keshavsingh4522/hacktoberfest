import cv2
import numpy as np
from matplotlib import pyplot as plt

def roi(image,vertices):
    mask=np.zeros_like(image)
    cv2.fillPoly(mask,vertices,255)
    masked_image=cv2.bitwise_and(image,mask)
    return masked_image
def image_with_lines(image,lines):
    image=np.copy(image)
    blank_image=np.zeros((image.shape[0],image.shape[1],3),np.uint8)

    for line in lines:
        for x1,y1,x,y in line:
            cv2.line(blank_image,(x1,y1),(x,y),(0,255,0),4)
    image =cv2.addWeighted(image,0.8,blank_image,1,0.0)
    return image


img=cv2.imread("roads.jpg")
img=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
print(img.shape,img.dtype)
height=img.shape[0]
width=img.shape[1]
region_of_interest_vertices=[(0,height),(height/2,width/2),(width,height)]
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
edge=cv2.Canny(gray,100,200)

cropped_image=roi(edge,np.array([region_of_interest_vertices],np.uint8))
line=cv2.HoughLinesP(cropped_image,1,np.pi/180,60,lines=np.array([]),minLineLength=40,maxLineGap=25)

final=image_with_lines(img,line)

plt.imshow(final)
plt.show()
