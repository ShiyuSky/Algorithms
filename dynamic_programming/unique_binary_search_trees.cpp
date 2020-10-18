using namespace std;

class Solution {
public:
    int numTrees(int n) {
        /*
        Returns the number of structually unique BST's that store values 1...n
        */
        vector<int> res{ 1, 1 };
        
        for (int i=2; i<=n; i++) {
            int subRes = 0;
            for (int j=0; j<i; j++) {
                subRes += (res[j] * res[i-1-j]);
            }
            res.push_back(subRes);
        }
        return res[n];
    }
};