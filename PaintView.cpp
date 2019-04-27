// PaintView.cpp : implementation of the CPaintView class
//

#include "stdafx.h"
#include "Paint.h"

#include "PaintDoc.h"
#include "PaintView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintView

IMPLEMENT_DYNCREATE(CPaintView, CView)

BEGIN_MESSAGE_MAP(CPaintView, CView)
	//{{AFX_MSG_MAP(CPaintView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_CONTEXTMENU()
	ON_CBN_SELCHANGE(IDC_LINESTYLE, OnSelchangeLineStyle)
	ON_EN_KILLFOCUS(IDC_PENWIDTH, OnKillfocusPenWidth)
	ON_BN_CLICKED(IDC_GETPENCOLOR, OnGetPenColor)
	ON_BN_CLICKED(IDC_GETBRUSHCOLOR, OnGetBrushColor)
	ON_CBN_SELCHANGE(IDC_BRUSHSTYLE, OnSelchangeBrushStyle)
	ON_CBN_SELCHANGE(IDC_BRUSHHATCH, OnSelchangeBrushHatch)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	// Zakresowe
	ON_COMMAND_RANGE(ID_FIGURY_CHWYC, ID_FIGURY_CHORD, OnFigury)
	ON_UPDATE_COMMAND_UI_RANGE(ID_FIGURY_CHWYC, ID_FIGURY_CHORD, OnUpdateFigury)
	ON_COMMAND_RANGE(ID_EDIT_MOVEUP, ID_EDIT_MOVEBOTTOM, OnEditMove)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaintView construction/destruction

CPaintView::CPaintView()
{
	m_nCurrentFigure = ID_FIGURY_LINE;
	m_pCurrentFigure = NULL;
	m_pPoints = NULL;
	CreateFigure();
	m_nPointNumber = -1;
	m_lgpnPenProporties.lopnStyle = 0;
	m_lgpnPenProporties.lopnWidth = CPoint(1, 0);
	m_lgpnPenProporties.lopnColor = RGB(0, 0, 0);
	m_lbBrushProporties.lbStyle = 0;
	m_lbBrushProporties.lbColor = RGB(255, 255, 255);
	m_lbBrushProporties.lbHatch = 0;
//	m_colPenColor = RGB(0, 0, 0);
//	m_nPenStyle = 0;
//	m_nPenWidth = 1;
//	m_colBrushColor = RGB(0, 0, 0);
//	m_nBrushHatch = 0;
//	m_nBrushStyle = 0;
}

CPaintView::~CPaintView()
{
}

BOOL CPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPaintView drawing

void CPaintView::OnDraw(CDC *pDC)
{
	CPaintDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CFigure *pCurrentFigure;
	int nSize = pDoc->m_Figures.GetSize();
	for (int i = 0; i < nSize; ++i)
	{
		pCurrentFigure = (CFigure*)pDoc->m_Figures[i];
		pCurrentFigure->Draw(pDC);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPaintView printing

BOOL CPaintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPaintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPaintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPaintView diagnostics

#ifdef _DEBUG
void CPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintDoc* CPaintView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintDoc)));
	return (CPaintDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaintView message handlers

void CPaintView::OnFigury(UINT mID) 
{
	m_nCurrentFigure = mID;
	CreateFigure();
}

void CPaintView::OnUpdateFigury(CCmdUI* pCmdUI) 
{
	CMainFrame* pMainFrame = (CMainFrame*)GetParentFrame();
	pCmdUI->SetCheck(pCmdUI->m_nID == m_nCurrentFigure ? 1 : 0);

	int nCmdShow;
	switch (m_nCurrentFigure)
	{
	case ID_FIGURY_CHWYC:
		nCmdShow = SW_HIDE;
		break;
	default:
		nCmdShow = SW_SHOW;
	}
	pMainFrame->m_wndPenProporties.ShowWindow(nCmdShow);

	switch (m_nCurrentFigure)
	{
	case ID_FIGURY_CHWYC:
	case ID_FIGURY_ARC:
	case ID_FIGURY_LINE:
		nCmdShow = SW_HIDE;
		break;
	default:
		nCmdShow = SW_SHOW;
	}
	pMainFrame->m_wndBrushProporties.ShowWindow(nCmdShow);

	pMainFrame->RecalcLayout();
}

void CPaintView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if (m_nCurrentFigure == ID_FIGURY_CHWYC)
	{
		CPaintDoc *pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		CFigure *m_pFigure;
		int nSize = pDoc->m_Figures.GetSize();
		if (nSize > 0)
		{
			m_pFigure = (CFigure*)pDoc->m_Figures[--nSize];
			while (nSize > 0 && !m_pFigure->PtInFigure(point))
				m_pFigure = (CFigure*)pDoc->m_Figures[--nSize];

			if (m_pFigure->PtInFigure(point))
			{
				m_pCurrentFigure = m_pFigure;
				m_ptOldPoint = point;
				m_pPoints = m_pCurrentFigure->m_pPoints;
				SetCapture();
				SetCursor(AfxGetApp()->LoadCursor(IDC_MOVE));
			}
			else
				m_pCurrentFigure = NULL;
		}
	}
	else
	{
		++m_nPointNumber;
		m_pPoints[m_nPointNumber] = point;
		if (m_nPointNumber == 0)
		{
			SetCapture();
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		}
	}

	CView::OnLButtonDown(nFlags, point);
}

