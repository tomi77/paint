#if !defined(AFX_MYTOOLBAR_H__40FE6807_0995_11D6_8CB3_00024400DF2B__INCLUDED_)
#define AFX_MYTOOLBAR_H__40FE6807_0995_11D6_8CB3_00024400DF2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyToolBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyToolBar window

class CMyToolBar : public CToolBar
{
// Construction
public:
	CMyToolBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyToolBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	UINT GetColumns();
	void SetColumns(UINT nColumns);
	virtual ~CMyToolBar();

	// Generated message map functions
protected:
	UINT m_nColumns;
	//{{AFX_MSG(CMyToolBar)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTOOLBAR_H__40FE6807_0995_11D6_8CB3_00024400DF2B__INCLUDED_)
