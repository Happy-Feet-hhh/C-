#include"Wizard.h"
#include"MyDraw.h"
#include<vector>
#include<algorithm>

// ��ȡ����
std::string Wizard::getClassName() const {
	return std::string("Wizard");
}
// ��ȡ���ħ��ֵ
double Wizard::getmaxMP() const {
	return this->maxMP;
}

double Wizard::getMP() const {
	return this->MP;
}

// �����������Ķ���
void Wizard::makeDecision(Soldier** enemies) {

	if (this->HP < this->maxHP * 0.3) {
		//����ֵ���������ֵ��30%�ûغϾͳ�ҩ
		this->attack(enemies);
	}
	else if (this->SP < this->maxSP * 0.5) {
		//�����������ֵ��50%�ûغϾ���Ϣ
		this->rest();
	}
	else if (this->MP >= 25 && this->SP >= 10) {
		// ħ��ֵ���ڵ���25������ֵ���ڵ���10ʱִ��ħ������
		this->wizardAttack(enemies);
	}
	else {
		//������������������ûغϾͷ��𹥻�
		this->takingDrug();
	}
	MyDraw::setCursorPosition(40, 15);
}

// ��д��Ϣ����
void Wizard::rest() {
	std::cout << this->getName() << "��ʼ��Ϣ";
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
	std::cout << "***��Ϣ����***";
	MyDraw::setCursorPosition(40, 17);
	std::cout << "��ǰ����ֵ��(" << this->HP << "/" << this->maxHP << ")";
	MyDraw::setCursorPosition(40, 18);
	std::cout << "��ǰ����ֵ��(" << this->SP << "/" << this->maxSP << ")";
	MyDraw::setCursorPosition(40, 19);
	std::cout << "��ǰħ��ֵ��(" << this->MP << "/" << this->maxMP << ")";
}
// ħ������
void Wizard::wizardAttack(Soldier** enemies) {
	std::vector<int> aim;
	for (int i = 0; i < NUMBEROFLEGIONS; ++i)
		aim.push_back(i);
	std::random_shuffle(aim.begin(), aim.end());
	for (auto it = aim.cbegin(); it != aim.cend(); ++it) {
		if(this->MP >= 25 && this->SP >= 10){
			if (enemies[*it]->getHP() > 0) {
				// ��ѡ�еĵз���ɫ���ʱ,������Ч
				std::cout << this->getName() << "��" << enemies[*it]->getName() << "������ħ������";
				enemies[*it]->underAttack(this->damage * 0.3);
				this->SP -= 10;
				this->MP -= 25;
				this->exp += 5;
				MyDraw::setCursorPosition(40, 16);
				std::cout << this->getName() << "������ֵ�½�������" << this->SP << "/" << this->maxSP << ")";
				MyDraw::setCursorPosition(40, 17);
				std::cout << "��ħ��ֵ�½�������" << this->MP << "/" << this->maxMP << ")";
				MyDraw::setCursorPosition(40, 18);
				std::cout << "����ֵ+5��(" << this->exp << "/20)";
				if (exp == 20) {
					// ��ɫ����
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
					std::cout << this->getName() << "������" << "��ǰ�ȼ���" << this->level << std::endl;
				}
				if (enemies[*it]->getHP() <= 0) {
					enemies[*it]->dead();
					this->drugNum += enemies[*it]->getdrugnum();
					MyDraw::setCursorPosition(40, 20);
					std::cout << "��ȡҩƿ����" << enemies[*it]->getdrugnum();
				}
				else {
					MyDraw::setCursorPosition(40, 21);
					std::cout << "��ǰ����ֵΪ��" << enemies[*it]->getHP();
				}
			}
		}
		else {
			MyDraw::setCursorPosition(40, 22);
			std::cout << "ħ��ֵ��������ֵ�����޷�����ħ������";
			return;
		}
	}
	return;
}