void CPaintView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (m_nCurrentFigure == ID_FIGURY_CHWYC && (nFlags & MK_LBUTTON == MK_LBUTTON))
	{
		if (m_pCurrentFigure != NULL)
		{
			CPoint ptC(point - m_ptOldPoint);
			UINT nSize = m_pCurrentFigure->m_nNumberOfPoints;
			// Kod dodatkowy dla RoundRectangle
			if (m_pCurrentFigure->m_strName == "Round rectangle")
				--nSize;
			for (UINT i = 0; i < nSize; ++i)
				m_pPoints[i] += ptC;

			m_ptOldPoint = point;
			CRect *pRect = m_pCurrentFigure->GetFrameRect();
			pRect->InflateRect(abs(ptC.x), abs(ptC.y), abs(ptC.x), abs(ptC.y));
			InvalidateRect(pRect);
		}
	}
	else
	{
		if (m_nPointNumber < m_nMaxPoint-1)
		{
			m_pPoints[m_nPointNumber+1] = point;

			// Kod dodatkowy dla RoundRectangle
			if (m_nCurrentFigure == ID_FIGURY_ROUNDRECTANGLE && m_nPointNumber == 0)
				m_pPoints[m_nPointNumber+2] = point;

			CClientDC dc(this);
			m_pCurrentFigure->Sketch(&dc, m_pPoints);
		}
	}
	
	CView::OnMouseMove(nFlags, point);
}

void CPaintView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (m_nCurrentFigure == ID_FIGURY_CHWYC)
	{
		if (m_pCurrentFigure != NULL)
		{
			m_pPoints = NULL;
			m_pCurrentFigure = NULL;
		}
		ReleaseCapture();
		SetCursor(AfxGetApp()->LoadCursor(IDC_ARROW));
	}
	else
	{
		if (m_nPointNumber < m_nMaxPoint-1)
			++m_nPointNumber;

		if (m_nPointNumber >= m_nMaxPoint-1)
		{
			CFigure* pNewFigure;
			pNewFigure = m_pCurrentFigure->Get();
			if (pNewFigure)
			{
				CPaintDoc* pDoc = GetDocument();
				ASSERT_VALID(pDoc);
				CClientDC dc(this);
				pNewFigure->SetPen(m_lgpnPenProporties);
				pNewFigure->SetBrush(m_lbBrushProporties);
				pNewFigure->Draw(&dc);
				pDoc->m_Figures.Add(pNewFigure);
				SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
				pDoc->SetModifiedFlag();
			}
			m_nPointNumber = -1;
			ReleaseCapture();
			CreateFigure();
		}
	}

	CView::OnLButtonUp(nFlags, point);
}

void CPaintView::CreateFigure()
{
	if (m_pCurrentFigure != NULL)
		delete m_pCurrentFigure;
	if (m_pPoints != NULL)
		delete[] m_pPoints;
	switch (m_nCurrentFigure)
	{
	case ID_FIGURY_LINE:
		m_pCurrentFigure = new CLine;
		break;
	case ID_FIGURY_ELLIPSE:
		m_pCurrentFigure = new CEllipse;
		break;
	case ID_FIGURY_RECTANGLE:
		m_pCurrentFigure = new CRectangle;
		break;
	case ID_FIGURY_ROUNDRECTANGLE:
		m_pCurrentFigure = new CRoundRectangle;
		break;
	case ID_FIGURY_ARC:
		m_pCurrentFigure = new CArc;
		break;
	case ID_FIGURY_CHORD:
		m_pCurrentFigure = new CChord;
		break;
	default:
		m_pCurrentFigure = NULL;
	}
	if (m_pCurrentFigure != NULL)
	{
		m_nMaxPoint = m_pCurrentFigure->m_nNumberOfPoints;
		m_pPoints = new CPoint[m_nMaxPoint];
	}
	else
	{
		m_nMaxPoint = 0;
		m_pPoints = NULL;
	}
}

