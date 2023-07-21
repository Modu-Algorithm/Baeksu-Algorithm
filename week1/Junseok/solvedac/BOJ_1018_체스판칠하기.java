package week1.Junseok.solvedac;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ_1018_체스판칠하기 {

	public static void main(String[] args) {
		// 입력
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] c = new String[n];
		for(int i = 0; i < n; i++) {
			c[i] = sc.next();
		}
		String[][] board = new String[n][m];
		
		// n * m 2차원 배열에 입력값 저장.
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				board[i][j] = c[i].split("")[j]; 
			}
		}
		
		int cnt1 = 0;	// 맨 왼쪽 위가 W인 경우 다시 칠해야 하는 정사각형의 개수
		int cnt2 = 0;	// 맨 왼쪽 위가 B인 경우 다시 칠해야 하는 정사각형의 개수
		int tr = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(board[i][j].equals("W")) {	// 맨 왼쪽 위가 W인 경우 
					for(int k = 0; k < 7; k++) {
						if(j+k+1 < 8) {
							if(board[i][j+k].equals(board[i][j+k+1])) {
								if(board[i][j+k].equals("W")) {
									board[i][j+k+1] = "B";
								} else {
									board[i][j+k+1] = "W";
								}
								cnt1++;
								System.out.println(cnt1 + "cnt1");
							}
						}
					}
				}
				else {						// 맨 왼쪽 위가 B인 경우
					for(int o = 0; o < 7; o++) {
						if(j+o+1 < 8) {
							if(board[i][j+o].equals(board[i][j+o+1])) {
								if(board[i][j+o].equals("W")) {
									board[i][j+o+1] = "B";
								} else {
									board[i][j+o+1] = "W";
								}
								cnt2++;
								System.out.println(cnt2 + "cnt2");
							}
						}
					}
						
				}
			}
			
			System.out.println("-------------");
			if(i+1 < n) {
				if(board[i][0].equals(board[i+1][0])) {
					if(board[i][0].equals("W")) {
						board[i+1][0] = "B";
					} else {
						board[i+1][0] = "W";
					}
				}
			}
			
		}
	}
}


