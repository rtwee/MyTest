#include <stdio.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/md5.h>

#pragma disable(warning:4996)

void getMD5(const char * str, char *result)
{
	MD5_CTX ctx;
	//md5初始化
	MD5_Init(&ctx);
	//添加数据
	MD5_Update(&ctx, str, strlen(str));
	unsigned char md[16] = { 0 };
	MD5_Final(md, &ctx);
	for (int i = 0; i < 16; ++i) {
		snprintf(&result[i * 2],33, "%02x", md[i]);
	}
}

int main() {

	char result[33] = { 0 };
	getMD5("hello,md5", result);
	printf("md5 value is %s\n", result);



	return 0;
}
