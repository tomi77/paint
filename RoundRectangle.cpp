// RoundRectangle.cpp: implementation of the CRoundRectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Paint.h"
#include "RoundRectangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CRoundRectangle, CObject, 1)

CRoundRectangle::CRoundRectangle()
{
	m_nNumberOfPoints = 3;
	m_pPoints = new CPoint[m_nNumberOfPoints];
	m_strName = "Round rectangle";
}

CRoundRectangle::~CRoundRectangle()
{
}

CFigure *CRoundRectangle::Get()
{
	CRoundRectangle *pRoundRectangle = new CRoundRectangle;
	GetProporties((CFigure*)pRoundRectangle);
	return pRoundRectangle;
}

void CRoundRectangle::DrawFigure(CDC *pDC)
{
	pDC->RoundRect(CRect(m_pPoints[0], m_pPoints[1]), m_pPoints[2]);
}

void CRoundRectangle::CopyPoints(CPoint *pPoints, BOOL bFirstPoint)
{
	if (bFirstPoint)
		m_pPoints[0] = pPoints[0];
	else
	{
		m_pPoints[1] = pPoints[1];
		m_pPoints[2] = pPoints[2] - pPoints[1];
	}
}
