class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> map;

    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    void mostRecentlyUsed(int key){
        dll.erase(map[key].first);
        dll.push_front(key);
        map[key].first = dll.begin();
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        
        mostRecentlyUsed(key);

        return map[key].second;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            map[key].second = value;
            mostRecentlyUsed(key);
        }else{
            dll.push_front(key);
            map[key] = {dll.begin(), value};
            n--;
        }

        if(n < 0){
            int todel = dll.back();
            map.erase(todel);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */