import java.util.Arrays;

public class Triangle_Count
{
	public int triangle_count(int[] S){
		int count = 0;
		int len = S.length;
		Arrays.sort(S);
		for(int i = 0; i < len - 2; ++i){
			for(int right = len - 1; i + 1 < right; --right){
				for(int left = i + 1; left < right;){
					if(S[left] + S[i] > S[right]){
						count += right - left;
						break;
					}
					else{
						left++;
					}
				}
			}
		}
		return count;
	}
	
	public static void main(String[] args){
		int[] numbers = {8990,3146,9568,3889,7253,7395,10032,6179,1299,8738,1315,1280,830,6593};
		System.out.println(new Triangle_Count().triangle_count(numbers));
		for(int num : numbers){
			System.out.print(num + " ");
		}
	}
}