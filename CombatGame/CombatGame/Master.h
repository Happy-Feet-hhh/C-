#ifndef __MASTER_H__
#define __MASTER_H__
#include"Wizard.h"

class Master : public Wizard {
public:
	Master() : Wizard(), maxNP(100.0), NP(100.0) {
		damage = 30.0;
	}
	virtual ~Master() {}

	// �����������Ķ���
	virtual void makeDecision(Soldier** enemies);
	// ��д��Ϣ����
	virtual void rest();
	// ��ʦ�ľ�ɱ����
	void masterAttack(Soldier** enemies);
	virtual std::string getClassName() const;  // ��ȡ����
	virtual double getMP() const;	// ��ȡħ��ֵ
	virtual double getmaxMP() const;	// ��ȡ���ħ��ֵ
	virtual double getNP() const;		// ��ȡ����ֵ
	virtual double getmaxNP() const;	// ��ȡ�������ֵ
protected:
	double maxNP;	// �������
	double NP;		// ����
};

#endif
