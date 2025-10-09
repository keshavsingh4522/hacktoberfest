import cv2
import numpy as np
import os

def xor_two_pictures(path1, path2):
    picture1 = cv2.imread(os.getcwd() + "/" + path1)
    picture2 = cv2.imread(os.getcwd() + "/" + path2)

    assert picture1.shape == picture2.shape, "invalid size"

    h, w, c = picture1.shape
    ans = np.empty([h, w, c])
    for i in range(h):
        for j in range(w):
            for k in range(c):
                ans[i][j][k] = picture1[i][j][k] ^ picture2[i][j][k]

    cv2.imwrite("ans.png", ans)
