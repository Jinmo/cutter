/**
 * \file   SimpleCommandPaletteEngine.h
 * \brief  Defines class SimpleCommandPaletteEngine
 *
 * \author Stephan Seitz (stephan.seitz@fau.de)
 * \date   01.09.2017
 */

#ifndef SIMPLECOMANDPALETTEENGINE_H
#define SIMPLECOMANDPALETTEENGINE_H

#include "AbstractCommandPaletteEngine.h"

class SimpleCommandPaletteEngine: public AbstractCommandPaletteEngine
{
	Q_OBJECT
public:
	SimpleCommandPaletteEngine();
	virtual ~SimpleCommandPaletteEngine();
	
	

public slots:
	virtual void onSearchRequest( const QString& searchQuery ) override;

private:

};

#endif // SIMPLECOMANDPALETTEENGINE_H
