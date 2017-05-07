// Relay module class
// by default, this assumes an 8 Relay Module connected on pins 2-9

class RelayModule {
  public:
    const static int numberOfPins = 8;                  // Number of relays in module
    int pins[numberOfPins] = {2, 3, 4, 5, 6, 7, 8, 9}; // pins used by relay module 
    boolean states[numberOfPins] = {false, false, false, false, false, false, false, false}; // relay state (true = HIGH = off) (false = LOW = on)
    
    void init(void) {
      for (int i = 0; i < numberOfPins; i++) {
        pinMode(pins[i], OUTPUT);     // set all pins as output
        digitalWrite(pins[i], HIGH);  // set all modules off
        states[i] = true;             // set state off
      }
    };

    // toggle will toggle the state of a given pin
    void toggle(int pin) {
      states[pin] = !states[pin];
      digitalWrite(pins[pin], states[pin]);
    };
    
    void toggle(String pin) {
      toggle(pin.toInt());
    };

    // toggleAll will toggle the state of all of the pins
    void toggleAll(void) {
      for (int i = 0; i < numberOfPins; i++) {
        toggle(i);
      }
    };

    // set will set a given pin to a given state
    void set(int pin, boolean state) {
      states[pin] = state;
      digitalWrite(pins[pin], state);
    };
    
    void set(String pin, String state) {
      set(pin.toInt(), state.toInt());
    };

    // when given a byte, set will set all of the pins based on the bits of a byte
    void set(byte b) {
      for (int i = 0; i < numberOfPins; i++) {
        set(i, ((b >> i)  & 0x01));
      }
    };

    void set(int setStates[]) {
      for (int i = 0; i < numberOfPins; i++) {
        set(i, setStates[i]);
      }
    };

    void set(String s) {
      for (int i = 0; i < numberOfPins; i++) {
        char c = s.charAt(i);
        boolean b = (c == '1');
        set(i, b);
      }
    };

    void setAll(boolean state) {
      for (int i = 0; i < numberOfPins; i++) {
        set(i, state);
      }
    };

    void setAll(String s) {
      boolean b = (s == "1");
      setAll(b);
    }

    String getStates() {
      String res = "";
      for (int i = 0; i < numberOfPins; i++) {
        res += (states[i]) ? "1" : "0";
      }
      return res;
    }
};
