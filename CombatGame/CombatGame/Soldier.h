#ifndef __SOLDIER_H__
#define __SOLDIER_H__
#include<string>
#include<iostream>

static const int NUMBEROFLEGIONS = 5;

// սʿ���ͷ�ļ�
 
class Soldier {
public:
	Soldier() : maxHP(100.0), HP(100.0), maxSP(100.0), SP(100.0),
		damage(20.0), exp(0), level(1), drugNum(5) {
		std::cout << "�������ɫ����";
		std::string name;
		std::cin >> name;
		setName(name);
	}
	virtual ~Soldier() {}

	// �ṩ�������ý�ɫ���Լ�������Եĺ���
	void setName(const std::string& name);
	std::string getName() const;//��ȡ����
	double getmaxHP() const;//��ȡ�������ֵ
	double getHP() const;//��ȡ����ֵ
	double getmaxSP() const;//��ȡ�������ֵ
	double getSP() const;//��ȡ����ֵ
	double getdrugnum() const;//��ȡҩƿ����
	void dead();         // ����Ϊ����״̬
	void underAttack(const double damage);  // �յ�����ʱ�ĺ���
	virtual std::string getClassName() const;  // ��ȡ����
	virtual double getMP() const;    // ��ȡħ��ֵ
	virtual double getmaxMP() const;  // ��ȡ���ħ��ֵ
	virtual double getNP() const;     // ��ȡ����ֵ
	virtual double getmaxNP() const;  // ��ȡ�������ֵ
	int getLevel() const;             // ��ȡ�ȼ�

	// �����������Ķ���
	virtual void makeDecision(Soldier** enemies);
	void attack(Soldier** enemies);
	virtual void rest();
	void takingDrug();

protected:
	double maxHP;    // �������ֵ
	double HP;       // ��ǰ����ֵ
	double maxSP;    // �������ֵ
	double SP;       // ��ǰ����ֵ
	double damage;   // ��ɫ������
	int exp;       // ����ֵ
	int level;     // �ȼ�
	std::string name; // ��ɫ��
	int drugNum;    // ҩƿ����
};


#endif