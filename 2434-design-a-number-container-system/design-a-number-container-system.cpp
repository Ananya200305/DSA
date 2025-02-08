class NumberContainers {
unordered_map<int,int> index_no;
unordered_map<int, set<int>> no_index;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(index_no.count(index)){
            no_index[index_no[index]].erase(index);
            if(no_index[index_no[index]].size() == 0){
                no_index.erase(index_no[index]);
            }
        }
        index_no[index] = number;
        no_index[number].insert(index);
    }
    
    int find(int number) {
        if(!no_index.count(number)){
            return -1;
        }
        return *no_index[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */