// Rectangle.h: interface for the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANGLE_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_)
#define AFX_RECTANGLE_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Figure.h"

class CRectangle : public CFigure  
{
	DECLARE_SERIAL(CRectangle)
public:
	CFigure *Get();
	CRectangle();
	virtual ~CRectangle();

private:
	void CopyPoints(CPoint *pPoints, BOOL bFirstPoint=true);
	void DrawFigure(CDC *pDC);
};

#endif // !defined(AFX_RECTANGLE_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_)
