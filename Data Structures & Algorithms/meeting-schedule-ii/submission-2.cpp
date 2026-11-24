/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](const Interval&a, const Interval&b){return a.start<b.start;});
        int ans = 0;
        // minHeap to store end time
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto&iv: intervals){
            int start = iv.start;
            int end = iv.end;
            while(!pq.empty() && pq.top()<= start ){
                pq.pop();
            }
            pq.push(end);
            ans = max(ans,(int)pq.size());
        }
        return ans;
    }
};
