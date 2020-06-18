class Solution {
public:
    int hIndex(vector<int>& arr) {
        if (arr.size() == 0) {
		    return 0;
        }
        int si = 0, size = arr.size(), ei = size - 1;
        while(si <= ei) {
            int mid = (si + ei) >> 1;
            if (arr[mid] == size - mid) {
                return arr[mid];
            } else if(arr[mid] > size - mid) {
                ei = mid - 1;
            } else {
                si = mid + 1;
            }
        }
        return size - si;
    }
};
