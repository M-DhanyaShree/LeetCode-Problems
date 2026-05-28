class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left=0,right=height.size()-1,ans=0,area,w,h;
        while(left<right)
        {
            w=abs(right-left);
            h=min(height[left],height[right]);
            area=h*w;
            ans=ans>area?ans:area;
            if(height[left]<height[right]) left++;
            else right--;
        }
        return ans;
    }
};