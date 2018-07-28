#pragma once

#include <mutex>
#include <list>

#include "player.h"
#include "mechanics.h"
#include "npc_ids.h"
#include "helpers.h"

class Tracker
{
public:
	std::mutex players_mtx;
	std::mutex tracker_mtx;
	
	std::list<Player> players;
	
	Boss* boss_data;

	Tracker();
	~Tracker();

	Player* getPlayer(ag* new_player);
	bool addPlayer(char* name, char* account, uintptr_t id);
	bool removePlayer(char* name, char* account, uintptr_t id);
	Player generatePlayer(char* name, char* account, uintptr_t id);

	void addPull(Boss* boss);
	void resetAllPlayerStats();
	uint16_t getMechanicsTotal();
	uint8_t getPlayerNumInCombat();

	void processCombatEnter(ag* new_agent);
	void processCombatExit(ag* new_agent);
	void processMechanic(cbtevent* ev, Player* new_player_src, Player* new_player_dst, Mechanic* new_mechanic, int64_t value);
};
