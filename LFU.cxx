#include <list>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Using typedef to make things easier to understand
// We will use a linkedlist of a pair of integers
// where the first integer will be the key
// and the second integer will be the value

typedef std::pair<int, int> KeyValuePairLL;

struct Element {
    public:
    KeyValuePairLL value_;
    int freq_;
    Element(KeyValuePairLL value, int freq): value_(value),freq_(freq) {

    }
    Element():value_(-1,-1),freq_(-1) {}
    bool comparator( const Element& that) {
        if (freq_<= that.freq_) return true;
        return false;
    }
    Element(const Element& that) {
        value_ = that.value_;
        freq_ = that.freq_;
    }
    Element& operator=(const Element& that) {
        value_ = that.value_;
        freq_ = that.freq_;
        return *this;
    }
};

class LFUCache {
    vector<Element> x;
    int size=0;
    int c_;
    map<int,int> keyToHeapIndexMapT;
public:
// Constructor that sets the size of the cache
    LFUCache(int capacity):c_(capacity)
    {
       x.resize(c_, Element(KeyValuePairLL(-1, -1),INT_MAX));    
    }
    int Get(int key)
    {
        if ( keyToHeapIndexMapT.find(key) !=keyToHeapIndexMapT.end()){
          cout << "Key found: " << endl; 
          return GetValueChangeFreq( keyToHeapIndexMapT[key]);
        } else {
            return -1;
        }        
    }

    void Put(int key, int value)
    {
        cout << "Put: " << key << " : " << value << endl;
        if ( keyToHeapIndexMapT.find(key) !=keyToHeapIndexMapT.end()){
           SetValueChangeFreq( keyToHeapIndexMapT[key], value);
        } else {
           int index = push(Element(KeyValuePairLL(key,value),1));
           cout << "Pushed element: " << index << endl;
           keyToHeapIndexMapT.insert(pair<int,int>(key, index));
        }
        
    }

    int Heapify(int index) {
      if (index*2<=size) {
        if ( x[index].comparator(x[index*2])) {

        } else {
            Element temp = x[index];
            x[index] = x[index*2];
            x[index*2] = temp;
            return Heapify(index*2);
        }
      }
      
      int child2 = index*2+1;
      if ( child2<=size) {
        if ( x[index].comparator(x[child2])) {

        } else {
            Element temp = x[index];
            x[index] = x[child2];
            x[child2] = temp;
            return Heapify(child2);
        }
      }
      return index;
    }

    int pop() {
        if( size <=0) return -1;
        Element top = x[0];
        x[0] = x[size--];
        Heapify(0);
        return top.value_.second;
    }

    int HeapUp(int index) {
        if (index==0) return 0;
        if ( x[index].comparator(x[index/2])) {
            Element e = x[index];
            x[index] = x[index/2];
            x[index/2] = e;
            return HeapUp(index/2);
        }
        return index;
    }
   
    int GetValueChangeFreq(int index) {
        if (index>=size) return -1;
        int val = x[index].value_.second;
        x[index].freq_++;
        Heapify(index);
        return val;
    }

    int SetValueChangeFreq(int index, int value) {
        if (index>=size) return -1;
        x[index].value_.second = value;
        x[index].freq_++;
        return Heapify(index);
    }
   
    int push(Element e) {
    if ( size<c_) {
        x[size++] = e;
        return HeapUp(size-1);
    } else {
        // pop the least freq element
        x[0] = e;
        return Heapify(0);
    }
   }

};


int main () {
    LFUCache c(2);
    cout << c.Get(10) << endl;
    c.Put(10,10);
    cout << c.Get(10) << endl;
    return 0;
}