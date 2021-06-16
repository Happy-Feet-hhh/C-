#ifndef __STATE_H__
#define __STATE_H__
#include"Master.h"

class State {
public:
    void StateEffect(Soldier& a);
    std::string name;
    // 生成这个状态的技能的名字
    std::string skillName;
    // 状态生效的次数
    int times = 0;
    // 状态生效的回合数
    int counts = 0;
    // DOT时候的伤害
    int damage = 0;
    // HOT时候的伤害
    int hprecover = 0;
    // 属性或伤害加深减少时候的比率
    double ratio = 0;
    // 当前状态提升的物理攻击力
    int atkUp = 0;
    // 当前状态提升的物理防御力
    int defUp = 0;
    // 当前状态提升的魔法攻击力
    int matUp = 0;
    // 当前状态提升的魔法防御力
    int menUp = 0;
    

};


#endif