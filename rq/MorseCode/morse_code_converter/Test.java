package morse_code_converter;

public class Test {

	public static void main(String[] args) {
		MorseCode mc = new MorseCode();
		String resEncode = mc.encode("and e e e eeee spandan");
		System.out.println(resEncode);
		
		String resDecode = mc.decode(resEncode);
		System.out.println(resDecode);
	}
}