class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size();
        int l2=nums2.size();
        int i=0,j=0;
        int m=(l1+l2+1)/2;
        int cnt=0;int flag=0;double ans=0;
        while(i<l1||j<l2){
           if(j==l2||(i<l1&&nums1[i]<nums2[j]))
           {
              cnt++;
               if(flag==1)
             {
               ans+=nums1[i];
                ans=ans/2.0;
               flag=2;
               break;
             }
             if(cnt==m)
             {
               ans=nums1[i];
               if((l1+l2)%2==0)
               {
                 flag=1;
               }
               else break;
             }
              i++;
               // cout<<"i"<<i<<endl;
           }
           else{
             cnt++;
              if(flag==1)
              {
                ans+=nums2[j];
                 ans=ans/2.0;
                flag=2;
                break;
              }
             if(cnt==m)
             {
               ans=nums2[j];
               if((l1+l2)%2==0)
               {
                 flag=1;
               }
               else break;
             }
            j++;
               // cout<<"j"<<j<<endl;
           }
        }
       
        return ans;
    }
};