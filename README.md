# Remote-controlled-traffic-light
I used red, yellow and green LED's and an infrared receiver and remote to control what LED's turn on, and they light up like a traffic light.

## The build
It's a very simple build that taught me a lot on how to use infrared signals to control outputs. I started out with LED's to give me a safe, less time-consuming experiment to learn the basics of infrared control with an Arduino. After watching some videos and getting some ideas, I managed to pull through and build it. 

## How it works. 
The LED's only turn on when a specific signal from the remote is received by the receiver. I only programmed it to respond to 6 buttons; 3 to turn each LED on, andanother 3 to turn each of them off. I learned the basics of decoding the signals using '.command' and '.decodedRawData', which both return different values. 

## Footage
Here's some footage of it working: 

![Untitledvideo-MadewithClipchamp4-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/cae0751c-d010-49ea-8900-9b0b0d4421e6)

