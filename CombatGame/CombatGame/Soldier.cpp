#include"Soldier.h"
#include<vector>
#include<algorithm>
#include"MyDraw.h"

// �ṩ�������ý�ɫ���Լ�������Եĺ���

void Soldier::underAttack(const double edamage)  // �յ�����ʱ�ĺ���
{
	this->HP -= edamage;
}
void Soldier::setName(const std::string& name) {
	this->name = name;
}
void Soldier::dead() {
	this->HP = 0;
	std::cout << this->getName() << "��������" << std::endl;
}
std::string Soldier::getName() const//��ȡ����
{
	return (" [" + name + "] ");
}
double Soldier::getmaxHP() const//��ȡ�������ֵ
{
	return maxHP;
}
double Soldier::getHP() const//��ȡ����ֵ
{
	return HP;
}
double Soldier::getmaxSP() const//��ȡ�������ֵ
{
	return maxSP;
}
double Soldier::getSP() const//��ȡ����ֵ
{
	return SP;
}
double Soldier::getdrugnum() const//��ȡҩƿ����
{
	return drugNum;
}
// ��ȡ����
std::string Soldier::getClassName() const {
	return std::string("Soldier");
}
double Soldier::getMP() const {    // ��ȡħ��ֵ
	return 0;
}  
double Soldier::getmaxMP() const { // ��ȡ���ħ��ֵ
	return 0;
}  
double Soldier::getNP() const {  // ��ȡ����ֵ
	return 0;
}  
double Soldier::getmaxNP() const {  // ��ȡ�������ֵ
	return 0;
}  
int Soldier::getLevel() const {	// ��ȡ�ȼ�
	return this->level;
}

// �����������Ķ���
void Soldier::makeDecision(Soldier** enemies) {

	if (this->HP < this->maxHP * 0.3) {
		//����ֵ���������ֵ��30%�ûغϾͳ�ҩ
		this->takingDrug();
	}
	else if (this->SP < this->maxSP * 0.5){
		//�����������ֵ��50%�ûغϾ���Ϣ
		this->rest();
	}
	else {
		//������������������ûغϾͷ��𹥻�
		this->attack(enemies);
	}
	MyDraw::setCursorPosition(40, 15);
}

/*
*	@param (Soldier**) �з����ŵĶ���ָ��
*	�˺���ִ�й��������������ѡ�ез���ɫ�ķ�ʽѡ�н�Ҫ������Ŀ��
*	��Ŀ����������������ѡ��Ϊ���������ѭ����ʹ��STL�е�random_shuffleģ��
*/
void Soldier::attack(Soldier** enemies) {
	std::vector<int> aim;
	for (int i = 0; i < NUMBEROFLEGIONS; ++i)
		aim.push_back(i);
	std::random_shuffle(aim.begin(), aim.end());
	for (auto it = aim.cbegin(); it != aim.cend(); ++it) {
		
		if (enemies[*it]->getHP() > 0) {
			// ��ѡ�еĵз���ɫ���ʱ,������Ч
			std::cout << this->getName() << "��" << enemies[*it]->getName() << "��������ͨ����";
			enemies[*it]->underAttack(this->damage);
			this->SP -= 10;
			this->exp += 5;
			MyDraw::setCursorPosition(40, 16);
			std::cout << this->getName() << "������ֵ�½�������" << this->SP << "/" << this->maxSP << ")";
			MyDraw::setCursorPosition(40, 17);
			std::cout << "����ֵ+5��(" << this->exp << "/20)";
			if (exp == 20) {
				// ��ɫ����
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
				std::cout << this->getName() << "������" << "��ǰ�ȼ���" << this->level;
			}
			std::cout << enemies[*it]->getName() << "�ܵ�" << this->damage << "�˺�";
			if (enemies[*it]->getHP() <= 0) {
				enemies[*it]->dead();
				MyDraw::setCursorPosition(40, 18);
				std::cout << "��ǰ����ֵΪ��" << 0;
				this->drugNum += enemies[*it]->getdrugnum();
				MyDraw::setCursorPosition(40, 19);
				std::cout << "��ȡҩƿ����" << enemies[*it]->getdrugnum();
			}
			else {
				MyDraw::setCursorPosition(40, 18);
				std::cout << "��ǰ����ֵΪ��" << enemies[*it]->getHP();
			}
			return;
		}
	}
	return;
}
/*
*	��Ϣ����ʵ��7)��Ϣ��rest��һ�Σ�����ֵ��HP����������SP���������ֵ��50%������Ҫ�������ֵ��
*	�����磬��ǰ����ֵ��30���������ֵ��100�����ҩ��ĵ�ǰ����ֵΪ30+100*50%=80����
*/
void Soldier::rest() {
	std::cout << this->getName() << "��ʼ��Ϣ";
	this->HP += this->maxHP * 0.5;
	if (this->HP > this->maxHP)
		this->HP = this->maxHP;
	this->SP += this->maxSP * 0.5;
	if (this->SP > this->maxSP)
		this->SP = this->maxSP;
	MyDraw::setCursorPosition(40, 16);
	std::cout << "***��Ϣ����***";
	MyDraw::setCursorPosition(40, 17);
	std::cout << "��ǰ����ֵ��(" << this->HP << "/" << this->maxHP << ")";
	MyDraw::setCursorPosition(40, 18);
	std::cout << "��ǰ����ֵ��(" << this->SP << "/" << this->maxSP << ")";
}

/*
*	��ҩ����ʵ�֣����ҩƿ����Ϊ0�����ܳ�ҩ��
*	��ҩһ�Σ�ҩƿ��������1������ֵ��HP���������ֵ��80%�������ܳ���maxHP��
*/
void Soldier::takingDrug() {
	std::cout << this->getName() << "ʩչ��ũ����(��ҩ)";
	if (drugNum == 0)
	{
		MyDraw::setCursorPosition(40, 16);
		std::cout << "���ź�," << this->getName() << "û��ҩƿ��";
		return;
	}
	else {
		this->drugNum--;
		this->HP += this->maxHP * 0.8;
		if (this->HP > this->maxHP)
			this->HP = this->maxHP;
	}
	MyDraw::setCursorPosition(40, 17);
	std::cout << "��ǰ����ֵ��(" << this->HP << "/" << this->maxHP << ")";
}