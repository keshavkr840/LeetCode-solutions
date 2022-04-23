class Solution {
public:
    string base = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> map;
    string format = "http://tnyurl.com/";
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string hash = "";
        int n =6;
        while(n--){
            int random = rand() %62;
            hash.push_back(base[random]);
        }
        if(map.find(hash)!= map.end())
            return encode(longUrl);
        else{
            map[hash]= longUrl;
        }
        return (format + hash);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string hash = shortUrl.substr(shortUrl.size()-6);
        return map[hash];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));