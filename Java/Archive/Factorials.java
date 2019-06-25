public class Factorials {

	public static void main(String[] args) {

		int iVal = 5;
		int factorial = 1;

		while (iVal > 1) {
			factorial *= iVal--;
		}

		System.out.println(factorial);
	}
}