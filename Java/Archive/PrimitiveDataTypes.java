public class PrimitiveDataTypes {

	public static void main(String[] args) {
		// integer
		byte numberOfEnglishAlphabets = 26;
		short currentVehicleSpeed = 140;
		int particleCount = 54976;
		long atomCount = 18737485L;

		System.out.printf("numberOfEnglishAlphabets: %s\n", ((Object)numberOfEnglishAlphabets).getClass().getName());
		System.out.printf("currentVehicleSpeed: %s\n", ((Object)currentVehicleSpeed).getClass().getName());
		System.out.printf("particleCount: %s\n", ((Object)particleCount).getClass().getName());
		System.out.printf("atomCount: %s\n", ((Object)atomCount).getClass().getName());

		//Decimal
		float weight = 80.30f; // W/o literal gives data loss warning
		double speed = 100.2456;

		System.out.printf("Weight: %s\n", ((Object)weight).getClass().getName());
		System.out.printf("Speed: %s\n", ((Object)speed).getClass().getName());

		//Character
		char alph = 'A';
		char alphU = '\u00DC';

		System.out.printf("%c: %s\n", alph, ((Object)alph).getClass().getName());
		System.out.printf("%c: %s\n", alphU, ((Object)alphU).getClass().getName());

		//Boolean
		boolean flag = true;
		System.out.printf("%b: %s", flag, ((Object)flag).getClass().getName());
	}
}