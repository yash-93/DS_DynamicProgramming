import java.util.Arrays;
import java.util.Scanner;

public class KnapsackRecursiveMemo {

	public static int knapsack(int[] weights, int[] values, int w, int n, int[] memo) {
		if(n==0 || w==0) return 0;
		if(weights[n-1]<=w) {
			return Math.max(values[n-1] + knapsack(weights, values, w-weights[n-1], n-1, memo), knapsack(weights, values, w, n-1, memo));
		}else {
			return knapsack(weights, values, w, n-1, memo);
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n;
		n = in.nextInt();
		int[] weights = new int[n];
		int[] values = new int[n];
		int[] memo = new int[n];
		Arrays.fill(memo, -1);
		int w = in.nextInt();
		
		for(int i=0; i<n; i++) {
			values[i] = in.nextInt();
		}
		
		for(int i=0; i<n; i++) {
			weights[i] = in.nextInt();
		}
		long startTime = System.nanoTime();
		System.out.println(knapsack(weights, values, w, n, memo));
		long endTime = System.nanoTime();
		long timeElapsed = endTime - startTime;
		System.out.println("Execution time in nanoseconds  : " + timeElapsed);
	}

}
