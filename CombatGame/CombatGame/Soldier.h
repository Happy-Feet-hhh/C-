#ifndef __SOLDIER_H__
#define __SOLDIER_H__
#include<string>
#include<iostream>

static const int NUMBEROFLEGIONS = 5;

// 战士类的头文件
 
class Soldier {
public:
	Soldier() : maxHP(100.0), HP(100.0), maxSP(100.0), SP(100.0),
		damage(20.0), exp(0), level(1), drugNum(5) {
		std::cout << "请输入角色名：";
		std::string name;
		std::cin >> name;
		setName(name);
	}
	virtual ~Soldier() {}

	// 提供设置设置角色名以及获得属性的函数
	void setName(const std::string& name);
	std::string getName() const;//获取名字
	double getmaxHP() const;//获取最大生命值
	double getHP() const;//获取生命值
	double getmaxSP() const;//获取最大体力值
	double getSP() const;//获取体力值
	double getdrugnum() const;//获取药瓶数量
	void dead();         // 设置为死亡状态
	void underAttack(const double damage);  // 收到攻击时的函数
	virtual std::string getClassName() const;  // 获取类名
	virtual double getMP() const;    // 获取魔法值
	virtual double getmaxMP() const;  // 获取最大魔法值
	virtual double getNP() const;     // 获取内力值
	virtual double getmaxNP() const;  // 获取最大内力值
	int getLevel() const;             // 获取等级

	// 决策所包含的动作
	virtual void makeDecision(Soldier** enemies);
	void attack(Soldier** enemies);
	virtual void rest();
	void takingDrug();

protected:
	double maxHP;    // 最大生命值
	double HP;       // 当前生命值
	double maxSP;    // 最大体力值
	double SP;       // 当前体力值
	double damage;   // 角色攻击力
	int exp;       // 经验值
	int level;     // 等级
	std::string name; // 角色名
	int drugNum;    // 药瓶数量
};


#endif