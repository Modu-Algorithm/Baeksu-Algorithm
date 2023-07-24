package week1.Junseok.solvedac;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class BOJ_1181_단어정렬 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] arr = new String[n];
		for(int i = 0; i < n; i++) {
			arr[i] = sc.next();
		}
		
		String[] result = new String[n];
		result[0] = arr[0];
		int dup = 0;
		boolean isPre = false;
		
		for(int i = 1; i < n; i++) {
			String temp = "";
			result[i] = arr[i];
			for(int j = i; j > 0; j--) {
				if(result[j].length() < result[j-1].length()) {
					temp = result[j];
					result[j] = result[j-1];
					result[j-1] = temp;
				}
				if(result[j].length() == result[j-1].length()) {
					char[] char1 = result[j-1].toCharArray();
					char[] char2 = result[j].toCharArray();
					for(int k = 0; i < char1.length; i++) {
						if((int)(char1[i]) > (int)(char2[i])) {
							isPre = true;
							break;
						}
					}
					
					if(isPre) {
						temp = result[j];
						result[j] = result[j-1];
						result[j-1] = temp;
						System.out.println(Arrays.toString(result));						
					}
				}
				if(result[j].equals(result[j-1])) {
					result[j] = "";
				}
			}
		}
		
		for(int i = 0; i < result.length; i++) {
			if(result[i].equals("")) {
				dup++;
			}
		}
		
		String[] reresult = new String[result.length - dup];
		System.arraycopy(result, dup, reresult, 0, reresult.length);
		
		System.out.println(Arrays.toString(reresult));
		
	}
	
//	public static boolean isPre(String a, String b) {
//		boolean result = false;
//		
//		char[] char1 = a.toCharArray();
//		char[] char2 = b.toCharArray();
//		for(int i = 0; i < a.length(); i++) {
//			if((int)(char1[i]) > (int)(char2[i])) {
//				result = true;
//				break;
//			}
//		}
//		
//		return result;
//	}

}
