#include"Soldier.h"
#include<vector>
#include<algorithm>
#include"MyDraw.h"

// 提供设置设置角色名以及获得属性的函数

void Soldier::underAttack(const double edamage)  // 收到攻击时的函数
{
	this->HP -= edamage;
}
void Soldier::setName(const std::string& name) {
	this->name = name;
}
void Soldier::dead() {
	this->HP = 0;
	std::cout << this->getName() << "已死亡！" << std::endl;
}
std::string Soldier::getName() const//获取名字
{
	return (" [" + name + "] ");
}
double Soldier::getmaxHP() const//获取最大生命值
{
	return maxHP;
}
double Soldier::getHP() const//获取生命值
{
	return HP;
}
double Soldier::getmaxSP() const//获取最大体力值
{
	return maxSP;
}
double Soldier::getSP() const//获取体力值
{
	return SP;
}
double Soldier::getdrugnum() const//获取药瓶数量
{
	return drugNum;
}
// 获取类名
std::string Soldier::getClassName() const {
	return std::string("Soldier");
}
double Soldier::getMP() const {    // 获取魔法值
	return 0;
}  
double Soldier::getmaxMP() const { // 获取最大魔法值
	return 0;
}  
double Soldier::getNP() const {  // 获取内力值
	return 0;
}  
double Soldier::getmaxNP() const {  // 获取最大内力值
	return 0;
}  
int Soldier::getLevel() const {	// 获取等级
	return this->level;
}

// 决策所包含的动作
void Soldier::makeDecision(Soldier** enemies) {

	if (this->HP < this->maxHP * 0.3) {
		//生命值若低于最大值的30%该回合就吃药
		this->takingDrug();
	}
	else if (this->SP < this->maxSP * 0.5){
		//体力低于最大值的50%该回合就休息
		this->rest();
	}
	else {
		//生命力和体力都充足该回合就发起攻击
		this->attack(enemies);
	}
	MyDraw::setCursorPosition(40, 15);
}

/*
*	@param (Soldier**) 敌方军团的二级指针
*	此函数执行攻击动作，以随机选中敌方角色的方式选中将要攻击的目标
*	若目标已阵亡，则重新选择，为避免进入死循环，使用STL中的random_shuffle模拟
*/
void Soldier::attack(Soldier** enemies) {
	std::vector<int> aim;
	for (int i = 0; i < NUMBEROFLEGIONS; ++i)
		aim.push_back(i);
	std::random_shuffle(aim.begin(), aim.end());
	for (auto it = aim.cbegin(); it != aim.cend(); ++it) {
		
		if (enemies[*it]->getHP() > 0) {
			// 当选中的敌方角色存活时,攻击生效
			std::cout << this->getName() << "对" << enemies[*it]->getName() << "发起了普通攻击";
			enemies[*it]->underAttack(this->damage);
			this->SP -= 10;
			this->exp += 5;
			MyDraw::setCursorPosition(40, 16);
			std::cout << this->getName() << "的体力值下降至：（" << this->SP << "/" << this->maxSP << ")";
			MyDraw::setCursorPosition(40, 17);
			std::cout << "经验值+5：(" << this->exp << "/20)";
			if (exp == 20) {
				// 角色升级
				double HPRatio = this->HP / this->maxHP;
				double SPRatio = this->SP / this->maxSP;
				this->maxHP += 20;
				this->maxSP += 20;
				this->damage += 20;
				this->level++;
				this->exp = 0;
				this->HP = this->maxHP * HPRatio;
				this->SP = this->maxSP * SPRatio;
				MyDraw::setCursorPosition(40, 18);
				std::cout << this->getName() << "升级！" << "当前等级：" << this->level;
			}
			std::cout << enemies[*it]->getName() << "受到" << this->damage << "伤害";
			if (enemies[*it]->getHP() <= 0) {
				enemies[*it]->dead();
				MyDraw::setCursorPosition(40, 18);
				std::cout << "当前生命值为：" << 0;
				this->drugNum += enemies[*it]->getdrugnum();
				MyDraw::setCursorPosition(40, 19);
				std::cout << "获取药瓶数：" << enemies[*it]->getdrugnum();
			}
			else {
				MyDraw::setCursorPosition(40, 18);
				std::cout << "当前生命值为：" << enemies[*it]->getHP();
			}
			return;
		}
	}
	return;
}
/*
*	休息函数实现7)休息（rest）一次，生命值（HP）、体力（SP）增加最大值的50%，但不要超过最大值。
*	（例如，当前生命值是30，最大生命值是100，则吃药后的当前生命值为30+100*50%=80。）
*/
void Soldier::rest() {
	std::cout << this->getName() << "开始休息";
	this->HP += this->maxHP * 0.5;
	if (this->HP > this->maxHP)
		this->HP = this->maxHP;
	this->SP += this->maxSP * 0.5;
	if (this->SP > this->maxSP)
		this->SP = this->maxSP;
	MyDraw::setCursorPosition(40, 16);
	std::cout << "***休息结束***";
	MyDraw::setCursorPosition(40, 17);
	std::cout << "当前生命值：(" << this->HP << "/" << this->maxHP << ")";
	MyDraw::setCursorPosition(40, 18);
	std::cout << "当前体力值：(" << this->SP << "/" << this->maxSP << ")";
}

/*
*	吃药函数实现：如果药瓶数量为0，不能吃药。
*	吃药一次，药瓶数量减少1，生命值（HP）增加最大值的80%，但不能超过maxHP。
*/
void Soldier::takingDrug() {
	std::cout << this->getName() << "施展神农剑法(吃药)";
	if (drugNum == 0)
	{
		MyDraw::setCursorPosition(40, 16);
		std::cout << "很遗憾," << this->getName() << "没有药瓶了";
		return;
	}
	else {
		this->drugNum--;
		this->HP += this->maxHP * 0.8;
		if (this->HP > this->maxHP)
			this->HP = this->maxHP;
	}
	MyDraw::setCursorPosition(40, 17);
	std::cout << "当前生命值：(" << this->HP << "/" << this->maxHP << ")";
}