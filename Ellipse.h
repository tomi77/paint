// Ellipse.h: interface for the CEllipse class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELLIPSE_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_)
#define AFX_ELLIPSE_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Figure.h"

class CEllipse : public CFigure  
{
	DECLARE_SERIAL(CEllipse)
public:
	CFigure *Get();
	CEllipse();
	virtual ~CEllipse();

private:
	void CopyPoints(CPoint *pPoints, BOOL bFirstPoint=true);
	void DrawFigure(CDC *pDC);
};

#endif // !defined(AFX_ELLIPSE_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_)
