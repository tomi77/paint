// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Paint.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CLine, CObject, 1)

CLine::CLine()
{
	m_nNumberOfPoints = 2;
	m_pPoints = new CPoint[m_nNumberOfPoints];
	m_strName = "Line";
}

CLine::~CLine()
{
}

CFigure *CLine::Get()
{
	CLine *pLine = new CLine;
	GetProporties((CFigure*)pLine);
	return pLine;
}

void CLine::DrawFigure(CDC *pDC)
{
	pDC->MoveTo(m_pPoints[0]);
	pDC->LineTo(m_pPoints[1]);
}

void CLine::CopyPoints(CPoint *pPoints, BOOL bFirstPoint)
{
	if (bFirstPoint)
		m_pPoints[0] = pPoints[0];
	else
		m_pPoints[1] = pPoints[1];
}
