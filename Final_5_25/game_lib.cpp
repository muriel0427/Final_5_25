#pragma once
#include "pch.h"
#include "game_lib.h"
#include "Resource.h"
#include "other.h"
#include "data_format.h"




// 函數用於玩家攻擊怪物
void AttackMonster(Role^ player, Monster^ monster) {
    int damage = player->GetAttackDamage();
	monster->ReceiveDamage(damage);
    // 檢查怪物是否被擊敗
    if (monster->IsDefeated()) {
        // 獲得經驗值和金幣
        player->GainExperience(monster->GetExperiencePoints(monster->dropItems));
        //player->GainCoins(monster->GetCoins());

        // 檢查是否升級
        if (player->CheckLevelUp()) {
            // 解鎖新技能
            player->UnlockNewSkill();
        }
    }
}

// 函數用於玩家使用物品
/*
void UseItem(Role^ player, Item^ item) {
    if (item->GetType() == ItemType::MPPoison) {
        player->RestoreMP(10);
    }
    else if (item->GetType() == ItemType::HPPoison) {
        player->RestoreHP(5);
    }
    else if (item->GetType() == ItemType::SPPoison) {
        player->RestoreSP(10);
    }
    else if (item->GetType() == ItemType::EXPGem) {
        player->GainExperience(10);
    }
    else if (item->GetType() == ItemType::Boom) {
        // 在周圍造成傷害
        player->DealDamageToSurroundingMonsters(10);
    }
}
*/

// 函數用於檢查玩家是否可以使用技能
bool CanUseSkill(Role^ player, Skill^ skill)
{
    ResourceType requiredResource = player->GetResourceType(skill);

    switch (requiredResource)
    {
    case ResourceType::HP:
        return player->GetCurrentResourcePoints(player,ResourceType::HP) >= skill->cost;
    case ResourceType::MP:
        return player->GetCurrentResourcePoints(player, ResourceType::MP) >= skill->cost;
    case ResourceType::SP:
        return player->GetCurrentResourcePoints(player, ResourceType::SP) >= skill->cost;
    default:
        return false;
    }
}

// 函數用於玩家使用技能
void UseSkill(Role^ player, Skill^ skill) {
    if (CanUseSkill(player, skill)) {
        player->ReduceResourcePoints(player->GetResourceType(skill), skill->GetCost());
        //待完成
        player->StartSkillCooldown(skill);
        // 根據技能效果執行相應操作
        if (skill->name == "SKill_0") {
            player->Skill_0();
        }
        else if (skill->name == "SKill_1") {
            player->Skill_1();
        }
        else if (skill->name == "SKill_2") {
            player->Skill_2();
        }
        else if (skill->name == "SKill_3") {
            player->Skill_3();
        }
        else if (skill->name == "SKill_4") {
            player->Skill_4();
        }
        else if (skill->name == "SKill_5") {
            player->Skill_5();
        }
    }
}

// 函數用於遊戲開始時生成怪物
Monster^ GenerateMonster() {
    // 根據機率生成不同類型的怪物
    double random = GenerateRandomNumber(); // 生成一個0到1之間的隨機數
    if (random < 0.4) {
        Monster^ PurpleTurtle = gcnew Monster();
        PurpleTurtle->name = "Purple Turtle";
        PurpleTurtle->type = MonsterType::PurpleTurtle;
        return  PurpleTurtle;
    }
    else if (random < 0.8) {
        Monster^ redRat = gcnew Monster();
        redRat->name = "Red Rat";
        redRat->type = MonsterType::RedRat;
        return redRat;
    }
    else {
        Monster^ blueButterfly = gcnew Monster();
        blueButterfly->name = "Blue Butterfly";
        blueButterfly->type = MonsterType::BlueButterfly;
        return blueButterfly;
    }
}

// 函數用於遊戲開始時生成Boss
Boss^ GenerateBoss()
{
    double random = GenerateRandomNumber(); // 生成0到1之间的随机数

    if (random < 0.33) {
        Boss^ PurpleSnake = gcnew Boss();
        PurpleSnake->name = "PurpleSnake";
        PurpleSnake->type = BossType::PurpleSnake;
        return PurpleSnake;
    }
    else if (random < 0.67) {
        Boss^ RedLion = gcnew Boss();
        RedLion->name = "RedLion";
        RedLion->type = BossType::RedLion;
        return RedLion;
    }
    else {
        Boss^ BlueTanystropheus = gcnew Boss();
        BlueTanystropheus->name = "BlueTanystropheus";
        BlueTanystropheus->type = BossType::BlueTanystropheus;
        return BlueTanystropheus;
    }
}



