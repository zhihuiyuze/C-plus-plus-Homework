#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Distinct_String {
    public:
        string kth(vector<string> arr, int k){
            unordered_map<string, int> count;
            for (const string s : arr) {
                count[s]++;
            }
            int Found = 0;
            for (const string s : arr) {
                if (count[s] == 1) {
                    Found++;
                }
                if (Found == k) {
                    return s;
                }
            }
            return "";
        }
};

int main(){
    vector<string> arr;
    string input;
    int k;
    
    cout << "Please enter a string (e.g. abcbadc): ";
    cin >> input;
    

    for(char c : input) {
        string s(1, c); 
        arr.push_back(s);
    }
    
    cout << "Please enter k (k-th distinct string to find): ";
    cin >> k;
    
    Distinct_String obj;
    string result = obj.kth(arr, k);
    
    cout << "The " << k+1 << "th distinct string is: " << result << endl;
   
    return 0;
}