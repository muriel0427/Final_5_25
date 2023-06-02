#pragma once
#include "pch.h"


using namespace System;
using namespace System::Collections::Generic;

// 定義遊戲角色類別
public enum class RoleType
{
    Swordsman,
    Knifesmith,
    Gunner,
    Priest,
    Mage
};

public ref class Skill
{
public:
    String^ name;
    int level;
    int cooldown;
    int cost;
    int damage;

    int GetCost()
    {
        return cost;
    }
};

public enum class ResourceType
{
    HP,
    MP,
    SP
};


public ref class Role
{
public:
    String^ name;
    int maxHP;
    int maxSP;
    int maxMP;
    int currentHP;
    int currentSP;
    int currentMP;
    int attackDamage;
    int level; // 等級屬性
    int experience; // 經驗值屬性
    ResourceType resourceType; // 更新的屬性，表示資源類型

    RoleType type;
    List<Skill^>^ skills; // 技能列表

    int  GetAttackDamage() {
        return attackDamage;
    }
    bool CheckLevelUp()
    {
        // 檢查是否升級的函數
        // 每300 經驗值升級一次
        int requiredExperience = 300 * level;
        return experience >= requiredExperience;
    }

    void GainExperience(int points)
    {
        // 增加經驗值的函數
        experience += points;
    }
    void UnlockNewSkill()
    {
        // 解鎖新技能的邏輯
        Skill^ newSkill = gcnew Skill();

        switch (level)
        {
            //此部分尚須修改
        case 0:
            newSkill->name = "SKill_0";
            newSkill->level = 0;
            newSkill->cooldown = 30;
            newSkill->cost = 3;
            newSkill->damage = 0;
        case 1:
            newSkill->name = "SKill_1";
            newSkill->level = 1;
            newSkill->cooldown = 10;
            newSkill->cost = 3;
            newSkill->damage = 10;
            break;
        case 2:
            newSkill->name = "SKill_2";
            newSkill->level = 2;
            newSkill->cooldown = 15;
            newSkill->cost = 5;
            newSkill->damage = 15;
            break;
        case 3:
            newSkill->name = "SKill_3";
            newSkill->level = 3;
            newSkill->cooldown = 8;
            newSkill->cost = 5;
            newSkill->damage = 10;
            break;
        case 4:
            newSkill->name = "SKill_4";
            newSkill->level = 4;
            newSkill->cooldown = 60;
            newSkill->cost = 50;
            newSkill->damage = 50;
            break;
        case 5:
            newSkill->name = "SKill_5";
            newSkill->level = 5;
            newSkill->cooldown = 60;
            newSkill->cost = 25;
            newSkill->damage = 0;
            break;
        default:
            break;
        }

        skills->Add(newSkill);
    }
    bool GetSkillCooldown(Skill^ skill)
    {
        // 檢查技能是否存在於技能列表中
        if (!skills->Contains(skill))
        {
            Console::WriteLine("技能不存在於角色的技能列表中。");
            return false;
        }

        // 檢查技能是否在冷卻中
        int index = skills->IndexOf(skill);
        Skill^ currentSkill = skills[index];
        if (currentSkill->cooldown > 0)
        {
            Console::WriteLine("技能正在冷卻中，還需等待 {0} 秒", currentSkill->cooldown);
            return false;
        }

        // 技能冷卻完成
        Console::WriteLine("技能冷卻已完成，可以使用該技能。");
        return true;
    }
    int GetSkillCost(Skill^ skill)
    {
        if (skill != nullptr)
        {
            // 檢查技能的等級
            int skillLevel = skill->level;

            // 根據技能等級返回對應的消耗值
            switch (skillLevel)
            {
            case 0:
                return 3; // SP 消耗為 3
            case 1:
                return 3; // MP 消耗為 3
            case 2:
                return 5; // SP 消耗為 5
            case 3:
                return 5; // MP 消耗為 5
            case 4:
                return 50; // HP 消耗為 50
            case 5:
                return 25; // MP 消耗為 25
            default:
                return 0;
            }
        }

        return 0;
    }
    int GetCurrentResourcePoints(Role^ role, ResourceType resourceType)
    {
        if (role != nullptr)
        {
            // 根據資源類型返回對應的資源點數
            switch (resourceType)
            {
            case ResourceType::HP:
                return role->currentHP;
            case ResourceType::SP:
                return role->currentSP;
            case ResourceType::MP:
                return role->currentMP;
            default:
                return 0;
            }
        }

        return 0;
    }
    ResourceType GetResourceType(Skill^ skill)
    {
        String^ skillName = skill->name->ToUpper();

        if (skillName == "SKill_0")
            return ResourceType::SP;
        else if (skillName == "SKill_1")
            return ResourceType::MP;
        else if (skillName == "SKill_2")
            return ResourceType::SP;
        else if (skillName == "SKill_3")
            return ResourceType::MP;
        else if (skillName == "SKill_4")
            return ResourceType::HP;
        else if (skillName == "SKill_5")
            return ResourceType::MP;
    }
    void ReduceResourcePoints(ResourceType resourceType, int cost)
    {
        if (resourceType == ResourceType::HP)
        {
            currentHP -= cost;
        }
        else if (resourceType == ResourceType::MP)
        {
            currentMP -= cost;
        }
        else if (resourceType == ResourceType::SP)
        {
            currentSP -= cost;
        }
    }
    //等待完成
    void StartSkillCooldown(Skill^ skill){}
    void Skill_0(){}
    void Skill_1(){}
    void Skill_2(){}
    void Skill_3(){}
    void Skill_4(){}
    void Skill_5(){}



};

