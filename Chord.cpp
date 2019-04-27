// Chord.cpp: implementation of the CChord class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Paint.h"
#include "Chord.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CChord, CObject, 1)

CChord::CChord()
{
	m_nNumberOfPoints = 4;
	m_pPoints = new CPoint[m_nNumberOfPoints];
	m_strName = "Chord";
}

CChord::~CChord()
{
}

CFigure *CChord::Get()
{
	CChord *pChord = new CChord;
	GetProporties((CFigure*)pChord);
	return pChord;
}

void CChord::DrawFigure(CDC *pDC)
{
	pDC->Chord(CRect(m_pPoints[0], m_pPoints[1]), m_pPoints[2], m_pPoints[3]);
}

void CChord::CopyPoints(CPoint *pPoints, BOOL bFirstPoint)
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
