/*
For the given stream of message requests and their timestamps as input,
you must implement a logger rate limiter system that decides whether the current message request is displayed.
The decision depends on whether the same message has already been displayed in the last S seconds.
If yes, then the decision is FALSE, as this message is considered a duplicate. Otherwise, the decision is TRUE.

Note: Several message requests, though received at different timestamps, may carry identical messages.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class RequestLogger {
  private:
      unordered_map<string, int> requests;
      int timeLimit;

  public:

  RequestLogger(int newTimeLimit) :timeLimit(newTimeLimit){
  }
  
    bool MessageRequestDecision(int timestamp, string request) {

      if(requests.find(request)==requests.end()){
        requests.insert(pair<string,int>(request,timestamp));
        return true;
      } else {
        int oldtimestamp = requests[request];
        if ((timestamp-oldtimestamp)>timeLimit) {
            requests[request]=timestamp;
            return true;
        }
      }
      return false;
    }
};

