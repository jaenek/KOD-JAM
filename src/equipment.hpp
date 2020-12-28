#pragma once

#include "gold.hpp"
#include "rock.hpp"
#include "dwarf.hpp"

class gold;
class rock;

class dwarf
{
	friend class gold;
	friend class rock;
private:

	unsigned int _gold;
	unsigned int _torches;
	unsigned int _pickaxe;
	unsigned int _food;
	unsigned int _hp;
public:
	equipment();//sets attributes base values
	bool place_torch();
	bool use_pickaxe();
};