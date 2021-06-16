#ifndef __MASTER_H__
#define __MASTER_H__
#include"Wizard.h"

class Master : public Wizard {
public:
	Master() : Wizard(), maxNP(100.0), NP(100.0) {
		damage = 30.0;
	}
	virtual ~Master() {}

	// 决策所包含的动作
	virtual void makeDecision(Soldier** enemies);
	// 重写休息函数
	virtual void rest();
	// 大师的绝杀攻击
	void masterAttack(Soldier** enemies);
	virtual std::string getClassName() const;  // 获取类名
	virtual double getMP() const;	// 获取魔法值
	virtual double getmaxMP() const;	// 获取最大魔法值
	virtual double getNP() const;		// 获取内力值
	virtual double getmaxNP() const;	// 获取最大内力值
protected:
	double maxNP;	// 最大内力
	double NP;		// 内力
};

#endif
