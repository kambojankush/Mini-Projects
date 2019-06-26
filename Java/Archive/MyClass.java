public class MyClass {

	public void showSum(float x, float y, int count) {
		float sum = x + y;
		for (int i = 0; i < count; i++)
			System.out.println(sum);
	}


	public static void main(String[] args) {
		MyClass obj = new MyClass();
		obj.showSum(1.80f, 2.10f, 3);	
	}
}