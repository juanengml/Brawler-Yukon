import time 
import os 
import random
import datetime 


def sensor1(): # Esquerda
  distancia = random.choice(range(0,100))
  return distancia

def sensor2(): #Direita
  distancia = random.choice(range(0,100))
  return distancia

def sensor3(): #Frente
  distancia = random.choice(range(0,100))
  return distancia


def main():
  while True:
    if sensor1() > sensor2():
           print "Vire esquerda 90graus "
    if sensor1() < sensor2():
           print "Vire direita 90graus "
    if sensor1() == sensor2():
           for p in range(0,180):
               time.sleep(0.5)
               if sensor1() > sensor2():
                  print "Vire esquerda 90graus"

               if sensor1() < sensor2():
                  print "Vire Direita 90graus "


main()
