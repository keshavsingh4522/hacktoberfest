import cv2
import numpy as np
import face_recognition
#from google.colab.patches import cv2_imshow
import cv2
import os
from PIL import Image
#from IPython.display import display, Javascript
#from google.colab.output import eval_js
from base64 import b64decode,b64encode
import io
import pickle
import dlib
from datetime import datetime,time
import pandas as pd
#from google.colab import files
import PIL
from Register import BASE_DIR
foldername=input("Enter path of images:")
filename=input("Enter Filename You Want to Save Encodings in:")
def byte2image(byte):
    jpeg=b64decode(byte.split(',')[1])
    im = PIL.Image.open(io.BytesIO(jpeg))
    return np.array(im)
 
def image2byte(image):
    image= Image.fromarray(image)
    buffer = io.BytesIO()
    image.save(buffer,'jpeg')
    buffer.seek(0)
    x= b64encode(buffer.read()).decode('utf-8')
    return x

def Train(path):    
    images=[]
    Names=[]
    ids = []
    lst=os.listdir(path)
    
    for pl in lst:
        imgn=cv2.imread(f'{path}/{pl}')
        images.append(imgn)
        Names.append(os.path.splitext(pl)[0].upper().split('.')[1])
        ids.append(os.path.splitext(pl)[0].upper().split('.')[0])
    
    
    def findenc(images):
        encL=[]
        for img in images:
            img=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
            enc=face_recognition.face_encodings(img)[0]
            encL.append(enc)
        
        return encL
    
    enck= findenc(images)
    x=os.listdir(os.path.join(BASE_DIR,'Project'))
    if 'CriminalSet.pk' not in x:
        pickle.dump((ids,enck, Names), open(os.path.join(BASE_DIR,'Project/CriminalSet.pk'), 'wb'))
        print("Encoded Criminal Set")
    else:
        pickle.dump((ids,enck, Names), open(os.path.join(BASE_DIR,'Project/MissingSet.pk'), 'wb'))
        print("Encoded Missing Set")
    
    
    print(Names,ids)

x=os.listdir()
if f'{filename}.pk' not in x:
    path = foldername
    Train(path)
    
