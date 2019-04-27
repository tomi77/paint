// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Paint.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Zakresowe
	ON_COMMAND_RANGE(ID_VIEW_FIGURY, ID_VIEW_BRUSHPROPORTIES, OnView)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_FIGURY, ID_VIEW_BRUSHPROPORTIES, OnUpdateView)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	if (!m_wndFigury.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_SIZE_FIXED
		| CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY) ||
		!m_wndFigury.LoadToolBar(IDR_FIGURY))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	m_wndFigury.SetWindowText(_T("Figures"));
	if (!m_wndPenProporties.Create(this, IDD_PENPROPORTIES, CBRS_TOP,
		AFX_IDW_CONTROLBAR_LAST -1))
	{
		TRACE0("Failed to create dialog bar\n");
		return -1;      // fail to create
	}
	m_wndPenProporties.SetWindowText(_T("Pen proporties"));
	if (!m_wndBrushProporties.Create(this, IDD_BRUSHPROPORTIES, CBRS_TOP,
		AFX_IDW_CONTROLBAR_LAST -2))
	{
		TRACE0("Failed to create dialog bar\n");
		return -1;      // fail to create
	}
	m_wndBrushProporties.SetWindowText(_T("Brush proporties"));

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndFigury.EnableDocking(CBRS_ALIGN_ANY);
	m_wndPenProporties.EnableDocking(CBRS_ALIGN_TOP);
	m_wndBrushProporties.EnableDocking(CBRS_ALIGN_TOP);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_wndFigury, AFX_IDW_DOCKBAR_LEFT);
//	DockControlBarLeftOf(&m_wndFigury, &m_wndToolBar);
//	CPoint point(10, 50);
//	ClientToScreen(&point);
//	FloatControlBar(&m_wndFigury, point);
	DockControlBar(&m_wndPenProporties);
	DockControlBarLeftOf(&m_wndBrushProporties, &m_wndPenProporties);
	m_wndFigury.SetColumns(2);

	CComboBoxEx *pPenStyleSel = (CComboBoxEx*)m_wndPenProporties.GetDlgItem(IDC_PENSTYLE);
	if (pPenStyleSel) pPenStyleSel->SetCurSel(0);
	
	CEdit *pPenWidth = (CEdit*)m_wndPenProporties.GetDlgItem(IDC_PENWIDTH);
	if (pPenWidth) pPenWidth->SetWindowText("1");

	CComboBoxEx *pBrushStyleSel = (CComboBoxEx*)m_wndBrushProporties.GetDlgItem(IDC_BRUSHSTYLE);
	if (pBrushStyleSel) pBrushStyleSel->SetCurSel(0);

	CComboBoxEx *pBrushHatchSel = (CComboBoxEx*)m_wndBrushProporties.GetDlgItem(IDC_BRUSHHATCH);
	if (pBrushHatchSel) pBrushHatchSel->SetCurSel(0);

	return 0;
}

void CMainFrame::DockControlBarLeftOf(CControlBar* Bar, CControlBar* LeftOf)
{
	CRect rect;
	DWORD dw;
	UINT n;

	// get MFC to adjust the dimensions of all docked ToolBars
	// so that GetWindowRect will be accurate
	RecalcLayout();
	LeftOf->GetWindowRect(&rect);
	rect.OffsetRect(1,0);
	dw=LeftOf->GetBarStyle();
	n = 0;
	n = (dw&CBRS_ALIGN_TOP) ? AFX_IDW_DOCKBAR_TOP : n;
	n = (dw&CBRS_ALIGN_BOTTOM && n==0) ? AFX_IDW_DOCKBAR_BOTTOM : n;
	n = (dw&CBRS_ALIGN_LEFT && n==0) ? AFX_IDW_DOCKBAR_LEFT : n;
	n = (dw&CBRS_ALIGN_RIGHT && n==0) ? AFX_IDW_DOCKBAR_RIGHT : n;

	// When we take the default parameters on rect, DockControlBar will dock
	// each Toolbar on a seperate line.  By calculating a rectangle, we in effect
	// are simulating a Toolbar being dragged to that location and docked.
	DockControlBar(Bar,n,&rect);
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= WS_MAXIMIZE;
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnView(UINT nID)
{
	CControlBar *pToolBar;
	switch (nID)
	{
	case ID_VIEW_FIGURY:
		pToolBar = &m_wndFigury;
		break;
	case ID_VIEW_PENPROPORTIES:
		pToolBar = &m_wndPenProporties;
		break;
	case ID_VIEW_BRUSHPROPORTIES:
		pToolBar = &m_wndBrushProporties;
		break;
	}
	BOOL bVisible = !pToolBar->IsWindowVisible();
	ShowControlBar(pToolBar, bVisible, FALSE);
}

void CMainFrame::OnUpdateView(CCmdUI *pCmdUI)
{
	BOOL bVisible;
	switch (pCmdUI->m_nID)
	{
	case ID_VIEW_FIGURY:
		bVisible = m_wndFigury.IsWindowVisible();
		break;
	case ID_VIEW_PENPROPORTIES:
		bVisible = m_wndPenProporties.IsWindowVisible();
		break;
	case ID_VIEW_BRUSHPROPORTIES:
		bVisible = m_wndBrushProporties.IsWindowVisible();
		break;
	}
	pCmdUI->Enable();
	pCmdUI->SetCheck(bVisible);
}
