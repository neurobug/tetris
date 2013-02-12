//
//  Table.hpp
//  Tetris
//
//  Created by Edu San Martin Morote on 07/02/13.
//  Copyright 2013 Posva Games. All rights reserved.
//
#pragma once
#include "Block.hpp"
#include <list>
#include <ctime>
#include <cstdlib>

struct TableCell {
	BlockType type;
	bool empty;
	TableCell(uint16_t _type = 0, bool _empty = true) : type(_type), empty(_empty) {}
};

enum Rotation {
	None,
	Left,
	Right
	};

struct Control {
	Rotation rot, mov;
	bool force, doStep;
	
	Control(Rotation _rot = None, Rotation _mov = None, bool _force = false, bool _doStep = false) : rot(_rot), mov(_mov), force(_force), doStep(_doStep) {}
};

class Table {
	Position m_currentPos;
	std::vector<std::vector<TableCell> > m_tab;
	std::list<Block*> m_blockList;
	uint16_t m_maxRand;
	
	
	void initBlockList();
	
	bool canMove(bool right);
	bool canMoveDown();
	bool canTurn(bool rigth);
	
	void fillWithBlock();
	void removeBlock();
	
	void generateNewBlock();
	
	uint16_t cleanFilledLines();
	
public:
	
	Table(uint16_t w = 10, uint16_t h = 14);
	~Table();
	
	bool step(const Control& control, uint32_t &points);
	
	void print() const;
	
	void restart();
	
	
	inline Position getSize() const { Position p(m_tab[0].size(), m_tab.size()); return p; }
	
	inline const TableCell& getCell(uint16_t x, uint16_t y) const
	{
		return m_tab[y][x];
	}
	
	inline const Block& getCurrentBlock() const { return *m_blockList.front(); }
	inline const Block& getNextBlock() const { return **(++m_blockList.begin()); }
	inline Position getCurrentPosition() const { return m_currentPos; }
	
};