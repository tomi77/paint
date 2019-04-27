; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPaintView
LastTemplate=CToolBarCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Paint.h"
LastPage=0

ClassCount=6
Class1=CPaintApp
Class2=CPaintDoc
Class3=CPaintView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_PENPROPORTIES (English (U.S.))
Resource4=IDD_ABOUTBOX (English (U.S.))
Class6=CCMyToolBar
Resource5=IDR_MAINFRAME (English (U.S.))
Resource6=IDR_FIGURY (English (U.S.))
Resource7=IDR_MENU1
Resource8=IDR_POPUPMENU
Resource9=IDD_BRUSHPROPORTIES (English (U.S.))

[CLS:CPaintApp]
Type=0
HeaderFile=Paint.h
ImplementationFile=Paint.cpp
Filter=N
LastObject=CPaintApp

[CLS:CPaintDoc]
Type=0
HeaderFile=PaintDoc.h
ImplementationFile=PaintDoc.cpp
Filter=N
LastObject=CPaintDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CPaintView]
Type=0
HeaderFile=PaintView.h
ImplementationFile=PaintView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CPaintView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Paint.cpp
ImplementationFile=Paint.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
CommandCount=16
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command16=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
CommandCount=14
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE


[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_VIEW_FIGURY
Command17=ID_VIEW_PENPROPORTIES
Command18=ID_VIEW_BRUSHPROPORTIES
Command19=ID_APP_ABOUT
Command20=ID_FIGURY_CHWYC
Command21=ID_FIGURY_LINE
Command22=ID_FIGURY_ELLIPSE
Command23=ID_FIGURY_RECTANGLE
Command24=ID_FIGURY_ROUNDRECTANGLE
Command25=ID_FIGURY_ARC
Command26=ID_FIGURY_CHORD
CommandCount=26

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[TB:IDR_FIGURY (English (U.S.))]
Type=1
Class=?
Command1=ID_FIGURY_CHWYC
Command2=ID_FIGURY_LINE
Command3=ID_FIGURY_ELLIPSE
Command4=ID_FIGURY_RECTANGLE
Command5=ID_FIGURY_ROUNDRECTANGLE
Command6=ID_FIGURY_ARC
Command7=ID_FIGURY_CHORD
CommandCount=7

[CLS:CCMyToolBar]
Type=0
HeaderFile=CMyToolBar.h
ImplementationFile=CMyToolBar.cpp
BaseClass=CToolBarCtrl
Filter=W

[DLG:IDD_PENPROPORTIES (English (U.S.))]
Type=1
Class=CPaintView
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PENSTYLE,ComboBoxEx32,1344340226
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PENWIDTH,edit,1350639616
Control5=IDC_STATIC,static,1342308352
Control6=IDC_GETPENCOLOR,button,1342242816

[DLG:IDD_BRUSHPROPORTIES (English (U.S.))]
Type=1
Class=CPaintView
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BRUSHSTYLE,ComboBoxEx32,1344340226
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BRUSHHATCH,ComboBoxEx32,1344340226
Control5=IDC_STATIC,static,1342308352
Control6=IDC_GETBRUSHCOLOR,button,1342242944

[MNU:IDR_POPUPMENU]
Type=1
Class=?
Command1=ID_EDIT_MOVETOP
Command2=ID_EDIT_MOVEUP
Command3=ID_EDIT_MOVEDOWN
Command4=ID_EDIT_MOVEBOTTOM
CommandCount=4

