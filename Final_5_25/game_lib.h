#pragma once
#include "data_format.h"
#include "pch.h"

// 函數用於計算角色造成的傷害
int CalculateDamage(int attack, int defense);

// 函數用於玩家攻擊怪物
void AttackMonster(Role^ player, Monster^ monster);

// 函數用於玩家使用物品
void UseItem(Role^ player, Item^ item);

// 函數用於檢查玩家是否可以使用技能
bool CanUseSkill(Role^ player, Skill^ skill);

// 函數用於玩家使用技能
void UseSkill(Role^ player, Skill^ skill);

// 函數用於遊戲開始時生成怪物
Monster^ GenerateMonster();

// 函數用於遊戲開始時生成Boss
Boss^ GenerateBoss();

// 函數用於遊戲結束時判斷是否達到通關條件
bool CheckGameWinCondition(Role^ player);

// 函數用於遊戲結束時判斷是否失敗條件
bool CheckGameOverCondition(Role^ player);

// 函數用於遊戲結束時的操作
//void GameOver();

// 函數用於遊戲主循環
//void GameLoop();

// 函數用於處理玩家輸入
//void HandlePlayerInput(Role^ player);

// 函數用於玩家與怪物之間的戰鬥
//oid Battle(Role^ player, Monster^ monster);

// 函數用於遊戲勝利時的操作
//void GameWin();

// 函數用於處理玩家的升級和技能解鎖
//void LevelUp(Role^ player);

// 函數用於顯示遊戲畫面
//void RenderGameScreen();

// 函數用於初始化遊戲
//void InitializeGame();