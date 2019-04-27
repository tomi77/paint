// RoundRectangle.h: interface for the CRoundRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROUNDRECTANGLE_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_)
#define AFX_ROUNDRECTANGLE_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Figure.h"

class CRoundRectangle : public CFigure  
{
	DECLARE_SERIAL(CRoundRectangle)
public:
	CFigure *Get();
	CRoundRectangle();
	virtual ~CRoundRectangle();

private:
	void CopyPoints(CPoint *pPoints, BOOL bFirstPoint=true);
	void DrawFigure(CDC *pDC);
};

#endif // !defined(AFX_ROUNDRECTANGLE_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_)
