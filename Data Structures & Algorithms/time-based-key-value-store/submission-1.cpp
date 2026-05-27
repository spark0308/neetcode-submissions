class TimeMap {
public:
    map<string, vector<pair<string, int>>> timeMap;

    TimeMap() {
        timeMap = map<string, vector<pair<string, int>>>();
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        if(!timeMap.contains(key)) return "";
        int low = 0;
        int high = timeMap[key].size() - 1;
        string result = "";

        while(low <= high){
            int mid = (high-low)/2 + low;

            if(timestamp == timeMap[key][mid].second){
                result = timeMap[key][mid].first;
                break;
            }
            else if(timestamp > timeMap[key][mid].second){
                result = timeMap[key][mid].first;
                low = mid + 1;

            }
            else if(timestamp < timeMap[key][mid].second) high = mid - 1;
        }

        return result;
    }
};
