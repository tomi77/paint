// Ellipse.cpp: implementation of the CEllipse class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Paint.h"
#include "Ellipse.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CEllipse, CObject, 1)

CEllipse::CEllipse()
{
	m_nNumberOfPoints = 2;
	m_pPoints = new CPoint[m_nNumberOfPoints];
	m_strName = "Ellipse";
}

CEllipse::~CEllipse()
{
}

CFigure *CEllipse::Get()
{
	CEllipse *pEllipse = new CEllipse;
	GetProporties((CFigure*)pEllipse);
	return pEllipse;
}

void CEllipse::DrawFigure(CDC *pDC)
{
	pDC->Ellipse(CRect(m_pPoints[0], m_pPoints[1]));
}

void CEllipse::CopyPoints(CPoint *pPoints, BOOL bFirstPoint)
{
	if (bFirstPoint)
		m_pPoints[0] = pPoints[0];
	else
		m_pPoints[1] = pPoints[1];
}
