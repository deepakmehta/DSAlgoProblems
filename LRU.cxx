#include <list>
#include <iostream>
#include <map>
using namespace std;

// Using typedef to make things easier to understand
// We will use a linkedlist of a pair of integers
// where the first integer will be the key
// and the second integer will be the value

typedef std::list<std::pair<int, int>> KeyValuePairLL;

class LRUCache
{
    KeyValuePairLL list_;
    map<int,KeyValuePairLL::iterator> map_;
    int c_=0;
    public:
        // Constructor that sets the size of the cache
        LRUCache(int capacity):c_(capacity) 
        {
            // Write your code here
        }

        int Get(int key)
        {
            if(map_.find(key)==map_.end()) return -1;
            KeyValuePairLL::iterator iter = (*(map_.find(key))).second;
            pair<int,int> keyValuePair = *iter;
            list_.erase(iter);
            list_.push_back(keyValuePair);
            map_.insert(pair<int,KeyValuePairLL::iterator>(key,(--list_.end())));
            return keyValuePair.second;
        }

        void Set(int key, int value)
        {
           if (Get(key)== -1) {
            if (list_.size()<c_) {
                list_.push_back(pair<int,int>(key,value));
                map_.insert(pair<int,KeyValuePairLL::iterator>(key,(--list_.end())));
            } else {
                list_.pop_front();
                list_.push_back(pair<int,int>(key,value));
                map_.insert(pair<int,KeyValuePairLL::iterator>(key,(--list_.end())));
            }
           } else {
            KeyValuePairLL::iterator iter = (*(map_.find(key))).second;
            //pair<int,int> keyValuePair = *iter;
            list_.erase(iter);
            list_.push_back(pair<int,int>(key,value));
            map_.insert(pair<int,KeyValuePairLL::iterator>(key,(--list_.end())));
           }
        }
        
};
