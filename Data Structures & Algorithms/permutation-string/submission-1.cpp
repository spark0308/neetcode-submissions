class Solution {
public:
    void printmap(map<char, int> mp){
        for(auto x: mp) cout<<x.first<<" - "<<x.second<<endl;
        cout<<"-------"<<endl;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 > n2) return false;
        map<char, int> freq1;
        map<char, int> freq2;
        for(auto x: s1) freq1[x]++;
        int i=0;
        for(int j = 0; j<n2; j++){
            freq2[s2[j]]++;
            if(freq1 == freq2) return true;
            while(freq1[s2[j]] < freq2[s2[j]]){
                freq2[s2[i]]--;
                i++;
            }
        }

        return false;
    }
};
