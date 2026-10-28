class LRUCache {
public:

    list<int> order;
    unordered_map<int, pair<int, list<int>::iterator>> cache; // (k, (v, pointer to list))
    int capacity;

    LRUCache(int capacity) {

        this->capacity = capacity;
        
    }
    
    int get(int key) {

        if(cache.find(key) == cache.end()) {
            return -1;
        }

        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();
        return cache[key].first;
        
    }
    
    void put(int key, int value) {


        // if key is not present
        if (cache.find(key) == cache.end()) {

            // delete needs to be performed, if at capacity
            if(cache.size() == capacity) {
                int k = order.front();
                order.pop_front(); 
                cache.erase(k);
            }

            order.push_back(key);
            cache[key].first = value;
            cache[key].second = --order.end();
        } else {

            order.erase(cache[key].second);
            order.push_back(key);
            cache[key].first = value;
            cache[key].second = --order.end();
        }
        
    }
};
