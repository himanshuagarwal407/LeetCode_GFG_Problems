class Twitter {
    map<int, set<int>> map;
    list<pair<int, int>> tweets;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_front({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> v;
        
        for(auto x:tweets)
        {
            int id = x.first;
            int post = x.second;
            
            if(map[userId].find(id)!=map[userId].end() || userId==id)
                v.push_back(post);
            if(v.size()==10)
                return v;
        }
        
        return v;
    }
    
    void follow(int followerId, int followeeId) {
        map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        map[followerId].erase(followeeId);
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