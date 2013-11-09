package morse_code_converter;

public class CodeConverter {
	
	private String[] tmpSentence;
	private String[] tmpWord;
	private String tmp;
	private String multiStr = "";
	private String singleStr;
	private int counter;
	
	public String multiCodeConvert(String str) {
		String ans_s = "";
		String ls[] = str.split(" ");
		
		for(int i = 0; i < ls.length; i++)
		{
			ans_s  = ans_s + singleCodeConvert(ls[i]);
			
		}
		
		return ans_s;
	}

    public String singleCodeConvert(String str) {
        singleStr = "";

        if (str.equals("10")) {
            singleStr = "a";
        } else if (str.equals("0111")) {
            singleStr = "b";
        } else if (str.equals("0101")) {
            singleStr = "c";
        } else if (str.equals("011")) {
            singleStr = "d";
        } else if (str.equals("1")) {
            singleStr = "e";
        } else if (str.equals("1101")) {
            singleStr = "f";
        } else if (str.equals("001")) {
            singleStr = "g";
        } else if (str.equals("1111")) {
            singleStr = "h";
        } else if (str.equals("11")) {
            singleStr = "i";
        } else if (str.equals("1000")) {
            singleStr = "j";
        } else if (str.equals("010")) {
            singleStr = "k";
        } else if (str.equals("1011")) {
            singleStr = "l";
        } else if (str.equals("00")) {
            singleStr = "m";
        } else if (str.equals("0000")) {
            singleStr = "n";
        } else if (str.equals("000")) {
            singleStr = "o";
        } else if (str.equals("1001")) {
            singleStr = "p";
        } else if (str.equals("0010")) {
            singleStr = "q";
        } else if (str.equals("101")) {
            singleStr = "r";
        } else if (str.equals("111")) {
            singleStr = "s";
        } else if (str.equals("0")) {
            singleStr = "t";
        } else if (str.equals("110")) {
            singleStr = "u";
        } else if (str.equals("1110")) {
            singleStr = "v";
        } else if (str.equals("100")) {
            singleStr = "w";
        } else if (str.equals("0110")) {
            singleStr = "x";
        } else if (str.equals("0100")) {
            singleStr = "y";
        } else if (str.equals("0011")) {
            singleStr = "z";
        } else if (str.equals("00000")) {
            singleStr = "0";
        } else if (str.equals("10000")) {
            singleStr = "1";
        } else if (str.equals("11000")) {
            singleStr = "2";
        } else if (str.equals("11100")) {
            singleStr = "3";
        } else if (str.equals("11110")) {
            singleStr = "4";
        } else if (str.equals("11111")) {
            singleStr = "5";
        } else if (str.equals("01111")) {
            singleStr = "6";
        } else if (str.equals("00111")) {
            singleStr = "7";
        } else if (str.equals("00011")) {
            singleStr = "8";
        } else if (str.equals("00001")) {
            singleStr = "9";
        } else if (str.equals("01")) {
            singleStr = " ";
        } else {
            //System.out.println("wrong input in single convert!");
        }
    return singleStr;
  }

}
