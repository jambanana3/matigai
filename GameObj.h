#pragma once
class GameObj
{
public:
	GameObj();
	virtual ~GameObj();
public:
	virtual void update() = 0;
};

