#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        if (!head) return matrix;
        
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        ListNode* current = head;
        
        while (current && top <= bottom && left <= right) {
            for (int j = left; j <= right && current; j++) {
                matrix[top][j] = current->val;
                current = current->next;
            }
            top++;
            
            for (int i = top; i <= bottom && current; i++) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            right--;
            
            if (top <= bottom) {
                for (int j = right; j >= left && current; j--) {
                    matrix[bottom][j] = current->val;
                    current = current->next;
                }
                bottom--;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top && current; i--) {
                    matrix[i][left] = current->val;
                    current = current->next;
                }
                left++;
            }
        }
        
        return matrix;
    }
};

ListNode* createList(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    
    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    
    return head;
}

void printMatrix(const vector<vector<int>>& matrix) {
    cout << "\nGenerated Spiral Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;
    
    cout << "Enter the number of elements for the linked list: ";
    int size;
    cin >> size;
    
    cout << "Enter " << size << " integers for the linked list (separated by spaces): ";
    vector<int> nums;
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    ListNode* head = createList(nums);
    
    vector<vector<int>> result = solution.spiralMatrix(m, n, head);
    printMatrix(result);
    
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}