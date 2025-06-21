// https://leetcode.com/problems/design-twitter/

class Twitter {
private:
    struct Tweet {
        int tweetId;
        int time;
        
        Tweet(int tweetId, int time) : tweetId(tweetId), time(time) {}
    };

    int timeStamp = 0;  
    unordered_map<int, vector<Tweet>> userTweets;  
    unordered_map<int, unordered_set<int>> followers; 

public:
    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back(Tweet(tweetId, timeStamp++));
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<pair<int, int>> pq; 
        
        for (const auto& tweet : userTweets[userId]) {
            pq.push({tweet.time, tweet.tweetId});
        }

        if (followers.find(userId) != followers.end()) {
            for (int followee : followers[userId]) {
                for (const auto& tweet : userTweets[followee]) {
                    pq.push({tweet.time, tweet.tweetId});
                }
            }
        }
        
        int count = 0;
        while (!pq.empty() && count < 10) {
            result.push_back(pq.top().second);
            pq.pop();
            ++count;
        }
        
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {  
            followers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {  
            followers[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */