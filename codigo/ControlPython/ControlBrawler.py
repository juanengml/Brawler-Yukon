#!/usr/bin/env python
# -*- coding: utf-8 -*-

import zbar 
from PIL import Image 
import cv2 
from serial import Serial

comp = open("dados","rb").read().split("\n\n")[0].split("\n")  
comm = False
try:
    arduino = Serial("/dev/ttyACM0",9600)
    comm = True
    try:
        arduino = Serial("/dev/ttyACM1",9600)
        comm = True
    except:
        arduino = Serial("/dev/ttyUSB0",9600)
        comm = True
else:
    print "Fail Port Connected !"
    comm = False


def main():
    
    capture = cv2.VideoCapture(1) 

    while True:
        if cv2.waitKey(1) & 0xFF == ord('q'): 
            break
        ret, ibagem = capture.read() 
        gray = cv2.cvtColor(ibagem, cv2.COLOR_BGR2GRAY) 
        image = Image.fromarray(gray)  
        width, height = image.size 
        zbar_image = zbar.Image(width, height, 'Y800', image.tostring())
        scanner = zbar.ImageScanner() 
        scanner.scan(zbar_image)  
        cv2.imshow('Detect QRCODE', ibagem)
#        cv2.imshow('gray', gray)

        for decoded in zbar_image: 
            text = decoded.data  
#            print text
            for p in range(len(comp)): 
                if text == comp[p]:
                   print "TEXT:",text,"\t COMPARAR:",comp[p] 
                   if text == "siga em frente":
                    if comm == True:
                        print text
                        arduino.write('w')
                    else:
                        print "Board not Detect ! "

                   if text == "vire a esquerda":
                    if comm == True:
                        print text
                        arduino.write('a')
                    else:
                        print "Board not Detect ! "    

                   if text == "retorne":
                    if comm == True:
                        print text
                        arduino.write("s")
                    else:
                        print "Board not Detect ! "    

                   if text == "pare":
                    if comm == True:
                        print text
                        arduino.write('p')
                    else:
                        print "Board not Detect ! "

                   if text == "vire a direita":
                    if comm == True:
                        print text
                        arduino.write('d')
                    else:
                        print "Board not Detect ! "


if __name__ == "__main__": # EXECUTA A FUNÇÃO 
    main()
