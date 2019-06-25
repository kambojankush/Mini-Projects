public class Arrays {

	public static void main(String[] args) {
		int[] arr1 = new int[3];
		arr1[0] = 0;
		arr1[1] = 1;
		arr1[2] = 2;
		int sum1 = 0;

		for (int i = 0; i < arr1.length; i++)
			sum1 += arr1[i];

		System.out.println(sum1);

		float[] arr2 = {0.23f, 0.56f, 1.35f};
		float sum2 = 0.0f;

		for (float iVal : arr2)
			sum2 += iVal;

		System.out.println(sum2);
	}
}