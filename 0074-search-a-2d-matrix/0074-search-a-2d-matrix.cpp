class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int c=matrix[0].size(),r=matrix.size();
        int low=0,high=(r*c)-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2,e=matrix[mid/c][mid%c];
            if(e==target) return true;
            else if(target>e) 
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        return false;
    }
};