#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
    /*
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(std::vector<int> &S) {
        // write your code here
        int result = 0;
        std::sort(S.begin(), S.end());
        int size = S.size();
		for(int i = 0; i < size - 2; ++i){
			for(int j = size - 1; j > i + 1; --j){
				for(int k = i +1; k < j; ++k){
					if(S[i] + S[k] > S[j]){
						result += j - k;
						break;
					}
				}
			}
		}
        /*for(int i = 0; i < size - 2; ++i){
            for(int j = size - 1; j > i + 1; --j){
                if(S[j] - S[j - 1] < S[i]){
                    for (int k = i + 1; k < j; ++k){
                        if(S[i] + S[k] > S[j]){
                            result += j - k;
                            break;
                        }
                    }
                }
            }
        }*/
        return result;
    }
};

int main(int argc, char * argv[]){
    Solution so;
    int arr[] = {8990,3146,9568,3889,7253,7395,10032,6179,1299,8738,1315,1280,830,6593};
    std::vector<int> nums(arr, arr + sizeof(arr)/sizeof(int)); 
    std::cout << so.triangleCount(nums) << std::endl;
}