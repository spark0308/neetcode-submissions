class Twitter {
    int tweetCounter = 0;
    map<int, unordered_set<int>> users_followees;
    map<int, vector<pair<int, int>>> users_tweets;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetCounter++;
        users_tweets[userId].push_back({tweetCounter, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> heap;
        vector<int> feed;

        for(auto followee : users_followees[userId]){
            for(auto tweets : users_tweets[followee]){
                heap.push(tweets);
            }
        }

        for(auto tweets : users_tweets[userId]) heap.push(tweets);

        for(int i=0; i<10 && !heap.empty(); i++){
            feed.push_back(heap.top().second);
            heap.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        users_followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users_followees[followerId].erase(followeeId);
    }
};
