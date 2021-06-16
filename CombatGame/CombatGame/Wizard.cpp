#include"Wizard.h"
#include"MyDraw.h"
#include<vector>
#include<algorithm>

// 获取类名
std::string Wizard::getClassName() const {
	return std::string("Wizard");
}
// 获取最大魔法值
double Wizard::getmaxMP() const {
	return this->maxMP;
}

double Wizard::getMP() const {
	return this->MP;
}

// 决策所包含的动作
void Wizard::makeDecision(Soldier** enemies) {

	if (this->HP < this->maxHP * 0.3) {
		//生命值若低于最大值的30%该回合就吃药
		this->attack(enemies);
	}
	else if (this->SP < this->maxSP * 0.5) {
		//体力低于最大值的50%该回合就休息
		this->rest();
	}
	else if (this->MP >= 25 && this->SP >= 10) {
		// 魔法值大于等于25且体力值大于等于10时执行魔法攻击
		this->wizardAttack(enemies);
	}
	else {
		//生命力和体力都充足该回合就发起攻击
		this->takingDrug();
	}
	MyDraw::setCursorPosition(40, 15);
}

// 重写休息函数
void Wizard::rest() {
	std::cout << this->getName() << "开始休息";
	this->HP += this->maxHP * 0.5;
	if (this->HP > this->maxHP)
		this->HP = this->maxHP;
	this->SP += this->maxSP * 0.5;
	if (this->SP > this->maxSP)
		this->SP = this->maxSP;
	this->MP += this->maxMP * 0.5;
	if (this->MP > this->maxMP)
		this->MP = this->maxMP;
	MyDraw::setCursorPosition(40, 16);
	std::cout << "***休息结束***";
	MyDraw::setCursorPosition(40, 17);
	std::cout << "当前生命值：(" << this->HP << "/" << this->maxHP << ")";
	MyDraw::setCursorPosition(40, 18);
	std::cout << "当前体力值：(" << this->SP << "/" << this->maxSP << ")";
	MyDraw::setCursorPosition(40, 19);
	std::cout << "当前魔法值：(" << this->MP << "/" << this->maxMP << ")";
}
// 魔法攻击
void Wizard::wizardAttack(Soldier** enemies) {
	std::vector<int> aim;
	for (int i = 0; i < NUMBEROFLEGIONS; ++i)
		aim.push_back(i);
	std::random_shuffle(aim.begin(), aim.end());
	for (auto it = aim.cbegin(); it != aim.cend(); ++it) {
		if(this->MP >= 25 && this->SP >= 10){
			if (enemies[*it]->getHP() > 0) {
				// 当选中的敌方角色存活时,攻击生效
				std::cout << this->getName() << "对" << enemies[*it]->getName() << "发起了魔法攻击";
				enemies[*it]->underAttack(this->damage * 0.3);
				this->SP -= 10;
				this->MP -= 25;
				this->exp += 5;
				MyDraw::setCursorPosition(40, 16);
				std::cout << this->getName() << "的体力值下降至：（" << this->SP << "/" << this->maxSP << ")";
				MyDraw::setCursorPosition(40, 17);
				std::cout << "的魔法值下降至：（" << this->MP << "/" << this->maxMP << ")";
				MyDraw::setCursorPosition(40, 18);
				std::cout << "经验值+5：(" << this->exp << "/20)";
				if (exp == 20) {
					// 角色升级
					double HPRatio = this->HP / this->maxHP;
					double SPRatio = this->SP / this->maxSP;
					double MPRatio = this->MP / this->maxMP;
					this->maxHP += 20;
					this->maxSP += 20;
					this->maxMP += 20;
					this->damage += 20;
					this->level++;
					this->exp = 0;
					this->HP = this->maxHP * HPRatio;
					this->SP = this->maxSP * SPRatio;
					this->MP = this->maxMP * MPRatio;
					MyDraw::setCursorPosition(40, 19);
					std::cout << this->getName() << "升级！" << "当前等级：" << this->level << std::endl;
				}
				if (enemies[*it]->getHP() <= 0) {
					enemies[*it]->dead();
					this->drugNum += enemies[*it]->getdrugnum();
					MyDraw::setCursorPosition(40, 20);
					std::cout << "获取药瓶数：" << enemies[*it]->getdrugnum();
				}
				else {
					MyDraw::setCursorPosition(40, 21);
					std::cout << "当前生命值为：" << enemies[*it]->getHP();
				}
			}
		}
		else {
			MyDraw::setCursorPosition(40, 22);
			std::cout << "魔法值或者体力值不足无法继续魔法攻击";
			return;
		}
	}
	return;
}