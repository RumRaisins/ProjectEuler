#include"ReadText.h"
#include<time.h>
using namespace std;
#define R_M_TEST_ROUND 30
//(a^b)%c ������ȡģ�㷨
//�����κ�һ��������ģ������
//a^b%c
//����b���ǿ��Բ�ɶ����Ƶ���ʽ
//b = b0 + b1 * 2 + b2 * 2 ^ 2 + ... + bn * 2 ^ n
//�������ǵ�b0��Ӧ����b�����Ƶĵ�һλ
//��ô���ǵ�a^b����Ϳ��Բ���
//a^b0*a^b1 * 2 * ...*a ^ (bn * 2 ^ n)
//����b��˵��������λ����0����1����ô����bxΪ0�������ǵļ�������1�Ͳ��ÿ����ˣ�����������Ҫ����ʵ��b�ķ�0������λ
//
//��ô�����ȥ��b��0�Ķ�����λ֮�����ǵõ���ʽ����
//a ^ (bx * 2 ^ x)*...*a(bn * 2 ^ n)
//����������Ӧ������һ��ʼ�ᵽ�Ĺ�ʽ����ô���ǵ�a^b%c����Ϳ���ת��Ϊ
//(a ^ (bx * 2 ^ x) % c��*...*(a ^ (bn * 2 ^ n) % c)
//	�����Ļ������Ǿͺܽӽ������ݵı�����
//(a ^ (bx * 2 ^ x) % c)*...*(a ^ (bn * 2 ^ n) % c)
//���ǻᷢ����
//A1 = (a ^ (bx * 2 ^ x) % c)
//...
//An = (a ^ (bn * 2 ^ n) % c)
//�����Ļ���Anʼ����A(n - 1)��ƽ��������Ȼ�ӽ�ȥ��ȡģ�����ǣ������ε���
//int quick(int a, int b, int c)
//{
//	int ans = 1;   //��¼���  
//	a = a%c;   //Ԥ����ʹ��a����c�����ݷ�Χ֮��  
//	while (b != 0)
//	{
//		if (b & 1) ans = (ans*a) % c;   //���b�Ķ�����λ����0����ô���ǵĽ����Ҫ���������  
//		b >>= 1;    //�����Ƶ���λ�������൱��ÿ�γ���2���ö����ƿ����������ǲ��ϵı���b�Ķ�����λ  
//		a = (a*a) % c;   //���ϵļӱ�  
//	}
//	return ans;
//}
//����������������a^(p-1)%p==1,p������
int32_t R_M_TEST(int32_t *num, int32_t n) {
	int64_t x = 0, a, m, ans;
	while (n--) {
		x = x * 10 + num[n];
	}
	if (!(x & 0x1))return 0;
	//������ȡģ�㷨 (a^(x-1))%x
	for (int32_t i = 0; i < R_M_TEST_ROUND; i++) {
		a = (rand() % (x - 1)) + 1; //����
		ans = 1; //�������ı���
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