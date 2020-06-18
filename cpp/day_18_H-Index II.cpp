class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size(), mid, left = 0, right = N-1;
        while(left <= right){
            mid = left + (right - left)/2;
            if(citations[mid] == N - mid){
                return citations[mid];
            }else if(citations[mid] > N - mid){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return N - left;
    }
};
