//TC: O(N)
//SC: O(N)
class MyHashMap {
public:
    vector<list<pair<int, int>>> map;
    int size = 10000;
    
    MyHashMap(){
        map.resize(size);
    }
    
    void put(int key, int value){
        auto &list = map[key % size];
        for(auto &it : list){
            if(it.first == key){
                it.second = value;
                return;
            }
        }
        return list.push_back({key, value});
    }
    
    int get(int key){
        auto& list = map[key % size];
        for(auto it : list){
            if(it.first == key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key){
        auto& list = map[key % size];
        for(auto it : list){
            if(it.first == key){
                list.remove(it);
                return;
            }
        }
    }
    
};

