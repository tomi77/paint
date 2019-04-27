// Arc.cpp: implementation of the CArc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Paint.h"
#include "Arc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CArc, CObject, 1)

CArc::CArc()
{
	m_nNumberOfPoints = 4;
	m_pPoints = new CPoint[m_nNumberOfPoints];
	m_strName = "Arc";
}

CArc::~CArc()
{
}

CFigure *CArc::Get()
{
	CArc *pArc = new CArc;
	GetProporties((CFigure*)pArc);
	return pArc;
}

void CArc::DrawFigure(CDC *pDC)
{
	pDC->Arc(CRect(m_pPoints[0], m_pPoints[1]), m_pPoints[2], m_pPoints[3]);	
}

void CArc::CopyPoints(CPoint *pPoints, BOOL bFirstPoint)
{
	if (bFirstPoint)
		m_pPoints[0] = pPoints[0];
	else
	{
		m_pPoints[1] = pPoints[1];
		m_pPoints[2] = pPoints[2];
		m_pPoints[3] = pPoints[3];
	}
}
