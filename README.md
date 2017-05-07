# RelayServer
An Arduino project for controlling a relay module with a web server

## Build
For this project, you will need:
- Arduino Uno
- Ethernet Shield 
- Relay Module
- Jumper wires

## API
By default, the Arduino's IP address is hardcoded to be ```192.168.1.177```. 
This can be changed depending on your needs. 
The general API request is as follows:

```http://192.168.1.177/{action}/{pin}/{state}```

```http://192.168.1.177/{get|set|toggle}/{all|0-8}/{0|1}```

### ```actions```
- #### ```get```: gets the current state of all ```pins``` (no other parameters needed)
  - ex. ```http://192.168.1.177/get```
- #### ```set```: sets ```pin``` to a certain ```state```
  - ex. ```http://192.168.1.177/set/1/0```: sets pin index 1 ON
  - ex. ```http://192.168.1.177/set/all/1```: sets all pins OFF
- #### ```toggle```: switches ```pin``` to the opposite of it's current ```state``
  - ex. ```http://192.168.1.177/toggle/all```: toggles all pins

### ```pins```
- #### ```all```: address all of the pins
- #### ```0-7```: index of the relay pin defined in ```RelayModule.h```

### ```state```
- #### ```0```: relay ON state
- #### ```1```: relay OFF state
