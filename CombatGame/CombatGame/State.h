#ifndef __STATE_H__
#define __STATE_H__
#include"Master.h"

class State {
public:
    void StateEffect(Soldier& a);
    std::string name;
    // �������״̬�ļ��ܵ�����
    std::string skillName;
    // ״̬��Ч�Ĵ���
    int times = 0;
    // ״̬��Ч�Ļغ���
    int counts = 0;
    // DOTʱ����˺�
    int damage = 0;
    // HOTʱ����˺�
    int hprecover = 0;
    // ���Ի��˺��������ʱ��ı���
    double ratio = 0;
    // ��ǰ״̬��������������
    int atkUp = 0;
    // ��ǰ״̬���������������
    int defUp = 0;
    // ��ǰ״̬������ħ��������
    int matUp = 0;
    // ��ǰ״̬������ħ��������
    int menUp = 0;
    

};


#endif