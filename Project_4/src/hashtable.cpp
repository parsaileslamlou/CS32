#include "hashtable.h"

HashTable::HashTable(size_t bucketCount) : buckets_(bucketCount ? bucketCount : 1) {}

// TODO: Implement separate chaining insert/update
bool HashTable::insert(const std::string& key, const ItemHandle& value) {
    // STUB: does nothing; return false to signal "updated" (forces tests to fail until implemented)
    // (void)key; (void)value;
    std::hash<std::string> h;
    size_t hashed_index = h(key)  % bucket_count();  //size_t becuase it will fit whatever index we get
    for(Node& n:buckets_[hashed_index]){
        if(n.first == key){
            n.second = value; //std::pair == std::map
            return false; // key exists already
        }
    }
    buckets_[hashed_index].push_back({key, value});
    return true;
}

// TODO: Implement find (non-const)
ItemHandle* HashTable::find(const std::string& key) {
    //(void)key;
    std::hash<std::string> h;
    size_t hashed_index = h(key)  % bucket_count();
    for( Node& n: buckets_[hashed_index]){
        if(n.first == key) return &n.second;
    }
    return nullptr; // STUB}
}
// TODO: Implement find (const)
const ItemHandle* HashTable::find(const std::string& key) const {
    //(void)key;
    std::hash<std::string> h;
    size_t hashed_index = h(key)  % bucket_count();
    for(const Node& n: buckets_[hashed_index]){
        if(n.first == key) return &n.second;
    }
    return nullptr; // STUB
}

// TODO: Implement erase
bool HashTable::erase(const std::string& key) {
    // (void)key;
    std::hash<std::string> h;
    size_t hashed_index = h(key)  % bucket_count();
    
    std::list<Node>& bucket = buckets_[hashed_index];
    std::list<Node>::iterator bucketIt = bucket.begin();
    
    while(bucketIt != bucket.end()){
        if(bucketIt->first == key){
            buckets_[hashed_index].erase(bucketIt);
            return true;
        }
        bucketIt++;
    }
    return false; // STUB
}
