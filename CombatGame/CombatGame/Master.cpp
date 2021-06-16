#include"Master.h"
#include<vector>
#include<algorithm>
#include"MyDraw.h"

// 获取类名
std::string Master::getClassName() const{
	return std::string("Master");
}
double Master::getMP() const {    // 获取魔法值
	return this->MP;
}
double Master::getmaxMP() const { // 获取最大魔法值
	return this->maxMP;
}
double Master::getNP() const {  // 获取内力值
	return this->NP;
}
double Master::getmaxNP() const {  // 获取最大内力值
	return this->maxNP;
}

// 决策所包含的动作
void Master::makeDecision(Soldier** enemies) {
	if (this->HP < this->maxHP * 0.3) {
		//生命值若低于最大值的30%该回合就吃药
		this->attack(enemies);
	}
	else if (this->SP < this->maxSP * 0.5) {
		//体力低于最大值的50%该回合就休息
		this->rest();
	}
	else if (this->NP >= 50 && this->SP >= 30) {
		// 如果内力大于等于50且体力大于等于30就使用大师的绝杀攻击
		this->masterAttack(enemies);
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
void Master::rest() {
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
	this->NP += this->maxNP * 0.3;
	if (this->NP > this->maxNP)
		this->NP = this->maxNP;
	MyDraw::setCursorPosition(40, 16);
	std::cout << "***休息结束***";
	MyDraw::setCursorPosition(40, 17);
	std::cout << "当前生命值：(" << this->HP << "/" << this->maxHP << ")";
	MyDraw::setCursorPosition(40, 18);
	std::cout << "当前体力值：(" << this->SP << "/" << this->maxSP << ")";
	MyDraw::setCursorPosition(40, 19);
	std::cout << "当前魔法值：(" << this->MP << "/" << this->maxMP << ")";
	MyDraw::setCursorPosition(49, 20);
	std::cout << "当前内力值：(" << this->NP << "/" << this->maxNP << ")";
}
// 大师的绝杀攻击
void Master::masterAttack(Soldier** enemies) {
	std::vector<int> aim;
	for (int i = 0; i < NUMBEROFLEGIONS; ++i)
		aim.push_back(i);
	std::random_shuffle(aim.begin(), aim.end());
	for (auto it = aim.cbegin(); it != aim.cend(); ++it) {

		if (enemies[*it]->getHP() > 0) {
			// 当选中的敌方角色存活时,攻击生效
			std::cout << this->getName() << ":\"终结技来咯！\"" << " ";
			MyDraw::setCursorPosition(40, 16);
			std::cout << this->getName() << "对" << enemies[*it]->getName() << "发起了绝杀攻击";
			enemies[*it]->underAttack(this->damage + enemies[*it]->getmaxHP() * 0.15);
			this->SP -= 30;
			this->NP -= 50;
			this->exp += 5;
			MyDraw::setCursorPosition(40, 17);
			std::cout << this->getName() << "的体力值下降至：（" << this->SP << "/" << this->maxSP << ")";
			MyDraw::setCursorPosition(40, 18);
			std::cout << "的内力值下降至：（" << this->NP << "/" << this->maxNP << ")";
			MyDraw::setCursorPosition(40, 19);
			std::cout << "经验值+5：(" << this->exp << "/20)";
			if (exp == 20) {
				// 角色升级
				double HPRatio = this->HP / this->maxHP;
				double SPRatio = this->SP / this->maxSP;
				double MPRatio = this->MP / this->maxMP;
				double NPRatio = this->NP / this->maxNP;
				this->maxHP += 20;
				this->maxSP += 20;
				this->maxMP += 20;
				this->maxNP += 20;
				this->damage += 20;
				this->level++;
				this->exp = 0;
				this->HP = this->maxHP * HPRatio;
				this->SP = this->maxSP * SPRatio;
				this->MP = this->maxMP * MPRatio;
				this->NP = this->maxNP * NPRatio;
				MyDraw::setCursorPosition(40, 20);
				std::cout << this->getName() << "升级！" << "当前等级：" << this->level;
			}
			MyDraw::setCursorPosition(40, 21);
			std::cout << enemies[*it]->getName() << "受到" << this->damage + enemies[*it]->getmaxHP() * 0.15 << "伤害";
			if (enemies[*it]->getHP() <= 0) {
				enemies[*it]->dead();
				this->drugNum += enemies[*it]->getdrugnum();
				MyDraw::setCursorPosition(40, 22);
				std::cout << "获取药瓶数：" << enemies[*it]->getdrugnum();
			}
			else {
				MyDraw::setCursorPosition(40, 22);
				std::cout << "当前生命值为：" << enemies[*it]->getHP();
			}
			return;
		}
	}
	return;
}