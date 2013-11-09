package morse_code_converter;

public class MorseCode {
	
	public String encode(String str)
	{
		WordConverter wc = new WordConverter();
		return wc.multiWordConvert(str);
	}
	
	public String decode(String str)
	{
		CodeConverter cw = new CodeConverter();
		return cw.multiCodeConvert(str);
	}
}
