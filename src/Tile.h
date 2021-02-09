#pragma once
#ifndef __TILE__
#define __TILE__
#include "DisplayObject.h"
#include "Label.h"
#include "NeighbourTile.h"

class Tile : public DisplayObject
{
public:
	// Constructor
	Tile();
	
	// Destructor
	~Tile();
	
	// Life-Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;

	Tile* getNeighbourTile(NeighbourTile position);
	void setNeighbourTile(NeighbourTile position, Tile* tile);

	float getTileCost();
	void setTileCost(float cost);

	void addLabels();
	void setLabelsEnabled(bool state);

	glm::vec2 getGridPosition() const;
	void setGridPosition(float col, float row);

private:
	Label* m_costLabel;
	Label* m_statusLabel;

	glm::vec2 m_gridPosition;
	
	float m_cost;
	Tile* m_neighbours[NUM_OF_NEIGHBOUR_TILES];
	
};

#endif /* defined (__TILE__) */