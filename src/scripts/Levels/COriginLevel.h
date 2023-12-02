#ifndef CORIGINLEVEL_H
#define CORIGINLEVEL_H

#include "CommonDefine.h"
#include "ALevel.h"
#include "TilemapParser/CTilemapParser.h"

BEGIN_NAMESPACE(script)
class COriginLevel: public engine::ALevel
{
private:
    CTilemapParser                  m_parser;

public:
    COriginLevel();

    // ALevel interface
public:
    virtual void update(float) override;
    virtual void render() override;
};
END_NAMESPACE

#endif // CORIGINLEVEL_H
