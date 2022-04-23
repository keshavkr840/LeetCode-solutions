class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.length()>k){
            int num=0,count =0;
            string str="";
            for(int i=0;i<s.length();i++){
                num+= s[i] -'0';
                ++count;
                if(count==k){
                    str.append(to_string(num));
                    num=0;
                    count=0;
                }
                
            }
            if(count!=0) str+=to_string(num);
            s= str;
        }
        return s;
    }
};