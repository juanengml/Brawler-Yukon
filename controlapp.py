

from flask import Flask
from flask import render_template, request,url_for
import serial
import time


app = Flask(__name__, static_url_path='/static')

print "DOne"

try: 
  arduino = serial.Serial("/dev/ttyACM0",9600)
except: pass

@app.route("/")

def index():
    return render_template('robot.html')

@app.route('/left_side')
def left_side():
    data1="LEFT"
    arduino.write('a')
    time.sleep(0.3)
    arduino.write('p')
    print data1
    return 'true'

@app.route('/right_side')
def right_side():
   data1="RIGHT"
   arduino.write('d')
   time.sleep(0.3)
   arduino.write('p')
   print data1
   return 'true'

@app.route('/up_side')
def up_side():
   data1="FORWARD"
   arduino.write('w')
   time.sleep(0.3)
   arduino.write('p')
   print data1
   return 'true'

@app.route('/down_side')
def down_side():
   data1="BACK"    
   arduino.write('w')
   time.sleep(0.3)
   arduino.write('p')
   print data1
   return 'true'

@app.route('/stop')
def stop():
   data1="STOP"
   arduino.write('p')
   print data1
   return  'true'

if __name__ == "__main__":
 print "Start"
 app.run(host='0.0.0.0',port=80,debug=True)

