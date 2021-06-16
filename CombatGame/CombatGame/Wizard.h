#ifndef __WIZARD_H__
#define __WIZARD_H__
#include"Soldier.h"

class Wizard : public Soldier {
public:
	Wizard() : Soldier(), maxMP(100.0), MP(100.0) {}
	virtual ~Wizard() {}

	// �����������Ķ���
	virtual void makeDecision(Soldier** enemies);
	// ��д��Ϣ����
	virtual void rest();
	// ħ������
	void wizardAttack(Soldier** enemies);
	virtual std::string getClassName() const;
	// ��ȡħ��ֵ
	double getMP() const;
	// ��ȡ���ħ��ֵ
	double getmaxMP() const;
protected:
	double maxMP;       // ���ħ��ֵ
	double MP;			// ħ��ֵ
};


#endif
