#include "CBroadPhaseCulling.h"

using namespace engine;
CBroadPhaseCulling* CBroadPhaseCulling::s_instance = nullptr;
CBroadPhaseCulling::CBroadPhaseCulling(float cellWidth, float cellHeight, int rows, int columns)
    :CGrid<std::unordered_set<uint32_t>>(cellWidth, cellHeight, rows, columns)
{

}

CBroadPhaseCulling *CBroadPhaseCulling::instance(float cellWidth, float cellHeight, int rows, int columns)
{
    return s_instance = (s_instance == nullptr)? new CBroadPhaseCulling(cellWidth, cellHeight, rows, columns): s_instance;
}

void CBroadPhaseCulling::insert(uint32_t id, float x, float y)
{
    int position = hash(x, y);
    if(position >= this->cells()) return;
    if(this->at(position).find(id) == this->at(position).end())
    {
        this->at(position).insert(id);
    }
}

void CBroadPhaseCulling::clean()
{
    for(int row = 0; row < rows(); row++)
    {
        for(int column = 0; column < columns(); column++)
        {
            this->at(row, column).clear();
        }
    }
}







