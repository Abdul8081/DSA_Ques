class Solution {
public:
    using ll = long long int;
    bool checkIfCanReduceInTimeMidByAllWorker(ll mid, int mH, vector<int>& workerTimes){
        ll height = 0;
        for(int &t: workerTimes) {
            height += (ll)(sqrt(2.0 * (mid / t) + 0.25) - 0.5);
            // this calculation can be obtained buy solving QE
            // height = t * (currHeight * (currHeight + 1)) / 2;
            // from this we can get currHeight
            if(height >= mH)  return true;
        }
        return height >= mH;
    }
    ll minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(begin(workerTimes), end(workerTimes));
        ll result = 0;

        ll low = 1;
        ll high =  (1LL * maxTime * mountainHeight * (mountainHeight + 1)) >> 1;

        while(low <= high) {
            ll mid = low + ((high - low) >> 1);

            if(checkIfCanReduceInTimeMidByAllWorker(mid, mountainHeight, workerTimes)){
                result = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return result;
    }
};
