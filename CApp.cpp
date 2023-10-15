#include <afxwin.h>
#include "CApp.h"

BOOL CApp::InitInstance() {
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CApp App;

CMainWin::CMainWin()
{
	timer = 0;
	Create(NULL, "MFC_Proj");
	SetTimer(1, 1000, nullptr);
}

BEGIN_MESSAGE_MAP(CMainWin, CFrameWnd)

	ON_WM_CLOSE()//

	ON_WM_CHAR()//

	ON_WM_MOUSEMOVE()//

	ON_WM_ACTIVATE()//

	ON_WM_TIMER()//

END_MESSAGE_MAP()

void CMainWin::OnMouseMove(UINT nFlags, CPoint point) {
	char str[30];
	wsprintf(str, "Mouse moved to (%d, %d)", point.x, point.y);

	CClientDC dc(this);
	dc.TextOutA(500, 250, str, strlen(str));
}

void CMainWin::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CString str;
	if (nState == WA_ACTIVE || nState == WA_CLICKACTIVE)
	{
		str.Format("Activated");
	}
	else if (nState == WA_INACTIVE)
	{
		str.Format("Deactivated");
	}
	CClientDC dc(this);
	dc.TextOut(500, 300, str);

}

void CMainWin::OnTimer(UINT_PTR nIDEvent)
{
	timer++;
	char str[20];
	wsprintf(str, "time: %d", timer);
	CClientDC dc(this);
	dc.TextOutA(500, 200, str, strlen(str));
	SetWindowText(str);
}

void CMainWin::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	char str[20];
	wsprintf(str, "key: %c", nChar);
	CClientDC dc(this);
	dc.TextOutA(500, 150, str, strlen(str));
}

void CMainWin::OnClose()
{
	int res = MessageBox("Close program???", "Message Box", MB_YESNOCANCEL);
	if (res == IDYES) {CFrameWnd::OnClose();}
}

