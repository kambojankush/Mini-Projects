public class Variables {
	
	public static void main(String[] args) {
		int myVar;
		myVar = 50;
		System.out.println(myVar);

		int anotherVar = 200;
		System.out.println(anotherVar);

		anotherVar = myVar;
		System.out.format("AnotherVar: %d\n", anotherVar);

		anotherVar = 500;
		System.out.printf("AnotherVar: %d", anotherVar);
	}
}