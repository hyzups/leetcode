#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

struct Tweet {
public:
    int tweetId;
    int time;

    Tweet(int tweetId, int time) {
        this->tweetId = tweetId;
        this->time = time;
    }

};

class Twitter {
private:
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, set<int>> followers;
    int time = 0;

public:
    /** Initialize your data structure here. */
    Twitter() {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, ++time);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        using iter = vector<Tweet>::reverse_iterator;

        auto f = [](const pair<iter, iter>& a, const pair<iter, iter>& b) {
            return a.first->time < b.first->time;
        };

        priority_queue<pair<iter, iter>, vector<pair<iter, iter>>, decltype(f)> p(f);

        for (auto followerId : followers[userId]) {
            if (tweets[followerId].size() > 0)
                p.emplace(tweets[followerId].rbegin(), tweets[followerId].rend());
        }
        if (tweets[userId].size() > 0) {
            p.emplace(tweets[userId].rbegin(), tweets[userId].rend());
        }

        vector<int> res;

        int n = 10;
        while (n > 0 && !p.empty()) {
            auto temp = p.top();
            p.pop();
            res.push_back(temp.first->tweetId);
            temp.first++;
            if (temp.first != temp.second) {
                p.emplace(temp.first, temp.second);
            }
            n--;
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].erase(followeeId);
        }
    }
};
