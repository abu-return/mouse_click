#include <iostream>//��׼ͷ�ļ� 
#include <windows.h>//ϵͳͷ�ļ� 
using namespace std;

//��갴���ж� 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
// ��  ��KEY_DOWN(MOUSE_MOVED)
// ��  ��KEY_DOWN(MOUSE_EVENT)
//���� ��KEY_DOWN(MOUSE_WHEELED)

bool check(char c)
{//���ĳ�������Ƿ���
	if(!KEY_DOWN(c))return 0;
	else return 1;
}

int main()
{
	int time;//���ʱ��
	int run = 0;
	
	//����ʱ�� 
	while (1)
	{
		cout << "Input interval time (more than 10, in MS):";
		cin >> time;
		if (time < 10)//���ʱ�䣬��СΪ10����ֹ���Կ��� 
		{
			cout << "The time needs to be less than 10, please input again...";
			Sleep (500);
			system ("cls");//cmdָ�� 
		}
		else break;
	}
	
	//��ʼ����
	while (1)
	{
		if (KEY_DOWN(MOUSE_MOVED) && run)
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		if (check('G')) run = !run;
		
		Sleep (time);//�ȴ�
	} 
}
