#include <iostream>//��׼ͷ�ļ� 
#include <windows.h>//ϵͳͷ�ļ� 
using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

bool check(char c)
{//���ĳ�������Ƿ���
	if(!KEY_DOWN(c)) return 0;
	else return 1;
}


int main()
{
	int time;//���ʱ��
	bool key;//bool�������ͱ�����0��fales����1��true�� ��keyΪҪ������������0�����Ҽ���1��
	bool run;//�Ƿ���
	
	//����ʱ�� 
	cout << "��������ʱ�䣨С��10����";
	while (1)
	{
		cin >> time;
		if (time < 10)//���ʱ�䣬��СΪ10����ֹ���Կ��� 
		{
			cout << "ʱ����ҪС��10Ŷ������������...";
			system ("cls");//cmdָ�� 
		}
		else break;
	}
	
	//����������Ҽ�
	cout << "���������������������Ҽ��������0���Ҽ���1��";
	cin >> key;
	
	//��ʼ����
	while (1)
	{
		if (check ('N')) run = 1;//ע�ⵥ������һ���Ǵ�д��n���� 
		if (check ('M')) run = 0;//ע�ⵥ������һ���Ǵ�д��m�ر� 
		if (check ('R')) return 0;//ע�ⵥ������һ���Ǵ�д��r�˳����� 
		if (run)
		{
			if (!key) mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);//�����mouse_event�������������
			else mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); //�Ҽ� 
			Sleep (time);//�ȴ� 
		}
	} 
}
