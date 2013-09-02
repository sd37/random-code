def generate_substr(s):
    substr_l = []
    i = 0

    while i < len(s):
	j = i + 1
	while j <= len(s):
	    substr_l.append(s[i:j])
	    j = j + 1
	i = i + 1
    return substr_l

def longest_palind(s):
    s_rev = s[::-1]
    ans = longest_common_substr(s,s_rev)
    print ans

def longest_common_substr(s1,s2):
    max_l = 0
    max_s = ""
    substr_l = generate_substr(s2)
    for x in substr_l:
	if x in s1:
	    if max_l < len(x):
		max_l = len(x)
		max_s = x

    return max_s

longest_palind("abcdxyzyxabcdaaa")
