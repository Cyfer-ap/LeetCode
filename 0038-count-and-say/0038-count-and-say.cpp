class Solution {
public:
    string countAndSay(int n) {
        string s="1"; 
        for( int i=1;i<n;i++){
            string ans="";
            int cnt =0;
         int j=0;
         while(j<s.size()){
            int k =j; 
            while(k<s.size()&&s[j]==s[k]){k++;}
          cnt=k-j;
        ans+=to_string(cnt);
        ans+=s[j];
         j=k;
         }
             s=ans;


        }
 return s;

    }
};