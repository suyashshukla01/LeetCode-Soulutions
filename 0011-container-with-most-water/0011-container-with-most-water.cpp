class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int st = 0 , end = height.size()-1;

        while(st < end){
            int currWater = min(height[st] , height[end]) * (end - st);
            maxWater = max(maxWater , currWater);

            height[st] < height[end] ? st++ : end--;
        }
            return maxWater;
    }
};