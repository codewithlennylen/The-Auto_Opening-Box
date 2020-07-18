# The-Auto_Opening-Box
 This is a simple Arduino project modelled after the contactless bins all over YouTube
 
 Especially due to the Covid-19 pandemic, most innovative projects are built around contactless devices,
 Such as Automatic Dispenser, Non-contact Infrared Thermometer and so much more
 This project (The-Auto_Opening-Box) is a mockup of the non-contact dust-bins I watched while browsing YouTube
 
 ## Project Requirements
 The Project is very simple as it contains:
 + HC-SRO4 Ultrasonic Sensor (HY SRF-05 Ultrasonic Sensor will work as well)
 + 9gram Servo (Any servo motor will work)
 + Arduino Mega(Arduino Uno & Nano Boards will also work just fine)
 
 ## How It Works
 The Ultrasonic sensor triggers the open_box function when the distance between the sensor and the obstacle/object is less than a threshold/trigger distance
 In this case, the trigger distance is set to 15cm.
 Once triggered, the servo opens the box and remains open for a certain period of time (openDelay); which in my case is 2 seconds.
 
 ***
 
 ### Feel Free to Contribute to the Project and also Star & Fork this Project if it Inspires You or Find it Cool & Useful.
