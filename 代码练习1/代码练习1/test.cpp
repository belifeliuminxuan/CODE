#include <iostream>
using namespace std;
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;//�������ڱ���׶Σ�������ʵ�����ͽ������ݣ�������������ѡ�����
}
//�������ر�������ͬ�������򣬺�����������ͬ�������б�ͬ���������������������ͣ����ʹ���
//����������������Ƿ���ֵ���Ͳ�ͬ�����ܹ�������
//C���Բ�֧�����أ���ΪC���Ա������Ժ������ֵ����ι����Ǻ�����ǰ�����»���_
//ͬ�����޲κ�����ȫȱʡ����������Ҫͬʱ���ڡ�
//C++�е�����

void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Swap(int& left, int& right)
{

}

//���ã�  ����� 
const int a = 10;
const int& ra = a;//���ÿ�����Ϊ������������

//�����Ҫͨ���βθı��ⲿʵ�Σ���ͨ���͵�����
//�������ͨ���βθı��ⲿʵ�Σ�const ���͵�����

//���ÿ�����Ϊ�����ķ���ֵ
//ע�ⲻ���Է��غ���ջ�ϵĿռ�



int main()
{
	
	return 0;
}