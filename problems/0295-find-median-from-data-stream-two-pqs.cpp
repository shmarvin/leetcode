// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/
// Difficulty: Hard

class MedianFinder {
/*
If we can somehow maintain an upper and lower pq...

Rebalance on every add.

We put half in each, such that the lower one is a max PQ, higher one is a min pq
inserts are all O(logn) and find median is O(1)
we either take the pq with larger size or take both!

ALTERNATIVE SOLUTION: Multiset with iterator tracking median
*/
private:
    std::priority_queue<int, std::vector<int>, std::less<int>> lower_pq;
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper_pq;

public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        // Add number into appropriate pq by comparing to tops
        // if diff in size is ever >= 2, rebalance (one time op)

        // Insert (first goes to lower)
        if(lower_pq.empty() || num <= lower_pq.top()) {
            lower_pq.push(num);
        } else {
            upper_pq.push(num);
        }

        // Rebalance (if diff by 2 or more)
        if (lower_pq.size() > upper_pq.size() + 1) {
            upper_pq.push(lower_pq.top());
            lower_pq.pop();
        } else if (upper_pq.size() > lower_pq.size() + 1) {
            lower_pq.push(upper_pq.top());
            upper_pq.pop();
        }
    }
    
    double findMedian() {
        int diff = lower_pq.size() - upper_pq.size();
        if(diff < 0) {
            return upper_pq.top();
        } else if (diff > 0) {
            return lower_pq.top();
        } else {
            return double(upper_pq.top() + lower_pq.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */