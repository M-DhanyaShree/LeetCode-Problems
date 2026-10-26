class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size(),tot,i,j,idx1,idx2,prev,curr,cnt;
        tot=n1+n2;
        idx1=tot/2;
        idx2=idx1-1;
        prev=-1;curr=-1;i=0;j=0;
        for(int cnt=0;cnt<=idx1;cnt++) {
            prev=curr;
            if(i<n1 && (j>=n2 || nums1[i]<=nums2[j])) curr=nums1[i++];
            else curr=nums2[j++];
        }
        if(tot%2!=0) return curr;
        return (prev+curr)/2.0;

    }
};