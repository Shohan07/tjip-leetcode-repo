// Time:  O(1), 
// Space: O(k), k is the max number of printed messages in last 10 seconds

class Logger {
public:
    
    Logger() {
        
    }
    
   
    bool shouldPrintMessage(int timestamp, string message) {
        while (!dq_.empty() && dq_.front().first <= timestamp - 10) {
            printed_.erase(dq_.front().second);
            dq_.pop_front();
        }
        if (printed_.count(message)) {
            return false;
        }
        dq_.emplace_back(timestamp, message);
        printed_.emplace(message);
        return true;
    }

private:
    deque<pair<int, string>> dq_;
    unordered_set<string> printed_;
};

// Time:  O(1)
// Space: O(n), n is the number of total unique messages
class Logger2 {
public:
    
    Logger2() {
        
    }
    
   
    bool shouldPrintMessage(int timestamp, string message) {
        if (message_time_.count(message) &&
            timestamp < message_time_[message] + 10) {
            return false;
        }
        message_time_[message] = timestamp;
        return true;
    }

private:
    unordered_map<string, int> message_time_;
};