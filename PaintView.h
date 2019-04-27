// PaintView.h : interface of the CPaintView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAINTVIEW_H__ED1D9A2D_0549_11D6_8CB3_00024400DF2B__INCLUDED_)
#define AFX_PAINTVIEW_H__ED1D9A2D_0549_11D6_8CB3_00024400DF2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Figures.h"

class CPaintView : public CView
{
protected: // create from serialization only
	CPaintView();
	DECLARE_DYNCREATE(CPaintView)

// Attributes
public:
	CPaintDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	UINT m_nMaxPoint;
	void OnFigury(UINT nID);
	void OnUpdateFigury(CCmdUI* pCmdUI);
	void OnEditMove(UINT nID);
	//{{AFX_MSG(CPaintView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnSelchangeLineStyle();
	afx_msg void OnKillfocusPenWidth();
	afx_msg void OnGetPenColor();
	afx_msg void OnGetBrushColor();
	afx_msg void OnSelchangeBrushStyle();
	afx_msg void OnSelchangeBrushHatch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	LOGBRUSH m_lbBrushProporties;
	LOGPEN m_lgpnPenProporties;
	UINT m_nSelectFigure;
	CPoint m_ptOldPoint;
	CPoint* m_pPoints;
	UINT m_nPointNumber;
	CFigure* m_pCurrentFigure;
	void CreateFigure();
	UINT m_nCurrentFigure;
};

#ifndef _DEBUG  // debug version in PaintView.cpp
inline CPaintDoc* CPaintView::GetDocument()
   { return (CPaintDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTVIEW_H__ED1D9A2D_0549_11D6_8CB3_00024400DF2B__INCLUDED_)
