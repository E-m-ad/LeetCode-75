class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0 ;
        int right = n - 1;
        int max_water = 0;
        while(left < right) {
            int width = right - left ;
            int max_height =  width *  min(height[right] , height[left]);
            max_water = max(max_water , max_height);
            if(height[left] < height[right])
                left+=1;
            else 
                right-=1;
        }
        return max_water;
    }
};
/*
The brute force solution will be O(n^2) , will get every pair and assign the maximum height.
the Optimized Solution with O(n) , we get use of searching for best height at the situation we need , such that if i stand on the first and last element with two pointer, 
the left and the right  , and one of them is less than the other for ex 1 and 7 there is no meaning to continue searching for best solution for pairing with 1 i already know that if the possible solution that may come
will limited by the 1 so why to look for possible pair ? instead of that we move the pointer left to 1 searching for optimal height solution , the same thing on the right pointer if it become lower.
*/
