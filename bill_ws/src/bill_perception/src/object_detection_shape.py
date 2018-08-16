#! /usr/bin/env python
import cv2
import numpy as np

def matchandfind(winn,imgt):
    offset=20
    _,cnts, _ = cv2.findContours(imgt, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnts = sorted(cnts, key=cv2.contourArea, reverse=True)
    if len(cnts):    
        for c in cnts:      
            rect = cv2.minAreaRect(c)
            box = np.int0(cv2.boxPoints(rect))
            cv2.drawContours(img, [box], -1, (0, 240, 0), 3)
            Xs = [i[0] for i in box]
            Ys = [i[1] for i in box]
            xl = sorted(Xs)[1]+offset
            xr = sorted(Xs)[2]-offset
            yl = sorted(Ys)[1]+offset
            yr = sorted(Ys)[2]-offset
            h=yr-yl
            w=xr-xl
            offset1=int(h/30)
            width1=int(w/4)
            points=[xl,xr,yl,yr,h,w]
            #print(points)
            cImg = imgt[yl:yl+h, xl:xl+w]
            cv2.line(cImg,(width1,0),(width1,offset1),(255, 255, 255),3)
            cv2.line(cImg,(width1*2,0),(width1*2,offset1),(255, 255, 255),3)
            cv2.line(cImg,(width1*3,0),(width1*3,offset1),(255, 255, 255),3)
            cv2.line(cImg,(width1,h),(width1,h-offset),(255, 255, 255),3)
            cv2.line(cImg,(width1*2,h),(width1*2,h-offset1),(255, 255, 255),3)
            cv2.line(cImg,(width1*3,h),(width1*3,h-offset1),(255, 255, 255),3)
            #cv2.imshow(winn, cImg)
            return cImg,points

def thre(gray):
    ret,imgt=cv2.threshold(gray,127,255,cv2.THRESH_BINARY)
    imgt = cv2.bitwise_not(imgt)
    imgt = cv2.erode(imgt, None, iterations=4)
    imgt = cv2.dilate(imgt, None, iterations=6)
    cv2.imshow("After Threshold", imgt)
    return imgt

cap = cv2.VideoCapture(0)
while cap.isOpened() :
	ret, img = cap.read()
	# img = cv2.addWeighted(img,1,np.zeros(img.shape,img.dtype),0,85)
	# img=img[50:430, 50:590]
	gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
	# imgr = thre(gray)
	# bimg,pb = matchandfind("box", imgr)
	cv2.imshow('weighted', gray)
cap.release()
cv2.destroyAllWindows()