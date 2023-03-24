/*
Design a stack-like data structure.
You should be able to push elements to this data structure and pop elements with maximum frequency.
You’ll need to implement the FreqStack class that should consist of the following:


FreqStack: This is a class used to declare a frequency stack.
Push(data): This is used to push an integer data onto the top of the stack.
Pop(): This is used to remove and return the most frequent element in the stack.

Note: If there is a tie for the most frequent element, then the most recently pushed element is removed and returned.

Constraints:
0≤value ≤10^9
At most, 2×10^3 calls will be made to Push() and Pop().
It is guaranteed that there will be at least one element in the stack before calling Pop().
*/

//#include<queue>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Number {
    public:
  int data_;
  int freq_;
  int stamp_;
  Number(int data, int freq,int stamp):data_(data),freq_(freq),stamp_(stamp){}
};

bool compare( Number a, Number b) {
  if (a.freq_<b.freq_) return true;
  if(a.stamp_<b.stamp_) return true;
  return false;
}


class FreqStack {
    private:
    vector<Number> q_;
   int size_=0;
   int numberofPush_=0;
   map<int,int> dataToIndexMap_;
  public:
    // Use constructor to initialize the maxFrequency
    FreqStack() {
        
    }
    

void HeapifyUp(int index) {
    while(index!=0) {
       if(compare(q_[index/2],q_[index])) {
        // lets swap elements
        Number temp =q_[index/2];
        q_[index/2]=q_[index];
        q_[index] =temp;
        
        // change the data to index map
        dataToIndexMap_[q_[index].data_]=index;
        dataToIndexMap_[q_[index/2].data_]=index/2;
        index=index/2;
       } else {
        //return index;
        //break;
       }
    }
  //return 0;
}

void IncreaseFreq(int index) {
    // get the elemnent
    q_[index].freq_++;
    q_[index].stamp_=numberofPush_++;
    HeapifyUp(index);
}

    // Use push function to push the data into the FreqStack
    void push(int data) {
        if(dataToIndexMap_.find(data)!=dataToIndexMap_.end()) {
            IncreaseFreq(dataToIndexMap_[data]);
        } else {
            // Number not present
            Number insert(data,1,numberofPush_++);
            q_.push_back(insert);
            size_++;
            dataToIndexMap_[q_[size_-1].data_]=size_-1;
            HeapifyUp(size_-1);
        }
    }
    
    // Use the pop function to pop the data from the FreqStack
    int pop() {
        if (size_==0) {
            return INT_MAX;
        }
        int data = q_[0].data_;
        if ( q_[0].freq_-->1) {
         HeapifyDown(0);

        } else {
        // Lets move the element at the end to top
        if (size_>1) {
        q_[0]=q_[--size_];
        HeapifyDown(0);
        } else {
           q_.pop_back();
           size_--; 
        }

        dataToIndexMap_.erase(data);
        }
        return data;
    }

    void HeapifyDown(int index) {

       if ((2*index +1)<size_) {
        // lets compare the elements
        if (compare(q_[index],q_[2*index+1])) {
            // lets swap
            Number temp = q_[2*index+1];
            q_[2*index+1] = q_[index];
            q_[index] = temp;
             dataToIndexMap_[q_[2*index+1].data_]=2*index+1;
             dataToIndexMap_[q_[index].data_]=index;
            HeapifyDown(2*index+1);
            return;
        }
       }
       
       if ((2*index +2)<size_) {
        // lets compare the elements
        if (compare(q_[index],q_[2*index+2])) {
            // lets swap
            Number temp = q_[2*index+2];
            q_[2*index+2] = q_[index];
            q_[index] = temp;
            dataToIndexMap_[q_[2*index+2].data_]=2*index+2;
            dataToIndexMap_[q_[index].data_]=index;
            HeapifyDown(2*index+2);
            return;
        }
       }

    }
};

int main(){
    FreqStack f;
    f.push(5);
    f.push(7);
    f.push(7);
    f.push(5);
    cout << f.pop() << endl;
    f.push(7);
    cout << f.pop() << endl;
}