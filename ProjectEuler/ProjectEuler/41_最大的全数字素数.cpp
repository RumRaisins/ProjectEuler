#include"ReadText.h"
#include<time.h>
using namespace std;
#define R_M_TEST_ROUND 30
//(a^b)%c 快速幂取模算法
//对于任何一个整数的模幂运算
//a^b%c
//对于b我们可以拆成二进制的形式
//b = b0 + b1 * 2 + b2 * 2 ^ 2 + ... + bn * 2 ^ n
//这里我们的b0对应的是b二进制的第一位
//那么我们的a^b运算就可以拆解成
//a^b0*a^b1 * 2 * ...*a ^ (bn * 2 ^ n)
//对于b来说，二进制位不是0就是1，那么对于bx为0的项我们的计算结果是1就不用考虑了，我们真正想要的其实是b的非0二进制位
//
//那么假设除去了b的0的二进制位之后我们得到的式子是
//a ^ (bx * 2 ^ x)*...*a(bn * 2 ^ n)
//这里我们再应用我们一开始提到的公式，那么我们的a^b%c运算就可以转化为
//(a ^ (bx * 2 ^ x) % c）*...*(a ^ (bn * 2 ^ n) % c)
//	这样的话，我们就很接近快速幂的本质了
//(a ^ (bx * 2 ^ x) % c)*...*(a ^ (bn * 2 ^ n) % c)
//我们会发现令
//A1 = (a ^ (bx * 2 ^ x) % c)
//...
//An = (a ^ (bn * 2 ^ n) % c)
//这样的话，An始终是A(n - 1)的平方倍（当然加进去了取模匀速那），依次递推
//int quick(int a, int b, int c)
//{
//	int ans = 1;   //记录结果  
//	a = a%c;   //预处理，使得a处于c的数据范围之下  
//	while (b != 0)
//	{
//		if (b & 1) ans = (ans*a) % c;   //如果b的二进制位不是0，那么我们的结果是要参与运算的  
//		b >>= 1;    //二进制的移位操作，相当于每次除以2，用二进制看，就是我们不断的遍历b的二进制位  
//		a = (a*a) % c;   //不断的加倍  
//	}
//	return ans;
//}
//拉宾米勒素数测试a^(p-1)%p==1,p是素数
int32_t R_M_TEST(int32_t *num, int32_t n) {
	int64_t x = 0, a, m, ans;
	while (n--) {
		x = x * 10 + num[n];
	}
	if (!(x & 0x1))return 0;
	//快速幂取模算法 (a^(x-1))%x
	for (int32_t i = 0; i < R_M_TEST_ROUND; i++) {
		a = (rand() % (x - 1)) + 1; //？？
		ans = 1; //计算结果的保留
		m = x - 1;
		while (m) {
			if (m & 1) ans = (ans * a) % x;
			a = (a * a) % x;
			m >>= 1;
		}
		if (ans != 1) return 0;
	}
	return x;
}

int32_t main() {
	srand(time(0));
	int32_t num[9] = { 0 }, ans = 0, temp_ans;
	for (int32_t i = 3; i <= 9; ++i) {
		for (int32_t j = 0; j < i; ++j) {
			num[j] = j + 1;
		}
		do {
			temp_ans = R_M_TEST(num, i);
			if (temp_ans > ans) ans = temp_ans;
		} while (next_permutation(num, num + i));
	}
	cout << ans << endl;
	return 0;
}