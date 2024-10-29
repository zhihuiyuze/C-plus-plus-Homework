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
    vector<string> arr = {"a", "b", "c", "b", "a", "d", "c"};
    int k = 2;
    Distinct_String obj;
    string result = obj.kth(arr, k);
        cout << result << endl;
    
    return 0;
}