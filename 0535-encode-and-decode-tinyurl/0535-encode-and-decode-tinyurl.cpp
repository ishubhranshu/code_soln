class Solution {
public:
    int count=0;
    unordered_map<string , string> encodeMap;
    unordered_map<string , string> decodeMap;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string currCount=to_string(count++);
        
        encodeMap[longUrl]=currCount;
        decodeMap[currCount]=longUrl;
        
        return currCount; 
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));