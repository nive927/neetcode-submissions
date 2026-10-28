class LRUCache {
public:

    // key, value, key order (iterator pointer) in the list
    unordered_map<int, pair<int, list<int>::iterator>> cache;

    // keys are stored
    list<int> order;
    int capacity;

    LRUCache(int capacity) {
        
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        
        if(cache.find(key) == cache.end()) {
            return -1;
        }

        // erase the key using the iterator pointer
        order.erase(cache[key].second);
        // move to the back - most recently used
        order.push_back(key);
        // update the cache pointer
        cache[key].second = --order.end();
        return cache[key].first;


    }
    
    void put(int key, int value) {

        // if the key already exist, just update the value
        // and move it to the back (similar to get)
        if(cache.find(key) != cache.end()) {
            // delete the key in the order DLL using the iterator pointer
            order.erase(cache[key].second);
            // move it to the end
            order.push_back(key);
            // update the cache
            cache[key].first = value;
            cache[key].second = --order.end();
            return;
        }

        else if (cache.size() == this->capacity) {
            // remove the front pair
            int keyToErase = order.front();
            order.pop_front();
            cache.erase(keyToErase);
            order.push_back(key);
            cache[key] = {value, --order.end()};
            return;
        } else {     
            order.push_back(key);
            cache[key] = {value, --order.end()};
        }
    }
};
