class Request {
  public:
    void setRequestText(String s) {
      requestText = s;
    };
    String getRequestText(void) {
      return requestText;
    };
    void setPath(String s) {
      path = s;
    };
    String getPath(void) {
      return path;
    };
    void parseRequest(String _reqText) {
      setRequestText(_reqText);

      String parseString = "";
      boolean finishOnNext = false;
      
      for (int i = 0; i < _reqText.length(); i++) {
        char c = _reqText.charAt(i);
        if (c == ' ' || c == '\r' || c == '\n') {
          if (finishOnNext) {
            setPath(parseString);
            break;
          } else {
            if (parseString == "GET") {
              finishOnNext = true;
            }
          }
          parseString = "";
        } else {
          parseString += c;
        }
      }
      
    };
  private:
    String requestText = "";
    String path = "";
};

