class Solution {
public:
    bool isFre(int Fre1[],int Fre2[]){
        for(int i=0; i<26; i++){
            if(Fre1[i] !=Fre2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i = 0; i<s1.length(); i++){
            freq[s1[i] - 'a']++;
        }
        int windSize = s1.length();
        for(int i = 0; i<s2.length(); i++){
            int windidx = 0,idx= i;
            int windFre[26]= {0};

            while(windidx < windSize && idx < s2.length()){
                windFre[s2[idx]-'a']++;
                windidx++; idx++;
            }
            if (isFre(freq, windFre)) {
                return true;
            }
        }
        return false;

        
    }
    
};