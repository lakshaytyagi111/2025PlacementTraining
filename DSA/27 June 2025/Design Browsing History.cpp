// https://leetcode.com/problems/design-browser-history/

class BrowserHistory {
private:
    vector<string> history;
    int curr;
    int last;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
        last = 0;
    }

    void visit(string url) {
        curr++;
        if (curr == history.size()) {
            history.push_back(url);
        } else {
            history[curr] = url;
        }
        last = curr;  
    }

    string back(int steps) {
        curr = max(0, curr - steps);
        return history[curr];
    }

    string forward(int steps) {
        curr = min(last, curr + steps);
        return history[curr];
    }
};
