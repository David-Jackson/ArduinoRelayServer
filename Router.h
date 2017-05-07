#include "RelayModule.h"
#include <Ethernet.h>

class Router {
  public:
    RelayModule relay;
    void respond(String route, EthernetClient client) {
      // send a standard http response header
      Serial.println(route);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/plain");
      client.println("Access-Control-Allow-Origin: *");
      client.println("Connection: close");  // the connection will be closed after completion of the response
      client.println();
      
      if (route.indexOf("toggle/all") != -1) {
        Serial.println("Toggling all");
        relay.toggleAll();
        client.println(relay.getStates());
      } else if (route.indexOf("toggle") != -1) {
        String pin = route.substring(8, route.length());
        Serial.print("Toggling: ");
        Serial.print(pin);
        if (pin != "") relay.toggle(pin);
        client.println(relay.getStates());
      } else if (route.indexOf("set/all") != -1) {
        String state = route.substring(9, route.length());
        Serial.print("Setting all to: ");
        Serial.println(state);
        relay.setAll(state);
        client.println(relay.getStates());
      } else if (route.indexOf("set") != -1) {
        String pin = route.substring(5, route.length());
        String state = pin.substring(pin.length() - 1, pin.length());
        pin = pin.substring(0, pin.length() - 2);
        Serial.print("Setting: ");
        Serial.print(pin);
        Serial.print(" to ");
        Serial.println(state);
        relay.set(pin, state);
        client.println(relay.getStates());
      } else if (route.indexOf("get") != -1) {
        Serial.print("Getting Current States: ");
        Serial.println(relay.getStates());
        client.println(relay.getStates());
      } else {
        Serial.print("Ignoring request: ");
        Serial.println(route);
        client.print("Ignoring: ");
        client.println(route);
      }
    };
    Router(void) {
      relay.init();
    }
};

