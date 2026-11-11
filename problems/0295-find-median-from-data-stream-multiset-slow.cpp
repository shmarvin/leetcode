// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/
// Difficulty: Hard

class MedianFinder {
public:
    /*
    Extension: Solve it without using priority queues. (Try another DS)

    Multiset with iterator pointing to center. For even number, point to the left element of the center 2.
    Every time an element is added, check if its larger or smaller than middle.

    Cases.
    If currently odd length:
    - elt added smaller -> median moves down one
    - elt added larger -> nothing
    If currently even length:
    - elt added smaller -> nothing
    - elt added larger -> median moves up one

    When adding an elt that alr exists, it gets added AFTER existing copies.
    */
    std::multiset<int> elements;
    std::multiset<int>::iterator med_it = elements.end();
    
    MedianFinder() {}
    
    void addNum(int num) {
        elements.insert(num);
        if(elements.size() == 1) {
            --med_it;
        } else if (elements.size() % 2 == 0) {
            if (num < *med_it) {
                --med_it;
            }
        } else {
            if (num >= *med_it) {
                ++med_it;
            }
        }
    }
    
    double findMedian() {
        if (elements.size() % 2 == 0) return ((double)(*med_it) + (double)(*next(med_it)))/2;
        else return *med_it;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */