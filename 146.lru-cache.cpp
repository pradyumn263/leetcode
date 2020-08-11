/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (32.52%)
 * Likes:    6207
 * Dislikes: 262
 * Total Accepted:    577.8K
 * Total Submissions: 1.7M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 /* capacity  );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 * 
 * 
 */

// @lc code=start
class LRUCache {
public:
    list<int> l;
    map<int, pair<int, list<int>::iterator>> mp;
    int maxCap;
    LRUCache(int capacity) {
        maxCap = capacity;
        mp.clear();
        l.clear();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        list<int>::iterator it;
        it = mp[key].second;
        l.erase(it);
        l.push_front(key);
        it = l.begin();
        mp[key].second = it;
        return mp[key].first;
    }
    
    void put(int key, int value) {
        //If it is not present
        list<int>::iterator it;
        if(mp.find(key) == mp.end()) {
            if(maxCap == 0) {
                //Remove LRU item
                int k = l.back();
                l.pop_back();
                mp.erase(k);
                maxCap++;
            }
            l.push_front(key);
            it = l.begin();
            mp[key] = {value, it};
            maxCap--;
        } else {
            //Delete Node and append to front
            it = mp[key].second;
            l.erase(it);
            l.push_front(key);
            it = l.begin();
            mp[key].first = value;
            mp[key].second = it;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

