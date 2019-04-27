// Chord.h: interface for the CChord class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHORD_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_)
#define AFX_CHORD_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Figure.h"

class CChord : public CFigure  
{
	DECLARE_SERIAL(CChord)
public:
	CFigure *Get();
	CChord();
	virtual ~CChord();

private:
	void CopyPoints(CPoint *pPoints, BOOL bFirstPoint=true);
	void DrawFigure(CDC *pDC);
};

#endif // !defined(AFX_CHORD_H__DCF63CEB_069F_11D6_8CB3_00024400DF2B__INCLUDED_)
