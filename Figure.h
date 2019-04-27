// Figure.h: interface for the CFigure class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIGURE_H__4AAA8004_0670_11D6_8CB3_00024400DF2B__INCLUDED_)
#define AFX_FIGURE_H__4AAA8004_0670_11D6_8CB3_00024400DF2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFigure : public CObject  
{
public:
	virtual void Serialize(CArchive &ar);
	BOOL PtInFigure(CPoint point);
	CString m_strName;
	virtual CRect *GetFrameRect();
	void SetBrush(LOGBRUSH lb);
	virtual void SetPen(LOGPEN lgpn);
	void Draw(CDC* pDC);
	virtual CFigure *Get() =0;
	UINT m_nNumberOfPoints;
	void Sketch(CDC *pDC, CPoint *pPoints);
	CPoint *m_pPoints;
	CFigure();
	virtual ~CFigure();

protected:
	virtual void CopyPoints(CPoint *pPoints, BOOL bFirstPoint=true) =0;
	virtual void DrawFigure(CDC *pDC) =0;
	void GetProporties(CFigure *pFigure);
	BOOL flag;
	LOGBRUSH m_brushProporties;
	LOGPEN m_penProporties;
};

#endif // !defined(AFX_FIGURE_H__4AAA8004_0670_11D6_8CB3_00024400DF2B__INCLUDED_)
