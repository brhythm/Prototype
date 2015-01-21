/*
 * Solution.cpp
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and set.
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache,
 *            otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present.
 *                   When the cache reached its capacity,
 *                   it should invalidate the least recently used item before inserting a new item.
 */
#include <unordered_map>
#include <list>
#include <assert.h>
using namespace std;

class LRUCache{
public:
    struct CacheNode
    {
        int key;
        int value;
        CacheNode(int k, int v)
        :key(k),
         value(v)
        {
        }
    };
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        //query hashmap to see whether key is found or not
        //if found, fetch value, move that node to the head of list
        //if not found, return -1

        int value = -1;
        auto mapIter = m_listIteratorMap.find(key);
        if ( mapIter != m_listIteratorMap.end())
        {//key found
            auto listIterator = mapIter->second;
            value = (*listIterator).value;
            //learn how to use splice to transfer elements from list WITHOUT copy
            //Note: splice function only takes iterator, not pointer to nodes
            m_cacheList.splice(m_cacheList.begin(), m_cacheList, listIterator);
            //iterators shall still be valid after splice function call
            assert(m_cacheList.begin() == listIterator);
        }//not found , return default value
        return value;
    }

    void set(int key, int value) {
        //if key not found
        //   if hash.size == m_capacity, remove list tail node, remove it from hash
        //   insert new cache at list head, add it to hash
        //else
        //   update value for that cache
        //   move it to the list head

        //warning, only dump last node if key is not found
        auto mapIter = m_listIteratorMap.find(key);
        if ( mapIter == m_listIteratorMap.end()) {
            if (m_listIteratorMap.size() == m_capacity) {
                //warning, end() points to past-end position!!!
                //auto listIter = m_cacheList.end();
                m_listIteratorMap.erase(m_cacheList.back().key);
                m_cacheList.pop_back();
            }
            CacheNode newCache(key, value);
            m_cacheList.push_front(newCache);
            m_listIteratorMap[key] = m_cacheList.begin();
        }
        else
        {//key is found
            auto listIter = mapIter->second;
            (*listIter).value = value;//listIterator value shall not change
            m_cacheList.splice(m_cacheList.begin(), m_cacheList, listIter);

        }
    }

    list<CacheNode> m_cacheList;
    unordered_map<int, list<CacheNode>::iterator> m_listIteratorMap;
    int m_capacity;
};

//why do we have to define cacheNode ?? why not use list<int> , where int is the value ??
//because when deleting the least recently used node from hash,
//we know the list tail, but if it is only a value, we could not get the associated key , then no way to erase that item from hash
//suprise


