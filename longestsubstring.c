#include<iostream>
using namespace std;
// LONGEST SUBSTRING WIHTOUT REPEATING CHARACTERS
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string temp = "";
        string final = "";
        float exist=0, i, j, k;
        for(i=0;s.length()-1>=i;i++){
            temp = s[i];
            for(j=i+1;s.length()-1>=j;j++){
                exist = 0;
                for(k=0;temp.length()-1>=k;k++){
                    if(s[j]==temp[k]){
                        exist=1;
                        break;
                    }
                }
                if(exist==1){
                    break;
                }else{
                    temp = temp + s[j];
                }
            }
            if(temp.length()>=final.length()){
                final = temp;
            }
        }
        return final.length();
    };
};

int main(){
    int a=0;
    Solution s;
    string arr[20] = {"hello", "pwa", "flskfjfsda"};
    while(a<3){
        cout << s.lengthOfLongestSubstring(arr[a]);
        a++;
    }
}