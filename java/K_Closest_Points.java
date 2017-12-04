import java.util.PriorityQueue;
import java.util.Arrays;
import java.util.Comparator;

public class K_Closest_Points
{
	public Point [] kClosest(Point[] points, Point origin, int k){
		Point[] result  = new Point[k];
		PriorityQueue<Point> p_queue = new PriorityQueue<Point>( new Comparator<Point>(){
			private int distanceOfTwoPoints(Point l_p, Point r_p){
				return this.square(l_p.x - r_p.x) + this.square(l_p.y - r_p.y);
			}

			private int square(int src){
				return src * src;
			}

			public int compare(Point l_p, Point r_p){
				int l_distance = this.distanceOfTwoPoints(l_p, origin);
				int r_distance = this.distanceOfTwoPoints(r_p, origin);
				if(l_distance == r_distance){
					if(r_p.x == l_p.x){
						return r_p.y - l_p.y;
					}
					else{
						return r_p.x - l_p.x;
					}
				}
				else{
					return r_distance - l_distance;
				}
			}
		});
		for(Point point : points){
			p_queue.add(point);
			if(p_queue.size() > k){
				p_queue.poll();
			}
		}
		//Object [] tempArr = p_queue.toArray();  返回的是无序数组，并不一定是无序的，总之顺序不保证。
		for(int i = k - 1; (!p_queue.isEmpty()) && (i >= 0); --i){
			result[i] = p_queue.poll();
		}
		return result;
	}
	public static void main(String [] args){
		Point [] points = {new Point(4,6),new Point(4,7),new Point(4,4),new Point(2,5),new Point(1,1),new Point(1, 0)};
		Point origin = new Point(0, 0);
		int k = 3;
		Point [] result = new K_Closest_Points().kClosest(points, origin, k);
		System.out.print("[");
		for(Point point : result){
			System.out.print("[" + point.x + "," + point.y + "]");
		}
		System.out.println("]");
		
		int [] S = {3,4,6,7};
		System.out.print(new K_Closest_Points().triangleCount(S));
	}

	public int triangleCount(int[] S) {
		// write your code here
		int[] tempArray = S;
		Arrays.sort(tempArray);
		int size = S.length;
		int result = 0;
		//boolean out = false;
		for(int index = 0; index < size - 2; ++index){
			//int j = index + 1;
			out = false;
			for(int j = size - 1; j > index + 1; --j){
				if(tempArray[j] - tempArray[j - 1] < tempArray[index]){
					int k = index + 1;
					for(; k < j; ++k){
						if(tempArray[j] < tempArray[k] + tempArray[index]){
							result += j - k;
							break;
						}
					}
				}
			}
		}
        return result;
    }

}
class Point
{
	int x;
	int y;
	Point(){
		this.x = 0;
		this.y = 0;
	}
	Point(int a, int b){
		this.x = a;
		this.y = b;
	}
}