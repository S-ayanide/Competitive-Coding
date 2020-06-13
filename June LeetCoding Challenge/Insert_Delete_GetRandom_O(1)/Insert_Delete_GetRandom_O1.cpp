class RandomizedSet {
public:
    unordered_set<int>con;
    vector<int>v;
    RandomizedSet() {
        con.clear(),v.clear();
    }
    
    bool insert(int val) {
        if(!con.empty()){// - > when there are some element into the set
           auto it = find(begin(con),end(con),val);// - > to check if the element is alredy there
            if(it==con.end()){// -> element is not present
                con.insert(val),v.push_back(val);//do insert
            }else{//  - > element is present 
              return false;  
            }
        }else{// - > set is empty we need to insert 
                con.insert(val),v.push_back(val);
            }
        return true;
    }
    bool remove(int val) {
        if(con.empty())return false;// - > no elements are there return false
        auto it = find(begin(con),end(con),val);// - > find that element is exist or not
        if(it==end(con))return false;// - > element is not thre return false
        con.erase(it);// - > delete that element from vector and set
        auto it1 = find(begin(v),end(v),val);
        v.erase(it1);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];//
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
