#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[2] <= rec2[0] || rec2[2] <= rec1[0]) {
            return false;
        }
        
        if (rec1[3] <= rec2[1] || rec2[3] <= rec1[1]) {
            return false;
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> rec1(4), rec2(4);
    
    cout << "Enter coordinates for first rectangle (x1 y1 x2 y2): ";
    for (int i = 0; i < 4; i++) {
        cin >> rec1[i];
    }
    
    cout << "Enter coordinates for second rectangle (x1 y1 x2 y2): ";
    for (int i = 0; i < 4; i++) {
        cin >> rec2[i];
    }
    
    bool result = solution.isRectangleOverlap(rec1, rec2);
    
    cout << "\nResult: " << (result ? "The rectangles overlap" : "The rectangles do not overlap") << endl;
    
    cout << "\nSimple visualization (not to scale):" << endl;
    int minX = min(rec1[0], rec2[0]);
    int maxX = max(rec1[2], rec2[2]);
    int minY = min(rec1[1], rec2[1]);
    int maxY = max(rec1[3], rec2[3]);
    
    for (int y = maxY + 1; y >= minY - 1; y--) {
        for (int x = minX - 1; x <= maxX + 1; x++) {
            bool inRect1 = (x >= rec1[0] && x < rec1[2] && y >= rec1[1] && y < rec1[3]);
            bool inRect2 = (x >= rec2[0] && x < rec2[2] && y >= rec2[1] && y < rec2[3]);
            
            if (inRect1 && inRect2) cout << "O"; 
            else if (inRect1) cout << "1";
            else if (inRect2) cout << "2";
            else cout << ".";
        }
        cout << endl;
    }
    
    return 0;
}