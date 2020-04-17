// https://leetcode.com/problems/trapping-rain-water/

class Solution 
{
	public:
		int trap(vector<int>& height) 
		{
			int len = height.size();
			 
			if (len==0)
				return 0;
			 
			int maxElementIndex = max_element(height.begin(),height.end()) - height.begin();

			//checking level from the left till the top
			int level=height[0];
			int ans=0;
			for (int i=0; i<maxElementIndex; i++)
			{
				if (height[i]>level)
					level=height[i];
				ans+=level-height[i];
			}
			
			//checking level from the right till the top
			level=height[len-1];
			for (int i=len-1; i>maxElementIndex; i--)
			{
				if (height[i]>level)
					level=height[i];
				ans+=level-height[i];
			}
			return ans;
		}   
};