void CPaintView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();
	ScreenToClient(&point);
	CPaintDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CFigure *pFigure;
	m_nSelectFigure = pDoc->m_Figures.GetSize();
	if (m_nSelectFigure > 0)
	{
		pFigure = (CFigure*)pDoc->m_Figures[--m_nSelectFigure];
		while (m_nSelectFigure > 0 && !pFigure->PtInFigure(point))
			pFigure = (CFigure*)pDoc->m_Figures[--m_nSelectFigure];

		if (pFigure->PtInFigure(point))
		{
			ClientToScreen(&point);
			CMenu Menu;
			Menu.LoadMenu(IDR_POPUPMENU);
			Menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
		}
	}
}

void CPaintView::OnSelchangeLineStyle() 
{
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();

	CComboBoxEx *pPenStyleSel = (CComboBoxEx*)
		(pMainFrame->m_wndPenProporties.GetDlgItem(IDC_PENSTYLE));
	if (pPenStyleSel) m_lgpnPenProporties.lopnStyle = pPenStyleSel->GetCurSel();
}

void CPaintView::OnKillfocusPenWidth() 
{
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();

	CEdit *pPenWidth = (CEdit*)
		(pMainFrame->m_wndPenProporties.GetDlgItem(IDC_PENWIDTH));
	if (pPenWidth)
	{
		CString str;
		pPenWidth->GetWindowText(str);
		m_lgpnPenProporties.lopnWidth.x = atoi(str);
	}
}

void CPaintView::OnGetPenColor() 
{
	CColorDialog dlgColor(m_lgpnPenProporties.lopnColor);
	if (IDOK == dlgColor.DoModal())
		m_lgpnPenProporties.lopnColor = dlgColor.GetColor();
}

void CPaintView::OnSelchangeBrushStyle() 
{
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();

	CComboBoxEx *pBrushStyleSel = (CComboBoxEx*)
		(pMainFrame->m_wndBrushProporties.GetDlgItem(IDC_BRUSHSTYLE));
	if (pBrushStyleSel) m_lbBrushProporties.lbStyle = pBrushStyleSel->GetCurSel();
}

void CPaintView::OnSelchangeBrushHatch() 
{
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();

	CComboBoxEx *pBrushHatchSel = (CComboBoxEx*)
		(pMainFrame->m_wndBrushProporties.GetDlgItem(IDC_BRUSHHATCH));
	if (pBrushHatchSel) m_lbBrushProporties.lbHatch = pBrushHatchSel->GetCurSel();
}

void CPaintView::OnGetBrushColor() 
{
	CColorDialog dlgColor(m_lbBrushProporties.lbColor);
	if (IDOK == dlgColor.DoModal())
		m_lbBrushProporties.lbColor = dlgColor.GetColor();	
}

void CPaintView::OnEditMove(UINT nID)
{
	BOOL bOK;
	int nNewPos;
	CPaintDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	UINT nSize = pDoc->m_Figures.GetSize();

	switch (nID)
	{
	case ID_EDIT_MOVEUP:
		bOK = m_nSelectFigure < nSize-1;
		nNewPos = m_nSelectFigure+1;
		break;
	case ID_EDIT_MOVEDOWN:
		bOK = m_nSelectFigure > 0;
		nNewPos = m_nSelectFigure-1;
		break;
	case ID_EDIT_MOVETOP:
		bOK = m_nSelectFigure < nSize-1;
		nNewPos = nSize-1;
		break;
	case ID_EDIT_MOVEBOTTOM:
		bOK = m_nSelectFigure > 0;
		nNewPos = 0;
		break;
	}
	if (bOK)
	{
		CFigure *pFigure = (CFigure*)pDoc->m_Figures[m_nSelectFigure];
		pDoc->m_Figures.RemoveAt(m_nSelectFigure);
		pDoc->m_Figures.InsertAt(nNewPos, pFigure);
		Invalidate();
		pDoc->SetModifiedFlag();
	}
}
