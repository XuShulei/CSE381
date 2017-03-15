#include <stdio.h>

int string_len(char str[]) {
	int result = 0;
	while (str[result] != 0) {
		result++;
	}
	return result;
}

int string_copy(char src[], char dst[]) {
	int i = 0;
	while (src[i] != 0) {
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return i;
}

char *string_append(char str1[], char str[]) {
	int i = string_len(str1);
	int j = 0;
	while (str[j] != 0) {
		str1[i++] = str[j++];
	}
	str1[i] = 0;
	return str1;
}

int main() {
	char str[10] = "HELLO";
	char str1[10] = "";
	printf("Length of HELLO is: %d\n", string_len(str));
	int cp = string_copy(str, str1);
	printf("Now copy str to str1, we get str1 as: %s\n", str1);
	char* str2 = string_append(str1, str);
	printf("Now we append str to str1, then we get: %s\n", str2);

	return 0;
}