#include<stdio.h>
#include<string.h>
#include<assert.h>
//1.memmove µœ÷
//void * memmove(void * dst, const void * src, size_t count)
//{
//	void * ret = dst;
//	if (dst <= src || (char *)dst >= ((char *)src + count)) {
//		while (count--) {
//			*(char *)dst = *(char *)src;
//			dst = (char *)dst + 1;
//			src = (char *)src + 1;
//		}
//	}
//	else {
//		dst = (char *)dst + count - 1;
//		src = (char *)src + count - 1;
//		while (count--) {
//			*(char *)dst = *(char *)src;
//			dst = (char *)dst - 1;
//			src = (char *)src - 1;
//		}
//	}
//	return(ret);
//}
//2.strchr
//const char* Mystrchr(const char*dst, const char str) {
//	assert(dst != NULL);
//		while (*dst && *dst != str)
//			dst++;
//		return(dst);
//}
//int main() {
//	char buf[] = "hello world";
//	char*p = Mystrchr(buf, 'o');
//	printf("%s", p);
//	return 0;
//}