/*
// 函數用於遊戲結束時判斷是否達到通關條件
bool CheckGameWinCondition(Role^ player) {
    // 判斷玩家是否達到通關條件，例如擊敗所有Boss或達到最高等級等
    // 返回true表示通關，返回false表示未達到通關條件
    // 這裡假設通關條件是達到最高等級
    return player->GetCurrentLevel() == MaxLevel;
}

// 函數用於遊戲結束時判斷是否失敗條件
bool CheckGameOverCondition(Role^ player) {
    // 判斷玩家是否失敗條件，例如生命值歸零等
    // 返回true表示失敗，返回false表示未達到失敗條件
    // 這裡假設失敗條件是生命值歸零
    return player->GetCurrentHP() <= 0;
}

// 函數用於遊戲結束時的操作
void GameOver() {
    // 執行遊戲結束的相應操作，例如顯示得分、統計數據等
    // 重置遊戲狀態或返回主菜單等
}

// 函數用於遊戲主循環
void GameLoop() {
    // 初始化玩家和地圖等遊戲元素
    Role^ player = gcnew Role();
    Map^ map = gcnew Map();

    // 遊戲主循環
    while (true) {
        // 獲取玩家輸入或執行自動操作，例如移動、攻擊、使用物品、使用技能等
        HandlePlayerInput(player);

        // 更新怪物位置、狀態等
        map->UpdateMonsters();

        // 玩家與怪物之間的戰鬥
        Monster^ currentMonster = map->GetCurrentMonster();
        Battle(player, currentMonster);

        // 檢查遊戲結束條件
        if (CheckGameWinCondition(player)) {
            // 玩家通關，執行相應的操作，例如顯示勝利畫面、統計數據等
            GameWin();
            break;
        }

        if (CheckGameOverCondition(player)) {
            // 玩家失敗，執行相應的操作，例如顯示失敗畫面、統計數據等
            GameOver();
            break;
        }

        // 等待一段時間，控制遊戲節奏
        Sleep(GameSpeed);
    }
}
*/
/*
// 函數用於處理玩家輸入
void HandlePlayerInput(Role^ player) {
    // 根據玩家輸入進行相應操作，例如移動、攻擊、使用物品、使用技能等
    // 這裡假設玩家按下按鍵時執行相應操作，你可以根據實際情況修改
    if (IsKeyPressed(KeyCode::UpArrow)) {
        player->MoveUp();
    }
    else if (IsKeyPressed(KeyCode::DownArrow)) {
        player->MoveDown();
    }
    else if (IsKeyPressed(KeyCode::LeftArrow)) {
        player->MoveLeft();
    }
    else if (IsKeyPressed(KeyCode::RightArrow)) {
        player->MoveRight();
    }
    else if (IsKeyPressed(KeyCode::Space)) {
        player->Attack();
    }
    else if (IsKeyPressed(KeyCode::1)) {
        player->UseItem(ItemType::MPPoison);
    }
    else if (IsKeyPressed(KeyCode::2)) {
        player->UseItem(ItemType::HPPoison);
    }
    else if (IsKeyPressed(KeyCode::3)) {
        player->UseItem(ItemType::SPPoison);
    }
    else if (IsKeyPressed(KeyCode::4)) {
        player->UseItem(ItemType::EXPGem);
    }
    else if (IsKeyPressed(KeyCode::5)) {
        player->UseItem(ItemType::Boom);
    }
}
*/

/*
// 函數用於玩家與怪物之間的戰鬥
void Battle(Role^ player, Monster^ monster) {
    // 玩家攻擊怪物
    player->Attack(monster);

    // 檢查怪物是否死亡
    if (monster->IsDead()) {
        // 怪物死亡，獲得經驗和金幣等獎勵
        player->GainExperience(monster->GetExperienceReward());
        player->GainCoins(monster->GetCoinReward());
        // 獲得怪物掉落的物品
        Item^ droppedItem = monster->GetDroppedItem();
        if (droppedItem != nullptr) {
            player->AddItemToInventory(droppedItem);
        }
        // 移除已經死亡的怪物
        map->RemoveMonster(monster);
    }
    else {
        // 怪物存活，怪物攻擊玩家
        monster->Attack(player);
    }
}
*/

/*
// 函數用於遊戲勝利時的操作
void GameWin() {
    // 執行遊戲勝利的相應操作，例如顯示勝利畫面、統計數據等
    // 重置遊戲狀態或返回主菜單等
}

// 函數用於處理玩家的升級和技能解鎖
void LevelUp(Role^ player) {
    // 玩家獲得足夠的經驗值，升級並解鎖新的技能
    // 根據玩家的等級執行相應的操作，例如增加生命值、增加攻擊力、解鎖新的技能等
}

// 函數用於顯示遊戲畫面
void RenderGameScreen() {
    // 渲染遊戲畫面，包括玩家、地圖、怪物、物品等的顯示
    // 根據遊戲界面的設計，使用相應的圖形庫或控制台輸出來顯示遊戲畫面
}

// 函數用於初始化遊戲
void InitializeGame() {
    // 執行遊戲的初始化操作，例如設定遊戲參數、載入資源、顯示開始畫面等
}
*/