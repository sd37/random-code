package morse_code_converter;

public class WordConverter {

	   private String[] tmpWord;
           private String multiStr = "";
           private String singleStr;
       
	   public String multiWordConvert(String str) {

	        if (str != null) {
	            tmpWord = new String[str.length()];
	            tmpWord = str.split("");
	            for (int i = 0; i < tmpWord.length; i++) {
	                multiStr = multiStr + singleWordConvert(tmpWord[i]);
	            }
	        }

	        return multiStr;
	    }

	    public String singleWordConvert(String str) {
	        singleStr = "";

	        if (str.equals("a") || str.equals("A")) {
	            singleStr = "10 ";
	        } else if (str.equals("b") || str.equals("B")) {
	            singleStr = "0111 ";
	        } else if (str.equals("c") || str.equals("C")) {
	            singleStr = "0101 ";
	        } else if (str.equals("d") || str.equals("D")) {
	            singleStr = "011 ";
	        } else if (str.equals("e") || str.equals("E")) {
	            singleStr = "1 ";
	        } else if (str.equals("f") || str.equals("F")) {
	            singleStr = "1101 ";
	        } else if (str.equals("g") || str.equals("G")) {
	            singleStr = "001 ";
	        } else if (str.equals("h") || str.equals("H")) {
	            singleStr = "1111 ";
	        } else if (str.equals("i") || str.equals("I")) {
	            singleStr = "11 ";
	        } else if (str.equals("j") || str.equals("J")) {
	            singleStr = "1000 ";
	        } else if (str.equals("k") || str.equals("K")) {
	            singleStr = "010 ";
	        } else if (str.equals("l") || str.equals("L")) {
	            singleStr = "1011 ";
	        } else if (str.equals("m") || str.equals("M")) {
	            singleStr = "00 ";
	        } else if (str.equals("n") || str.equals("N")) {
	            singleStr = "0000 ";
	        } else if (str.equals("o") || str.equals("O")) {
	            singleStr = "000 ";
	        } else if (str.equals("p") || str.equals("P")) {
	            singleStr = "1001 ";
	        } else if (str.equals("q") || str.equals("Q")) {
	            singleStr = "0010 ";
	        } else if (str.equals("r") || str.equals("R")) {
	            singleStr = "101 ";
	        } else if (str.equals("s") || str.equals("S")) {
	            singleStr = "111 ";
	        } else if (str.equals("t") || str.equals("T")) {
	            singleStr = "0 ";
	        } else if (str.equals("u") || str.equals("U")) {
	            singleStr = "110 ";
	        } else if (str.equals("v") || str.equals("V")) {
	            singleStr = "1110 ";
	        } else if (str.equals("w") || str.equals("W")) {
	            singleStr = "100 ";
	        } else if (str.equals("x") || str.equals("X")) {
	            singleStr = "0110 ";
	        } else if (str.equals("y") || str.equals("Y")) {
	            singleStr = "0100 ";
	        } else if (str.equals("z") || str.equals("Z")) {
	            singleStr = "0011 ";
	        } else if (str.equals("0")) {
	            singleStr = "00000 ";
	        } else if (str.equals("1")) {
	            singleStr = "10000 ";
	        } else if (str.equals("2")) {
	            singleStr = "11000 ";
	        } else if (str.equals("3")) {
	            singleStr = "11100 ";
	        } else if (str.equals("4")) {
	            singleStr = "11110 ";
	        } else if (str.equals("5")) {
	            singleStr = "11111 ";
	        } else if (str.equals("6")) {
	            singleStr = "01111 ";
	        } else if (str.equals("7")) {
	            singleStr = "00111 ";
	        } else if (str.equals("8")) {
	            singleStr = "00011 ";
	        } else if (str.equals("9")) {
	            singleStr = "00001 ";
	        } else if (str.equals(" ")) {
	            singleStr = "01 ";
	        } else if (str.equals("")) {
	            singleStr = "";
	        } else {
	            //System.out.println("wrong input in single convert!");
	        }
	        return singleStr;
	    }
}

