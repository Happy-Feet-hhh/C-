#ifndef __WIZARD_H__
#define __WIZARD_H__
#include"Soldier.h"

class Wizard : public Soldier {
public:
	Wizard() : Soldier(), maxMP(100.0), MP(100.0) {}
	virtual ~Wizard() {}

	// 决策所包含的动作
	virtual void makeDecision(Soldier** enemies);
	// 重写休息函数
	virtual void rest();
	// 魔法攻击
	void wizardAttack(Soldier** enemies);
	virtual std::string getClassName() const;
	// 获取魔法值
	double getMP() const;
	// 获取最大魔法值
	double getmaxMP() const;
protected:
	double maxMP;       // 最大魔法值
	double MP;			// 魔法值
};


#endif
