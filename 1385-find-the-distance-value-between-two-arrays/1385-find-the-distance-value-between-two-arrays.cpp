class Solution {
public:
    int search(vector<int>& arr,int target) {
        int low=0,high=arr.size()-1,mid;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(arr[mid]>=target) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    int findTheDistanceValue(vector<int>& arr1,vector<int>& arr2,int d) {
        sort(arr2.begin(),arr2.end());
        int i,ans=0,n2=arr2.size();
        for(i=0;i<arr1.size();i++) {
            int x=arr1[i];
            int idx=search(arr2,x);
            bool ok=true;
            if(idx<n2&&abs(arr2[idx]-x)<=d) ok=false;
            if(idx-1>=0&&abs(arr2[idx-1]-x)<=d) ok=false;
            if(ok) ans++;
        }
        return ans;
    }
};