// 定義物品類別
public enum class ItemType
{
    MPPoison,
    HPPoison,
    SPPoison,
    EXPGem,
    Boom
};

public ref class Item
{
public:
    String^ name;
    ItemType type;
    int value;
};



// 定義怪物類別
public enum class MonsterType
{
    PurpleTurtle,
    RedRat,
    BlueButterfly
};

public ref class Monster
{
public:
    String^ name;
    MonsterType type;
    int occurrenceProbability;
    int maxHP;
    int HP;
    int attackDamage;
    String^ attackMethod;
    String^ speed;
    String^ features;
    List<Item^>^ dropItems;




    List<Item^>^ GenerateDropItems()
    {
        List<Item^>^ dropItems = gcnew List<Item^>();

        // 20% 的機率獲得 HP Potion
        if (GetRandomPercentage() <= 20)
        {
            Item^ hpPotion = gcnew Item();
            hpPotion->name = "HP Potion";
            hpPotion->type = ItemType::HPPoison;
            hpPotion->value = 5;
            dropItems->Add(hpPotion);
        }

        // 80% 的機率獲得 SP Potion
        if (GetRandomPercentage() <= 80)
        {
            Item^ spPotion = gcnew Item();
            spPotion->name = "SP Potion";
            spPotion->type = ItemType::SPPoison;
            spPotion->value = 10;
            dropItems->Add(spPotion);
        }

        // 100% 的機率獲得 EXP Gem
        Item^ expGem = gcnew Item();
        expGem->name = "EXP Gem";
        expGem->type = ItemType::EXPGem;
        expGem->value = 10;
        dropItems->Add(expGem);

        return dropItems;
    }
    int GetRandomPercentage()
    {
        Random^ random = gcnew Random();
        return random->Next(1, 101);
    }
    void ReceiveDamage(int damage) {
        HP = HP - damage;
    }
    bool IsDefeated() {
        if (HP <= 0) {
            return true;
        }
        else
        {
            return false;
        }
    }
    int GetExperiencePoints(List<Item^>^ dropItems)
    {
        int experiencePoints = 0;

        for each (Item ^ item in dropItems)
        {
            if (item->type == ItemType::EXPGem)
            {
                experiencePoints += item->value;
            }
        }

        return experiencePoints;
    }
};

// 定義Boss類別
public enum class BossType
{
    PurpleSnake,
    RedLion,
    BlueTanystropheus
};

public ref class Boss
{
public:
    String^ name;
    BossType type;
    TimeSpan occurrenceTiming;
    int maxHP;
    String^ speed;
    String^ features;
    List<Item^>^ dropItems;
};

// 定義遊戲數據類別
public ref class GameData
{
public:
    List<Role^>^ roles;
    List<Item^>^ items;
    List<Skill^>^ skills;
    List<Monster^>^ monsters;
    List<Boss^>^ bosses;

    GameData()
    {
        roles = gcnew List<Role^>();
        items = gcnew List<Item^>();
        skills = gcnew List<Skill^>();
        monsters = gcnew List<Monster^>();
        bosses = gcnew List<Boss^>();
    }
};
