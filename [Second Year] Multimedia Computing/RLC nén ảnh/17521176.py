from PIL import Image
import numpy as np

img = Image.open('broken.bmp').convert('1')
file = open("image_compress.bin","w+")
np_img = np.array(img)
print(np_img)

count = 1
img_cvt = ""
#format: luu so luong + gia tri + dau "." de phan biet giua cac pixel
for i in range(len(np_img[0])-1): #0-9
    for j in range(len(np_img[0])-1,0,-1): #9-1
        if (np_img[i][j] == np_img[i][j-1]):
            count += 1
        elif (j == 0):
            img_cvt += "1" + str(np_img[i][j]) + "."
            count = 1
        else:
            img_cvt += str(count) + str(np_img[i][j]) + "."
            count = 1
print(img_cvt)
file.write(img_cvt)
file.close()
