import java.util.Scanner;

public class KnapsackTopDown {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n;
		n = in.nextInt();
		int[] weights = new int[n];
		int[] values = new int[n];
		int w = in.nextInt();
		
		for(int i=0; i<n; i++) {
			values[i] = in.nextInt();
		}
		
		for(int i=0; i<n; i++) {
			weights[i] = in.nextInt();
		}
		
		long startTime = System.nanoTime();
		
		int[][] dp = new int[n+1][w+1];
		
		for(int i=0; i<=n; i++)
			dp[i][0] = 0;
		
		for(int i=0; i<=w; i++)
			dp[0][i] = 0;
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=w; j++) {
				if(weights[i-1]<=j) {
					dp[i][j] = Math.max(values[i-1]+dp[i-1][j-weights[i-1]], dp[i-1][j]);
				}else {
				dp[i][j] = dp[i-1][j];
				}
			}
		}
		
		System.out.println(dp[n][w]);
		
		long endTime = System.nanoTime();
		long timeElapsed = endTime - startTime;
		System.out.println("Execution time in nanoseconds  : " + timeElapsed);
	}

}
