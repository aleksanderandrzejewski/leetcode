// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int ln1=nums1.size();
        int ln2=nums2.size();
        int lnall = ln1+ln2; //total number of elements in both arrays

        if(lnall%2==1) //odd total number of elements: median is based on one central numberer
        {
            int n=lnall/2;
            int wynik=0;
            int counter1=0;
            int counter2=0;

            while((counter1+counter2)<=n)
            {
                if(counter1<ln1 and counter2<ln2)
                {
	                 if (nums1[counter1]<=nums2[counter2])
	                 {
	                     wynik=nums1[counter1];   
	                     counter1++;
	                 }
	                 else
	                 {
	                    wynik=nums2[counter2];
	                    counter2++;
	                 }
                }
                else
                    if (counter1==ln1)
                    {
                        wynik=nums2[counter2];
                        counter2++;
                    }
                    else
                    {
                        wynik=nums1[counter1];
                        counter1++;
                    }
            }
            return wynik;
        }
        else  //even total number of elements: median is based on two central numbers
        {
        	
            int n=lnall/2;
            int m=n-1;
            int wynik=0;
            int wynik2=0;
            int counter1=0;
            int counter2=0;
            
                        
            while(true)
            {
                if(counter1<ln1 and counter2<ln2)
                {
	                 if (nums1[counter1]<=nums2[counter2])
	                 {
	                     if (counter1+counter2==m)
	                     	wynik=nums1[counter1];
	                     else
		                     if (counter1+counter2==n)	
		                     {
		                     	wynik2=nums1[counter1];
		                     	break;
		                     }   
	                     counter1++;
	                 }
	                 else
	                 {
	                    if (counter1+counter2==m)
	                     	wynik=nums2[counter2];
	                     else
		                     if (counter1+counter2==n)	
		                     {
		                     	wynik2=nums2[counter2];
		                     	break;
		                     }
	                    counter2++;
	                 }
                }
                else
                    if (counter1==ln1)
                    {
                         if (counter1+counter2==m)
	                     	wynik=nums2[counter2];
	                     else
		                     if (counter1+counter2==n)	
		                     {
		                     	wynik2=nums2[counter2];
		                     	break;
		                     }
                        counter2++;
                    }
                    else
                    {
                        if (counter1+counter2==m)
	                     	wynik=nums1[counter1];
	                     else
		                     if (counter1+counter2==n)	
		                     {
		                     	wynik2=nums1[counter1];
		                     	break;
		                     }
                        counter1++;
                    }
            }
            return (wynik+wynik2)/2.;
        }         
    }
};
