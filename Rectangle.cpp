// Rectangle.cpp: implementation of the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Paint.h"
#include "Rectangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CRectangle, CObject, 1)

CRectangle::CRectangle()
{
	m_nNumberOfPoints = 2;
	m_pPoints = new CPoint[m_nNumberOfPoints];
	m_strName = "Rectangle";
}

CRectangle::~CRectangle()
{
}

CFigure *CRectangle::Get()
{
	CRectangle *pRectangle = new CRectangle;
	GetProporties((CFigure*)pRectangle);
	return pRectangle;
}

void CRectangle::DrawFigure(CDC *pDC)
{
	pDC->Rectangle(CRect(m_pPoints[0], m_pPoints[1]));
}

void CRectangle::CopyPoints(CPoint *pPoints, BOOL bFirstPoint)
{
	if (bFirstPoint)
		m_pPoints[0] = pPoints[0];
	else
		m_pPoints[1] = pPoints[1];
}
