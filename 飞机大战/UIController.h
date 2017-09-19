#ifndef __UICONTROLLER__
#define __UICONTROLLER__

#include <list>

class Box;
class BlackBoard; 
class MyPlane;

class UIController
{
public:
	// �����������ɵķ�������
	const static int ROWS = 30; 
	const static int COLS = 15;
	int _boxes[ROWS][COLS]; //����һ����Ӧ������,Լ��1���ӵ���2���һ���3���л�
	// ��ʼ����λ��
	const static int INITIAL_COL = COLS / 2; 
	
	std::list<Box*> figure;//����ӵ��ͷɻ�

public:
	// UIController���õ���ģʽ�����������Ψһ
	static UIController &handle()
	{
		static UIController instance; 
		return instance; 
	}

	// �����ٶȣ���λ���룬��ÿX�����ƶ�һ��
	int PlaneGameSpeed() { return 500;}
	int BulletGameSpeed() {return 30;}

	// ��ʱ�������߼����˴���Ҫ�������������Զ�����
	void PlaneOnTimer(int code);
	void BulletOnTimer(int code);

	// ��ͼ�߼��������߿���ƣ��������
	void OnDraw(BlackBoard &board); 

	// �����߼�����Ҫ�����û����ҡ�����������Ĳ���
	void OnKey(unsigned char key, int x, int y); 

	// �жϷ����Ƿ�����߽硢�ұ߽硢�±߽硢�����й̶�����
	bool HitLeft(Box &box);
	bool HitRight(Box &box);
	bool HitBottom(Box &box);
	bool HitTop(Box &box);
	bool HitBulletPlane(Box &box); 

	~UIController(); 

private:
	UIController(); //����ģʽ������޷�ʹ�ù��캯��
	
	// ɾ����������
	void EraseFullRows();

	// ɾ�������к��Ϸ���������
	void PushRows(int row);

	// ���������߼�
	void MoveBoxLeft(); 
	void MoveBoxRight(); 
	void MoveBoxDown(); 
	void MoveBoxUp();
	void shoot_Bullet();
		
private:
	int _left,  _bottom; //���ڹ�����Ϸ��Ĵ�С�����������
	int _right, _top; 

	
	MyPlane *bigplane;
}; 


#endif // #ifndef __UICONTROLLER__