// Figure.cpp: implementation of the CFigure class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Paint.h"
#include "Figure.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFigure::CFigure()
{
	flag = false;
}

CFigure::~CFigure()
{
	delete[] m_pPoints;
}

void CFigure::SetPen(LOGPEN lgpn)
{
//	m_penProporties.lopnStyle = lgpn.lopnStyle;
//	m_penProporties.lopnWidth = lgpn.lopnWidth;
//	m_penProporties.lopnColor = lgpn.lopnColor;
	m_penProporties = lgpn;
}

void CFigure::SetBrush(LOGBRUSH lb)
{
//	m_brushProporties.lbStyle = lb.lbStyle;
//	m_brushProporties.lbColor = lb.lbColor;
//	m_brushProporties.lbHatch = lb.lbHatch;
	m_brushProporties = lb;
}

void CFigure::GetProporties(CFigure *pFigure)
{
	pFigure->m_penProporties = m_penProporties;
	pFigure->m_brushProporties = m_brushProporties;
	for (UINT i = 0; i < m_nNumberOfPoints; ++i)
		pFigure->m_pPoints[i] = m_pPoints[i];
}

void CFigure::Draw(CDC *pDC)
{
	CPen *pOldPen = pDC->GetCurrentPen();
	CPen pen;
	pen.CreatePenIndirect(&m_penProporties);
	pDC->SelectObject(&pen);

	CBrush *pOldBrush = pDC->GetCurrentBrush();
	CBrush brush;
	brush.CreateBrushIndirect(&m_brushProporties);
	pDC->SelectObject(&brush);
	
	DrawFigure(pDC);

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}

void CFigure::Sketch(CDC* pDC, CPoint* pPoints)
{
	pDC->SetROP2(R2_NOT);
	CPen* pOldPen = (CPen*)pDC->SelectStockObject(BLACK_PEN);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	if (flag)
	{
		DrawFigure(pDC);
	}
	else
	{
		flag = true;
		CopyPoints(pPoints);
	}
	CopyPoints(pPoints, false);
	DrawFigure(pDC);

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}

/*void CFigure::ReSketch(CDC *pDC, CPoint *pPoints)
{
	CPen pen;
	pen.CreatePenIndirect(&m_penProporties);
	CPen *pOldPen = (CPen*)pDC->SelectObject(&pen);

	CBrush brush;
	brush.CreateBrushIndirect(&m_brushProporties);
	CBrush *pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	int nROPOld = pDC->SetROP2(R2_NOT);
	DrawFigure(pDC);

	CopyPoints(pPoints);
	CopyPoints(pPoints, false);

	pDC->SetROP2(nROPOld);
	DrawFigure(pDC);

	pDC->SelectObject(&pOldBrush);
	pDC->SelectObject(&pOldPen);
}
*/
CRect *CFigure::GetFrameRect()
{
	int nMinX = m_pPoints[0].x;
	int nMinY = m_pPoints[0].y;
	int nMaxX = m_pPoints[0].x;
	int nMaxY = m_pPoints[0].y;
	for (UINT i = 1; i < m_nNumberOfPoints; ++i)
	{
		nMinX = min(nMinX, m_pPoints[i].x);
		nMinY = min(nMinY, m_pPoints[i].y);
		nMaxX = max(nMaxX, m_pPoints[i].x);
		nMaxY = max(nMaxY, m_pPoints[i].y);
	}
	CRect *rect = new CRect(nMinX, nMinY, nMaxX, nMaxY);
	return rect;
}

BOOL CFigure::PtInFigure(CPoint point)
{
	CRect *rect;
	BOOL bInFigure = false;
	rect = GetFrameRect();
	if (rect->PtInRect(point)) bInFigure = true;
	delete rect;
	return bInFigure;
}

void CFigure::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		for (UINT i = 0; i < m_nNumberOfPoints; ++i)
			ar << m_pPoints[i];
		ar << m_penProporties.lopnColor << m_penProporties.lopnStyle << m_penProporties.lopnWidth;
		ar << m_brushProporties.lbColor << m_brushProporties.lbHatch << m_brushProporties.lbStyle;
	}
	else
	{
		for (UINT i = 0; i < m_nNumberOfPoints; ++i)
			ar >> m_pPoints[i];
		ar >> m_penProporties.lopnColor >> m_penProporties.lopnStyle >> m_penProporties.lopnWidth;
		ar >> m_brushProporties.lbColor >> m_brushProporties.lbHatch >> m_brushProporties.lbStyle;
	}
}
